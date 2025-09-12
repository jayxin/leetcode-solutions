#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3541. 找到频率最高的元音和辅音 - 给你一个由小写英文字母（'a' 到 'z'）组成的字符串 s。你的任务是找出出现频率 最高 的元音（'a'、'e'、'i'、'o'、'u' 中的一个）和出现频率最高 的辅音（除元音以外的所有字母），并返回这两个频率之和。
// 注意：如果有多个元音或辅音具有相同的最高频率，可以任选其中一个。如果字符串中没有 元音或没有辅音，则其频率视为 0。
// 一个字母 x 的 频率 是它在字符串中出现的次数。
//  
// 示例 1：
// 输入: s = "successes"
// 输出: 6
// 解释:
//  * 元音有：'u' 出现 1 次，'e' 出现 2 次。最大元音频率 = 2。
//  * 辅音有：'s' 出现 4 次，'c' 出现 2 次。最大辅音频率 = 4。
//  * 输出为 2 + 4 = 6。
// 示例 2：
// 输入: s = "aeiaeia"
// 输出: 3
// 解释:
//  * 元音有：'a' 出现 3 次，'e' 出现 2 次，'i' 出现 2 次。最大元音频率 = 3。
//  * s 中没有辅音。因此，最大辅音频率 = 0。
//  * 输出为 3 + 0 = 3。
//  
// 提示:
//  * 1 &lt;= s.length &lt;= 100
//  * s 只包含小写英文字母

// #v1
int maxFreqSum(char* s) {
  char tab[26] = {0}, maxVowelFreq = 0, maxConsonantFreq = 0, c;

  while (*s) {
    ++tab[*s - 'a'];
    ++s;
  }

  for (int i = 0; i < 26; i++) {
    if (tab[i]) {
      c = 'a' + i;
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        if (tab[i] > maxVowelFreq)
          maxVowelFreq = tab[i];
      } else {
        if (tab[i] > maxConsonantFreq)
          maxConsonantFreq = tab[i];
      }
    }
  }

  return maxVowelFreq + maxConsonantFreq;
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
  char s[101];
  read_line(s, 100, stdin);
  printf("%d\n", maxFreqSum(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
