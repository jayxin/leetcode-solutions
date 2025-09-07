#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 205. 同构字 符串 - 给定两个字符串 s 和 t ，判断它们是否是同构的。
// 如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
// 每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。不同字符不能映射到同 一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。
//  
// 示例 1:
// 输入：s = "egg", t = "add"
// 输出：true
// 示例 2：
// 输入：s = "foo", t = "bar"
// 输出：false
// 示例 3：
// 输入：s = "paper", t = "title"
// 输出：true
//  
// 提示：
//  * 1 <= s.length <= 5 * 104
//  * t.length == s.length
//  * s 和 t 由任意有效的 ASCII 字符组成

// #v1
int arr[300], arr1[300];
bool isIsomorphic(char* s, char* t) {
  if (!s && !t) return true;
  int l1 = strlen(s), l2 = strlen(t), ss, tt;
  if (l1 != l2) return false;
  memset(arr, 0, sizeof(int) * 300);
  memset(arr1, 0, sizeof(int) * 300);
  bool state = true;
  while (*s && *t) {
    ss = *s;
    tt = *t;
    if ((arr[ss] && tt != arr[ss])) {
      state = false;
      break;
    } else if (!arr[ss]) {
      if (arr1[tt]) {
        state = false;
        break;
      }
      arr[ss] = tt;
      arr1[tt] = 1;
    }
    s++;
    t++;
  }
  return state;
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
  int n;
  char s[200], t[200];
  read_line(s, 199, stdin);
  read_line(t, 199, stdin);
  if (isIsomorphic(s, t)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
