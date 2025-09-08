#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 228. 汇总区间 - 给定一个  无重复元素 的 有序 整数数组 nums 。
// 区间 [a,b] 是从 a 到 b（包含）的所有整数的集合。
// 返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素 都恰好被某个区间范围所覆盖，并且不存在属于某个区间但不属于 nums 的数字 x 。
// 列表中的每个区间范围 [a,b] 应该按如下格式输出：
//  * "a->b" ，如果 a != b
//  * "a" ，如果 a == b
//  
// 示例 1：
// 输入：nums = [0,1,2,4,5,7]
// 输出：["0->2","4->5","7"]
// 解释：区间范围是：
// [0,2] --> "0->2"
// [4,5] --> "4->5"
// [7,7] --> "7"
// 示例 2：
// 输入：nums = [0,2,3,4,6,8,9]
// 输出：["0","2->4","6","8->9"]
// 解释：区间范围是：
// [0,0] --> "0"
// [2,4] --> "2->4"
// [6,6] --> "6"
// [8,9] --> "8->9"
//  
// 提示：
//  * 0 <= nums.length <= 20
//  * -2^31 <= nums[i] <= 2^31 - 1
//  * nums 中的所有值都 互不相同
//  * nums 按升序排列

// #v1
char ss[12];
int ssLen;
void numToStr(int n) {
  ssLen = 0;
  int r = 0;
  char *s, *e, c;
  if (n < 0) {
    ss[ssLen++] = '-';
    s = ss + 1;
  } else {
    s = ss;
    if (n == 0) ss[ssLen++] = '0';
  }

  while (n) {
    r = n % 10;
    ss[ssLen++] = '0' + (r >= 0 ? r : -r);
    n /= 10;
  }

  ss[ssLen] = '\0';
  e = ss + ssLen - 1;
  while (s < e) {
    c = *s;
    *s = *e;
    *e = c;
    s++;
    e--;
  }
}

char** summaryRanges(int* nums, int numsSize, int* returnSize) {
  if (numsSize == 0) {
    *returnSize = 0;
    return NULL;
  }

  char **ret = (char **)malloc(sizeof(char *) * 21), *el, *s;
  int retLen = 0, l, r, elLen = 0;
  l = r = nums[0];
  for (int i = 1; i < numsSize; i++) {
    if (nums[i] == r + 1) {
      r++;
    } else {
      elLen = 0;
      el = (char *)malloc(sizeof(char) * 25);
      numToStr(l);
      s = ss;
      while (*s) {
        el[elLen++] = *s;
        s++;
      }
      if (l != r) {
        el[elLen++] = '-';
        el[elLen++] = '>';

        numToStr(r);
        s = ss;
        while (*s) {
          el[elLen++] = *s;
          s++;
        }
      }

      el[elLen++] = '\0';
      ret[retLen++] = el;
      l = r = nums[i];
    }
  }
  elLen = 0;
  el = (char *)malloc(sizeof(char) * 24);
  numToStr(l);
  s = ss;
  while (*s) {
    el[elLen++] = *s;
    s++;
  }
  if (l != r) {
    el[elLen++] = '-';
    el[elLen++] = '>';
    numToStr(r);
    s = ss;
    while (*s) {
      el[elLen++] = *s;
      s++;
    }
  }
  el[elLen++] = '\0';
  ret[retLen++] = el;

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

int main(int argc, char *argv[])
{
  int n, *a, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  char **ret = summaryRanges(a, n, &s);
  for (int i = 0; i < s; i++) {
    printf("%s\n", ret[i]);
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
