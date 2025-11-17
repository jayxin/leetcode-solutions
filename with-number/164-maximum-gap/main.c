#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// 164. 最大间距 - 给定一个无序的数组 nums，返回 数组在排序之后，相邻元素之间最大的差值 。如果数组元素个数小于 2，则返回 0 。
// 您必须编写一个在「线性时间」内运行并使用「线性额外空间」的算法。
//  
// 示例 1:
// 输入: nums = [3,6,9,1]
// 输出: 3
// 解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3 。
// 示例 2:
// 输入: nums = [10]
// 输出: 0
// 解释: 数组元素个数小于 2，因此返回 0。
//  
// 提示:
//  * 1 <= nums.length <= 105
//  * 0 <= nums[i] <= 109

//// #v1
//// 超时
//// 桶排序
//int maximumGap(int* nums, int numsSize) {
  //if (numsSize <= 1) return 0;
//
  //int maxEl = nums[0];
  //char *a;
//
  //for (int i = 1; i < numsSize; i++) {
    //if (nums[i] > maxEl) maxEl = nums[i];
  //}
//
  //a = (char *)malloc((maxEl/8+1) * sizeof(char));
  //memset(a, 0, sizeof(char) * (maxEl/8+1));
  //for (int i = 0; i < numsSize; i++) {
    //int byte_idx = nums[i] / 8, bit_idx = nums[i] % 8;
    //a[byte_idx] |= 1 << bit_idx;
  //}
//
  //int diff = 0, prev = -1;
//
  //for (int i = 0; i <= maxEl; i++) {
    //int byte_idx = i / 8, bit_idx = i % 8;
    //if (a[byte_idx] == 0) i += 7;
    //if (a[byte_idx] & (1 << bit_idx)) {
      //if (prev >= 0) {
        //int tmp = i - prev;
        //if (tmp > diff) diff = tmp;
      //}
//
      //prev = i;
    //}
  //}
//
  //free(a);
//
  //return diff;
//}
//// #v1

//// #v2
//// 内存超限
//// 桶排序, bit map
//int maximumGap(int* nums, int numsSize) {
  //if (numsSize <= 1) return 0;
//
  //int max_el = nums[0], min_el = nums[0];
  //char *a;
//
  //for (int i = 1; i < numsSize; i++) {
    //if (nums[i] > max_el) max_el = nums[i];
    //if (nums[i] < min_el) min_el = nums[i];
  //}
//
  //size_t bucket_size = sizeof(char) * (max_el/8 + 1);
  //a = (char *)malloc(bucket_size);
  //memset(a, 0, bucket_size);
  //for (int i = 0; i < numsSize; i++) {
    //int byte_idx = nums[i] / 8, bit_idx = nums[i] % 8;
    //a[byte_idx] |= 1 << bit_idx;
  //}
//
  //int diff = 0, prev = -1;
//
  //for (int i = min_el; i <= max_el; i++) {
    //int byte_idx = i / 8, bit_idx = i % 8;
//
    //if (a[byte_idx] == 0) {
      //i += 7;
    //} else if (a[byte_idx] & (1 << bit_idx)) {
      //if (prev >= 0) {
        //int tmp = i - prev;
        //if (tmp > diff) diff = tmp;
      //}
//
      //prev = i;
    //}
  //}
//
  //return diff;
//}
//// #v2

//// #v3
//// 超时
//// 桶排序, bit map
//int maximumGap(int* nums, int numsSize) {
  //if (numsSize <= 1) return 0;
//
  //int max_el = nums[0], min_el = nums[0];
  //char *a;
//
  //for (int i = 1; i < numsSize; i++) {
    //if (nums[i] > max_el) max_el = nums[i];
    //if (nums[i] < min_el) min_el = nums[i];
  //}
//
  //max_el -= min_el;
//
  //for (int i = 0; i < numsSize; i++) {
    //nums[i] -= min_el;
  //}
//
  //min_el = 0;
//
  //size_t bucket_size = sizeof(char) * (max_el/8 + 1);
  //a = (char *)malloc(bucket_size);
  //memset(a, 0, bucket_size);
  //for (int i = 0; i < numsSize; i++) {
    //int byte_idx = nums[i] / 8, bit_idx = nums[i] % 8;
    //a[byte_idx] |= 1 << bit_idx;
  //}
//
  //int diff = 0, prev = -1;
//
  //for (int i = min_el; i <= max_el; i++) {
    //int byte_idx = i / 8, bit_idx = i % 8;
