#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2845. 统计趣味子数组的数目 - 给你一个下标从 0 开始的整数数组 nums ，以及整数 modulo 和整数 k 。
// 请你找出并统计数组中 趣味子数组 的数目。
// 如果 子数组 nums[l..r] 满足下述条件，则称其为 趣味子数组 ：
//  * 在范围 [l, r] 内，设 cnt 为满足 nums[i] % modulo == k 的索引 i 的数量。并且 cnt % modulo == k 。
// 以整数形式表示并返回趣味子数组的数目。
// 注意：子数组是数组中的一个连续非空的元素序列。
//  
// 示例 1：
// 输入：nums = [3,2,4], modulo = 2, k = 1
// 输出：3
// 解释：在这个示例中，趣味子数组分别是：
// 子数组 nums[0..0] ，也就是 [3] 。
// - 在范围 [0, 0] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
// - 因此 cnt = 1 ，且 cnt % modulo == k 。
// 子数组 nums[0..1] ，也就是 [3,2] 。
// - 在范围 [0, 1] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
// - 因此 cnt = 1 ，且 cnt % modulo == k 。
// 子数组 nums[0..2] ，也就是 [3,2,4] 。
// - 在范围 [0, 2] 内，只存在 1 个下标 i = 0 满足 nums[i] % modulo == k 。
// - 因此 cnt = 1 ，且 cnt % modulo == k 。
// 可以证明不存在其他趣味子数组。因此，答案为 3 。
// 示例 2：
// 输入：nums = [3,1,9,6], modulo = 3, k = 0
// 输出：2
// 解释：在这个示例中，趣味子数组分别是：
// 子数组 nums[0..3] ，也就是 [3,1,9,6] 。
// - 在范围 [0, 3] 内，只存在 3 个下标 i = 0, 2, 3 满足 nums[i] % modulo == k 。
// - 因此 cnt = 3 ，且 cnt % modulo == k 。
// 子数组 nums[1..1] ，也就是 [1] 。
// - 在范围 [1, 1] 内，不存在下标满足 nums[i] % modulo == k 。
// - 因此 cnt = 0 ，且 cnt % modulo == k 。
// 可以证明不存在其他趣味子数组，因此答案为 2 。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 1 <= nums[i] <= 109
//  * 1 <= modulo <= 109
//  * 0 <= k < modulo
// 1. The problem can be solved using prefix sums.
// 2. Let count[i] be the number of indices where nums[i] % modulo == k among the
// first i indices.
// 3. count[0] = 0 and count[i] = count[i - 1] + (nums[i - 1] % modulo == k ? 1 :
// 0) for i = 1, 2, ..., n.
// 4. Now we want to calculate for each i = 1, 2, ..., n, how many indices j < i
// such that (count[i] - count[j]) % modulo == k.
// 5. Rewriting (count[i] - count[j]) % modulo == k becomes count[j] = (count[i] + modulo - k) % modulo.
// 6. Using a map data structure, for each i = 0, 1, 2, ..., n, we just sum up
// all map[(count[i] + modulo - k) % modulo] before increasing map[count[i] %
// modulo], and the total sum is the final answer.

//// #v1
//// NOTE: stack overflow
//// prefix sum, hash table, count, math
//long long countInterestingSubarrays(int* nums, int numsSize, int modulo, int k) {
  //// edge case
  //if (modulo == 1) return (1 + numsSize) * numsSize / 2;
//
  //long long ret = 0LL;
  //// p[i] 是 nums[0...(i-1)] 中 nums[j] % modulo == k 的索引 j 的数量
  //int p[numsSize+1];
  //int ht[modulo];
//
  //memset(ht, 0, sizeof(ht));
//
  //// prefix sum
  //p[0] = 0;
  //for (int i = 0; i < numsSize; i++) {
    //int q = nums[i] % modulo == k ? 1 : 0;
    //p[i+1] = p[i] + q;
  //}
//
  //// (p[j+1] - p[i]) % modulo == k
  //// p[j+1] - p[i] = q * modulo + k
  //// p[j+1]-k 和 p[i] 同余
  //// 因为做了减法所以要加上
  //// (p[j+1]-k+modulo) % modulo == p[i] % modulo
  //// p[j+1] 和 p[i]+k 同余
  //// p[j+1] % modulo == (p[i]+k) % modulo
  //for (int i = 0; i <= numsSize; i++) { // 注意边界 i=0
    ////int r = (p[i] - k + modulo) % modulo;
    ////ret += ht[r];
    ////r = p[i] % modulo;
    ////++ht[r];
//
    //int r = p[i] % modulo;
    //ret += ht[r];
    //r = (p[i]+k) % modulo;
    //++ht[r];
  //}
//
  //return ret;
//}
//// #v1

// #v2
// prefix sum, hash table, count, math
struct HashNode {
  int val, cnt;
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

#define HashFunc(t, k) ((k % t->c + t->c) % t->c)

struct HashNode* HashTableFind(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *p = t->a[h];
  while (p) {
    if (p->val == val) return p;
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *p = t->a[h];

  struct HashNode *n = calloc(1, sizeof(struct HashNode));

  n->val = val;
  n->cnt = 1;
  n->next = p;

  t->a[h] = n;
}

long long countInterestingSubarrays(int* nums, int numsSize, int modulo, int k) {
  long long ret = 0LL;

  // edge case
  if (modulo == 1) {
    ret = (1LL + numsSize) * numsSize / 2LL;
    return ret;
  }

  // p[i] 是 nums[0...(i-1)] 中 nums[j] % modulo == k 的索引 j 的数量
  int p[numsSize+1];
  struct HashTable *ht = NewHashTable(3727);
  struct HashNode *q;

  // prefix sum
  p[0] = 0;
  for (int i = 0; i < numsSize; i++) {
    int q = nums[i] % modulo == k ? 1 : 0;
    p[i+1] = p[i] + q;
  }

  // (p[j+1] - p[i]) % modulo == k
  // p[j+1] - p[i] = q * modulo + k
  // p[j+1]-k 和 p[i] 同余
  // 因为做了减法所以要加上
  // (p[j+1]-k+modulo) % modulo == p[i] % modulo
  // p[j+1] 和 p[i]+k 同余
  // p[j+1] % modulo == (p[i]+k) % modulo
  for (int i = 0; i <= numsSize; i++) { // 注意边界 i=0
    //int r = (p[i] - k + modulo) % modulo;
    //ret += ht[r];
    //r = p[i] % modulo;
    //++ht[r];

    int r = p[i] % modulo;
    q = HashTableFind(ht, r);
    if (q) ret += q->cnt;

    //r = (p[i]+k) % modulo;
    r = (r+k) % modulo;
    q = HashTableFind(ht, r);
    if (q) ++q->cnt;
    else HashTableAdd(ht, r);
  }

  return ret;
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
  int n, k, *a, modulo;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d%d", &modulo, &k);
  printf("%lld\n", countInterestingSubarrays(a, n, modulo, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
