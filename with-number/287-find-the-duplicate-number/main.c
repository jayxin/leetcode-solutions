#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 287. 寻找重复数
// 给定一个包含 n + 1 个整数的数组 nums ，其数字都在 [1, n] 范围内（包括 1 和 n），可知至少存在一个重复的整数。

// 假设 nums 只有 一个重复的整数 ，返回 这个重复的数 。

// 你设计的解决方案必须 不修改 数组 nums 且只用常量级 O(1) 的额外空间。

//// #v1
//// 失败, 只能判断奇偶和处于 [2^k, 2^(k+1)-1]
//#define max(a, b) (a > b ? a : b)
//#define min(a, b) (a < b ? a : b)
//
//int table[32];
//
//void init_table(int start, int end) {
  //for (int i = start; i <= end; ++i) {
    //table[i] = 1 << i;
  //}
//}
//
//int count_bits(int n) {
  //int ret = 0;
  //while (n) {
    //ret++;
    //n >>= 1;
  //}
  //return ret;
//}
//
//int findDuplicate(int *nums, int numsSize) {
  //int n = numsSize - 1;
  //int i, min_el = nums[0], max_el = nums[0];
  //int even_cnt = 0;
//
  //for (i = 0; i < numsSize; ++i) {
    //min_el = min(min_el, nums[i]);
    //max_el = max(max_el, nums[i]);
    //if ((nums[i] & 1) == 0) {
      //even_cnt++;
    //}
  //}
  //if (min_el == max_el) {
    //return min_el;
  //}
  //if (even_cnt > n / 2) {
    //printf("even\n");
  //} else {
    //printf("odd\n");
  //}
//
  //int min_bits = count_bits(min_el),
      //max_bits = count_bits(max_el);
  //init_table(min_bits - 1, max_bits - 1);
  //table[max_bits - 1] -= (1 << max_bits) - 1 - max_el;
  //table[min_bits - 1] -= min_el - (1 << (min_bits - 1));
//
  //int index;
//
  //for (i = 0; i < numsSize; ++i) {
    //index = count_bits(nums[i]) - 1;
    //--table[index];
    //if (table[index] < 0) {
      //break;
    //}
  //}
  //printf("%d - %d\n", (1 << index), (1 << (index+1)) - 1);
  //int left = 1 << index,
      //right = (1 << (index+1)) - 1;
//
  //return 1;
//}
//// #v1

//// #v2
//// 超时
//#define max(a, b) (a > b ? a : b)
//#define min(a, b) (a < b ? a : b)
//
//int findDuplicate(int *nums, int numsSize) {
  //int n = numsSize - 1;
  //int i, j, min_el = nums[0], max_el = nums[0];
  //int even_cnt = 0, is_even = 0;
//
  //for (i = 0; i < numsSize; ++i) {
    //min_el = min(min_el, nums[i]);
    //max_el = max(max_el, nums[i]);
    //if ((nums[i] & 1) == 0) {
      //even_cnt++;
    //}
  //}
  //if (min_el == max_el) {
    //return min_el;
  //}
  //if (even_cnt > n / 2) {
    //is_even = 1;
  //}
//
  //for (i = 0; i < numsSize; ++i) {
    //if ((is_even && (nums[i] & 1)) || (!is_even && !(nums[i] & 1))) {
      //continue;
    //}
//
    //int cnt = 0;
    //for (j = 0; j < numsSize; ++j) {
      //if (nums[i] == nums[j]) {
        //cnt++;
      //}
      //if (cnt >= 2) {
        //return nums[i];
      //}
    //}
  //}
//
  //return nums[i];
//}
//// #v2

//// #v3
//// 超时
//#define max(a, b) (a > b ? a : b)
//#define min(a, b) (a < b ? a : b)
//
//int table[32];
//
//void init_table(int start, int end) {
  //for (int i = start; i <= end; ++i) {
    //table[i] = 1 << i;
  //}
//}
//
//int count_bits(int n) {
  //int ret = 0;
  //while (n) {
    //ret++;
    //n >>= 1;
  //}
  //return ret;
//}
//
//int findDuplicate(int *nums, int numsSize) {
  //int n = numsSize - 1;
  //int i, j, min_el = nums[0], max_el = nums[0];
  //int even_cnt = 0, is_even = 0;
//
  //for (i = 0; i < numsSize; ++i) {
    //min_el = min(min_el, nums[i]);
    //max_el = max(max_el, nums[i]);
    //if ((nums[i] & 1) == 0) {
      //even_cnt++;
    //}
  //}
  //if (min_el == max_el) {
    //return min_el;
  //}
  //if (even_cnt > n / 2) {
    //is_even = 1;
  //}
