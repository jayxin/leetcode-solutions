#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 3085. 成为 K 特殊字符串需要删除的最少字符数 - 给你一个字符串 word 和一个整数 k。
// 如果 |freq(word[i]) - freq(word[j])| <= k 对于字符串中所有下标 i 和 j  都成立 ，则认为 word 是 k 特殊字符串。
// 此处，freq(x) 表示字符 x 在 word 中的出现频率，而 |y| 表示 y 的绝对值。
// 返回使 word 成为 k 特殊字符串 需要删除的字符的最小数量。
//  
// 示例 1：
// 输入：word = "aabcaba", k = 0
// 输出：3
// 解释：可以删除 2 个 "a" 和 1 个 "c" 使 word 成为 0 特殊字符串。word 变为 "baba"，此时 freq('a') == freq('b') == 2。
// 示例 2：
// 输入：word = "dabdcbdcdcd", k = 2
// 输出：2
// 解释：可以删除 1 个 "a" 和 1 个 "d" 使 word 成为 2 特殊字符串。word 变为 "bdcbdcdcd"，此时 freq('b') == 2，freq('c') == 3，freq('d') == 4。
// 示例 3：
// 输入：word = "aaabaaa", k = 2
// 输出：1
// 解释：可以删除 1 个 "b" 使 word 成为 2特殊字符串。因此，word 变为 "aaaaaa"，此时每个字母的频率都是 6。
//  
// 提示：
//  * 1 <= word.length <= 105
//  * 0 <= k <= 105
//  * word 仅由小写英文字母组成。
// 1. Count the frequency of each letter.
// 2. Suppose we select several characters as the final answer, and let x be the
// character with the smallest frequency in the answer. It can be shown that out
// of the selected characters, the optimal solution will never delete an
// occurrence of character x to obtain the answer.
// 3. We will fix a character c and assume that it will be the character with
// the smallest frequency in the answer. Suppose its frequency is x.
// 4. Then, for every other character, we will count the number of occurrences
// that will be deleted. Suppose that the current character has y occurrences.
//  1) If y < x, we need to delete all of them.
//  2) if y > x + k, we should delete y - x - k of such character.
//  3) Otherwise we don’t need to delete it.

// #v1
// sort, count
int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

int minimumDeletions(char* word, int k) {
  int cnts[26] = {0}, ret = 0x7fffffff;
  int s;

  // count
  while (*word) ++cnts[*word++ - 'a'];

  // sort
  qsort(cnts, 26, sizeof(int), cmp);

  // skip cnts[i] == 0
  s = 0;
  while (s < 26 && cnts[s] == 0) ++s;

  for (int i = s; i < 26; i++) {
    int j = s, tmp = 0;

    while (j < 26 && cnts[j] < cnts[i])
      tmp += cnts[j++];

    j = 25;
    while (j >= 0 && cnts[j] > cnts[i] + k)
      tmp += cnts[j--] - cnts[i] - k;

    if (tmp < ret) ret = tmp;
  }

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int k;
  char s[100];
  scanf("%d\n", &k);
  scanf("%s", s);
  printf("%d\n", minimumDeletions(s, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
