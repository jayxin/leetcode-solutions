#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 966. 元 音拼写检查器 - 在给定单词列表 wordlist 的情况下，我们希望实现一个拼写检查器，将查询单词转换为正确的单词。
// 对于给定的查询单词 query，拼写检查器将会处理两类拼写错误：
//  * 大小写：如果查询匹配单词列表中的某个单词（不区分大小写），则返回的正确单词与单词列表中的大小写相同。
//    * 例如：wordlist = ["yellow"], query = "YellOw": correct = "yellow"
//    * 例如：wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
//    * 例如：wordlist = ["yellow"], query = "yellow": correct = "yellow"
//  * 元音错误：如果在将查询单词中的元音 ('a', 'e', 'i', 'o', 'u')  分别替换为任何元音后，能与单词列表中的单词匹配 （不区分大小写），则返回的正确单词与单词列表中的匹配项大小写相同。
//    * 例如：wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
//    * 例如：wordlist = ["YellOw"], query = "yeellow": correct = "" （无匹配项）
//    * 例如：wordlist = ["YellOw"], query = "yllw": correct = "" （无匹配项）
// 此外，拼写检查器还按照以下优先级规则操作：
//  * 当查询完全匹配单词列表中的某个单词（区分大小写）时，应返回相同的单词。
//  * 当查询匹配到大小写问题的单词时，您应该返回单词列表中的第一个这样的匹配项。
//  * 当查询匹配到元音错误的单词时，您应该返回单词列表中的第一个这样的匹配项。
//  * 如果该查询在单词列表中没有匹配项，则应返回空字符串。
// 给出一些查询 queries，返回一个单词列表 answer，其中 answer[i] 是由查询 query = queries[i] 得到的正确单词。
//  
// 示例 1：
// 输入：wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
// 输出：["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
// 示例 2:
// 输入：wordlist = ["yellow"], queries = ["YellOw"]
// 输出：["yellow"]
//  
// 提示：
//  * 1 <= wordlist.length, queries.length <= 5000
//  * 1 <= wordlist[i].length, queries[i].length <= 7
//  * wordlist[i] 和 queries[i] 只包含英文字母

// #v1
int64_t std, v;
// 判断字母 c 是否为元音字母
bool isVowel(char c) {
  v = 0LL;
  v |= 1LL << (c & 0x3f);
  return (v & std);
}

// 是否可以通过替换元音字母得到匹配
// 只要保证对应位置的辅音字母相等即可
bool vowelCmp(char *w, char *q) {
  char c1, c2;

  while (*w) {
    // 大写转小写
    c1 = (*w) | 0x20;
    c2 = (*q) | 0x20;

    // 判断是否为辅音且相等
    if (!(isVowel(c1) && isVowel(c2)) && c1 != c2) return false;

    ++w;
    ++q;
  }

  return true;
}

// 忽略大小写进行比较
bool ignoreCaseCmp(char *w, char *q) {
  while (*w) {
    if (((*w)|0x20) != ((*q)|0x20)) return false;

    ++w;
    ++q;
  }

  return true;
}

// 获得字符串的长度和各个字符的和
void getValAndLen(char *s, int *val, int *len) {
  *len = *val = 0;
  while (*s) {
    *val += *s;
    ++(*len);
    ++s;
  }
}

char** spellchecker(char** wordlist, int wordlistSize, char** queries, int queriesSize, int* returnSize) {
  *returnSize = queriesSize;
  char **ret = (char **)malloc(sizeof(char *) * queriesSize),
       *w, *q, vowels[5] = {'a', 'e', 'i', 'o', 'u'},
       *p1, *p2, *p3;
  int i, j, lens[5001], vals[5001], qv, ql;

  // init std
  for (i = 0; i < 5; i++) {
    std |= 1LL << (vowels[i] & 0x3f);
  }

  // process wordlist
  for (i = 0; i < wordlistSize; i++) {
    getValAndLen(wordlist[i], &vals[i], &lens[i]);
  }

  // process queries
  for (i = 0; i < queriesSize; i++) {
    // allocate
    ret[i] = (char *)malloc(sizeof(char) * 8);

    p1 = p2 = p3 = NULL;
    q = queries[i];
    getValAndLen(q, &qv, &ql);

    for (j = 0; j < wordlistSize; j++) {
      if (lens[j] == ql) { // 长度相同
        w = wordlist[j];

        if (!p1 && vals[j] == qv && !strcmp(w, q)) { // 完全匹配
          p1 = w;
          break;
        }

        if (!p2 && ignoreCaseCmp(w, q)) { // 忽略大小写进行匹配
          p2 = w;
          continue;
        }

        if (!p3 && vowelCmp(w, q)) {
          p3 = w;
          continue;
        }
      }
    }

    // 完全匹配
    if (p1) {
      strcpy(ret[i], p1);
      continue;
    }

    // 大小写问题
    if (p2) {
      strcpy(ret[i], p2);
      continue;
    }

    // 元音错误
    if (p3) {
      strcpy(ret[i], p3);
      continue;
    }

    // 没有匹配
    ret[i][0] = '\0';
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
  int m, n, s;
  char **words, **queries, **ret;
  scanf("%d\n", &m);
  words = (char **)malloc(sizeof(char *) * m);
  for (int i = 0; i < m; i++) {
    words[i] = (char *)malloc(sizeof(char) * 100);
    read_line(words[i], 99, stdin);
    //printf("%s\n", words[i]);
  }
  scanf("%d\n", &n);
  queries = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    queries[i] = (char *)malloc(sizeof(char) * 100);
    read_line(queries[i], 99, stdin);
    //printf("%s\n", queries[i]);
  }
  ret = spellchecker(words, m, queries, n, &s);
  for (int i = 0; i < s; i++) {
    printf("%s\n", ret[i]);
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
