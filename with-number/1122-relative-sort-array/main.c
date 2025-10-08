#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1122.  数组的相对排序 - 给你两个数组，arr1 和 arr2，arr2 中的元素各不相同，arr2 中的每个元素都出现在 arr1 中。
// 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。
//  
// 示例 1：
// 输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
// 输出：[2,2,2,1,4,3,3,9,6,7,19]
// 示例  2:
// 输入：arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
// 输出：[22,28,8,6,17,44]
//  
// 提示：
//  * 1 &lt;= arr1.length, arr2.length &lt;= 1000
//  * 0 &lt;= arr1[i], arr2[i] &lt;= 1000
//  * arr2 中的元素 arr2[i]  各不相同 
//  * arr2 中的每个元素 arr2[i] 都出现在 arr1 中

// #v1
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {
  *returnSize = arr1Size;
  int t[1001] = {0}, i, len;

  for (i = 0; i < arr1Size; i++) {
    ++t[arr1[i]];
  }

  len = 0;
  for (i = 0; i < arr2Size; i++) {
    while (t[arr2[i]]--) {
      arr1[len++] = arr2[i];
    }
  }

  for (i = 0; i < 1001; i++) {
    if (t[i] > 0)
      while (t[i]--) {
        arr1[len++] = i;
      }
  }

  return arr1;
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
  int *a1, n1, *a2, n2, *ret, s;
  scanf("%d", &n1);
  a1 = read_1d_arr(n1);
  scanf("%d", &n2);
  a2 = read_1d_arr(n2);
  ret = relativeSortArray(a1, n1, a2, n2, &s);
  print_1d_arr(ret, s);
  free(a1);
  free(a2);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
