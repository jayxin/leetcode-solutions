#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 17.  电话号码的字母组合 - 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合 。答案可以按 任意顺序 返回。
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
// [https://pic.leetcode.cn/1752723054-mfIHZs-image.png]
//  
// 示例 1：
// 输入：digits = "23"
// 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 示例 2：
// 输入：digits = ""
// 输出：[]
// 示例 3：
// 输入：digits = "2"
// 输出：["a","b","c"]
//  
// 提示：
//  * 0 &lt;= digits.length &lt;= 4
//  * digits[i] 是范围 ['2', '9'] 的一个数字。

// #v1
char **digitCharMap, **ret, *tmp;
int *lens, retLen;

void _letterCombinations(char *s, int pos) {
  if (*s == '\0') {
    strcpy(ret[retLen], tmp);
    retLen++;
    return ;
  }

  int digit = *s - '0', nextPos, i;

  ++s;
  nextPos = pos + 1;

  for (i = 0; i < lens[digit]; i++) {
    tmp[pos] = digitCharMap[digit][i];
    _letterCombinations(s, nextPos);
  }
}

char** letterCombinations(char* digits, int* returnSize) {
  if (*digits == '\0') {
    *returnSize = 0;
    return NULL;
  }

  char *map[10] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
  }, *p = digits, t[5];
  int lenArr[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4}, l = 0;

  // init
  digitCharMap = map;
  lens = lenArr;
  tmp = t;
  retLen = 0;

  *returnSize = 1;
  while (*p) {
    *returnSize *= lens[*p - '0'];
    ++l;
    ++p;
  }

  // allocate
  ret = (char **)malloc(sizeof(char *) * (*returnSize));
  for (int i = 0; i < *returnSize; i++) ret[i] = (char *)malloc(sizeof(char) * (l + 1));
  tmp[l] = '\0';

  _letterCombinations(digits, 0);

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
  char s[16], **rr;
  int ll;
  read_line(s, 15, stdin);
  rr = letterCombinations(s, &ll);
  if (!ll) {
    putchar('\n');
    return EXIT_SUCCESS;
  }
  for (int i = 0; i < ll; i++) {
    printf("%s\n", rr[i]);
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
