#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2150. 找出数组中的所有孤独数字 - 给你一个整数数组 nums 。如果数字 x 在数组中仅出现 一次 ，且没有 相邻 数字（即，x + 1 和 x - 1）出现在数组中，则认为数字 x 是  孤独数字 。
// 返回 nums 中的 所有 孤独数字。你可以按 任何顺序 返回答案。
//  
// 示例 1：
// 输入：nums = [10,6,5,8]
// 输出：[10,8]
// 解释：
// - 10 是一个孤独数字，因为它只出现一次，并且 9 和 11 没有在 nums 中出现。
// - 8 是一个孤独数字，因为它只出现一次，并且 7 和 9 没有在 nums 中出现。
// - 5 不是一个孤独数字，因为 6 出现在 nums 中，反之亦然。
// 因此，nums 中的孤独数字是 [10, 8] 。
// 注意，也可以返回 [8, 10] 。
// 示例 2：
// 输入：nums = [1,3,5,3]
// 输出：[1,5]
// 解释：
// - 1 是一个孤独数字，因为它只出现一次，并且 0 和 2 没有在 nums 中出现。
// - 5 是一个孤独数字，因为它只出现一次，并且 4 和 6 没有在 nums 中出现。
// - 3 不是一个孤独数字，因为它出现两次。
// 因此，nums 中的孤独数字是 [1, 5] 。
// 注意，也可以返回 [5, 1] 。
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * 0 <= nums[i] <= 106

//// #v1
//struct HashNode {
  //int val, cnt;
  //struct HashNode *next;
//};
//
//struct HashTable {
  //int c;
  //struct HashNode **a;
//};
//
//struct HashTable* NewHashTable(int c) {
  //struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
//
  //ret->c = c;
  //ret->a = (struct HashNode **)malloc(c * sizeof(struct HashNode *));
  //for (int i = 0; i < c; i++) ret->a[i] = NULL;
//
  //return ret;
//}
//
//#define HashFunc(t, k) (((k) % (t)->c + (t)->c) % (t)->c)
//
//struct HashNode* HashTableFind(struct HashTable *t, int val) {
  //int h = HashFunc(t, val);
  //struct HashNode *p = t->a[h];
  //while (p) {
    //if (p->val == val) {
      //return p;
    //}
    //p = p->next;
  //}
  //return NULL;
//}
//
//void HashTableAdd(struct HashTable *t, int val) {
  //struct HashNode *q = HashTableFind(t, val);
//
  //if (q) {
    //++q->cnt;
    //return ;
  //}
//
  //int h = HashFunc(t, val);
  //struct HashNode *p = t->a[h];
  //struct HashNode *n = (struct HashNode *)malloc(sizeof(struct HashNode));
//
  //n->val = val;
  //n->cnt = 1;
  //t->a[h] = n;
  //n->next = p;
//}
//
//int* findLonely(int* nums, int numsSize, int* returnSize) {
  //int *ret = (int *)malloc(sizeof(int) * numsSize), retLen = 0;
  //struct HashTable *ht = NewHashTable(3727);
  //struct HashNode *p;
//
  //for (int i = 0; i < numsSize; i++) HashTableAdd(ht, nums[i]);
//
  //for (int i = 0; i < numsSize; i++) {
    //p = HashTableFind(ht, nums[i]);
    //if (p && p->cnt > 1) continue;
    //p = HashTableFind(ht, nums[i]-1);
    //if (p) continue;
    //p = HashTableFind(ht, nums[i]+1);
    //if (p) continue;
    //ret[retLen++] = nums[i];
  //}
//
  //*returnSize = retLen;
//
  //return ret;
//}
//// #v1

// #v2
int* findLonely(int* nums, int numsSize, int* returnSize) {
  int *ret = (int *)malloc(sizeof(int) * numsSize), retLen = 0, pos;
  char ht[1000003] = {0};

  for (int i = 0; i < numsSize; i++) {
    pos = nums[i] + 1;
    if (ht[pos] <= 1) ++ht[pos];
  }

  for (int i = 0; i < numsSize; i++) {
    pos = nums[i] + 1;
    if (ht[pos] == 1 && !ht[pos-1] && !ht[pos+1])
      ret[retLen++] = nums[i];
  }

  *returnSize = retLen;

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

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int n, *a, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = findLonely(a, n, &s);
  print_1d_arr(ret, s);
  free(ret);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
