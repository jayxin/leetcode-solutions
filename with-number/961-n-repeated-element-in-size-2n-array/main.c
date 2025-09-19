#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 961. 在长度 2N 的数组中找出重复 N 次的元素 - 给你一个整数数组 nums ，该数组具有以下属性：
//  * nums.length == 2 * n.
//  * nums 包含 n + 1 个 不同的 元素
//  * nums 中恰有一个元素重复 n 次
// 找出并返回重复了 n 次的那个元素。
//  
// 示例 1：
// 输入：nums = [1,2,3,3]
// 输出：3
// 示例 2：
// 输入：nums = [2,1,2,5,3,2]
// 输出：2
// 示例 3：
// 输入：nums = [5,1,5,2,5,3,5,4]
// 输出：5
//  
// 提示：
//  * 2 <= n <= 5000
//  * nums.length == 2 * n
//  * 0 <= nums[i] <= 104
//  * nums 由 n + 1 个 不同的 元素组成，且其中一个元素恰好重复 n 次

// #v1
// 哈希表
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

void HashTablePrint(struct HashTable *t) {
  if (!t) return ;
  struct HashNode *p;
  int i;
  for (i = 0; i < t->capacity; i++) {
    if (t->table[i] == NULL) {
      continue;
    }
    p = t->table[i];
    while (p) {
      printf("%d ", t->table[i]->val);
      p = p->next;
    }
    putchar('\n');
  }
}

void HashTableRemove(struct HashTable *t, int val) {
  if (!t) return ;
  int h = HashFunc(t, val);
  struct HashNode *p = (t->table)[h];
  if (p == NULL) {
    return ;
  } else {
    struct HashNode *prev = NULL;
    while (p) {
      if (p->val == val) {
        break;
      }
      prev = p;
      p = p->next;
    }
    if (p) {
      if (prev) {
        prev->next = p->next;
      } else {
        (t->table)[h] = (t->table)[h]->next;
      }
      free(p);
    }
  }
}

int repeatedNTimes(int* nums, int numsSize) {
  struct HashTable *h = NewHashTable(131);
  for (int i = 0; i < numsSize; i++) {
    if (HashTableFind(h, nums[i])) {
      return nums[i];
    }
    HashTableAdd(h, nums[i]);
  }
  return 0;
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
  printf("%d\n", repeatedNTimes(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
