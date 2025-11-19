#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 373. 查找和最小的 K 对数字 - 给定两个以 非递减顺序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。
// 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。
// 请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
//  
// 示例 1:
// 输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// 输出: [1,2],[1,4],[1,6]
// 解释: 返回序列中的前 3 对数：
//      [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
// 示例 2:
// 输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// 输出: [1,1],[1,1]
// 解释: 返回序列中的前 2 对数：
//      [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
//  
// 提示:
//  * 1 <= nums1.length, nums2.length <= 105
//  * -109 <= nums1[i], nums2[i] <= 109
//  * nums1 和 nums2 均为 升序排列
//  * 1 <= k <= 104
//  * k <= nums1.length * nums2.length

// #v1
// min heap, BFS
typedef struct Node {
  // v == nums1[i] + nums2[j], p1 == i, p2 == j
  int v, p1, p2;
} Node;

typedef struct Heap {
  Node **a;
  int c, size;
} Heap;

Heap* NewHeap(int c) {
  Heap *h = malloc(sizeof(Heap));
  h->size = 0;
  h->a    = malloc(c * sizeof(Node *));
  h->c    = c;
  for (int i = 0; i < c; i++) {
    h->a[i] = malloc(sizeof(Node));
  }
  return h;
}

void HeapSwap(Heap *h, int i, int j) {
  Node *t = h->a[i];
  h->a[i] = h->a[j];
  h->a[j] = t;
}

void HeapUp(Heap *h, int p) {
  while (p > 1) {
    if (h->a[p]->v < h->a[p>>1]->v) {
      HeapSwap(h, p, p>>1);
      p >>= 1;
    } else {
      return ;
    }
  }
}

void HeapDown(Heap *h, int p) {
  int s = p << 1;

  while (s <= h->size) {
    if (s < h->size && h->a[s]->v > h->a[s+1]->v) s++;
    if (h->a[s]->v < h->a[p]->v) {
      HeapSwap(h, s, p);
      p = s;
      s = p<<1;
    } else {
      return ;
    }
  }
}

void HeapInsert(Heap *h, int v, int i, int j) {
  h->a[++(h->size)]->v = v;
  h->a[h->size]->p1    = i;
  h->a[h->size]->p2    = j;
  HeapUp(h, h->size);
}

void HeapExtract(Heap *h) {
  // swap
  Node *tmp     = h->a[1];
  h->a[1]       = h->a[h->size];
  h->a[h->size] = tmp;

  --(h->size);
  HeapDown(h, 1);
}

void DelHeap(Heap *h) {
  for (int i = 0; i < h->c; i++) free(h->a[i]);
  free(h->a);
  free(h);
}

int** kSmallestPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k, int* returnSize, int** returnColumnSizes) {
  // (i, j) --> (i+1, j)/(i, j+1)
  *returnSize        = k;
  *returnColumnSizes = malloc(sizeof(int) * k);

  int **ret = malloc(sizeof(int *) * k), retLen = 0;
  Heap *h = NewHeap(nums1Size + 1);

  // allocate
  for (int i = 0; i < k; i++) {
    ret[i] = malloc(sizeof(int) * 2);
    (*returnColumnSizes)[i] = 2;
  }

  // init
  // 包含 nums1[i] 的所有数对中 (nums[i], nums2[0]) 最小
  // 包含 nums[i] 的其它数对可由最小数对逐步生成
  for (int i = 0; i < nums1Size; i++) {
    HeapInsert(h, nums1[i]+nums2[0], i, 0);
  }

  while (retLen < k) {
    // pick top of min heap
    Node *p = h->a[1];
    // write to return value
    ret[retLen][0]   = nums1[p->p1];
    ret[retLen++][1] = nums2[p->p2];
    // pop top from min heap
    HeapExtract(h);
    if (p->p2+1 < nums2Size)
      HeapInsert(h, nums1[p->p1]+nums2[p->p2+1], p->p1, p->p2+1);
  }

  DelHeap(h);

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

void print_2d_arr(int **arr, int rows, int *cols) {
  if (!arr || rows <= 0) {
    putchar('\n');
    return ;
  }
  int i, j;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols[i]; j++) {
      if (j) {
        putchar(' ');
      }
      printf("%d", arr[i][j]);
    }
    putchar('\n');
  }
}

int main(int argc, char *argv[])
{
  int *nums1, nums1Size, *nums2, nums2Size, k, **ret, returnSize, *returnColumnSizes;
  scanf("%d", &nums1Size);
  nums1 = read_1d_arr(nums1Size);
  scanf("%d", &nums2Size);
  nums2 = read_1d_arr(nums2Size);
  scanf("%d", &k);
  ret = kSmallestPairs(nums1, nums1Size, nums2, nums2Size, k, &returnSize, &returnColumnSizes);
  print_2d_arr(ret, returnSize, returnColumnSizes);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
