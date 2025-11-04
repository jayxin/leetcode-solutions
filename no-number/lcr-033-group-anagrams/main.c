#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LCR 033. 字母异位词分组 - 给定一个字符串数组 strs ，将 变位词 组合在一起。 可以按任意顺序返回结果列表。
// 注意：若两个字符串中每个字符出现的次数都相同，则称它们互为变位词。
//  
// 示例 1：
// 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
// 示例 2：
// 输入: strs = [""]
// 输出: [[""]]
// 示例 3：
// 输入: strs = ["a"]
// 输出: [["a"]]
//  
// 提示：
//  * 1 <= strs.length <= 104
//  * 0 <= strs[i].length <= 100
//  * strs[i] 仅包含小写字母
//  
// 注意：本题与主站 49 题相同： https://leetcode-cn.com/problems/group-anagrams/ [https://leetcode-cn.com/problems/group-anagrams/]

// #v1
struct Word {
  char *s;
  char tab[26];
  int set, len, sum;
};

struct Word* NewWord(char *s) {
  char *p = s;
  int i;
  struct Word *w = calloc(1, sizeof(struct Word));

  w->s = s;
  w->set = w->len = w->sum = 0;
  memset(w->tab, 0, sizeof(char) * 26);

  while (*p) {
    i = *p - 'a';
    w->set |= 1 << i;
    w->sum += i;
    w->tab[i] += 1;
    ++w->len;
    ++p;
  }

  return w;
}

struct HashNode {
  int idx;
  struct Word *w;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
  struct HashNode **table;
};

struct HashNode* NewHashNode(struct Word *w, int idx) {
  struct HashNode *ret = calloc(1, sizeof(struct HashNode));
  ret->w = w;
  ret->idx = idx;
  return ret;
}

struct HashTable* NewHashTable(int capacity) {
  struct HashTable *ret = calloc(1, sizeof(struct HashTable));

  ret->capacity = capacity;
  ret->table = calloc(capacity, sizeof(struct HashNode *));
  for (int i = 0; i < capacity; i++) ret->table[i] = NULL;

  return ret;
}

#define HashFunc(t, k) ((k) % t->capacity)

struct HashNode* HashTableFind(struct HashTable *t, struct Word *w) {
  int h = HashFunc(t, w->sum);
  struct HashNode *p = (t->table)[h];
  while (p) {
    if (p->w->len == w->len && p->w->set == w->set && p->w->sum == w->sum) {
      char f = 0;
      for (int i = 0; i < 26; i++) {
        if ((p->w->tab)[i] != (w->tab)[i]) {
          f = 1;
          break;
        }
      }
      if (!f) return p;
    }
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, struct Word *w, int idx) {
  int h = HashFunc(t, w->sum);
  struct HashNode *n, *p = t->table[h];
  n = NewHashNode(w, idx);
  n->next = p;
  t->table[h] = n;
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
  // edge case
  if (!strsSize) {
    *returnSize = 0;
    return NULL;
  }

  int i, retLen = 0, cnts[strsSize], *c;
  char ***ret = NULL;
  struct Word *ws[strsSize];
  struct HashTable *h = NewHashTable(1331);
  struct HashNode *p;

  for (i = 0; i < strsSize; i++) {
    // 统计每个字符串的必要信息
    ws[i] = NewWord(strs[i]);

    // 检查哈希表
    p = HashTableFind(h, ws[i]);
    if (!p) {
      // 插入哈希表, 新增一类
      HashTableAdd(h, ws[i], retLen);
      cnts[retLen] = 1;
      ++retLen;
    } else {
      // p->idx 表示类别
      ++cnts[p->idx];
    }
  }

  // allocate
  ret = (char ***)malloc(sizeof(char **) * retLen);
  c = (int *)malloc(sizeof(int) * retLen);
  *returnColumnSizes = c;
  *returnSize = retLen;
  for (i = 0; i < retLen; i++) {
    ret[i] = (char **)malloc(sizeof(char *) * cnts[i]);
    c[i] = 0;
  }

  // 将分类好的字符串加入结果
  for (i = 0; i < strsSize; i++) {
    p = HashTableFind(h, ws[i]);
    ret[p->idx][c[p->idx]++] = ws[i]->s;
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
  int n, r, *c;
  char **s, ***ret;
  scanf("%d\n", &n);
  s = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    s[i] = (char *)malloc(sizeof(char) * 100);
    read_line(s[i], 98, stdin);
  }
  ret = groupAnagrams(s, n, &r, &c);
  if (!ret) {
    printf("\n");
    return 0;
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c[i]; j++) {
      if (j) putchar(',');
      printf("%s", ret[i][j]);
    }
    putchar('\n');
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
