#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1346. 检查整数及其两倍数是否存在 - 给你一个整数数组 arr，请你检查是否存在两 个整数 N 和 M，满足 N 是 M 的两倍（即，N = 2 * M）。
// 更正式地，检查是否存在两个下标 i 和 j 满足：
//  * i != j
//  * 0 <= i, j < arr.length
//  * arr[i] == 2 * arr[j]
//  
// 示例 1：
// 输入：arr = [10,2,5,3]
// 输出：true
// 解释：N = 10 是 M = 5 的两倍，即 10 = 2 * 5 。
// 示例 2：
// 输入：arr = [7,1,14,11]
// 输出：true
// 解释：N = 14 是 M = 7 的两倍，即 14 = 2 * 7 。
// 示例 3：
// 输入：arr = [3,1,7,11]
// 输出：false
// 解释：在该情况下不存在 N 和 M 满足 N = 2 * M 。
//  
// 提示：
//  * 2 <= arr.length <= 500
//  * -10^3 <= arr[i] <= 10^3

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
  if (capacity <= 0) {
    return NULL;
  }

  struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
  ret->capacity = capacity;
  ret->size = 0;
  int table_bytes = sizeof(struct HashNode *) * capacity;
  ret->table = (struct HashNode **)malloc(table_bytes);
  memset(ret->table, 0, table_bytes);

  return ret;
}

int HashFunc(struct HashTable *t, int key) {
  if (!t) return 0;
  int ret = key % t->capacity;
  if (ret < 0) {
    ret += t->capacity;
  }
  return ret;
}

struct HashNode* HashTableFind(struct HashTable *t, int val) {
  if (!t) return NULL;
  int h = HashFunc(t, val);
  if ((t->table)[h] == NULL) {
    return NULL;
  }
  struct HashNode *p = (t->table)[h];
  while (p) {
    if (p->val == val) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, int val) {
  if (!t) return ;
  int h = HashFunc(t, val);
  struct HashNode *n, *p = (t->table)[h];
  n = NewHashNode(val);
  if (p == NULL) {
    (t->table)[h] = n;
  } else {
    n->next = p;
    (t->table)[h] = n;
  }
}

bool checkIfExist(int* arr, int arrSize) {
  struct HashTable *h = NewHashTable(131);
  int i;

  for (i = 0; i < arrSize; i++) {
    // 是否存在 arr[i] * 2
    if (HashTableFind(h, arr[i]*2)) return true;
    // 是否存在 arr[i] / 2
    if (!(arr[i] & 1) && HashTableFind(h, arr[i]/2)) return true;
    HashTableAdd(h, arr[i]);
  }

  return false;
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
  if (checkIfExist(a, n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
