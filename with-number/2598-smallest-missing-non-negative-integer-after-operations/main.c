#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2598. 执行操作后的最大 MEX - 给你一个下标从 0 开始的整数数组 nums 和一个整数 value 。
// 在一步操作中，你可以对 nums 中的任一元素加上或减去 value 。
//  * 例如，如果 nums = [1,2,3] 且 value = 2 ，你可以选择 nums[0] 减去 value ，得到 nums = [-1,2,3] 。
// 数组的 MEX (minimum excluded) 是指其中数组中缺失的最小非负整数。
//  * 例如，[-1,2,3] 的 MEX 是 0 ，而 [1,0,3] 的 MEX 是 2 。
// 返回在执行上述操作 任意次 后，nums 的最大 MEX 。
//  
// 示例 1：
// 输入：nums = [1,-10,7,13,6,8], value = 5
// 输出：4
// 解释：执行下述操作可以得到这一结果：
// - nums[1] 加上 value 两次，nums = [1,0,7,13,6,8]
// - nums[2] 减去 value 一次，nums = [1,0,2,13,6,8]
// - nums[3] 减去 value 两次，nums = [1,0,2,3,6,8]
// nums 的 MEX 是 4 。可以证明 4 是可以取到的最大 MEX 。
// 示例 2：
// 输入：nums = [1,-10,7,13,6,8], value = 7
// 输出：2
// 解释：执行下述操作可以得到这一结果：
// - nums[2] 减去 value 一次，nums = [1,-10,0,13,6,8]
// nums 的 MEX 是 2 。可以证明 2 是可以取到的最大 MEX 。
//  
// 提示：
//  * 1 <= nums.length, value <= 105
//  * -109 <= nums[i] <= 109

//// #v1
//// 哈希表, 计数, 数学, 模运算
//struct HashNode {
  //int val;
  //int cnt;
  //struct HashNode *next;
//};
//
//struct HashTable {
  //int capacity;
  //struct HashNode **table;
//};
//
//struct HashNode* NewHashNode(int val) {
  //struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  //ret->val = val;
  //ret->cnt = 1;
  //ret->next = NULL;
  //return ret;
//}
//
//struct HashTable* NewHashTable(int capacity) {
  //struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
  //ret->capacity = capacity;
  //int table_bytes = sizeof(struct HashNode *) * capacity;
  //ret->table = (struct HashNode **)malloc(table_bytes);
  //memset(ret->table, 0, table_bytes);
//
  //return ret;
//}
//
//#define HashFunc(t, key) (key % t->capacity)
//
//struct HashNode* HashTableFind(struct HashTable *t, int val) {
  //int h = HashFunc(t, val);
  //struct HashNode *p = (t->table)[h];
  //while (p) {
    //if (p->val == val) return p;
    //p = p->next;
  //}
  //return NULL;
//}
//
//void HashTableAdd(struct HashTable *t, int val) {
  //int h = HashFunc(t, val);
  //struct HashNode *n, *p = (t->table)[h], *q;
//
  //q = HashTableFind(t, val);
  //if (q) {
    //q->cnt += 1;
  //} else {
    //n = NewHashNode(val);
    //if (!p) {
      //(t->table)[h] = n;
    //} else {
      //n->next = p;
      //(t->table)[h] = n;
    //}
  //}
//}
//
//int findSmallestInteger(int* nums, int numsSize, int value) {
  //int i, f, t, minVal = 0x3f3f3f3f;
  //struct HashTable *h = NewHashTable(8933);
  //struct HashNode *p;
//
  //// 把 nums 的元素根据 mod value 的余数分成 value 类
  //// 分别统计每一类的数量
  //// [0, value-1]
  //for (i = 0; i < numsSize; i++) {
    //t = nums[i] % value;
    //// 处理负数
    //if (t < 0) t += value;
//
    //// 加入哈希表
    //HashTableAdd(h, t);
  //}
//
  //f = 0;
  //for (i = 0; i < value; i++) {
    //p = HashTableFind(h, i);
//
    //if (!p) {
      //f = 1;
      //break;
    //} else {
      //t = i + (p->cnt - 1) * value;
      //// 寻找最小可能的值
      //if (t <= minVal) minVal = t;
    //}
  //}
//
  //// [0, value-1] 中缺少
  //if (f) return i;
//
  //// 返回下一个未被占用的最小的数
  //// 因为 minVal 是所有数中最小的, 所以 minVal + value 也是最小的
  //return minVal + value;
//}
//// #v1

// #v2
int findSmallestInteger(int* nums, int numsSize, int value) {
  int i, f, t, minVal = 0x3f3f3f3f, h[value];

  memset(h, 0, sizeof(int) * value);

  // 把 nums 的元素根据 mod value 的余数分成 value 类
  // 分别统计每一类的数量
  // [0, value-1]
  for (i = 0; i < numsSize; i++) {
    t = nums[i] % value;
    // 处理负数
    if (t < 0) t += value;

    // 加入哈希表
    ++h[t];
  }

  f = 0;
  for (i = 0; i < value; i++) {
    if (!h[i]) {
      f = 1;
      break;
    } else {
      t = i + (h[i] - 1) * value;
      // 寻找最小可能的值
      if (t <= minVal) minVal = t;
    }
  }

  // [0, value-1] 中缺少
  if (f) return i;

  // 返回下一个未被占用的最小的数
  // 因为 minVal 是所有数中最小的, 所以 minVal + value 也是最小的
  return minVal + value;
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
  int n, *a, v;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &v);
  printf("%d\n", findSmallestInteger(a, n, v));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
