#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2062. 统计字符串中的元音子字符串 - 子字符串 是字符串中的一个连续（非空）的字符序列。
// 元音子字符串 是 仅 由元音（'a'、'e'、'i'、'o' 和 'u'）组成的一个子字符串，且必须包含 全部五种 元音。
// 给你一个字符串 word ，统计并返回 word 中 元音子字符串的数目 。
//  
// 示例 1：
// 输入：word = "aeiouu"
// 输出：2
// 解释：下面列出 word 中的元音子字符串（斜体加粗部分）：
// - "aeiouu"
// - "aeiouu"
// 示例 2：
// 输入：word = "unicornarihan"
// 输出：0
// 解释：word 中不含 5 种元音，所以也不会存在元音子字符串。
// 示例 3：
// 输入：word = "cuaieuouac"
// 输出：7
// 解释：下面列出 word 中的元音子字符串（斜体加粗部分）：
// - "cuaieuouac"
// - "cuaieuouac"
// - "cuaieuouac"
// - "cuaieuouac"
// - "cuaieuouac"
// - "cuaieuouac"
// - "cuaieuouac"
// 示例 4：
// 输入：word = "bbaeixoubb"
// 输出：0
// 解释：所有包含全部五种元音的子字符串都含有辅音，所以不存在元音子字符串。
//  
// 提示：
//  * 1 &lt;= word.length &lt;= 100
//  * word 仅由小写英文字母组成

// #v1
int64_t std, v;

bool isVowel(char c) {
  v = 0LL;
  v |= 1LL << (c & 0x3f);
  return (v & std);
}

int countVowelSubstrings(char* word) {
  int ret = 0, len = strlen(word), i, b = len - 5;
  int64_t set = 0;
  char *l, vowels[5] = {'a', 'e', 'i', 'o', 'u'};

  // init std
  for (i = 0; i < 5; i++) {
    std |= 1LL << (vowels[i] & 0x3f);
  }

  for (i = 0; i <= b; i++) {
    l = word + i;
    set = 0LL;

    while (*l) {
      if (isVowel(*l)) {
        set |= 1LL << ((*l) & 0x3f);
      } else {
        break;
      }

      if (set == std) {
        ++ret;
      }

      l++;
    }
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
  char s[200];
  read_line(s, 199, stdin);
  printf("%d\n", countVowelSubstrings(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
