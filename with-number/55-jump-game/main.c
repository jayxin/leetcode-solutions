#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 55. 跳跃游戏 - 给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你 在该位置可以跳跃的最大长度。
// 判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。
//  
// 示例 1：
// 输入：nums = [2,3,1,1,4]
// 输出：true
// 解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标 。
// 示例 2：
// 输入：nums = [3,2,1,0,4]
// 输出：false
// 解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 104
//  * 0 &lt;= nums[i] &lt;= 105

//// #v1
//// 动态规划
//bool canJump(int* nums, int numsSize) {
  //if (numsSize == 1) return true;
//
  //int cur = -1, max, i, end = numsSize - 1, j;
  //bool isReachable[numsSize];
  //memset(isReachable, 0, sizeof(bool) * numsSize);
  //isReachable[0] = true;
//
  //for (i = 0; i < end; i++) {
    //max = i + nums[i];
    //if (max > cur) {
      //if (isReachable[i]) {
        //cur = max;
        //if (max > end) max = end;
        //for (j = i; j <= max; j++) {
          //isReachable[j] = true;
        //}
      //}
    //}
  //}
//
  //return cur >= end;
//}
//// #v1

// #v2
// 动态规划
bool canJump(int* nums, int numsSize) {
  if (numsSize == 1) return true;

  // reachable 记录当前可达的最远的索引
  // max 记录若可到达当前索引, 则当前索引可达最远的索引
  int max, reachable = 0, end = numsSize - 1;

  for (int i = 0; i < end; i++) {
    if (i <= reachable) { // 当前索引可达
      max = i + nums[i];
      if (max > reachable) reachable = max;
    }

    // 条件已经满足
    if (reachable >= end) break;
  }

  return reachable >= end;
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

int main(int argc, char *argv[])
{
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);

  if (canJump(a, n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }

  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */

