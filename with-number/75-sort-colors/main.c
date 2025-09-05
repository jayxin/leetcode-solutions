#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 75. 颜色分类 - 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地 [https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95] 对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
// 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
// 必须在不使用库内置的 sort 函数的情况下解决这个问题。
//  
// 示例 1：
// 输入：nums = [2,0,2,1,1,0]
// 输出：[0,0,1,1,2,2]
// 示例 2：
// 输入：nums = [2,0,1]
// 输出：[0,1,2]
//  
// 提示：
//  * n == nums.length
//  * 1 <= n <= 300
//  * nums[i] 为 0、1 或 2
//  
// 进阶：
//  * 你能想出一个仅使用常数空间的一趟扫描算法吗？

//// #v1
//void sortColors(int* nums, int numsSize) {
  //int zero_cnt = 0, one_cnt = 0, i;
  //for (i = 0; i < numsSize; i++) {
    //switch (nums[i]) {
      //case 0:
        //zero_cnt++;
        //break;
      //case 1:
        //one_cnt++;
        //break;
    //}
  //}
  //for (i = 0; i < zero_cnt; i++) {
    //nums[i] = 0;
  //}
  //one_cnt += zero_cnt;
  //for (; i < one_cnt; i++) {
    //nums[i] = 1;
  //}
  //for (; i < numsSize; i++) {
    //nums[i] = 2;
  //}
//}
//// #v1

// #v2
void swap(int *nums, int i, int j) {
  int tmp = nums[i];
  nums[i] = nums[j];
  nums[j] = tmp;
}

void sortColors(int* nums, int numsSize) {
  // zero 表示 0 的右边界
  // one 表示 1 的右边界
  // two 表示 2 的左边界
  int zero = 0, one = 0, two = numsSize - 1;
  while (one <= two) {
    if (nums[one] == 0) { // 0
      swap(nums, zero, one);
      zero++;
      one++;
    } else if (nums[one] == 2) { // 2
      swap(nums, one, two);
      two--;
    } else { // 1
      one++;
    }
  }
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

// free 1d array
void free_1d_arr(int *arr) {
  if (!arr) {
    return;
  }
  free(arr);
}

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  sortColors(arr, n);
  print_1d_arr(arr, n);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
