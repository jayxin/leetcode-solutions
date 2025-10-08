#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1985. 找出数组中的第 K 大整数 - 给你一个字符串数组 nums 和一个整数 k 。nums 中 的每个字符串都表示一个不含前导零的整数。
// 返回 nums 中表示第 k 大整数的字符串。
// 注意：重复的数字在统计时会视为不同元素考虑。例如，如果 nums 是 ["1","2","2"]，那么 "2" 是最大的整数，"2" 是第二 大的整数，"1" 是第三大的整数。
//  
// 示例 1：
// 输入：nums = ["3","6","7","10"], k = 4
// 输出："3"
// 解释：
// nums 中的数字按非递减顺序排列为 ["3","6","7","10"]
// 其中第 4 大整数是 "3"
// 示例 2：
// 输入：nums = ["2","21","12","1"], k = 3
// 输出："2"
// 解释：
// nums 中的数字按非递减顺序排列为 ["1","2","12","21"]
// 其中第 3 大整数是 "2"
// 示例 3：
// 输入：nums = ["0","0"], k = 2
// 输出："0"
// 解释：
// nums 中的数字按非递减顺序排列为 ["0","0"]
// 其中第 2 大整数是 "0"
//  
// 提示：
//  * 1 <= k <= nums.length <= 104
//  * 1 <= nums[i].length <= 100
//  * nums[i] 仅由数字组成
//  * nums[i] 不含任何前导零

//// #v1
//// 正确但超时
//// 快速选择
//struct Pair {
  //int l;
  //char *s;
//};
//
//int cmp(struct Pair *a, struct Pair *b) {
  //if (a->l != b->l) return a->l - b->l;
//
  //char *s0 = a->s, *s1 = b->s;
//
  //while (*s0) {
    //if (*s0 != *s1) return *s0 - *s1;
    //++s0;
    //++s1;
  //}
//
  //return 0;
//}
//
//void swap(struct Pair *a, int l, int r) {
  //int len;
  //char *s;
//
  //len = a[l].l, s = a[l].s;
  //a[l].l = a[r].l, a[l].s = a[r].s;
  //a[r].l = len, a[r].s = s;
//}
//
//int partition(struct Pair *a, int len) {
  //int end = len - 1, l = 0, r = end - 1;
  //struct Pair tmp = { .s = a[end].s, .l = a[end].l };
//
  //while (l < r) {
    //while (l < end && cmp(a + l, &tmp) <= 0) ++l;
    //while (r > 0 && cmp(a + r, &tmp) >= 0) --r;
//
    //if (l < r && cmp(a + l, a + r) > 0) swap(a, l ,r);
  //}
//
  //if (cmp(a + l, a + end) > 0)
    //swap(a, l, end);
//
  //return l;
//}
//
//char* getKth(struct Pair *a, int len, int k) {
  //if (len < 1) return NULL;
  //if (len == 1) return a[0].s;
//
  //int q = partition(a, len);
//
  //if (q == k) {
    //return a[q].s;
  //} else if (q < k) {
    //int t = q + 1;
    //return getKth(a + t, len - t, k - t);
  //}
  //return getKth(a, q, k);
//}
//
//char* kthLargestNumber(char** nums, int numsSize, int k) {
  //struct Pair p[numsSize];
//
  //for (int i = 0; i < numsSize; i++) {
    //p[i].l = strlen(nums[i]), p[i].s = nums[i];
  //}
//
  //return getKth(p, numsSize, numsSize - k);
//}
//// #v1

//// #v2
//// 通过
//// 快速选择
//struct Pair {
  //int l;
  //char *s;
//};
//
//char *s0, *s1;
//
//int cmp(struct Pair *a, struct Pair *b) {
  //if (a->l != b->l) return a->l - b->l;
//
  //s0 = a->s, s1 = b->s;
  //while (*s0) {
    //if (*s0 != *s1) return *s0 - *s1;
    //++s0;
    //++s1;
  //}
//
  //return 0;
//}
//int partition(struct Pair **a, int n) {
  //if (n == 2) {
    //if (cmp(a[0], a[1]) > 0) {
      //struct Pair *t = a[0];
      //a[0] = a[1];
      //a[1] = t;
    //}
//
    //return 1;
  //}
//
  //int end = n - 1, l = 0, r = end - 1, m = n >> 1;
  //struct Pair tmp = { .s = a[m]->s, .l = a[m]->l }, *t;
  //t = a[end];
  //a[end] = a[m];
  //a[m] = t;
//
  //while (l < r) {
    //while (l < end && cmp(a[l], &tmp) <= 0) ++l;
    //while (r > 0 && cmp(a[r], &tmp) > 0) --r;
//
    //if (l < r && cmp(a[l], a[r]) > 0) {
      //// swap
      //t = a[l];
      //a[l] = a[r];
      //a[r] = t;
    //}
  //}
//
  //t = a[l];
  //a[l] = a[end];
  //a[end] = t;
//
  //return l;
//}
//
//char* getKth(struct Pair **a, int len, int k) {
  //if (len == 1) return a[0]->s;
