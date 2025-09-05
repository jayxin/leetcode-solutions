#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 31. 下一个排 列 - 整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。
//  * 例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
// 整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。更正式地，如果数组的所 有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 就是在这个有 序容器中排在它后面的那个排列。如果不存在下一个更大的排列，那么这个数组必须重排为 字典序最小的排列（即，其元素按升序排列）。
//  * 例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
//  * 类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
//  * 而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的 排列。
// 给你一个整数数组 nums ，找出 nums 的下一个排列。
// 必须 原地 [https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95]修改，只允许使用额外常数空间。
//  
// 示例 1：
// 输入：nums = [1,2,3]
// 输出：[1,3,2]
// 示例 2：
// 输入：nums = [3,2,1]
// 输出：[1,2,3]
// 示例 3：
// 输入：nums = [1,1,5]
// 输出：[1,5,1]
//  
// 提示：
//  * 1 <= nums.length <= 100
//  * 0 <= nums[i] <= 100

// #v1
void swap(int *a, int i, int j) {
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

void nextPermutation(int* nums, int numsSize) {
  if (numsSize <= 1) return ;

  int end = numsSize - 1, l, r;
  l = end - 1;

  // left
  // 寻找 小-大 模式
  while (l >= 0) {
    r  = end; // 每次从最后一个元素开始找
    while (l < r && nums[l] >= nums[r]) { // 注意这里的条件, r 要在 l 右边, 等号可取
      r--;
    }

    if (r == l) { // 在 nums[l] 的右边没有找到比 nums[l] 更小的
      l--;
    } else { // 找到更小的
      swap(nums, l, r);
      break; // 跳出循环, 切换方向
    }
  }

  l++;
  //if (l >= 0) { // 发生了交换, 进行交换的不是第一个元素
  //  l++;
  //} else { // 没有发生交换, 这里 l == -1, 假想在 nums[0] 之前发生了交换
  //  l = 0;
  //}

  // right
  // 寻找 大-小 模式
  while (l < end) { // 一直交换, 直到到达数组末尾
    r  = end; // 每次从最后一个元素开始找
    while (l < r && nums[l] <= nums[r]) { // 注意此处条件
      r--;
    }

    swap(nums, l, r);
    l++;
  }
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
  nextPermutation(arr, n);
  print_1d_arr(arr, n);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
