#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 451. 根据字符出现频率排序 - 给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排 序 。一个字符出现的 频率 是它出现在字符串中的次数。
// 返回 已排序的字符串 。如果有多个答案，返回其中任何一个。
//  
// 示例 1:
// 输入: s = "tree"
// 输出: "eert"
// 解释: 'e'出现两次，'r'和't'都只出现一次。
// 因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
// 示例 2:
// 输入: s = "cccaaa"
// 输出: "cccaaa"
// 解释: 'c'和'a'都出现三次。此外，"aaaccc"也是有效的 答案。
// 注意"cacaca"是不正确的，因为相同的字母必须放在一起。
// 示例 3:
// 输入: s = "Aabb"
// 输出: "bbAa"
// 解释: 此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
// 注意'A'和'a'被认为是两种不同的字符。
//  
// 提示:
//  * 1 &lt;= s.length &lt;= 5 * 105
//  * s 由大小写英文字母和数字组成

// #v1
struct Pair {
  char c;
  int freq;
};

int cmp(const void *a, const void *b) {
  return ((struct Pair *)b)->freq - ((struct Pair *)a)->freq;
}

char* frequencySort(char* s) {
  struct Pair t[62];
  int i, l = 0, retLen = 0;
  char *p, *ret;

  // init
  for (i = 0; i < 26; i++) {
    t[i].c = 'a' + i;
    t[i].freq = 0;
  }

  // init
  for (i = 26; i < 52; i++) {
    t[i].c = 'A' + i - 26;
    t[i].freq = 0;
  }

  // init
  for (i = 52; i < 62; i++) {
    t[i].c = '0' + i - 52;
    t[i].freq = 0;
  }

  p = s;
  while (*p) {
    if (islower(*p)) t[*p - 'a'].freq += 1;
    else if (isupper(*p)) t[*p - 'A' + 26].freq += 1;
    else t[*p - '0' + 52].freq += 1;

    ++l;
    ++p;
  }

  // allocate
  ret = (char *)malloc(sizeof(char) * (l + 1));

  // sort
  qsort(t, 62, sizeof(struct Pair), cmp);

  i = 0;
  while (i < 62) {
    if (t[i].freq == 0) {
      ++i;
      continue;
    }
    ret[retLen++] = t[i].c;
    --t[i].freq;
  }

  // string end
  ret[retLen] = '\0';

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
  char s[100];
  read_line(s, 99, stdin);
  printf("%s\n", frequencySort(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
