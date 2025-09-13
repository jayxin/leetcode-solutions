#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1456. 定长子串中元音的最大数目 - 给你字符串 s 和整数 k 。
// 请返回字符串 s 中长度为 k 的单个子字符串中可能包含的最大元音字母数。
// 英文中的 元音字母 为（a, e, i, o, u）。
//  
// 示例 1：
// 输入：s = "abciiidef", k = 3
// 输出：3
// 解释：子字符串 "iii" 包含 3 个元音字母。
// 示例 2：
// 输入：s = "aeiou", k = 2
// 输出：2
// 解释：任意长度为 2 的子字符串都包含 2 个元音字母。
// 示例 3：
// 输入：s = "leetcode", k = 3
// 输出：2
// 解释："lee"、"eet" 和 "ode" 都包含 2 个元音字母。
// 示例 4：
// 输入：s = "rhythms", k = 4
// 输出：0
// 解释：字符串 s 中不含任何元音字母。
// 示例 5：
// 输入：s = "tryhard", k = 4
// 输出：1
//  
// 提示：
//  * 1 &lt;= s.length &lt;= 10^5
//  * s 由小写英文字母组成
//  * 1 &lt;= k &lt;= s.length

// #v1
int maxVowels(char* s, int k) {
  char *p = s;
  int l = 0, r = 0, ret = 0, cnt;

  while (r < k) {
    if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u') {
      ++ret;
    }
    ++r;
    ++p;
  }
  cnt = ret;

  if (s[r] == '\0' || cnt == k) return cnt;

  while (*p) {
    if (ret == k) return k;
    if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') {
      --cnt;
    }
    if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u') {
      ++cnt;
    }
    if (cnt > ret) ret = cnt;
    ++l;
    ++p;
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
  int k;
  char s[100];
  read_line(s, 99, stdin);
  scanf("%d", &k);
  printf("%d\n", maxVowels(s, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
