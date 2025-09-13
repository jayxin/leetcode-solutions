#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2063. 所有子字符串中的元音 - 给你一个字符串 word ，返回 word 的所有子字符串中 元音的总数 ，元音是指 'a'、'e'、'i'、'o' 和 'u' 。
// 子字符串 是字符串中一个连续（非空）的字符序列。
// 注意：由于对 word 长度的限制比较宽松，答案可能超过有符号 32 位整数的范围。计算时 需当心。
//  
// 示例 1：
// 输入：word = "aba"
// 输出：6
// 解释：
// 所有子字符串是："a"、"ab"、"aba"、"b"、"ba" 和 "a" 。
// - "b" 中有 0 个元音
// - "a"、"ab"、"ba" 和 "a" 每个都有 1 个元 音
// - "aba" 中有 2 个元音
// 因此，元音总数 = 0 + 1 + 1 + 1 + 1 + 2 = 6 。
// 示例 2：
// 输入：word = "abc"
// 输出：3
// 解释：
// 所有子字符串是："a"、"ab"、"abc"、"b"、"bc" 和 "c" 。
// - "a"、"ab" 和 "abc" 每个都有 1 个元音
// - "b"、"bc" 和 "c" 每个都有 0 个元音
// 因此，元音总数 = 1 + 1 + 1 + 0 + 0 + 0 = 3 。
// 示例 3：
// 输入：word = "ltcd"
// 输出：0
// 解释："ltcd" 的子字符串均不含元音。
// 示例 4：
// 输入：word = "noosabasboosa"
// 输出：237
// 解释：所有子字符串中共有 237 个元音。
//  
// 提示：
//  * 1 &lt;= word.length &lt;= 105
//  * word 由小写英文字母组成

//// #v1
//int64_t std, v;
//
//// 判断字母 c 是否为元音字母
//bool isVowel(char c) {
  //v = 0LL;
  //v |= 1LL << (c & 0x3f);
  //return (v & std);
//}
//
//long long countVowels(char* word) {
  //// cur 记录字符串的元音总数
  //long long cur, s;
  //char *p, vowels[5] = {'a', 'e', 'i', 'o', 'u'};
  //// tab[i] 记录 word[0..i] 的元音个数
  //int tab[100001] = {0}, i;
//
  //// init std
  //for (i = 0; i < 5; i++) {
    //std |= 1LL << (vowels[i] & 0x3f);
  //}
//
  //// 初始化
  //i = 0;
  //cur = 0;
  //p = word;
  //if (isVowel(*p)) { // 第一个字母是元音
    //tab[i] = 1;
    //cur = 1;
  //}
  //s = 0;
  //++p;
  //++i;
//
  //while (*p) {
    //if (isVowel(*p)) { // 元音
      //tab[i] = tab[i-1] + 1; // 增加元音个数
      //cur += 1; // 贡献元音总数, 子字符串为单个字符, 即 *p 本身
    //} else { // 辅音
      //tab[i] = tab[i-1]; // 元音个数保持
    //}
//
    //// 计算加入字符 *p 后字符串的元音总数
    //cur += (long long)tab[i] * i - s;
//
    //// 更新 s, s == tab[0] + tab[1] + ... + tab[i-2]
    //s += tab[i-1];
//
    //++i;
    //++p;
  //}
//
  //return cur;
//}
//// #v1

//// #v2
//// 动态规划, 优化内存空间
//int64_t std, v;
//
//// 判断字母 c 是否为元音字母
//bool isVowel(char c) {
  //v = 0LL;
  //v |= 1LL << (c & 0x3f);
  //return (v & std);
//}
//
//long long countVowels(char* word) {
  //// cur 记录字符串的元音总数
  //long long cur, s;
  //char *p, vowels[5] = {'a', 'e', 'i', 'o', 'u'};
  //// tab[i] 记录 word[0..i] 的元音个数
  //int tab_i, tab_i_prev, i;
//
  //// init std
  //for (i = 0; i < 5; i++) {
    //std |= 1LL << (vowels[i] & 0x3f);
  //}
//
  //// 初始化
  //i = cur = tab_i = tab_i_prev = 0;
  //p = word;
  //if (isVowel(*p)) { // 第一个字母是元音
    //tab_i_prev = 1;
    //cur = 1;
  //}
  //s = 0;
  //++p;
  //++i;
//
  //while (*p) {
    //if (isVowel(*p)) { // 元音
      //tab_i = tab_i_prev + 1; // 增加元音个数
      //cur += 1; // 贡献元音总数, 子字符串为单个字符, 即 *p 本身
    //} else { // 辅音
      //tab_i = tab_i_prev; // 元音个数保持
    //}
//
    //// 计算加入字符 *p 后字符串的元音总数
    //cur += (long long)tab_i * i - s;
//
    //// 更新 s, s == tab[0] + tab[1] + ... + tab[i-2]
    //s += tab_i_prev;
//
    //tab_i_prev = tab_i;
    //++i;
    //++p;
  //}
//
  //return cur;
//}
//// #v2

// #v3
// 对偶性质, 组合数学, 从字符串的左端点和右端点考虑问题
// 对第 i 个字符, 若为元音, 则包含它的子串的左端点可选择 0,1,...,i
// 右端点可选择 i, i+1, ..., n-1
int64_t std, v;

// 判断字母 c 是否为元音字母
bool isVowel(char c) {
  v = 0LL;
  v |= 1LL << (c & 0x3f);
  return (v & std);
}

long long countVowels(char* word) {
  // cur 记录字符串的元音总数
  long long cur = 0;
  char *p, vowels[5] = {'a', 'e', 'i', 'o', 'u'};
  int i, len = strlen(word);

  // init std
  for (i = 0; i < 5; i++) {
    std |= 1LL << (vowels[i] & 0x3f);
  }

  // 初始化
  p = word;
  i = 0;

  while (*p) {
    if (isVowel(*p)) { // 元音
      cur += (long long)(i + 1) * (len - i);
    }

    ++i;
    ++p;
  }

  return cur;
}
// #v3

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
  printf("%d\n", countVowels(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
