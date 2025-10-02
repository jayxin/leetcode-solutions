#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 202. 快乐数 - 编写一个算法来判断一个数 n 是不是快乐数。
// 「快乐数」 定义为：
//  * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
//  * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//  * 如果这个过程 结果为 1，那么这个数就是快乐数。
// 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
//  
// 示例 1：
// 输入：n = 19
// 输出：true
// 解释：
// 1^2 + 9^2 = 82
// 8^2 + 2^2 = 68
// 6^2 + 8^2 = 100
// 1^2 + 0^2 + 0^2 = 1
// 示例 2：
// 输入：n = 2
// 输出：false
//  
// 提示：
//  * 1 &lt;= n &lt;= 2^31 - 1

// #v1
struct HashNode {
  int val;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
  int size;
  struct HashNode **table;
};

struct HashNode* NewHashNode(int val) {
  struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  ret->val = val;
  ret->next = NULL;
  return ret;
}

struct HashTable* NewHashTable(int capacity) {
  struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
  ret->capacity = capacity;
  ret->size = 0;
  int table_bytes = sizeof(struct HashNode *) * capacity;
  ret->table = (struct HashNode **)malloc(table_bytes);
  memset(ret->table, 0, table_bytes);

  return ret;
}

int HashFunc(struct HashTable *t, int key) {
  return key % t->capacity;
}

struct HashNode* HashTableFind(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *p = (t->table)[h];

  while (p) {
    if (p->val == val) return p;
    p = p->next;
  }

  return NULL;
}

void HashTableAdd(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *n, *p = (t->table)[h];
  n = NewHashNode(val);
  if (!p) {
    (t->table)[h] = n;
  } else {
    n->next = p;
    (t->table)[h] = n;
  }
}

bool isHappy(int n) {
  int t, r;
  struct HashTable *h = NewHashTable(131);

  while (n != 1) {
    HashTableAdd(h, n);
    t = 0;
    while (n) {
      r = n % 10;
      t += r * r;
      n /= 10;
    }
    n = t;
    if (HashTableFind(h, n)) {
      return false;
    }
  }

  return true;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  if (isHappy(n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
