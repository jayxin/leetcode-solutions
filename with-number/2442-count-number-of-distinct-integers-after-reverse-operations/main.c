#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2442. 反转之后不同整数的数目 - 给你一个由 正 整数组成的数组 nums 。
// 你必须取出数组中的每个整数，反转其中每个数位，并将反转后得到的数字添加到数组的末 尾。这一操作只针对 nums 中原有的整数执行。
// 返回结果数组中 不同 整数的数目。
//  
// 示例 1：
// 输入：nums = [1,13,10,12,31]
// 输出：6
// 解释：反转每个数字后，结果数组是 [1,13,10,12,31,1,31,1,21,13] 。
// 反转后得到的数字添加到数组的末尾并按斜体加粗表示。注意对于整数 10 ，反转之后会变 成 01 ，即 1 。
// 数组中不同整数的数目为 6（数字 1、10、12、13、21 和 31）。
// 示例 2：
// 输入：nums = [2,2,2]
// 输出：1
// 解释：反转每个数字后，结果数组是 [2,2,2,2,2,2] 。
// 数组中不同整数的数目为 1（数字 2）。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 1 <= nums[i] <= 106

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

#define HashFunc(t, k) ((k) % (t->capacity))

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
  (t->table)[h] = n;
  if (p) n->next = p;
}

int countDistinctIntegers(int* nums, int numsSize) {
  int ret = 0, t, x;
  struct HashTable *h = NewHashTable(numsSize);

  for (int i = 0; i < numsSize; i++) {
    t = nums[i];
    if (!HashTableFind(h, t)) {
      HashTableAdd(h, t);
      ++ret;
    }

    x = 0;
    while (t) {
      x = x * 10 + t % 10;
      t /= 10;
    }

    if (!HashTableFind(h, x)) {
      HashTableAdd(h, x);
      ++ret;
    }
  }

  for (int i = 0; i < h-> capacity; i++) {
    struct HashNode *p = (h->table)[i], *q;
    while (p) {
      q = p;
      p = p->next;
      free(q);
    }
    (h->table)[i] = NULL;
  }

  free(h);

  return ret;
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
  printf("%d\n", countDistinctIntegers(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
