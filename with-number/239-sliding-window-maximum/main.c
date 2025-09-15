#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 239. 滑 动窗口最大值 - 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
// 返回 滑动窗口中的最大值 。
//  
// 示例 1：
// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]
// 解释：
// 滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// 示例 2：
// 输入：nums = [1], k = 1
// 输出：[1]
//  
// 提示：
//  * 1 <= nums.length <= 10^5
//  * -10^4 <= nums[i] <= 10^4
//  * 1 <= k <= nums.length

//// #v1
//// 大根堆
//struct HeapEl {
  //int val, idx;
//};
//
//struct MaxHeap {
  //struct HeapEl **a;
  //int size, capacity;
//};
//
//struct HeapEl* NewHeapEl(int val, int idx) {
  //struct HeapEl *ret = (struct HeapEl *)malloc(sizeof(struct HeapEl));
  //ret->val = val;
  //ret->idx = idx;
  //return ret;
//}
//
//struct MaxHeap* NewHeap(int capacity) {
  //struct MaxHeap *ret = (struct MaxHeap *)malloc(sizeof(struct MaxHeap));
//
  //ret->a = (struct HeapEl **)malloc(sizeof(struct HeapEl *) * capacity);
  //ret->size = 0;
  //ret->capacity = capacity;
//
  //return ret;
//}
//
//void HeapSwap(struct MaxHeap *h, int i, int j) {
  //struct HeapEl *t = h->a[i];
  //h->a[i] = h->a[j];
  //h->a[j] = t;
//}
//
//void HeapUp(struct MaxHeap *h, int p) { // 向上调整
  //while (p > 1) {
    //if (h->a[p]->val > h->a[p>>1]->val) { // 子节点 > 父节点, 不满足大根堆性质
      //HeapSwap(h, p, p>>1);
      //p >>= 1; // 向上
    //} else {
      //break;
    //}
  //}
//}
//
//void HeapDown(struct MaxHeap *h, int p) { // 向下调整
  //int s = p << 1; // p 的左子节点
  //int n = h->size;
//
  //while (s <= n) {
    //if (s < n && h->a[s]->val < h->a[s+1]->val) s++; //左右子节点取较大
    //if (h->a[s]->val > h->a[p]->val) { // 子节点 > 父节点
      //HeapSwap(h, s, p);
//
      //// 向下
      //p = s;
      //s = p<<1;
    //} else {
      //break;
    //}
  //}
//}
//
//void HeapInsert(struct MaxHeap *h, int val, int idx) {
  //// 插入
  //struct HeapEl *v = NewHeapEl(val, idx);
  //++(h->size);
  //h->a[h->size] = v;
//
  //// 调整
  //HeapUp(h, h->size);
//}
//
//struct HeapEl* HeapTop(struct MaxHeap *h) {
  //return h->a[1];
//}
//
//// 移除大根堆顶部元素
//void HeapExtract(struct MaxHeap *h) {
  //// 移除
  //struct HeapEl *t = h->a[1];
  //h->a[1] = h->a[h->size];
  //--(h->size);
  //free(t);
//
  //// 调整
  //HeapDown(h, 1);
//}
//
//// 释放内存
//void DestroyHeap(struct MaxHeap *h) {
  //if (!h) return ;
  //for (int i = 1; i <= h->size; i++) {
    //free(h->a[i]);
  //}
  //free(h->a);
  //free(h);
//}
//
//int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
  //*returnSize = numsSize - k + 1;
  //int l, r, *ret, retLen = 0;
  //ret = (int *)malloc(sizeof(int) * (*returnSize));
  //struct MaxHeap *h = NewHeap(numsSize + 1);
//
  //// 第一个窗口
  //for (int i = 0; i < k; i++) HeapInsert(h, nums[i], i);
  //ret[retLen++] = HeapTop(h)->val;
//
  //l = 1;
  //r = k;
  //while (r < numsSize) {
    //// 插入窗口最右端元素
    //HeapInsert(h, nums[r], r);
//
    //// 弹出不在窗口内的元素
    //while (HeapTop(h)->idx < l) {
      //HeapExtract(h);
    //}
//
    //// 取大根堆的顶部即为当前窗口最大值
    //ret[retLen++] = HeapTop(h)->val;
//
    //// 更新窗口
    //++l;
    //++r;
  //}
//
  //DestroyHeap(h);
//
  //return ret;
//}
//// #v1

//// #v2
//// 大根堆
//struct MaxHeap {
  //int *val, *idx;
  //int size, capacity;
//};
//
//struct MaxHeap* NewHeap(int capacity) {
  //struct MaxHeap *ret = (struct MaxHeap *)malloc(sizeof(struct MaxHeap));
//
  //ret->val = (int *)malloc(sizeof(int) * capacity);
  //ret->idx = (int *)malloc(sizeof(int) * capacity);
  //ret->size = 0;
  //ret->capacity = capacity;
//
  //return ret;
//}
//
//void HeapSwap(struct MaxHeap *h, int i, int j) {
  //int t = h->val[i];
  //h->val[i] = h->val[j];
  //h->val[j] = t;
  //t = h->idx[i];
  //h->idx[i] = h->idx[j];
  //h->idx[j] = t;
