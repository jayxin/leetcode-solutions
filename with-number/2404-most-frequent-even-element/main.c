#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2404. 出现最频繁的偶数元素 - 给你一个整数数组 nums ，返回出现最频繁的偶数元素。
// 如果存在多个满足条件的元素，只需要返回 最小 的一个。如果不存在这样的元素，返回 -1 。
//  
// 示例 1：
// 输入：nums = [0,1,2,2,4,4,1]
// 输出：2
// 解释：
// 数组中的偶数元素为 0、2 和 4 ，在这些元素中，2 和 4 出现次数最多。
// 返回最小的那个，即返回 2 。
// 示例 2：
// 输入：nums = [4,4,4,9,2,4]
// 输出：4
// 解释：4 是出现最频繁的偶数元素。
// 示例 3：
// 输入：nums = [29,47,21,41,13,37,25,7]
// 输出：-1
// 解释：不存在偶数元素。
//  
// 提示：
//  * 1 <= nums.length <= 2000
//  * 0 <= nums[i] <= 105

// #v1
struct HashNode {
  int val, cnt;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
  struct HashNode **table;
};

struct HashNode* NewHashNode(int val) {
  struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  ret->val = val;
  ret->cnt = 1;
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

int HashTableAdd(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *n, *p = (t->table)[h], *q;
  q = HashTableFind(t, val);
  if (q) {
    q->cnt += 1;
    return q->cnt;
  }

  n = NewHashNode(val);
  n->next = p;
  (t->table)[h] = n;

  return 1;
}

int mostFrequentEven(int* nums, int numsSize) {
  int ret = 0x3f3f3f3f, maxCnt = 0, c;
  struct HashTable *h = NewHashTable(numsSize);

  for (int i = 0; i < numsSize; i++) {
    if (!(nums[i] & 1)) {
      c = HashTableAdd(h, nums[i]);
      if (c > maxCnt) {
        ret = nums[i];
        maxCnt = c;
      } else if (c == maxCnt) {
        if (nums[i] < ret) ret = nums[i];
      }
    }
  }

  if (!maxCnt) return -1;

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
  printf("%d\n", mostFrequentEven(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
