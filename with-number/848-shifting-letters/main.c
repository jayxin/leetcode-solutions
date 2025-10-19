#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 848. 字母移位 - 有一个由小写字母组成的字符串 s，和一个长度相同的整数数组 shifts。
// 我们将字母表中的下一个字母称为原字母的 移位 shift() （由于字母表是环绕的， 'z' 将会变成 'a'）。
//  * 例如，shift('a') = 'b', shift('t') = 'u', 以及 shift('z') = 'a'。
// 对于每个 shifts[i] = x ， 我们会将 s 中的前 i + 1 个字母移位 x 次。
// 返回 将所有这些移位都应用到 s 后最终得到的字符串 。
//  
// 示例 1：
// 输入：s = "abc", shifts = [3,5,9]
// 输出："rpl"
// 解释：
// 我们以 "abc" 开始。
// 将 S 中的第 1 个字母移位 3 次后，我们得到 "dbc"。
// 再将 S 中的前 2 个字母移位 5 次后，我们得到 "igc"。
// 最后将 S 中的这 3 个字母移位 9 次后，我们得到答案 "rpl"。
// 示例 2:
// 输入: s = "aaa", shifts = [1,2,3]
// 输出: "gfd"
//  
// 提示:
//  * 1 <= s.length <= 105
//  * s 由小写英文字母组成
//  * shifts.length == s.length
//  * 0 <= shifts[i] <= 109

// #v1
// suffix sum
char* shiftingLetters(char* s, int* shifts, int shiftsSize) {
  int i;

  for (i = shiftsSize - 2; i >= 0; i--) {
    shifts[i] = (shifts[i+1] + shifts[i]) % 26;
  }

  for (i = 0; i < shiftsSize; i++) {
    s[i] = (s[i] - 'a' + shifts[i]) % 26 + 'a';
  }

  return s;
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
  int n, *a;
  char s[100];
  read_line(s, 98, stdin);
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%s\n", shiftingLetters(s, a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