//
    //if (a[byte_idx] == 0) {
      //i += 7;
    //} else if (a[byte_idx] & (1 << bit_idx)) {
      //if (prev >= 0) {
        //int tmp = i - prev;
        //if (tmp > diff) diff = tmp;
      //}
//
      //prev = i;
    //}
  //}
//
  //return diff;
//}
//// #v3

//// #v4
//// queue, radix sort
//struct Node {
  //int v;
  //struct Node *prev, *next;
//};
//
//struct Node* new_node(int v) {
  //struct Node *n = (struct Node *)malloc(sizeof(struct Node));
  //n->v = v;
  //n->prev = n->next = n;
  //return n;
//}
//
//void add(struct Node *h, struct Node *n) {
  //n->prev = h->prev;
  //n->next = h;
  //h->prev->next = n;
  //h->prev = n;
//}
//
//void del(struct Node *h) {
  //h->prev->next = h->next;
  //h->next->prev = h->prev;
//}
//
//int maximumGap(int* nums, int numsSize) {
  //if (numsSize <= 1) return 0;
//
  //int ret = 0;
  //struct Node *x[10], *y[10], **a = x, **b = y;
//
  //for (int i = 0; i < 10; i++) {
    //a[i] = new_node(0);
    //b[i] = new_node(0);
  //}
//
  //for (int i = 0; i < numsSize; i++) {
    //struct Node *p = new_node(nums[i]);
    //add(a[nums[i] % 10], p);
  //}
//
  //long long weight = 10;
  //for (int j = 0; j < 10; j++) {
    //for (int i = 0; i < 10; i++) {
      //struct Node *p = a[i]->next, *tmp;
      //int t;
//
      //while (p != a[i]) {
        //tmp = p->next;
//
        //t = p->v / weight % 10;
        //del(p);
        //add(b[t], p);
//
        //p = tmp;
      //}
    //}
//
    //struct Node **tmp = a;
    //a = b;
    //b = tmp;
//
    //weight *= 10;
  //}
//
  //int prev = -1;
  //for (int i = 0; i < 10; i++) {
    //struct Node *p = a[i]->next;
//
    //while (p != a[i]) {
      //if (prev >= 0) {
        //int d = p->v - prev;
        //if (d > ret) ret = d;
      //}
//
      //prev = p->v;
      //p = p->next;
    //}
  //}
//
  //return ret;
//}
//// #v4

// #v5
// interval, bucket sort
struct Bucket {
  // 桶是否被使用
  int used;
  // 桶内最大值
  int max_val;
  // 桶内最小值
  int min_val;
};

int maximumGap(int* nums, int numsSize) {
  if (numsSize <= 1) return 0;

  int max_val = nums[0], min_val = nums[0];

  // find max value and min value
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] > max_val) max_val = nums[i];
    if (nums[i] < min_val) min_val = nums[i];
  }

  // 所有元素相等
  if (min_val == max_val) return 0;

  struct Bucket *buckets = malloc(numsSize * sizeof(struct Bucket));

  // init
  for (int i = 0; i < numsSize; i++) {
    buckets[i].used = 0;
    buckets[i].max_val = INT_MIN;
    buckets[i].min_val = INT_MAX;
  }

  // 计算桶的大小
  int bucket_size = (max_val - min_val) / numsSize + 1;

  // 根据 nums[i] 和 min_val 的距离将元素分配到桶中
  for (int i = 0; i < numsSize; i++) {
    int bucket_idx = (nums[i] - min_val) / bucket_size;
    buckets[bucket_idx].used = 1;
    if (nums[i] < buckets[bucket_idx].min_val) {
      buckets[bucket_idx].min_val = nums[i];
    }
    if (nums[i] > buckets[bucket_idx].max_val) {
      buckets[bucket_idx].max_val = nums[i];
    }
  }

  // 计算最大间隔, 第 1 个桶的最小值就是全局最小值
  int max_gap = 0, prev_max = min_val;

  for (int i = 0; i < numsSize; i++) {
    if (buckets[i].used) {
      // 当前桶的最小值 - 前一个桶的最大值
      int gap = buckets[i].min_val - prev_max;
      if (gap > max_gap) max_gap = gap;
      // update
      prev_max = buckets[i].max_val;
    }
  }

  free(buckets);

  return max_gap;
}
// #v5

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
  printf("%d\n", maximumGap(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
