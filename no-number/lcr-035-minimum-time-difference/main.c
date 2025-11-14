#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// LCR 035. 最小时间差 - 给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。
//  
// 示例 1：
// 输入：timePoints = ["23:59","00:00"]
// 输出：1
// 示例 2：
// 输入：timePoints = ["00:00","23:59","00:00"]
// 输出：0
//  
// 提示：
//  * 2 <= timePoints <= 2 * 104
//  * timePoints[i] 格式为 "HH:MM"
//  
// 注意：本题与主站 539 题相同： https://leetcode-cn.com/problems/minimum-time-difference/ [https://leetcode-cn.com/problems/minimum-time-difference/]

// #v1
#define LIMIT (24 * 60)

int cmp(const void *a, const void *b) {
  return *(const int *)a - *(const int *)b;
}

int findMinDifference(char** timePoints, int timePointsSize) {
  int ret, d, a[timePointsSize];

  // process timePoints
  for (int i = 0; i < timePointsSize; i++) {
    int h = (timePoints[i][0] & 0x0f) * 10 + (timePoints[i][1] & 0x0f),
        m = (timePoints[i][3] & 0x0f) * 10 + (timePoints[i][4] & 0x0f);
    // convert to minute
    a[i] = h * 60 + m;
  }
  // sort
  qsort(a, timePointsSize, sizeof(int), cmp);

  // compute difference
  ret = a[1] - a[0];
  for (int i = 2; i < timePointsSize; i++) {
    d = a[i] - a[i-1];
    if (d < ret) ret = d;
  }
  // compute a[0] and a[timePointsSize-1]
  d = LIMIT - a[timePointsSize-1] + a[0];
  if (d < ret) ret = d;

  return ret;
}
// #v1

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
  int n;
  char **s;
  scanf("%d\n", &n);
  s = calloc(n, sizeof(char*));
  for (int i = 0; i < n; i++) {
    s[i] = calloc(100, sizeof(char));
    read_line(s[i], 98, stdin);
  }
  printf("%d\n", findMinDifference(s, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
