#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 523. 连 续的子数组和 - 给你一个整数数组 nums 和一个整数 k ，如果 nums 有一个 好的子数组  返回 true ，否则返回 false：
// 一个 好的子数组 是：
//  * 长度 至少为 2 ，且
//  * 子数组元素总和为 k 的倍数。
// 注意：
//  * 子数组 是数组中 连续 的部分。
//  * 如果存在一个整数 n ，令整数 x 符合 x = n * k ，则称 x 是 k 的一个倍数。0 始终 视为 k 的一个倍数。
//  
// 示例 1：
// 输入：nums = [23,2,4,6,7], k = 6
// 输出：true
// 解释：[2,4] 是一个大小为 2 的子数组，并且和为 6 。
// 示例 2：
// 输入：nums = [23,2,6,4,7], k = 6
// 输出：true
// 解释：[23, 2, 6, 4, 7] 是大小为 5 的子数组，并且和为 42 。
// 42 是 6 的倍数，因为 42 = 7 * 6 且 7 是一个整数。
// 示例 3：
// 输入：nums = [23,2,6,4,7], k = 13
// 输出：false
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 0 <= nums[i] <= 109
//  * 0 <= sum(nums[i]) <= 231 - 1
//  * 1 <= k <= 231 - 1

//// #v1
//// NOTE: stack overflow
//// prefix sum
//bool checkSubarraySum(int* nums, int numsSize, int k) {
  //// edge case
  //if (numsSize == 1) return false;
//
  //int prefixSum, f = 0;
  //int ht[k];
//
  //memset(ht, 0, sizeof(ht));
//
  //// prefix sum
  //prefixSum = 0;
  //ht[0] = 1;
  //for (int i = 1; i <= numsSize; i++) {
    //prefixSum += nums[i-1];
//
    //int r = prefixSum % k;
//
    //// edge case
    //if (r == 0 && i > 1) return true;
//
    //if (ht[r]) {
      //if (i - ht[r] > 1) {
        //f = 1;
        //break;
      //}
    //} else { // 余数 r 还未记录索引
      //ht[r] = i;
    //}
  //}
//
  //if (f) return true;
//
  //return false;
//}
//// #v1

// #v2
// prefix sum
struct HashNode {
  // remainder, min index
  int r, i;
  struct HashNode *next;
};

struct HashTable {
  int c;
  struct HashNode **a;
};

struct HashTable* NewHashTable(int c) {
  struct HashTable *ret = calloc(1, sizeof(struct HashTable));

  ret->c = c;
  ret->a = calloc(c, sizeof(struct HashNode *));
  for (int i = 0; i < c; i++) ret->a[i] = NULL;

  return ret;
}

#define HashFunc(t, k) ((k) % (t->c))

struct HashNode* HashTableFind(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *p = t->a[h];
  while (p) {
    if (p->r == val) return p;
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, int remainder, int index) {
  int h = HashFunc(t, remainder);
  struct HashNode *p = t->a[h], *q;

  struct HashNode *n = calloc(1, sizeof(struct HashNode));

  n->r = remainder;
  n->i = index;
  n->next = p;

  t->a[h] = n;
}

bool checkSubarraySum(int* nums, int numsSize, int k) {
  // edge case
  if (numsSize == 1) return false;

  int prefixSum, f = 0;
  struct HashTable *ht = NewHashTable(3727);
  struct HashNode *q;

  // init
  prefixSum = 0;
  HashTableAdd(ht, 0, 1);

  // compute
  for (int i = 1; i <= numsSize; i++) {
    // prefix sum
    prefixSum += nums[i-1];

    // remainder
    int r = prefixSum % k;

    // edge case, (nums[0] + ... + nums[i-1]) % k == 0
    if (r == 0 && i > 1) return true;

    q = HashTableFind(ht, r);
    if (q) {
      if (i - q->i > 1) { // 区间长度 > 1
        f = 1;
        break;
      }
    } else { // 余数 r 还未记录索引, 记录最小的索引 i, r --> i
      HashTableAdd(ht, r, i);
    }
  }

  if (f) return true;

  return false;
}
// #v2

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
  int n, k, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &k);
  if (checkSubarraySum(a, n, k))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
