#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 575. 分糖果 - Alice 有 n 枚糖，其中第 i 枚糖的类型为 candyType[i] 。Alice 注意到她的体重正在增长 ，所以前去拜访了一位医生。
// 医生建议 Alice 要少摄入糖分，只吃掉她所有糖的 n / 2 即可（n 是一个偶数）。Alice  非常喜欢这些糖，她想要在遵循医生建议的情况下，尽可能吃到最多不同种类的糖。
// 给你一个长度为 n 的整数数组 candyType ，返回： Alice 在仅吃掉 n / 2 枚糖的情况下 ，可以吃到糖的 最多 种类数。
//  
// 示例 1：
// 输入：candyType = [1,1,2,2,3,3]
// 输出：3
// 解释：Alice 只能吃 6 / 2 = 3 枚糖，由于只有 3 种糖，她可以每种吃一枚。
// 示例 2：
// 输入：candyType = [1,1,2,3]
// 输出：2
// 解释：Alice 只能吃 4 / 2 = 2 枚糖，不管她选择吃的种类是 [1,2]、[1,3] 还是 [2,3]，她只能吃到两种不同类的糖。
// 示例 3：
// 输入：candyType = [6,6,6,6]
// 输出：1
// 解释：Alice 只能吃 4 / 2 = 2 枚糖，尽管她能吃 2 枚，但只能吃到 1 种糖。
//  
// 提示：
//  * n == candyType.length
//  * 2 <= n <= 104
//  * n 是一个偶数
//  * -105 <= candyType[i] <= 105

// #v1
struct HashNode {
  int val;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
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
  int table_bytes = sizeof(struct HashNode *) * capacity;
  ret->table = (struct HashNode **)malloc(table_bytes);
  memset(ret->table, 0, table_bytes);

  return ret;
}

int HashFunc(struct HashTable *t, int key) {
  int ret = key % t->capacity;
  if (ret < 0) {
    ret += t->capacity;
  }
  return ret;
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

#define min(a, b) ((a) >= (b) ? (b) : (a))

int distributeCandies(int* candyType, int candyTypeSize) {
  struct HashTable *h = NewHashTable(1331);
  int typesCnt = 0, halfSize = candyTypeSize >> 1, i;

  for (int i = 0; i < candyTypeSize; i++) {
    if (!HashTableFind(h, candyType[i])) {
      ++typesCnt;
      HashTableAdd(h, candyType[i]);
    }
  }

  return min(typesCnt, halfSize);
}
// #v1

// read 1d array
int* read_1d_arr(int n) {
  int *ret = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", ret + i);
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", distributeCandies(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
