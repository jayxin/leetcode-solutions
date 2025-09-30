#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 80. 删除有序数组中的重复项 II - 给你一个有序数组 nums ，请你 原地 [http://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95] 删除重复出现的元素，使得出 现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
// 不要使用额外的数组空间，你必须在 原地 [https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95]修改输入数组 并在使用 O(1) 额外空间的条件下完成。
//  
// 说明：
// 为什么返回数值是整数，但输出的答案是数组呢？
// 请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是 可见的。
// 你可以想象内部操作如下:
// // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
// int len = removeDuplicates(nums);
// // 在函数里修改输入数组对于调用者是可见的。
// // 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
// for (int i = 0; i &lt; len; i++) {
//     print(nums[i]);
// }
//  
// 示例 1：
// 输入：nums = [1,1,1,2,2,3]
// 输出：5, nums = [1,1,2,2,3]
// 解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。
// 示例 2：
// 输入：nums = [0,0,1,1,1,1,2,3,3]
// 输出：7, nums = [0,0,1,1,2,3,3]
// 解释：函数应返回新长度 length = 7, 并且原数组的前七个元素被修改为 0, 0, 1, 1, 2, 3, 3。不需要考虑数组中超出新长度后面的元素。
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 3 * 104
//  * -104 &lt;= nums[i] &lt;= 104
//  * nums 已按升序排列

// #v1
int removeDuplicates(int* nums, int numsSize) {
  int l = 0, cur = nums[0], cnt = 1, i = 1;

  while (i < numsSize) {
    if (nums[i] == cur) {
      ++cnt;
    } else {
      cnt = 1;
      cur = nums[i];
    }

    // 保留不重复的
    if (cnt <= 2) {
      ++l;
      nums[l] = nums[i];
    }

    ++i;
  }

  return l + 1;
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
  int n, *a, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  s = removeDuplicates(a, n);
  printf("%d\n", s);
  print_1d_arr(a, s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
