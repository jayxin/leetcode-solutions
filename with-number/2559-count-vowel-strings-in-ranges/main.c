#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2559. 统计范围内的元音字符串数 - 给你一个下标从 0 开始的字符串数组 words 以及 一个二维整数数组 queries 。
// 每个查询 queries[i] = [li, ri] 会要求我们统计在 words 中下标在 li 到 ri 范围内（ 包含 这两个值）并且以元音开头和结尾的字符串的数目。
// 返回一个整数数组，其中数组的第 i 个元素对应第 i 个查询的答案。
// 注意：元音字母是 'a'、'e'、'i'、'o' 和 'u' 。
//  
// 示例 1：
// 输入：words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
// 输出：[2,3,0]
// 解释：以元音开头和结尾的字符串是 "aba"、"ece"、"aa" 和 "e" 。
// 查询 [0,2] 结果为 2（字符串 "aba" 和 "ece"）。
// 查询 [1,4] 结果为 3（字符串 "ece"、"aa"、"e"）。
// 查询 [1,1] 结果为 0 。
// 返回结果 [2,3,0] 。
// 示例 2：
// 输入：words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
// 输出：[3,2,1]
// 解释：每个字符串都满足这一条件，所以返回 [3,2,1] 。
//  
// 提示：
//  * 1 <= words.length <= 105
//  * 1 <= words[i].length <= 40
//  * words[i] 仅由小写英文字母组成
//  * sum(words[i].length) <= 3 * 105
//  * 1 <= queries.length <= 105
//  * 0 <= queries[j][0] <= queries[j][1] < words.length

// #v1
// prefix sum, bit operation
int std;

int check(char *s) {
  if (!((std >> (*s & 0x1f)) & 1)) return 0;
  while (*s) ++s;
  return (std >> (*(s-1) & 0x1f)) & 1;
}

int* vowelStrings(char** words, int wordsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
  *returnSize = queriesSize;

  int *ret = calloc(queriesSize, sizeof(int)), prefixSum[wordsSize+1];

  // init
  std = 0;
  std |= 1 << ('a' & 0x1f);
  std |= 1 << ('e' & 0x1f);
  std |= 1 << ('i' & 0x1f);
  std |= 1 << ('o' & 0x1f);
  std |= 1 << ('u' & 0x1f);

  // prefix sum
  prefixSum[0] = 0;
  for (int i = 0;  i < wordsSize; i++) {
    prefixSum[i+1] = prefixSum[i] + check(words[i]);
  }

  // process queries
  for (int i = 0; i < queriesSize; i++) {
    ret[i] = prefixSum[queries[i][1] + 1] - prefixSum[queries[i][0]];
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

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

// read 2d array
int** read_2d_arr(int rows, int cols) {
  int i, j;
  int **ret = (int **)malloc(sizeof(int *) * rows);
  for (i = 0; i < rows; i++) {
    ret[i] = (int *)malloc(sizeof(int) * cols);
  }

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      scanf("%d", &ret[i][j]);
    }
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int wordsSize, **queries, queriesSize, queriesColSize, returnSize, *ret;
  char **words;
  scanf("%d\n", &wordsSize);
  words = calloc(wordsSize, sizeof(char*));
  for (int i = 0; i < wordsSize; i++) {
    words[i] = calloc(100, sizeof(char));
    read_line(words[i], 98, stdin);
  }
  scanf("%d\n", &queriesSize);
  queriesColSize = 2;
  queries = read_2d_arr(queriesSize, queriesColSize);
  ret = vowelStrings(words, wordsSize, queries, queriesSize, &queriesColSize,
      &returnSize);
  print_1d_arr(ret, returnSize);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
