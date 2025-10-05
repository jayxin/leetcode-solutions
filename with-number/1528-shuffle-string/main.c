#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1528.  重新排列字符串 - 给你一个字符串 s 和一个 长度相同 的整数数组 indices 。
// 请你重新排列字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。
// 返回重新排列后的字符串。
//  
// 示例 1：
// [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/07/26/q1.jpg]
// 输入：s = "codeleet", indices = [4,5,6,7,0,2,1,3]
// 输出："leetcode"
// 解释：如图所示，"codeleet" 重新排列后变为 "leetcode" 。
// 示例 2：
// 输入：s = "abc", indices = [0,1,2]
// 输出："abc"
// 解释：重新排列后，每个字符都还留在原来的位置上。
//  
// 提示：
//  * s.length == indices.length == n
//  * 1 <= n <= 100
//  * s 仅包含小写英文字母
//  * 0 <= indices[i] < n
//  * indices 的所有的值都是 唯一 的

// #v1
char* restoreString(char* s, int* indices, int indicesSize) {
  int len = 0, i;
  char *ret, *p = s;

  while (*p) {
    ++len;
    ++p;
  }
  ret = (char *)malloc(sizeof(char) * (len + 1));

  for (i = 0; i < indicesSize; i++) {
    ret[indices[i]] = s[i];
  }

  // string end
  ret[len] = '\0';

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

// read 1d array
int* read_1d_arr(int n) {
  int *ret = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", ret + i);
  }
  return ret;
}

int main(int argc, char *argv[])
{
  char s[100];
  int n, *a;
  read_line(s, 99, stdin);
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%s\n", restoreString(s, a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
