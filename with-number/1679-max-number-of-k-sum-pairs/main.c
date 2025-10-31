#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1679. K 和数对的最大数目 - 给你一个整数数组 nums 和一个整数 k 。
// 每一步操作中，你需要从数组中选出和为 k 的两个整数，并将它们移出数组。
// 返回你可以对数组执行的最大操作数。
//  
// 示例 1：
// 输入：nums = [1,2,3,4], k = 5
// 输出：2
// 解释：开始时 nums = [1,2,3,4]：
// - 移出 1 和 4 ，之后 nums = [2,3]
// - 移出 2 和 3 ，之后 nums = []
// 不再有和为 5 的数对，因此最多执行 2 次操作。
// 示例 2：
// 输入：nums = [3,1,3,4,3], k = 6
// 输出：1
// 解释：开始时 nums = [3,1,3,4,3]：
// - 移出前两个 3 ，之后nums = [1,4,3]
// 不再有和为 6 的数对，因此最多执行 1 次操作。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 1 <= nums[i] <= 109
//  * 1 <= k <= 109
// The abstract problem asks to count the number of disjoint pairs with a given
// sum k.
// For each possible value x, it can be paired up with k - x.
// The number of such pairs equals to min(count(x), count(k-x)), unless that x =
// k / 2, where the number of such pairs will be floor(count(x) / 2).

// #v1
// 哈希表, 计数
struct HashNode {
  int val, cnt;
  struct HashNode *next;
};

struct HashTable {
  int c;
  struct HashNode **table;
};

struct HashNode* NewHashNode(int v) {
  struct HashNode *ret = calloc(1, sizeof(struct HashNode));

  ret->val = v;
  ret->cnt = 1;

  return ret;
}

struct HashTable* NewHashTable(int c) {
  struct HashTable *ret = calloc(1, sizeof(struct HashTable));

  ret->c = c;
  ret->table = calloc(c, sizeof(struct HashNode *));
  for (int i = 0; i < c; i++) ret->table[i] = NULL;

  return ret;
}

#define HashFunc(t, k) ((k) % (t->c))

struct HashNode* HashTableFind(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *p = t->table[h];
  while (p) {
    if (p->val == val) return p;
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *n, *p = t->table[h], *q = p;

  while (q) {
    if (q->val == val) break;
    q = q->next;
  }

  if (q) {
    q->cnt += 1;
    return ;
  }

  n = NewHashNode(val);
  t->table[h] = n;
  n->next = p;
}

#define MIN(a, b) ((a) >= (b) ? (b) : (a))

int maxOperations(int* nums, int numsSize, int k) {
  struct HashTable *ht = NewHashTable(3727);
  struct HashNode *p, *q;

  char isEven = !(k & 1);
  int i, h = k>>1, ret = 0;

  // add to hash table and count
  for (i = 0; i < numsSize; i++) {
    // skip invalid number
    if (nums[i] >= k) continue;

    HashTableAdd(ht, nums[i]);
  }

  // iterate over every node in hash table
  for (i = 0; i < ht->c; i++) {
    p = ht->table[i];

    if (isEven) { // k is even number
      while (p) {
        if (p->val == h) {
          ret += p->cnt >> 1;
        } else {
          q = HashTableFind(ht, k - p->val);

          if (q) {
            ret += MIN(q->cnt, p->cnt);
            q->cnt = 0;
          }
        }

        p->cnt = 0;
        p = p->next;
      }
    } else { // k is odd number
      while (p) {
        q = HashTableFind(ht, k - p->val);

        if (q) {
          ret += MIN(q->cnt, p->cnt);
          q->cnt = 0;
        }

        p->cnt = 0;
        p = p->next;
      }
    }
  }

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
  int n, *a, k;

  scanf("%d", &n);
  a = read_1d_arr(n);

  scanf("%d", &k);

  printf("%d\n", maxOperations(a, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
