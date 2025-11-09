#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 438. 找到字符串中所有字母异位词 - 给定两个字符串 s 和 p，找到 s 中所有 p 的  异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
//  
// 示例 1:
// 输入: s = "cbaebabacd", p = "abc"
// 输出: [0,6]
// 解释:
// 起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
// 起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
//  示例 2:
// 输入: s = "abab", p = "ab"
// 输出: [0,1,2]
// 解释:
// 起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
// 起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
// 起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
//  
// 提示:
//  * 1 <= s.length, p.length <= 3 * 104
//  * s 和 p 仅包含小写字母

// #v1
// sliding window
int* findAnagrams(char* s, char* p, int* returnSize) {
  int m = 0, n = strlen(s), b;
  int set = 0, cnts[26] = {0}, sum = 0, pos;
  int *ret, retLen = 0;

  // process `p`
  while (*p) {
    pos = *p - 'a';
    // summation
    sum += pos;
    // set
    set |= 1<<pos;
    // count
    ++cnts[pos];
    // length
    ++m;
    // forward
    ++p;
  }

  // edge case
  if (n < m) {
    *returnSize = 0;
    return NULL;
  }

  b = n - m; // 滑动窗口左边界的最大值
  ret = calloc(b+1, sizeof(int));

  int cnts1[26] = {0}, set1 = 0, sum1 = 0;
  char isEqual;

  // process first window
  for (int i = 0; i < m; i++) {
    pos = s[i] - 'a';
    // summation
    sum1 += pos;
    // set
    set1 |= 1<<pos;
    // count
    ++cnts1[pos];
  }

  if (set1 == set && sum1 == sum) {
    isEqual = 1;
    for (int i = 0; i < 26; i++) {
      if (cnts1[i] != cnts[i]) {
        isEqual = 0;
        break;
      }
    }
    if (isEqual) ret[retLen++] = 0;
  }

  // process other windows
  for (int i = 1; i <= b; i++) { // 枚举窗口的左边界
    // 滑动窗口最左边的字符移出窗口
    pos = s[i-1] - 'a';
    sum1 -= pos;
    --cnts1[pos];
    if (cnts1[pos] == 0) set1 &= ~(1<<pos);

    // 向右边界添加新的字符
    pos = s[i+m-1] - 'a';
    sum1 += pos;
    ++cnts1[pos];
    set1 |= 1<<pos;

    // check
    if (set1 == set && sum1 == sum) {
      isEqual = 1;
      for (int j = 0; j < 26; j++) {
        if (cnts1[j] != cnts[j]) {
          isEqual = 0;
          break;
        }
      }
      if (isEqual) ret[retLen++] = i;
    }
  }

  *returnSize = retLen;

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

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  char s[100], p[100];
  int *ret, returnSize;
  read_line(s, 98, stdin);
  read_line(p, 98, stdin);
  ret = findAnagrams(s, p, &returnSize);
  print_1d_arr(ret, returnSize);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
