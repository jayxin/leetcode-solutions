#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1814. 统计一个数组中好对子的数目 - 给你一个数组 nums ，数组中只包含非负整数 。定义 rev(x) 的值为将整数 x 各个数字位反转得到的结果。比方说 rev(123) = 321 ， rev(120) = 21 。我们称满足下面条件的下标对 (i, j) 是 好的 ：
//  * 0 <= i < j < nums.length
//  * nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
// 请你返回好下标对的数目。由于结果可能会很大，请将结果对 109 + 7 取余 后返回。
//  
// 示例 1：
// 输入：nums = [42,11,1,97]
// 输出：2
// 解释：两个坐标对为：
//  - (0,3)：42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121 。
//  - (1,2)：11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12 。
// 示例 2：
// 输入：nums = [13,10,35,24,76]
// 输出：4
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 0 <= nums[i] <= 109

// #v1
struct HashNode {
  int val, cnt;
  struct HashNode *next;
};

struct HashTable {
  int c;
  struct HashNode **a;
};

struct HashNode* NewHashNode(int val) {
  struct HashNode *ret = calloc(1, sizeof(struct HashNode));

  ret->val = val;
  ret->cnt = 1;

  return ret;
}

struct HashTable* NewHashTable(int c) {
  struct HashTable *ret = calloc(1, sizeof(struct HashTable));

  ret->c = c;
  ret->a = calloc(c, sizeof(struct HashNode *));
  for (int i = 0; i < c; i++) ret->a[i] = NULL;

  return ret;
}

int HashFunc(struct HashTable *t, int key) {
  int ret = key % t->c;
  if (ret < 0) ret += t->c;
  return ret;
}

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
  struct HashNode *n, *p = t->a[h];

  n = NewHashNode(val);
  t->a[h] = n;
  n->next = p;
}

#define MOD 1000000007

int rev(int x) {
  int v = 0;

  while (x) {
    v = v * 10 + x % 10;
    x /= 10;
  }

  return v;
}

int countNicePairs(int* nums, int numsSize) {
  int ret = 0;
  struct HashTable *ht = NewHashTable(1399);

  for (int i = 0; i < numsSize; i++) {
    int v = nums[i] - rev(nums[i]);
    struct HashNode *p = HashTableFind(ht, v);

    if (p) {
      ret = (ret + p->cnt) % MOD;
      p->cnt = (p->cnt + 1) % MOD;
    }
    else HashTableAdd(ht, v);
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
  printf("%d\n", countNicePairs(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