//
  //int min_bits = count_bits(min_el),
      //max_bits = count_bits(max_el);
  //init_table(min_bits - 1, max_bits - 1);
  //table[max_bits - 1] -= (1 << max_bits) - 1 - max_el;
  //table[min_bits - 1] -= min_el - (1 << (min_bits - 1));
//
  //int index;
//
  //for (i = 0; i < numsSize; ++i) {
    //index = count_bits(nums[i]) - 1;
    //--table[index];
    //if (table[index] < 0) {
      //break;
    //}
  //}
  //int left = 1 << index,
      //right = (1 << (index+1)) - 1;
//
  //for (i = 0; i < numsSize; ++i) {
    //if ((nums[i] < left) || (nums[i] > right) || (is_even && (nums[i] & 1)) || (!is_even && !(nums[i] & 1))) {
      //continue;
    //}
//
    //int cnt = 0;
    //for (j = 0; j < numsSize; ++j) {
      //if (nums[i] == nums[j]) {
        //cnt++;
      //}
      //if (cnt >= 2) {
        //return nums[i];
      //}
    //}
  //}
//
  //return nums[i];
//}
//// #v3

//// #v4
//// 超时
//#define max(a, b) (a > b ? a : b)
//#define min(a, b) (a < b ? a : b)
//
//int table[32];
//
//void init_table(int start, int end) {
  //for (int i = start; i <= end; ++i) {
    //table[i] = 1 << i;
  //}
//}
//
//int count_bits(int n) {
  //int ret = 0;
  //while (n) {
    //ret++;
    //n >>= 1;
  //}
  //return ret;
//}
//
//int findDuplicate(int *nums, int numsSize) {
  //int n = numsSize - 1;
  //int i, j, min_el = nums[0], max_el = nums[0];
  //int even_cnt = 0, is_even = 0;
//
  //for (i = 0; i < numsSize; ++i) {
    //min_el = min(min_el, nums[i]);
    //max_el = max(max_el, nums[i]);
    //if ((nums[i] & 1) == 0) {
      //even_cnt++;
    //}
  //}
  //if (min_el == max_el) {
    //return min_el;
  //}
  //if (even_cnt > n / 2) {
    //is_even = 1;
  //}
//
  //int min_bits = count_bits(min_el),
      //max_bits = count_bits(max_el);
  //init_table(min_bits - 1, max_bits - 1);
  //table[max_bits - 1] -= (1 << max_bits) - 1 - max_el;
  //table[min_bits - 1] -= min_el - (1 << (min_bits - 1));
//
  //int index;
//
  //for (i = 0; i < numsSize; ++i) {
    //index = count_bits(nums[i]) - 1;
    //--table[index];
    //if (table[index] < 0) {
      //break;
    //}
  //}
  //int left = 1 << index,
      //right = (1 << (index+1)) - 1;
//
  //i = left;
  //if (!is_even && left != 1) {
    //i = left + 1;
  //}
  //for (; i <= right; i += 2) {
    //int cnt = 0;
    //for (j = 0; j < numsSize; ++j) {
      //if (i == nums[j]) {
        //cnt++;
      //}
      //if (cnt >= 2) {
        //return i;
      //}
    //}
  //}
//
  //return i;
//}
//// #v4

//// #v5
//// 通过
//// 比较比特位 0 和 1 的个数
//// 构造目标
//#define max(a, b) (a > b ? a : b)
//#define min(a, b) (a < b ? a : b)
//
//// 1-n 各个比特位 0 的计数表
//int std_zero_count_table[32];
//// 1-n 各个比特位 1 的计数表
//int std_one_count_table[32];
//// nums 数组各个比特位 0 的计数表
//int zero_count_table[32];
//// nums 数组各个比特位 1 的计数表
//int one_count_table[32];
//
//int count_bits(int n) {
  //int ret = 0;
  //while (n) {
    //ret++;
    //n >>= 1;
  //}
  //return ret;
//}
//
//int findDuplicate(int *nums, int numsSize) {
  //int n = numsSize - 1, i, j;
//
  //memset(std_zero_count_table, 0, sizeof(int) * 32);
  //memset(std_one_count_table, 0, sizeof(int) * 32);
  //memset(zero_count_table, 0, sizeof(int) * 32);
  //memset(one_count_table, 0, sizeof(int) * 32);
//
  //int max_bits = count_bits(n);
  //int tmp;
//
  //for (i = 0; i < max_bits; i++) {
    //for (j = 1; j <= n; j++) {
      //tmp = j >> i;
      //if ((tmp & 1) == 0) {
        //std_zero_count_table[i]++;
      //} else {
        //std_one_count_table[i]++;
      //}
