#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2094. 找出 3 位偶数 - 给你一个整数数组 digits ，其中每个元素是一个数字（0 - 9）。数组中可能存在重复元素。
// 你需要找出 所有 满足下述条件且 互不相同 的整数：
//  * 该整数由 digits 中的三个元素按 任意 顺序 依次连接 组成。
//  * 该整数不含 前导零
//  * 该整数是一个 偶数
// 例如，给定的 digits 是 [1, 2, 3] ，整数 132 和 312 满足上面列出的全部条件。
// 将找出的所有互不相同的整数按 递增顺序 排列，并以数组形式返回。
//  
// 示例 1：
// 输入：digits = [2,1,3,0]
// 输出：[102,120,130,132,210,230,302,310,312,320]
// 解释：
// 所有满足题目条件的整数都在输出数组中列出。
// 注意，答案数组中不含有 奇数 或带 前导零 的整数。
// 示例 2：
// 输入：digits = [2,2,8,8,2]
// 输出：[222,228,282,288,822,828,882]
// 解释：
// 同样的数字（0 - 9）在构造整数时可以重复多次，重复次数最多与其在 digits 中出现的次数一样。
// 在这个例子中，数字 8 在构造 288、828 和 882 时都重复了两次。
// 示例 3：
// 输入：digits = [3,7,5]
// 输出：[]
// 解释：
// 使用给定的 digits 无法构造偶数。
//  
// 提示：
//  * 3 &lt;= digits.length &lt;= 100
//  * 0 &lt;= digits[i] &lt;= 9

// #v1
struct vector {
  int *a, size, capacity;
};

struct vector* NewVector(int c) {
  struct vector *v = (struct vector *)malloc(sizeof(struct vector));

  v->a = (int *)malloc(sizeof(int) * c);
  v->capacity = c;
  v->size = 0;

  return v;
}

void VectorAddEl(struct vector *v, int val) {
  if (v->size == v->capacity) {
    v->capacity <<= 1;
    int *t = (int *)malloc(sizeof(int) * v->capacity);
    for (int i = 0; i < v->size; i++) {
      t[i] = v->a[i];
    }
    free(v->a);
    v->a = t;
  }

  v->a[v->size] = val;
  ++v->size;
}

int* findEvenNumbers(int* digits, int digitsSize, int* returnSize) {
  char cnts[10] = {0};
  struct vector *v = NewVector(128);
  int *ret, tmp, i, j;
  bool b;

  for (i = 0; i < digitsSize; i++) cnts[digits[i]] += 1;

  for (i = 100; i < 1000; i += 2) {
    tmp = i;
    b = true;
    char nums[10] = {0};

    while (tmp) {
      ++nums[tmp%10];
      tmp /= 10;
    }

    for (j = 0; j < 10; j++) {
      if (cnts[j] < nums[j]) {
        b = false;
        break;
      }
    }

    if (b) VectorAddEl(v, i);
  }

  *returnSize = v->size;
  ret = v->a;
  free(v);

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
  int n, *a, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = findEvenNumbers(a, n, &s);
  print_1d_arr(ret, s);
  free(ret);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
