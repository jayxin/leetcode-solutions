#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// #v1
// 大根堆, 弹出 2 个
int *h, size, tmp;

void HeapSwap(int i, int j) {
  tmp = h[i];
  h[i] = h[j];
  h[j] = tmp;
}

void HeapUp(int p) { // 向上调整
  while (p > 1) {
    if (h[p] > h[p>>1]) {
      HeapSwap(p, p>>1);
      p >>= 1;
    } else {
      return ;
    }
  }
}

void HeapDown(int p) { // 向下调整
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

void HeapInsert(int v) {
  h[++size] = v;
  HeapUp(size);
}

void HeapExtract() {
  h[1] = h[size--];
  HeapDown(1);
}

int findKthLargest(int* nums, int numsSize, int k) {
  int t[numsSize+1];
  h = t;
  size = 0;

  for (int i = 0; i < numsSize; i++) {
    HeapInsert(nums[i]);
  }

  while (--k) {
    HeapExtract();
  }

  return h[1];
}
int thirdMax(int* nums, int numsSize) {
  int t[numsSize+1], k = 0, prev, max;
  // heap init
  h = t;
  size = 0;

  for (int i = 0; i < numsSize; i++) HeapInsert(nums[i]);
  max = h[1];

  // init, 第 1 次弹出
  prev = h[1];
  HeapExtract();
  k++;

  while (size && k != 3) {
    // 弹出和之前相等的
    while (size && h[1] == prev) {
      HeapExtract();
    }

    // 元素不够
    if (size == 0) break;

    prev = h[1];
    ++k;
  }

  // 元素不够, 返回最大值
  if (size <= 0) return max;

  return prev;
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
  printf("%d\n", thirdMax(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
