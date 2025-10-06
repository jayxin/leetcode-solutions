#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 1805. 字符串中不同整数的数目 - 给你一个字符串 word ，该字符串由数字和小写英文字 母组成。
// 请你用空格替换每个不是数字的字符。例如，"a123bc34d8ef34" 将会变成 " 123  34 8  34" 。注意，剩下的这些整数为（相邻彼此至少有一个空格隔开）："123"、"34"、"8" 和 "34" 。
// 返回对 word 完成替换后形成的 不同 整数的数目。
// 只有当两个整数的 不含前导零 的十进制表示不同， 才认为这两个整数也不同。
//  
// 示例 1：
// 输入：word = "a123bc34d8ef34"
// 输出：3
// 解释：不同的整数有 "123"、"34" 和 "8" 。注意，"34" 只计数一次。
// 示例 2：
// 输入：word = "leet1234code234"
// 输出：2
// 示例 3：
// 输入：word = "a1b01c001"
// 输出：1
// 解释："1"、"01" 和 "001" 视为同一个整数的十进制表示，因为在比较十进制值时会忽略前导零的存在。
//  
// 提示：
//  * 1 <= word.length <= 1000
//  * word 由数字和小写英文字母组成

// #v1
struct HashNode {
  char *val;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
  struct HashNode **table;
};

struct HashNode* NewHashNode(char *val) {
  struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));

  // copy string
  ret->val = (char *)malloc(sizeof(char) * (strlen(val) + 1));
  strcpy(ret->val, val);

  ret->next = NULL;
  return ret;
}

struct HashTable* NewHashTable(int capacity) {
  struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
  ret->capacity = capacity;
  int table_bytes = sizeof(struct HashNode *) * capacity;
  ret->table = (struct HashNode **)malloc(table_bytes);
  memset(ret->table, 0, table_bytes);

  return ret;
}

int HashFunc(struct HashTable *t, char *key) {
  int sum = 0;

  while (*key) {
    sum += *key;
    ++key;
  }

  int ret = sum % t->capacity;

  return (ret < 0 ? ret + t->capacity : ret);
}

struct HashNode* HashTableFind(struct HashTable *t, char *s) {
  int h = HashFunc(t, s);
  struct HashNode *p = (t->table)[h];
  while (p) {
    if (!strcmp(p->val, s)) return p;
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, char *s) {
  int h = HashFunc(t, s);
  struct HashNode *n, *p = (t->table)[h];
  n = NewHashNode(s);
  if (!p) {
    (t->table)[h] = n;
  } else {
    n->next = p;
    (t->table)[h] = n;
  }
}

int numDifferentIntegers(char* word) {
  int cnt = 0;
  struct HashTable *h = NewHashTable(131);
  char *p = word, *s = NULL, *e = NULL, tmp[1001];

  while (*p) {
    if (isdigit(*p)) { // 数字
      if (!s) s = p;
      e = p;
    } else {
      if (s) { // 出现数字
        // 复制字符串
        int tmpLen = 0;
        // 删除前导 0
        while (*s == '0' && s < e) ++s;
        while (s <= e) tmp[tmpLen++] = *s++;
        tmp[tmpLen] = '\0';

        if (!HashTableFind(h, tmp)) {
          ++cnt;
          HashTableAdd(h, tmp);
        }
      }

      // reset
      s = e = NULL;
    }

    ++p;
  }

  if (s) { // 出现数字
    // 复制字符串
    int tmpLen = 0;
    // 删除前导 0
    while (*s == '0' && s < e) ++s;
    while (s <= e) tmp[tmpLen++] = *s++;
    tmp[tmpLen] = '\0';

    if (!HashTableFind(h, tmp)) ++cnt;
  }

  return cnt;
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
  char s[100];
  read_line(s, 99, stdin);
  printf("%d\n", numDifferentIntegers(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