//}
//
//void HeapUp(struct MaxHeap *h, int p) { // 向上调整
  //while (p > 1) {
    //if (h->val[p] > h->val[p>>1]) { // 子节点 > 父节点, 不满足大根堆性质
      //HeapSwap(h, p, p>>1);
      //p >>= 1; // 向上
    //} else {
      //break;
    //}
  //}
//}
//
//void HeapDown(struct MaxHeap *h, int p) { // 向下调整
  //int s = p << 1; // p 的左子节点
  //int n = h->size;
//
  //while (s <= n) {
    //if (s < n && h->val[s] < h->val[s+1]) s++; //左右子节点取较大
    //if (h->val[s] > h->val[p]) { // 子节点 > 父节点
      //HeapSwap(h, s, p);
//
      //// 向下
      //p = s;
      //s = p<<1;
    //} else {
      //break;
    //}
  //}
//}
//
//void HeapInsert(struct MaxHeap *h, int val, int idx) {
  //// 插入
  //++(h->size);
  //h->val[h->size] = val;
  //h->idx[h->size] = idx;
//
  //// 调整
  //HeapUp(h, h->size);
//}
//
//// 移除大根堆顶部元素
//void HeapExtract(struct MaxHeap *h) {
  //// 移除
  //h->val[1] = h->val[h->size];
  //h->idx[1] = h->idx[h->size];
  //--(h->size);
//
  //// 调整
  //HeapDown(h, 1);
//}
//
//// 释放内存
//void DestroyHeap(struct MaxHeap *h) {
  //if (!h) return ;
  //free(h->val);
  //free(h->idx);
  //free(h);
//}
//
//int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
  //*returnSize = numsSize - k + 1;
  //int l, r, *ret, retLen = 0;
  //ret = (int *)malloc(sizeof(int) * (*returnSize));
  //struct MaxHeap *h = NewHeap(numsSize + 1);
//
  //// 第一个窗口
  //for (int i = 0; i < k; i++) HeapInsert(h, nums[i], i);
  //ret[retLen++] = h->val[1];
//
  //l = 1;
  //r = k;
  //while (r < numsSize) {
    //// 插入窗口最右端元素
    //HeapInsert(h, nums[r], r);
//
    //// 弹出不在窗口内的元素
    //while (h->idx[1] < l) {
      //HeapExtract(h);
    //}
//
    //// 取大根堆的顶部即为当前窗口最大值
    //ret[retLen++] = h->val[1];
//
    //while (h->idx[1] < l) {
      //HeapExtract(h);
    //}
//
    //// 更新窗口
    //++l;
    //++r;
  //}
//
  //DestroyHeap(h);
//
  //return ret;
//}
//// #v2

// #v3
// 大根堆
int *val, *idx, size, tmp;

void HeapSwap(int i, int j) {
  tmp = val[i];
  val[i] = val[j];
  val[j] = tmp;

  tmp = idx[i];
  idx[i] = idx[j];
  idx[j] = tmp;
}

void HeapUp(int p) { // 向上调整
  while (p > 1) {
    if (val[p] > val[p>>1]) { // 子节点 > 父节点, 不满足大根堆性质
      HeapSwap(p, p>>1);
      p >>= 1; // 向上
    } else {
      return ;
    }
  }
}

void HeapDown(int p) { // 向下调整
  int s = p << 1; // p 的左子节点

  while (s <= size) {
    if (s < size && val[s] < val[s+1]) s++; //左右子节点取较大

    if (val[s] > val[p]) { // 子节点 > 父节点
      HeapSwap(s, p);

      // 向下
      p = s;
      s <<= 1;
    } else {
      return ;
    }
  }
}

void HeapInsert(int v, int i) {
  // 插入
  ++size;
  val[size] = v;
  idx[size] = i;

  // 调整
  HeapUp(size);
}

// 移除大根堆顶部元素
void HeapExtract() {
  // 移除
  val[1] = val[size];
  idx[1] = idx[size];
  --size;

  // 调整
  HeapDown(1);
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
  *returnSize = numsSize - k + 1;
  int l, r, *ret, retLen = 0;
  ret = (int *)malloc(sizeof(int) * (*returnSize));

  // heap init
  val = (int *)malloc(sizeof(int) * (numsSize + 1));
  idx = (int *)malloc(sizeof(int) * (numsSize + 1));
  size = 0;

  // 第一个窗口
  for (int i = 0; i < k; i++) HeapInsert(nums[i], i);
  ret[retLen++] = val[1];

  l = 1;
  r = k;
  while (r < numsSize) {
    // 插入窗口最右端元素
    HeapInsert(nums[r], r);

    // 弹出不在窗口内的元素
    while (idx[1] < l) {
      HeapExtract();
    }

    // 取大根堆的顶部即为当前窗口最大值
    ret[retLen++] = val[1];

    // 更新窗口
    ++l;
    ++r;
  }

  return ret;
}
// #v3

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
  int n, *a, *ret, s, k;
  scanf("%d", &n);
  a = read_1d_arr(n);
  scanf("%d", &k);

  ret = maxSlidingWindow(a, n, k, &s);
  print_1d_arr(ret, s);
  free(ret);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
