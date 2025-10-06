#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2208. 将数组和减半的最少操作次数 - 给你一个正整数数组 nums 。每一次操作中， 你可以从 nums 中选择 任意 一个数并将它减小到 恰好 一半。（注意，在后续操作中你可 以对减半过的数继续执行操作）
// 请你返回将 nums 数组和 至少 减少一半的 最少 操作数。
//  
// 示例 1：
// 输入：nums = [5,19,8,1]
// 输出：3
// 解释：初始 nums 的和为 5 + 19 + 8 + 1 = 33 。
// 以下是将数组和减少至少一半的一种方法：
// 选择数字 19 并减小为 9.5 。
// 选择数字 9.5 并减小为 4.75 。
// 选择数字 8 并减小为 4 。
// 最终数组为 [5, 4.75, 4, 1] ，和为 5 + 4.75 + 4 + 1 = 14.75 。
// nums 的和减小了 33 - 14.75 = 18.25 ，减小的部分超过了初始数组和的一半，18.25 &gt;= 33/2 = 16.5 。
// 我们需要 3 个操作实现题目要求，所以返回 3 。
// 可以证明，无法通过少于 3 个操作使数组和减少至少一半。
// 示例 2：
// 输入：nums = [3,8,20]
// 输出：3
// 解释：初始 nums 的和为 3 + 8 + 20 = 31 。
// 以下是将数组和减少至少一半的一种方法：
// 选择数字 20 并减小为 10 。
// 选择数字 10 并减小为 5 。
// 选择数字 3 并减小为 1.5 。
// 最终数组为 [1.5, 8, 5] ，和为 1.5 + 8 + 5 = 14.5 。
// nums 的和减小了 31 - 14.5 = 16.5 ，减小的部分超过了初始数组和的一半， 16.5 &gt;= 31/2 = 15.5 。
// 我们需要 3 个操作实现题目要求，所以返回 3 。
// 可以证明，无法通过少于 3 个操作使数组和减少至少一半。
//  
// 提示：
//  * 1 <= nums.length <= 10^5
//  * 1 <= nums[i] <= 10^7

// #v1
int size;
double *h;

void HeapSwap(int i, int j) {
  double t = h[i];
  h[i] = h[j];
  h[j] = t;
}

void HeapUp(int p) {
  while (p > 1) {
    if (h[p] > h[p>>1]) {
      HeapSwap(p, p>>1);
      p >>= 1;
    } else {
      return ;
    }
  }
}

void HeapDown(int p) {
  int s = p << 1;

  while (s <= size) {
    if (s < size && h[s] < h[s+1]) s++;
    if (h[s] > h[p]) {
      HeapSwap(s, p);
      p = s;
      s <<= 1;
    } else {
      return ;
    }
  }
}

void HeapInsert(double v) {
  h[++size] = v;
  HeapUp(size);
}

void HeapExtract() {
  h[1] = h[size--];
  HeapDown(1);
}

int halveArray(int* nums, int numsSize) {
  double sum = 0, halveSum, t, heap[numsSize + 1];
  int i, ret = 0;

  h = heap;
  size = 0;

  for (i = 0; i < numsSize; i++) {
    HeapInsert(nums[i]);
    sum += nums[i];
  }

  halveSum = sum / 2.0;

  while (sum > halveSum) {
    t = h[1] / 2.0;
    sum -= t;
    HeapExtract();
    HeapInsert(t);
    ++ret;
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
  printf("%d\n", halveArray(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
