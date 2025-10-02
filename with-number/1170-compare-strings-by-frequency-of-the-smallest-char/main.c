#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1170. 比较字符串最小字母出现频次 - 定义一个函数 f(s)，统计 s  中（按字典序比较）最小字母的出现频次 ，其中 s 是一个非空字符串。
// 例如，若 s = "dcce"，那么 f(s) = 2，因为字典序最小字母是 "c" ，它出现了 2 次。
// 现在，给你两个字符串数组待查表 queries 和词汇表 words 。对于每次查询 queries[i]  ，需统计 words 中满足 f(queries[i]) < f(W) 的 词的数目 ，W 表示词汇表 words 中的每个词。
// 请你返回一个整数数组 answer 作为答案，其中每个 answer[i] 是第 i 次查询的结果。
//  
// 示例 1：
// 输入：queries = ["cbd"], words = ["zaaaz"]
// 输出：[1]
// 解释：查询 f("cbd") = 1，而 f("zaaaz") = 3 所以 f("cbd") < f("zaaaz")。
// 示例 2：
// 输入：queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
// 输出：[1,2]
// 解释：第一个查询 f("bbb") < f("aaaa")，第二个查询 f("aaa") 和 f("aaaa") 都 &gt; f("cc")。
//  
// 提示：
//  * 1 <= queries.length <= 2000
//  * 1 <= words.length <= 2000
//  * 1 <= queries[i].length, words[i].length <= 10
//  * queries[i][j]、words[i][j] 都由小写英文字母组成

// #v1
int f(char *s) {
  if (*s == '\0') return 0;

  char m = *s, t[26] = {0};

  while (*s) {
    ++t[*s - 'a'];
    if (*s < m) m = *s;
    ++s;
  }

  return t[m - 'a'];
}

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int* numSmallerByFrequency(char** queries, int queriesSize, char** words, int wordsSize, int* returnSize) {
  *returnSize = queriesSize;

  int h[wordsSize], i, *ret, t, l, r, m;

  // allocate
  ret = (int *)malloc(sizeof(int) * queriesSize);

  // compute words
  for (i = 0; i < wordsSize; i++) h[i] = f(words[i]);

  // sort
  qsort(h, wordsSize, sizeof(int), cmp);

  // compute queries
  for (i = 0; i < queriesSize; i++) {
    t = f(queries[i]);

    // binary search
    l = 0, r = wordsSize - 1;
    while (l < r) {
      m = (l + r) >> 1;

      if (h[m] > t) {
        r = m;
      } else {
        l = m + 1;
      }
    }

    if (h[l] > t) ret[i] = wordsSize - l;
    else ret[i] = 0;
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

int main(int argc, char *argv[])
{
  int m, n, *a, s;
  char **q, **w;

  scanf("%d\n", &m);
  q = (char **)malloc(sizeof(char *) * m);
  for (int i = 0; i < m; i++) {
    q[i] = (char *)malloc(sizeof(char) * 51);
    read_line(q[i], 50, stdin);
  }

  scanf("%d\n", &n);
  w = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    w[i] = (char *)malloc(sizeof(char) * 51);
    read_line(w[i], 50, stdin);
  }

  a = numSmallerByFrequency(q, m, w, n, &s);

  print_1d_arr(a, s);

  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