//
  //int q = partition(a, len), newLen = 0, newK = 0;
  //struct Pair **newArr = NULL;
//
  //if (q == k) {
    //return a[q]->s;
  //} else if (q < k) {
    //int t = q + 1;
    //newArr = a + t;
    //newLen = len - t;
    //newK = k - t;
  //} else {
    //newArr = a;
    //newLen = q;
    //newK = k;
  //}
//
  //if (newLen >= 1)
    //return getKth(newArr, newLen, newK);
//
  //return NULL;
//}
//
//char* kthLargestNumber(char** nums, int numsSize, int k) {
  //struct Pair *p[numsSize];
//
  //for (int i = 0; i < numsSize; i++) {
    //p[i] = (struct Pair *)malloc(sizeof(struct Pair));
    //p[i]->l = strlen(nums[i]), p[i]->s = nums[i];
  //}
//
  //return getKth(p, numsSize, numsSize - k);
//}
//// #v2

//// #v3
//// 快速选择
//struct Pair {
  //int l;
  //char *s;
//};
//
//char *s0, *s1;
//
//int cmp(struct Pair *a, struct Pair *b) {
  //if (a->l != b->l) return a->l - b->l;
//
  //s0 = a->s, s1 = b->s;
  //while (*s0 && *s0 == *s1) {
    //++s0;
    //++s1;
  //}
//
  //return *s0 - *s1;
//}
//
//int partition(struct Pair **a, int n) {
  //if (n == 2) {
    //if (cmp(a[0], a[1]) > 0) {
      //struct Pair *t = a[0];
      //a[0] = a[1];
      //a[1] = t;
    //}
//
    //return 1;
  //}
//
  //int end = n - 1, l = 0, r = end - 1, m = n >> 1;
  //struct Pair *t;
//
  //t = a[end];
  //a[end] = a[m];
  //a[m] = t;
//
  //while (l < r) {
    //while (l < end && cmp(a[l], a[end]) <= 0) ++l;
    //while (r > 0 && cmp(a[r], a[end]) > 0) --r;
//
    //if (l < r) {
      //// swap
      //t = a[l];
      //a[l] = a[r];
      //a[r] = t;
    //}
  //}
//
  //t = a[l];
  //a[l] = a[end];
  //a[end] = t;
//
  //return l;
//}
//
//char* getKth(struct Pair **a, int len, int k) {
  //if (len == 1) return a[0]->s;
//
  //int q = partition(a, len);
//
  //if (q == k) {
    //return a[q]->s;
  //} else if (q < k) {
    //int t = q + 1;
    //if (len - t >= 1)
      //return getKth(a + t, len - t, k - t);
  //} else {
    //if (q >= 1)
      //return getKth(a, q, k);
  //}
//
  //return NULL;
//}
//
//char* kthLargestNumber(char** nums, int numsSize, int k) {
  //struct Pair *p[numsSize];
//
  //for (int i = 0; i < numsSize; i++) {
    //p[i] = (struct Pair *)malloc(sizeof(struct Pair));
    //p[i]->l = strlen(nums[i]), p[i]->s = nums[i];
  //}
//
  //return getKth(p, numsSize, numsSize - k);
//}
//// #v3

// #v4
// 将字符串根据长度进行分类

// nums[i] 的最大长度
#define MAX_LEN 100

// 降序排序
int cmp(const void *a, const void *b) {
  return strcmp(*(char **)b, *(char **)a);
}

char* kthLargestNumber(char** nums, int numsSize, int k) {
  // 分类数组, groups[i] 数组存储 nums 中长度为 i 的字符串
  char *groups[MAX_LEN + 1][numsSize];
  // 记录每个长度类别的字符串的数量
  // lens[i] 存储长度为 i 的字符串的数量
  int lens[MAX_LEN + 1] = {0}, l, i;

  // 将字符串根据长度分类
  for (i = 0; i < numsSize; i++) {
    l = strlen(nums[i]);
    groups[l][lens[l]++] = nums[i];
  }

  // 对每个长度组内字符串排序
  for (i = MAX_LEN; i >= 0; i--) {
    if (lens[i]) qsort(groups[i], lens[i], sizeof(char *), cmp);
  }

  // 寻找第 k 大的数
  for (i = MAX_LEN; i >= 0; i--) {
    if (lens[i]) {
      if (k <= lens[i]) return groups[i][k-1];
      k -= lens[i];
    }
  }

  return NULL;
}
// #v4

// read one line from stream
char* read_line(char *buffer, size_t size, FILE *stream) {
  if (fgets(buffer, size, stream) == NULL) {
    return NULL;
  }

  size_t len = strlen(buffer);
  if (len > 0 && buffer[len - 1] == '\n') {
    buffer[len - 1] = '\0';
  }

  return buffer;
}

int main(int argc, char *argv[])
{
  int n, k;
  char **s;
  scanf("%d\n", &n);
  s = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    s[i] = (char *)malloc(sizeof(char) * 103);
    read_line(s[i], 102, stdin);
  }
  scanf("%d", &k);
  printf("%s\n", kthLargestNumber(s, n, k));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
