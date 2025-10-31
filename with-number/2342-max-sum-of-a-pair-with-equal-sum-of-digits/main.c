#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2342. 数位和相等数对的最大和 - 给你一个下标从 0 开始的数组 nums ，数组中的元素都是 正 整数。请你选出两个下标 i 和 j（i != j），且 nums[i] 的数位和 与  nums[j] 的数位和相等。
// 请你找出所有满足条件的下标 i 和 j ，找出并返回 nums[i] + nums[j] 可以得到的 最大值。如果不存在这样的下标对，返回 -1。
//  
// 示例 1：
// 输入：nums = [18,43,36,13,7]
// 输出：54
// 解释：满足条件的数对 (i, j) 为：
// - (0, 2) ，两个数字的数位和都是 9 ，相加得到 18 + 36 = 54 。
// - (1, 4) ，两个数字的数位和都是 7 ，相加得到 43 + 7 = 50 。
// 所以可以获得的最大和是 54 。
// 示例 2：
// 输入：nums = [10,12,19,14]
// 输出：-1
// 解释：不存在满足条件的数对，返回 -1 。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 1 <= nums[i] <= 109

// #v1
struct HashNode {
  int val;
  int arr[2];
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
    if (p->val == val) return p;
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, int val, int el) {
  int h = HashFunc(t, val);
  struct HashNode *p = t->a[h];
  struct HashNode *n = calloc(1, sizeof(struct HashNode));

  n->val = val;
  n->arr[1] = -1;
  n->arr[0] = el;

  // add to hash table
  t->a[h] = n;
  n->next = p;
}

int maximumSum(int* nums, int numsSize) {
  struct HashTable *ht = NewHashTable(131);
  int ret = -1;

  for (int i = 0; i < numsSize; i++) {
    int x = nums[i], sum = 0;
    // 求 nums[i] 数位和
    while (x) {
      sum += x % 10;
      x /= 10;
    }

    // find sum in hash table
    struct HashNode *p = HashTableFind(ht, sum);
    if (p) {
      int *minPos = &(p->arr[0]);
      // determine min(p->arr[0], p->arr[1])
      if (p->arr[0] > p->arr[1]) minPos = &(p->arr[1]);

      if (nums[i] > *minPos) {
        // update p->arr
        *minPos = nums[i];

        // update result
        if (p->arr[1] != -1) {
          int tmp = p->arr[0] + p->arr[1];
          if (tmp > ret) ret = tmp;
        }
      }

    } else { // create new node
      HashTableAdd(ht, sum, nums[i]);
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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", maximumSum(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
