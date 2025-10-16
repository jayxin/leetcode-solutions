#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1636. 按照频率将数组升序排序 - 给你一个整数数组 nums ，请你将数组按照每个值的频 率 升序 排序。如果有多个值的频率相同，请你按照数值本身将它们 降序 排序。 
// 请你返回排序后的数组。
//  
// 示例 1：
// 输入：nums = [1,1,2,2,2,3]
// 输出：[3,1,1,2,2,2]
// 解释：'3' 频率为 1，'1' 频率为 2，'2' 频率为 3 。
// 示例 2：
// 输入：nums = [2,3,1,3,2]
// 输出：[1,3,3,2,2]
// 解释：'2' 和 '3' 频率都为 2 ，所以它们之间按照数值本身降序排 序。
// 示例 3：
// 输入：nums = [-1,1,-6,4,5,-6,1,4,1]
// 输出：[5,-1,4,4,-6,-6,1,1,1]
//  
// 提示：
//  * 1 &lt;= nums.length &lt;= 100
//  * -100 &lt;= nums[i] &lt;= 100

// #v1
struct Pair {
  int val, cnt;
};

int cmp(const void *a, const void *b) {
  struct Pair *aa = *(struct Pair **)a, *bb = *(struct Pair **)b;
  if (aa->cnt != bb->cnt) return aa->cnt - bb->cnt;
  return bb->val - aa->val;
}

int* frequencySort(int* nums, int numsSize, int* returnSize) {
  *returnSize = numsSize;
  int t[201] = {0}, l = 0, tmp, i, j;
  struct Pair **p;

  for (i = 0; i < numsSize; i++) {
    tmp = nums[i] + 100;
    ++t[tmp];
    if (t[tmp] == 1) ++l;
  }

  p = (struct Pair **)malloc(sizeof(struct Pair *) * l);
  for (i = 0; i < l; i++) {
    p[i] = (struct Pair *)malloc(sizeof(struct Pair));
  }

  j = 0;
  for (i = 0; i < 201; i++) {
    if (t[i]) {
      p[j]->val = i - 100;
      p[j]->cnt = t[i];
      ++j;
    }
  }

  qsort(p, l, sizeof(struct Pair *), cmp);

  j = 0;
  for (i = 0; i < l; i++) {
    while (p[i]->cnt--) {
      nums[j++] = p[i]->val;
    }
  }

  return nums;
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
  int n, *a, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = frequencySort(a, n, &s);
  print_1d_arr(ret, s);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
