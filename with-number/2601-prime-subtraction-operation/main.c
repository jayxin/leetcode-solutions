#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2601. 质 数减法运算 - 给你一个下标从 0 开始的整数数组 nums ，数组长度为 n 。
// 你可以执行无限次下述运算：
//  * 选择一个之前未选过的下标 i ，并选择一个 严格小于 nums[i] 的质数 p ，从 nums[i] 中减去 p 。
// 如果你能通过上述运算使得 nums 成为严格递增数组，则返回 true ；否则返回 false 。
// 严格递增数组 中的每个元素都严格大于其前面的元素。
//  
// 示例 1：
// 输入：nums = [4,9,6,10]
// 输出：true
// 解释：
// 在第一次运算中：选择 i = 0 和 p = 3 ，然后从 nums[0] 减去 3 ，nums 变为 [1,9,6,10] 。
// 在第二次运算中：选择 i = 1 和 p = 7 ，然后从 nums[1] 减去 7 ，nums 变为 [1,2,6,10] 。
// 第二次运算后，nums 按严格递增顺序排序，因此答案为 true 。
// 示例 2：
// 输入：nums = [6,8,11,12]
// 输出：true
// 解释：nums 从一开始就按严格递增顺序排序，因此不需要执行任何运算。
// 示例 3：
// 输入：nums = [5,8,3]
// 输出：false
// 解释：可以证明，执行运算无法使 nums 按严格递增顺序排序，因此答案是 false 。
//  
// 提示：
//  * 1 <= nums.length <= 1000
//  * 1 <= nums[i] <= 1000
//  * nums.length == n

// #v1
// 寻找比 target 小的质数 x, 同时 target - x > bottom
int primes[180], n, l, r, m, q;
int binarySearch(int target, int bottom) {
  l = 0, r = n - 1;
  while (l < r) {
    m = (l + r + 1) >> 1;
    q = target - primes[m];

    if (q <= 0 || q <= bottom) {
      r = m - 1;
    } else {
      l = m;
    }
  }

  q = target - primes[l];
  while (l < n && q > 0 && q > bottom) {
    ++l;
    q = target - primes[l];
  }

  if (l >= 1 && l <= n) return primes[l-1];

  return -1;
}

bool primeSubOperation(int* nums, int numsSize) {
  char isPrime[1001];
  int i, x;

  // init
  memset(isPrime, 1, sizeof(isPrime));
  n = 0;

  for (i = 2; i <= 1000; i++) {
    if (isPrime[i]) {
      primes[n++] = i;
      for (int j = i; j <= 1000 / i; j++) isPrime[i*j] = 0;
    }
  }

  x = binarySearch(nums[0], -1);
  if (x > 0) nums[0] -= x;

  for (i = 1; i < numsSize; i++) {
    x = binarySearch(nums[i], nums[i-1]);
    if (x > 0) nums[i] -= x;

    if (nums[i] <= nums[i-1]) return false;
  }

  return true;
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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  if (primeSubOperation(a, n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
