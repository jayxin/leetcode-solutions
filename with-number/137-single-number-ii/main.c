#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 137. 只出现一次的数字 II
// 给你一个整数数组 nums ，除某个元素仅出现 一次 外，
// 其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

// 你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。

//  1 <= nums.length <= 3 * 104
//  -231 <= nums[i] <= 231 - 1
//  nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次

//// #v1
//int singleNumber(int *nums, int numsSize) {
  //int i, j, index = 0, odd_cnt = 0, is_odd = 0, ret = 0, r = 0;
  //for (i = 0; i < numsSize; i++) {
    //r += nums[i] % 3;
    //if (nums[i] & 1) {
      //odd_cnt++;
    //}
  //}
  //r %= 3;
  //if (r < 0) { // negative
    //r = (r + 3) % 3;
  //}
//
  //if (odd_cnt % 3) {
    //is_odd = 1;
  //}
//
  //for (i = 0; i < numsSize; i++) {
    //if (is_odd && !(nums[i] & 1)) {
      //continue;
    //}
    //if (!is_odd && (nums[i] & 1)) {
      //continue;
    //}
    //if ((nums[i] % 3 + 3) % 3 != r) { // consider negative numbers
      //continue;
    //}
//
    //int cnt = 0;
    //for (j = 0; j < index; j++) {
      //if (nums[j] == nums[i]) {
        //cnt++;
      //}
    //}
    //if (cnt == 1 || cnt == 0) {
      //ret ^= nums[i];
      //nums[index] = nums[i];
      //index++;
    //}
  //}
//
  //return ret;
//}
//// #v1

// #v2
// bit operations
int singleNumber(int *nums, int numsSize) {
  // a_i b_i
  // 0 0
  // 0 1
  // 1 0
  int i, a = 0, b = 0;
  for (i = 0; i < numsSize; i++) {
    b = ~a & (b ^ nums[i]);
    a = ~b & (a ^ nums[i]);
  }
  return b;
}
// #v2

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  int *arr = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", arr + i);
  }
  printf("%d\n", singleNumber(arr, n));
  free(arr);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
