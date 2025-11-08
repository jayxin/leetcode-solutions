#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2937. 使三个字符串相等 - 给你三个字符串 s1、s2 和 s3。 你可以根据需要对这三个字符串执 行以下操作 任意次数 。
// 在每次操作中，你可以选择其中一个长度至少为 2 的字符串 并删除其 最右位置上 的字符 。
// 如果存在某种方法能够使这三个字符串相等，请返回使它们相等所需的 最小 操作次数；否 则，返回 -1。
//  
// 示例 1：
// 输入：s1 = "abc"，s2 = "abb"，s3 = "ab"
// 输出：2
// 解释：对 s1 和 s2 进行一次操作后，可以得到三个相等的字符串。
// 可以证明，不可能用少于两次操作使它们相等。
// 示例 2：
// 输入：s1 = "dac"，s2 = "bac"，s3 = "cac"
// 输出：-1
// 解释：因为 s1 和 s2 的最左位置上的字母不相等，所以无论进行多少次操作，它们都不可 能相等。因此答案是 -1 。
//  
// 提示：
//  * 1 <= s1.length, s2.length, s3.length <= 100
//  * s1、s2 和 s3 仅由小写英文字母组成。

// #v1
// find longest common prefix
int findMinimumOperations(char* s1, char* s2, char* s3) {
  int l1 = strlen(s1), l2 = strlen(s2), l3 = strlen(s3), c = 0;
  char *p = s1, *q = s2, *r = s3;

  while (*p && *q && *r) {
    if (*p == *q && *q == *r) ++c;
    else break;

    ++p;
    ++q;
    ++r;
  }

  if (l1 == l2 && l2 == l3 && c == l1) return 0;
  if (c == 0) return -1;

  return l1 + l2 + l3 - 3 * c;
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
  char s1[100], s2[100], s3[100];
  read_line(s1, 98, stdin);
  read_line(s2, 98, stdin);
  read_line(s3, 98, stdin);
  printf("%d\n", findMinimumOperations(s1, s2, s3));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
