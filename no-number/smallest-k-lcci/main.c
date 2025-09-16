#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 面试题 17.14. 最小K个数 - 设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数 均可。
//
// 示例：
//
// 输入： arr = [1,3,5,7,2,4,6,8], k = 4
// 输出： [1,2,3,4]
//
//
// 提示：
//
//  * 0 &lt;= len(arr) &lt;= 100000
//  * 0 &lt;= k &lt;= min(100000, len(arr))

//// #v1
//// 小根堆, 弹出 k 个
//int *h, size, tmp;
//
//void HeapSwap(int i, int j) {
  //tmp = h[i];
  //h[i] = h[j];
  //h[j] = tmp;
//}
//
//void HeapUp(int p) { // 向上调整
  //while (p > 1) {
    //if (h[p] < h[p>>1]) {
      //HeapSwap(p, p>>1);
      //p >>= 1;
    //} else {
      //return ;
    //}
  //}
//}
//
//void HeapDown(int p) { // 向下调整
  //int s = p << 1;
//
  //while (s <= size) {
    //if (s < size && h[s] > h[s+1]) s++;
    //if (h[s] < h[p]) {
      //HeapSwap(s, p);
      //p = s;
      //s <<= 1;
    //} else {
      //return ;
    //}
  //}
//}
//
//void HeapInsert(int v) {
  //h[++size] = v;
  //HeapUp(size);
//}
//
//void HeapExtract() {
  //h[1] = h[size--];
  //HeapDown(1);
//}
//
//int* smallestK(int* arr, int arrSize, int k, int* returnSize) {
  //*returnSize = k;
  //int *ret, retLen = 0, i;
  //ret = (int *)malloc(sizeof(int) * k);
//
  //// heap init
  //h = (int *)malloc(sizeof(int) * (arrSize + 1));
  //size = 0;
//
  //for (i = 0; i < arrSize; i++) {
    //HeapInsert(arr[i]);
  //}
//
  //while (retLen != k) {
    //ret[retLen++] = h[1];
    //HeapExtract();
  //}
//
  //free(h);
//
  //return ret;
//}
//// #v1

//// #v2
//// 排序
//int iCmp(const void *a, const void *b) {
  //return *(int *)a - *(int *)b;
//}
//
//int* smallestK(int* arr, int arrSize, int k, int* returnSize) {
  //*returnSize = k;
  //int *ret, retLen = 0, i = 0;
  //ret = (int *)malloc(sizeof(int) * k);
//
  //qsort(arr, arrSize, sizeof(int), iCmp);
//
  //while (retLen != k)
    //ret[retLen++] = arr[i++];
//
  //return ret;
//}
//// #v2

// #v3
// 利用快速排序的思想, 只要第 k 小的数在 k-1 位置上, 那么 arr[0..k-1] 就是最小的
// k 个数
void swap(int *a, int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

int partition(int *a, int n) {
  int end = n - 1, val = a[end], s = 0;
  for (int i = 0; i < end; i++) {
    if (a[i] <= val) {
      swap(a, i, s);
      ++s;
    }
  }

  //swap(a, s, end);
  a[end] = a[s];
  a[s] = val;

  return s;
}

//void quicksort(int *a, int n) {
//  if (n <= 1) return ;
//
//  int q = partition(a, n);
//  if (q > 1)
//  quicksort(a, q);
//  if (n - q - 1 > 1)
//    quicksort(a + q + 1, n - q - 1);
//}

int selectK(int *a, int n, int k) {
  if (n <= 0 ) return 0;
  if (n == 1) return a[0];

  int q = partition(a, n);
  if (q == k) {
    return a[q];
  } else if (q < k) {
    int t = q + 1;
    return selectK(a + t, n - t, k - t);
  }
  return selectK(a, q, k);
}

int* smallestK(int* arr, int arrSize, int k, int* returnSize) {
  *returnSize = k;
  int *ret, retLen = 0, i;
  ret = (int *)malloc(sizeof(int) * k);

  selectK(arr, arrSize, k - 1);

  for (i = 0; i < k; i++) ret[retLen++] = arr[i];

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
  ret = smallestK(a, n, k, &s);
  print_1d_arr(ret, s);
  free(a);
  free(ret);
  //kk = k - 1;
  //quicksort(a, n);
  //printf("%d\n", selectK(a, n));
  //print_1d_arr(a, n);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