//
      //tmp = nums[j-1] >> i;
      //if ((tmp & 1) == 0) {
        //zero_count_table[i]++;
      //} else {
        //one_count_table[i]++;
      //}
    //}
  //}
//
  //for (i = 0; i < max_bits; i++) {
    //for (j = n; j < numsSize; j++) {
      //tmp = nums[j] >> i;
      //if ((tmp & 1) == 0) {
        //zero_count_table[i]++;
      //} else {
        //one_count_table[i]++;
      //}
    //}
  //}
//
  //int ret = 0;
  //int weight = 1;
  //for (i = 0; i < max_bits; i++) {
    //if (one_count_table[i] > zero_count_table[i] || zero_count_table[i] == std_zero_count_table[i] || one_count_table[i] > std_one_count_table[i]) {
      //ret += weight;
    //}
    //weight = weight << 1;
  //}
//
  //return ret;
//}
//// #v5

//// #v6
//// 通过
//// 比较比特位 0 和 1 的个数
//// 构造目标
//#define max(a, b) (a > b ? a : b)
//#define min(a, b) (a < b ? a : b)
//
//// 1-n 各个比特位 0 的计数表
//int std_zero_count_table[32];
//// 1-n 各个比特位 1 的计数表
//int std_one_count_table[32];
//// nums 数组各个比特位 0 的计数表
//int zero_count_table[32];
//// nums 数组各个比特位 1 的计数表
//int one_count_table[32];
//
//int count_bits(int n) {
  //int ret = 0;
  //while (n) {
    //ret++;
    //n >>= 1;
  //}
  //return ret;
//}
//
//int findDuplicate(int *nums, int numsSize) {
  //int n = numsSize - 1, i, j;
//
  //memset(std_zero_count_table, 0, sizeof(int) * 30);
  //memset(std_one_count_table, 0, sizeof(int) * 30);
  //memset(zero_count_table, 0, sizeof(int) * 30);
  //memset(one_count_table, 0, sizeof(int) * 30);
//
  //int max_bits = count_bits(n);
  //int tmp;
//
  //// 统计 1-n 和 nums[0..numsSize-1]
  //for (i = 0; i < max_bits; i++) {
    //for (j = 1; j <= n; j++) {
      //tmp = j >> i;
      //if ((tmp & 1) == 0) {
        //std_zero_count_table[i]++;
      //}
//
      //tmp = nums[j-1] >> i;
      //if ((tmp & 1) == 0) {
        //zero_count_table[i]++;
      //}
    //}
//
    //std_one_count_table[i] = n - std_zero_count_table[i];
  //}
//
  //// 统计 nums[n] 即最后一个元素
  //for (i = 0; i < max_bits; i++) {
    //tmp = nums[n] >> i;
//
    //if ((tmp & 1) == 0) {
      //zero_count_table[i]++;
    //}
//
    //one_count_table[i] = n + 1 - zero_count_table[i];
  //}
//
  //int ret = 0;
  //int weight = 1;
  //for (i = 0; i < max_bits; i++) {
    ////if (one_count_table[i] > zero_count_table[i] || zero_count_table[i] == std_zero_count_table[i] || one_count_table[i] > std_one_count_table[i]) {
    ////  ret += weight;
    ////}
    //if (one_count_table[i] > zero_count_table[i] || one_count_table[i] > std_one_count_table[i]) {
      //ret += weight;
    //}
    //weight = weight << 1;
  //}
//
  //return ret;
//}
//// #v6

// #v7
// 通过
// 比较比特位 0 和 1 的个数
// 构造目标
// 删除了使用表记录
int count_bits(int n) {
  int ret = 0;
  while (n) {
    ret++;
    n >>= 1;
  }
  return ret;
}

int findDuplicate(int *nums, int numsSize) {
  int n = numsSize - 1, i, j;
  int ret = 0;
  int max_bits = count_bits(n);
  int std_ones, ones;

  // 统计 1-n 和 nums[0..numsSize-1]
  for (i = 0; i < max_bits; i++) {
    std_ones = ones = 0;

    for (j = 0; j < numsSize; j++) {
      if (j >= 1 && ((j >> i) & 1)) {
        std_ones += 1;
      }
      if ((nums[j] >> i) & 1) {
        ones += 1;
      }
    }
    if (ones > std_ones) {
      ret += 1 << i;
    }
  }

  return ret;
}
// #v7

int main(int argc, char *argv[])
{
  int n;
  int *arr;
  scanf("%d", &n);
  arr = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
  }
  printf("%d\n", findDuplicate(arr, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
