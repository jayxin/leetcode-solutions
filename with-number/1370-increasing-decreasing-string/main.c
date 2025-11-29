#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1370.  上升下降字符串 - 给你一个字符串 s ，请你根据下面的算法重新构造字符串：
//  1. 从 s 中选出 最小 的字符，将它 接在 结果字符串的后面。
//  2. 从 s 剩余字符中选出比上一个添加字符更大的 最小 字符，将它 接在 结果字符串后面。
//  3. 重复步骤 2 ，直到你没法从 s 中选择字符。
//  4. 从 s 中选出 最大 的字符，将它 接在 结果字符串的后面。
//  5. 从 s 剩余字符中选出比上一个添加字符更小的 最大 字符，将它 接在 结果字符串后面。
//  6. 重复步骤 5 ，直到你没法从 s 中选择字符。
//  7. 重复步骤 1 到 6 ，直到 s 中所有字符都已经被选过。
// 在任何一步中，如果最小或者最大字符不止一个 ，你可以选择其中任意一个，并将其添加到结果字符串。
// 请你返回将 s 中字符重新排序后的 结果字符串 。
//  
// 示例 1：
// 输入：s = "aaaabbbbcccc"
// 输出："abccbaabccba"
// 解释：第一轮的步骤 1，2，3 后，结果字符串为 result = "abc"
// 第一轮的步骤 4，5，6 后，结果字符串为 result = "abccba"
// 第一轮结束，现在 s = "aabbcc" ，我们再次回到步骤 1
// 第二轮的步骤 1，2，3 后，结果字符串为 result = "abccbaabc"
// 第二轮的步骤 4，5，6 后，结果字符串为 result = "abccbaabccba"
// 示例 2：
// 输入：s = "rat"
// 输出："art"
// 解释：单词 "rat" 在上述算法重排序以后变成 "art"
//  
// 提示：
//  * 1 <= s.length <= 500
//  * s 只包含小写英文字母。
// 1. Count the frequency of each character.
// 2. Loop over all character from 'a' to 'z' and append the character if it
// exists and decrease frequency by 1. Do the same from 'z' to 'a'.
// 3. Keep repeating until the frequency of all characters is zero.

// #v1
// set, count
char* sortString(char* s) {
  int freq[26] = {0}, n = 0, retLen = 0, set = 0;
  char *ret;

  // count and add to set
  while (*s) {
    int pos = *s - 'a';
    ++freq[pos];
    set |= 1 << pos;
    ++n;
    ++s;
  }

  ret = (char *)malloc(sizeof(char) * (n + 1));
  // string end
  ret[n] = '\0';

  while (set) {
    // from 'a' to 'z'
    for (int i = 0; i < 26; i++) {
      if (freq[i]) {
        --freq[i];
        ret[retLen++] = i +  'a';

        // remove from the set
        if (freq[i] == 0) set &= ~(1 << i);
      }
    }

    // from 'z' to 'a'
    for (int i = 25; i >= 0; i--) {
      if (freq[i]) {
        --freq[i];
        ret[retLen++] = i +  'a';

        // remove from the set
        if (freq[i] == 0) set &= ~(1 << i);
      }
    }
  }

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  printf("%s\n", sortString(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
