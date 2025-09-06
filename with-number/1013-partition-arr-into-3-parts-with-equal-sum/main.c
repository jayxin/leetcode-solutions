#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1013. 将数组分成和相等的三个部分 - 给你一个整数数组 arr，只有可以将其划分为 三个和相等的 非空 部分时才返回 true，否则返回 false。
// 形式上，如果可以找出索引 i + 1 < j 且满足 (arr[0] + arr[1] + ... + arr[i] == arr[i + 1] + arr[i + 2] + ... + arr[j - 1] == arr[j] + arr[j + 1] + ... + arr[arr.length - 1]) 就可以将数组三等分。
//  
// 示例 1：
// 输入：arr = [0,2,1,-6,6,-7,9,1,2,0,1]
// 输出：true
// 解释：0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
// 示例 2：
// 输入：arr = [0,2,1,-6,6,7,9,-1,2,0,1]
// 输出：false
// 示例 3：
// 输入：arr = [3,3,6,5,-2,2,5,1,-9,4]
// 输出：true
// 解释：3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
//  
// 提示：
//  * 3 <= arr.length <= 5 * 10^4
//  * -10^4 <= arr[i] <= 10^4

// #v1
// 需要注意 sum 为 0 的特殊情况
bool canThreePartsEqualSum(int* arr, int arrSize) {
  long long sum = 0;
  for (int i = 0; i < arrSize; i++) {
    sum += arr[i];
  }

  if (sum % 3) return false;

  long long partSum = sum / 3;
  int i = 0, part_cnt = 0;
  sum = 0;

  while (1) {
    if (i == arrSize) break;

    sum += arr[i++];

    if (sum == partSum) {
      sum = 0;
      part_cnt++;
    }
  }

  if (part_cnt >= 3) return true;

  return false;
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
  int *a = read_1d_arr(n);
  if (canThreePartsEqualSum(a, n)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
