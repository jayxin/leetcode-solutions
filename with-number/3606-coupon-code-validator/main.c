#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 3606. 优 惠券校验器 - 给你三个长度为 n 的数组，分别描述 n 个优惠券的属性：code、businessLine 和 isActive。其中，第 i 个优惠券具有以下属性：
//  * code[i]：一个 字符串，表示优惠券的标识符。
//  * businessLine[i]：一个 字符串，表示优惠券所属的业务类别。
//  * isActive[i]：一个 布尔值，表示优惠券是否当前有效。
// 当以下所有条件都满足时，优惠券被认为是 有效的 ：
//  1. code[i] 不能为空，并且仅由字母数字字符（a-z、A-Z、0-9）和下划线（_）组成。
//  2. businessLine[i] 必须是以下四个类别之一："electronics"、"grocery"、"pharmacy"、"restaurant"。
//  3. isActive[i] 为 true 。
// 返回所有 有效优惠券的标识符 组成的数组，按照以下规则排序：
//  * 先按照其 businessLine 的顺序排序："electronics"、"grocery"、"pharmacy"、"restaurant"。
//  * 在每个类别内，再按照 标识符的字典序（升序）排序。
//  
// 示例 1：
// 输入： code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]
// 输出： ["PHARMA5","SAVE20"]
// 解释：
//  * 第一个优惠券有效。
//  * 第二个优惠券的标识符为空（无效）。
//  * 第三个优惠券有效。
//  * 第四个优惠券的标识符包含特殊字符 @（无效）。
// 示例 2：
// 输入： code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"], businessLine = ["grocery","electronics","invalid"], isActive = [false,true,true]
// 输出： ["ELECTRONICS_50"]
// 解释：
//  * 第一个优惠券无效，因为它未激活。
//  * 第二个优惠券有效。
//  * 第三个优惠券无效，因为其业务类别无效。
//  
// 提示：
//  * n == code.length == businessLine.length == isActive.length
//  * 1 <= n <= 100
//  * 0 <= code[i].length, businessLine[i].length <= 100
//  * code[i] 和 businessLine[i] 由可打印的 ASCII 字符组成。
//  * isActive[i] 的值为 true 或 false。

// #v1
struct Pair {
  char *id;
  int businessKind;
};

bool isCodeValid(char *s) {
  int i = 0;
  while (*s) {
    if (!isalnum(*s) && *s != '_') return false;
    ++i;
    ++s;
  }
  if (!i) return false;
  return true;
}

bool isBusinessValid(char *s) {
  if (!strcmp(s, "electronics") || !strcmp(s, "grocery") || !strcmp(s, "pharmacy") || !strcmp(s, "restaurant"))
    return true;
  return false;
}

int cmp(const void *a, const void *b) {
  const struct Pair *aa = a, *bb = b;
  if (aa->businessKind != bb->businessKind)
    return aa->businessKind - bb->businessKind;
  return strcmp(aa->id, bb->id);
}

char** validateCoupons(char** code, int codeSize, char** businessLine, int businessLineSize, bool* isActive, int isActiveSize, int* returnSize) {
  struct Pair pair[codeSize];
  int pairLen = 0;
  char **ret;

  for (int i = 0; i < codeSize; i++) {
    if (!isActive[i]) continue;
    if (!isCodeValid(code[i])) continue;
    if (!isBusinessValid(businessLine[i])) continue;

    pair[pairLen].id = code[i];
    switch (businessLine[i][0]) {
      case 'e':
        pair[pairLen].businessKind = 0;
        break;
      case 'g':
        pair[pairLen].businessKind = 1;
        break;
      case 'p':
        pair[pairLen].businessKind = 2;
        break;
      case 'r':
        pair[pairLen].businessKind = 3;
        break;
    }
    ++pairLen;
  }

  qsort(pair, pairLen, sizeof(struct Pair), cmp);

  *returnSize = pairLen;
  ret = (char **)malloc(sizeof(char *) * pairLen);
  for (int i = 0; i < pairLen; i++) {
    int n = strlen(pair[i].id);
    ret[i] = (char *)malloc(sizeof(char) * (n + 1));
    sprintf(ret[i], "%s", pair[i].id);
  }

  return ret;
}
// #v1

// read one line from stream
char* read_line(char *buffer, size_t size, FILE *stream) {
  if (fgets(buffer, size, stream) == NULL) {
    return NULL;
  }

  size_t len = strlen(buffer);
  if (len > 0 && buffer[len - 1] == '\n') {
    buffer[len - 1] = '\0';
  }

  return buffer;
}

int main(int argc, char *argv[])
{
  int n, returnSize;
  char **code, **businessLine, **ret;
  bool *isActive;
  scanf("%d\n", &n);
  code = (char **)malloc(sizeof(char *) * n);
  businessLine = (char **)malloc(sizeof(char *) * n);
  isActive = (bool *)malloc(sizeof(bool) * n);
  for (int i = 0; i < n; i++) {
    code[i] = (char *)malloc(sizeof(char) * 100);
    read_line(code[i], 98, stdin);
  }
  for (int i = 0; i < n; i++) {
    businessLine[i] = (char *)malloc(sizeof(char) * 100);
    read_line(businessLine[i], 98, stdin);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &isActive[i]);
  }
  ret = validateCoupons(code, n, businessLine, n, isActive, n, &returnSize);
  for (int i = 0; i < returnSize; i++) {
    printf("%s\n", ret[i]);
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
