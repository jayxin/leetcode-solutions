#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2032. 至少在两个数组中出现的值 - 给你三个整数数组 nums1、nums2 和 nums3 ，请你构造并返回一个 元素各不相同的 数组，且由 至少 在 两个 数组中出现的所有值组成。数 组中的元素可以按 任意 顺序排列。
//  
// 示例 1：
// 输入：nums2 = [1,1,3,2], nums2 = [2,3], nums3 = [3]
// 输出：[3,2]
// 解释：至少在两个数组中出现的所有值为：
// - 3 ，在全部三个数组中都出现过。
// - 2 ，在数组 nums1 和 nums2 中出现过。
// 示例 2：
// 输入：nums1 = [3,1], nums2 = [2,3], nums3 = [1,2]
// 输出：[2,3,1]
// 解释：至少在两个数组中出现的所有值为：
// - 2 ，在数组 nums2 和 nums3 中出现过。
// - 3 ，在数组 nums1 和 nums2 中出现过。
// - 1 ，在数组 nums1 和 nums3 中出现过。
// 示例 3：
// 输入：nums1 = [1,2,2], nums2 = [4,3,3], nums3 = [5]
// 输出：[]
// 解释：不存在至少在两个数组中出现的值。
//  
// 提示：
//  * 1 &lt;= nums1.length, nums2.length, nums3.length &lt;= 100
//  * 1 &lt;= nums1[i], nums2[j], nums3[k] &lt;= 100

// #v1
int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {
  int h[101] = {0};
  int *ret = (int *)malloc(sizeof(int) * (nums1Size + nums2Size + nums3Size));
  int i, retLen = 0;

  for (i = 0; i < nums1Size; i++) h[nums1[i]] = 1;

  for (i = 0; i < nums2Size; i++) {
    if (h[nums2[i]] == 1) h[nums2[i]] = 2;
    else if (h[nums2[i]] == 0) h[nums2[i]] = -1;
  }

  for (i = 0; i < nums3Size; i++) {
    if (h[nums3[i]] == 1 || h[nums3[i]] == 2) {
      ++h[nums3[i]];
    } else if (h[nums3[i]] == -1) {
      h[nums3[i]] = 2;
    }
  }

  for (i = 1; i <= 100; i++) {
    if (h[i] >= 2) {
      ret[retLen++] = i;
    }
  }

  *returnSize = retLen;

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
  int n1, n2, n3, *a1, *a2, *a3, *ret, s;
  scanf("%d", &n1);
  a1 = read_1d_arr(n1);
  scanf("%d", &n2);
  a2 = read_1d_arr(n2);
  scanf("%d", &n3);
  a3 = read_1d_arr(n3);
  ret = twoOutOfThree(a1, n1, a2, n2, a3, n3, &s);
  print_1d_arr(ret, s);
  free(a1);
  free(a2);
  free(a3);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
