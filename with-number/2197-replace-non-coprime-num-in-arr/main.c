#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2197. 替换数组中的非互质数 - 给你一个整数数组 nums 。请你对数组执行下述操作：
//  1. 从 nums 中找出 任意 两个 相邻 的 非互质 数。
//  2. 如果不存在这样的数，终止 这一过程。
//  3. 否则，删除这两个数，并 替换 为它们的 最小公倍数（Least Common Multiple，LCM）。
//  4. 只要还能找出两个相邻的非互质数就继续 重复 这一过程。
// 返回修改后得到的 最终 数组。可以证明的是，以 任意 顺序替换相邻的非互质数都可以得 到相同的结果。
// 生成的测试用例可以保证最终数组中的值 小于或者等于 108 。
// 两个数字 x 和 y 满足 非互质数 的条件是：GCD(x, y) &gt; 1 ，其中 GCD(x, y) 是 x 和 y 的 最大公约数 。
//  
// 示例 1 ：
// 输入：nums = [6,4,3,2,7,6,2]
// 输出：[12,7,6]
// 解释：
// - (6, 4) 是一组非互质数，且 LCM(6, 4) = 12 。得到 nums = [12,3,2,7,6,2] 。
// - (12, 3) 是一组非互质数，且 LCM(12, 3) = 12 。得到 nums = [12,2,7,6,2] 。
// - (12, 2) 是一组非互质数，且 LCM(12, 2) = 12 。得到 nums = [12,7,6,2] 。
// - (6, 2) 是一组非互质数，且 LCM(6, 2) = 6 。得到 nums = [12,7,6] 。
// 现在，nums 中不存在相邻的非互质数。
// 因此，修改后得到的最终数组是 [12,7,6] 。
// 注意，存在其他方法可以获得相同的最终数组。
// 示例 2 ：
// 输入：nums = [2,2,1,1,3,3,3]
// 输出：[2,1,1,3]
// 解释：
// - (3, 3) 是一组非互质数，且 LCM(3, 3) = 3 。得到 nums = [2,2,1,1,3,3] 。
// - (3, 3) 是一组非互质数，且 LCM(3, 3) = 3 。得到 nums = [2,2,1,1,3] 。
// - (2, 2) 是一组非互质数，且 LCM(2, 2) = 2 。得到 nums = [2,1,1,3] 。
// 现在，nums 中不存在相邻的非互质数。
// 因此，修改后得到的最终数组是 [2,1,1,3] 。
// 注意，存在其他方法可以获得相同的最终数组。
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 105
//  * 1 &lt;= nums[i] &lt;= 105
//  * 生成的测试用例可以保证最终数组中的值 小于或者等于 108 。

// #v1
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

#define lcm(a, b, g) ((a)/(g)*(b))
//int lcm(int a, int b, int g) {
//  // avoid overflow
//  return (int64_t)a * b / g;
//}

int* replaceNonCoprimes(int* nums, int numsSize, int* returnSize) {
  if (numsSize == 1) {
    *returnSize = 1;
    return nums;
  }

  int *ret = (int *)malloc(sizeof(int) * numsSize), retLen = 1,
      i = 0, j, g;
  ret[0] = nums[0];
  i = 0;

  for (j = 1; j < numsSize; j++) {
    g = gcd(ret[i], nums[j]);
    // printf("gcd(%d, %d) = %d\n", ret[i], nums[j], g);
    if (g == 1) {
      ret[retLen++] = nums[j];
      i++;
    } else {
      ret[i] = lcm(ret[i], nums[j], g);

      while (i != 0 && g != 1) { // 确保和前面的数互质
        g = gcd(ret[i], ret[i-1]);
        if (g != 1) {
          ret[i-1] = lcm(ret[i], ret[i-1], g);
          --retLen;
          --i;
        }
      }
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
  int n, *a, *ret, s = 0;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = replaceNonCoprimes(a, n, &s);
  print_1d_arr(ret, s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
