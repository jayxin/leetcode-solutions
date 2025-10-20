#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3335. 字符串转换后的长度 I - 给你一个字符串 s 和一个整数 t，表示要执行的 转换 次数。每次 转换 需要根据以下规则替换字符串 s 中的每个字符：
//  * 如果字符是 'z'，则将其替换为字符串 "ab"。
//  * 否则，将其替换为字母表中的下一个字符。例如，'a' 替换为 'b'，'b' 替换为 'c'，依此类推。
// 返回 恰好 执行 t 次转换后得到的字符串的 长度。
// 由于答案可能非常大，返回其对 109 + 7 取余的结果。
//  
// 示例 1：
// 输入： s = "abcyy", t = 2
// 输出： 7
// 解释：
//  * 第一次转换 (t = 1)
//    * 'a' 变为 'b'
//    * 'b' 变为 'c'
//    * 'c' 变为 'd'
//    * 'y' 变为 'z'
//    * 'y' 变为 'z'
//    * 第一次转换后的字符串为："bcdzz"
//  * 第二次转换 (t = 2)
//    * 'b' 变为 'c'
//    * 'c' 变为 'd'
//    * 'd' 变为 'e'
//    * 'z' 变为 "ab"
//    * 'z' 变为 "ab"
//    * 第二次转换后的字符串为："cdeabab"
//  * 最终字符串长度：字符串为 "cdeabab"，长度为 7 个字符。
// 示例 2：
// 输入： s = "azbk", t = 1
// 输出： 5
// 解释：
//  * 第一次转换 (t = 1)
//    * 'a' 变为 'b'
//    * 'z' 变为 "ab"
//    * 'b' 变为 'c'
//    * 'k' 变为 'l'
//    * 第一次转换后的字符串为："babcl"
//  * 最终字符串长度：字符串为 "babcl"，长度为 5 个字符。
//  
// 提示：
//  * 1 <= s.length <= 105
//  * s 仅由小写英文字母组成。
//  * 1 <= t <= 105

// #v1
// 动态规划
int lengthAfterTransformations(char* s, int t) {
  // 状态表示: f(i, c), 表示在 i 次转换后, s 中包含的字符 c 的数量
  // i:[1,t], c:[0, 25]
  // 阶段: 从第 i - 1 次转换计算第 i 次转换
  // 对于 i 次:
  // c=0, 对应字符 a, 说明i-1次是 z, f(i, 0) = f(i-1, 25)
  // c=1, 对应字符 b, 说明i-1次是 a or z, f(i, 1) = f(i-1, 25) + f(i-1,0)
  // c >= 2, 则 f(i, c) = f(i-1, c-1)
  int mod = 1e9 + 7, c0[26] = {0}, c1[26], ret = 0, *p0, *p1, *tmp;

  // init
  while (*s) ++c0[*s++ - 'a'];

  // compute
  p0 = c0;
  p1 = c1;
  for (int i = 1; i <= t; i++) {
    // 'a'
    p1[0] = p0[25];
    // 'b'
    p1[1] = (p0[25] + p0[0]) % mod;

    // 'c' - 'z'
    for (int j = 2; j < 26; j++) {
      p1[j] = p0[j-1];
    }

    // swap
    tmp = p0;
    p0 = p1;
    p1 = tmp;
  }

  for (int i = 0; i < 26; i++) {
    ret = (ret + p0[i]) % mod;
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
  int t;
  char s[100];
  read_line(s, 98, stdin);
  scanf("%d", &t);
  printf("%d\n", lengthAfterTransformations(s, t));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
