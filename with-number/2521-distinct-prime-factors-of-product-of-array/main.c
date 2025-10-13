#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// 2521. 数组乘积中的不同质因数数目 - 给你一个正整数数组 nums ，对 nums 所有元 素求积之后，找出并返回乘积中 不同质因数 的数目。
// 注意：
//  * 质数 是指大于 1 且仅能被 1 及自身整除的数字。
//  * 如果 val2 / val1 是一个整数，则整数 val1 是另一个整数 val2 的一个因数。
//  
// 示例 1：
// 输入：nums = [2,4,3,7,10,6]
// 输出：4
// 解释：
// nums 中所有元素的乘积是：2 * 4 * 3 * 7 * 10 * 6 = 10080 = 25 * 32 * 5 * 7 。
// 共有 4 个不同的质因数，所以返回 4 。
// 示例 2：
// 输入：nums = [2,4,8,16]
// 输出：1
// 解释：
// nums 中所有元素的乘积是：2 * 4 * 8 * 16 = 1024 = 210 。
// 共有 1 个不同的质因数，所以返回 1 。
//  
// 提示：
//  * 1 <= nums.length <= 104
//  * 2 <= nums[i] <= 1000

// #v1
// 哈希表, 分解质因数, 质数

struct HashNode {
  int val;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
  struct HashNode **table;
};

struct HashNode* NewHashNode(int v) {
  struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  ret->val = v;
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

#define HashFunc(t, key) ((key) % (t->capacity))

struct HashNode* HashTableFind(struct HashTable *t, int v) {
  int h = HashFunc(t, v);
  struct HashNode *p = (t->table)[h];
  while (p) {
    if (p->val == v) return p;
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, int v) {
  int h = HashFunc(t, v);
  struct HashNode *n, *p = (t->table)[h];
  n = NewHashNode(v);
  if (!p) {
    (t->table)[h] = n;
  } else {
    n->next = p;
    (t->table)[h] = n;
  }
}

// 哈希表
struct HashTable *h;
// 质数表
int *primeTable;

bool isPrime(int n) {
  // 质数表中已有结果
  if (primeTable[n] >= 0) return primeTable[n];

  if (n == 2) {
    primeTable[2] = 1;
    return true;
  }

  int b = sqrt(n);

  for (int i = 2; i <= b; i++) {
    if (n % i == 0) {
      // n 不是质数
      primeTable[n] = 0;
      return false;
    }
  }

  // n 是质数
  primeTable[n] = 1;
  return true;
}

// 统计 n 的质因数分解中有多少新出现的质数
int factor(int n) {
  int ret = 0, f = 0, b = sqrt(n), v;

  for (int i = 2; i <= b; i++) {
    if (n % i == 0) {
      f = 1;

      v = i;
      // i 不在哈希表中
      if (!HashTableFind(h, v)) {
        HashTableAdd(h, v);
        if (isPrime(v)) ++ret;
      }

      v = n / i;
      // n/i 不在哈希表中
      if (!HashTableFind(h, v)) {
        HashTableAdd(h, v);
        if (isPrime(v)) ++ret;
      }
    }
  }

  if (!f) { // n 是质数
    HashTableAdd(h, n);
    return 1;
  }

  return ret;
}

int distinctPrimeFactors(int* nums, int numsSize) {
  h = NewHashTable(131);
  int ret = 0, pt[1001];

  // 初始化质数表
  memset(pt, 0xff, sizeof(int) * 1001);
  primeTable = pt;

  for (int i = 0; i < numsSize; i++) {
    // 哈希表中已经存在 nums[i], 说明 nums[i] 的质因数已经统计到结果中了
    if (HashTableFind(h, nums[i])) continue;

    ret += factor(nums[i]);

    // add to hash table
    HashTableAdd(h, nums[i]);
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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", distinctPrimeFactors(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
