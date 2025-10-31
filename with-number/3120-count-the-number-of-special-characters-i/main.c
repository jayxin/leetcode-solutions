#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3120. 统计特殊字母的数量 I - 给你一个字符串 word。如果 word 中同时存在某个字母的小写形式和大写形式，则称这个字母为 特殊字母 。
// 返回 word 中 特殊字母 的数量。
//  
// 示例 1:
// 输入：word = "aaAbcBC"
// 输出：3
// 解释：
// word 中的特殊字母是 'a'、'b' 和 'c'。
// 示例 2:
// 输入：word = "abc"
// 输出：0
// 解释：
// word 中不存在大小写形式同时出现的字母。
// 示例 3:
// 输入：word = "abBCab"
// 输出：1
// 解释：
// word 中唯一的特殊字母是 'b'。
//  
// 提示：
//  * 1 <= word.length <= 50
//  * word 仅由小写和大写英文字母组成。

//// #v1
//int numberOfSpecialChars(char* word) {
  //// set is used to store *word
  //int64_t set = 0LL;
  //int cnt = 0;
  //char c;
//
  //while (*word) {
    //if ((set >> (*word & 0x3f)) & 1) { // *word has been computed
      //// do not forget to forward
      //++word;
      //continue;
    //}
//
    //if (!(*word & 0x20)) { // *word is upper case
      //// to lower
      //c = *word | 0x20;
    //} else { // *word is lower case
      //// to upper
      //c = *word & ~0x20;
    //}
//
    //// update counter
    //if ((set >> (c & 0x3f)) & 1) ++cnt;
//
    //// add *word to set
    //set |= 1LL << (*word & 0x3f);
//
    //// forward
    //++word;
  //}
//
  //return cnt;
//}
//// #v1

// #v2
// 对于大写英文字母：其二进制从右往左第 6 个比特值一定是 0
// 对于小写英文字母：其二进制从右往左第 6 个比特值一定是 1
// 对于任何英文字母：其小写字母二进制低 5 位，一定和其大写字母二进制低 5 位相等
int numberOfSpecialChars(char* word) {
  int set[2] = {0, 0}, cnt = 0, x;
  char c;

  while (*word) {
    set[(*word>>5) & 1] |= 1 << (*word & 0x1f);

    // forward
    ++word;
  }

  // intersection
  x = set[0] & set[1];

  // count bits '1'
  while (x) {
    x -= x & (-x);
    ++cnt;
  }

  return cnt;
}
// #v2

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  printf("%d\n", numberOfSpecialChars(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
