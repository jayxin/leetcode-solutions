#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2423. 删除字符使频率相同 - 给你一个下标从 0 开始的字符串 word ，字符串只包含小写英文字母。你需要选择 一个 下标并 删除 下标处的字符，使得 word 中剩余每个字母出现 频率 相同。
// 如果删除一个字母后，word 中剩余所有字母的出现频率都相同，那么返回 true ，否则返回 false 。
// 注意：
//  * 字母 x 的 频率 是这个字母在字符串中出现的次数。
//  * 你 必须 恰好删除一个字母，不能一个字母都不删除。
//  
// 示例 1：
// 输入：word = "abcc"
// 输出：true
// 解释：选择下标 3 并删除该字母：word 变成 "abc" 且每个字母出现频率都为 1 。
// 示例 2：
// 输入：word = "aazz"
// 输出：false
// 解释：我们必须删除一个字母，所以要么 "a" 的频率变为 1 且 "z" 的频率为 2 ，要么两个字母频率反过来。所以不可能让剩余所有字母出现频率相同。
//  
// 提示：
//  * 2 <= word.length <= 100
//  * word 只包含小写英文字母。

// #v1
int cmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

bool equalFrequency(char* word) {
  int ht[101] = {0};
  int cnts[26] = {0}, c = 0;

  while (*word) {
    int pos = *word - 'a';

    --ht[cnts[pos]];
    if (ht[cnts[pos]] == 0) --c;

    ++cnts[pos];

    ++ht[cnts[pos]];
    if (ht[cnts[pos]] == 1) ++c;

    ++word;
  }

  // 多于 2 种频率
  if (c > 2) return false;

  // c == 1 || c == 2
  int t = 0;
  for (int i = 0; i < 26; i++) {
    if (cnts[i]) {
      cnts[t] = cnts[i];
      ++t;
    }
  }

  // 只有 1 个元素
  if (t == 1) return true;

  qsort(cnts, t, sizeof(int), cmp);

  // cnts[0...(t-1)] == 1
  if (ht[1] == t) return true;

  // cnts[0] == 1, cnts[1...(t-1)] != 1
  if (cnts[0] == 1 && ht[1] == 1) return true;

  int i = 1;
  while (i < t && cnts[i] == cnts[0]) ++i;

  if (i != t-1 || cnts[i]-cnts[0] > 1) return false;
  if ((ht[cnts[i]] != 1 && ht[cnts[0]] != 1)) return false;

  return true;
}
// #v1

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  if (equalFrequency(s))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
