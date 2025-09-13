#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3305. 元音辅音字符串计数 I - 给你一个字符串 word 和一个 非负 整数 k。
// 返回 word 的 子字符串 中，每个元音字母（'a'、'e'、'i'、'o'、'u'）至少 出现一次，并且 恰好 包含 k 个辅音字母的子 字符串的总数。
//  
// 示例 1：
// 输入：word = "aeioqq", k = 1
// 输出：0
// 解释：
// 不存在包含所有元音字母的子字符串。
// 示例 2：
// 输入：word = "aeiou", k = 0
// 输出：1
// 解释：
// 唯一一个包含所有元音字母且不含辅音字母的子字符串是 word[0..4]，即 "aeiou"。
// 示例 3：
// 输入：word = "ieaouqqieaouqq", k = 1
// 输出：3
// 解释：
// 包含所有元音字母并且恰好含有一个辅音字母的子字符串有：
//  * word[0..5]，即 "ieaouq"。
//  * word[6..11]，即 "qieaou"。
//  * word[7..12]，即 "ieaouq"。
//  
// 提示：
//  * 5 &lt;= word.length &lt;= 250
//  * word 仅由小写英文字母组成。
//  * 0 &lt;= k &lt;= word.length - 5

//// #v1
//char *vowels;
//int kk;
//
//bool check(char *t) {
  //int i, cnt = 0, l;
//
  //for (i = 0; i < 5; i++) {
    //if (t[vowels[i] - 'a'] == 0) return false;
  //}
//
  //for (i = 1; i < 26; i++) {
    //if (t[i]) {
      //l = i + 'a';
      //if (l == 'e' || l == 'i' || l == 'o' || l == 'u') continue;
      //cnt += t[i];
      //if (cnt > kk) return false;
    //}
  //}
//
  //if (cnt == kk) return true;
//
  //return false;
//}
//
//int countOfSubstrings(char* word, int k) {
  //char t[26] = {0}, *p, v[5] = {'a', 'e', 'i', 'o', 'u'};
//
  //vowels = v;
  //kk = k;
//
  //int r = 0, b = k + 5, ret = 0, l = strlen(word);
//
  //for (int i = 0; i <= l - k - 5; i++) {
    //p = word + i;
    //r = 0;
//
    //while (r < b) {
      //++t[(*p) - 'a'];
      //++r;
      //++p;
    //}
//
    //if (check(t)) {
      //++ret;
    //}
//
    //while (*p) {
      //++t[(*p) - 'a'];
      //if (check(t)) ++ret;
      //++p;
    //}
//
    //for (int j = 0; j < 26; j++) {
      //t[j] = 0;
    //}
  //}
//
  //return ret;
//}
//// #v1

// #v2
char *vowels;
int kk, consonants;

bool check(char *t) {
  int i, l;
  consonants = 0;

  // 检查元音字母是否满足条件
  for (i = 0; i < 5; i++) {
    // 表示当前子串中某一元音字母不存在
    if (t[vowels[i] - 'a'] == 0) return false;
  }

  // 检查辅音字母是否满足条件
  for (i = 1; i < 26; i++) {
    if (t[i]) { // 非零
      l = i + 'a';
      // 跳过元音字母
      if (l == 'e' || l == 'i' || l == 'o' || l == 'u') continue;
      // 统计辅音字母的个数
      consonants += t[i];
      if (consonants > kk) { // 超限
        return false;
      }
    }
  }

  // 辅音字母也满足条件
  if (consonants == kk) return true;

  // 元音字母满足, 辅音字母不满足条件
  return false;
}

int countOfSubstrings(char* word, int k) {
  char t[26] = {0}, *p, v[5] = {'a', 'e', 'i', 'o', 'u'};

  vowels = v;
  kk = k;

  int r, b = k + 5, ret = 0, l = strlen(word), m = l - b;
  bool f; // 标记子串是否满足条件

  for (int i = 0; i <= m; i++) {
    f = false;
    p = word + i;
    r = 0;

    while (r < b) {
      ++t[(*p) - 'a'];
      ++r;
      ++p;
    }

    if (check(t)) {
      f = true; // 满足条件
      ++ret;
    } else { // 不满足
      if (consonants > k) { // 检查辅音字母的个数是否超过 k, 超过则跳过接下来的比对
        for (int j = 0; j < 26; j++) t[j] = 0;
        continue;
      }
    }

    while (*p) {
      if (f) { // 满足条件
        if (*p != 'a' && *p != 'e' && *p != 'i' && *p != 'o' && *p != 'u') // 新加入子串的字符是辅音字母, 破坏了原来的条件
          break;
      }

      ++t[(*p) - 'a'];

      if (check(t)) {
        f = true; // 满足条件
        ++ret;
      } else {
        if (consonants > k) { // 辅音字母个数超限, 没有进行下去的必要了
          break;
        }
      }

      ++p;
    }

    // 恢复哈希表
    for (int j = 0; j < 26; j++) {
      t[j] = 0;
    }
  }

  return ret;
}
// #v2

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
  printf("%d\n", countOfSubstrings(s, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
