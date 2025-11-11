#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1010. 总持续时间可被 60 整除的歌曲 - 在歌曲列表中，第 i 首歌曲的持续时间为 time[i] 秒。
// 返回其总持续时间（以秒为单位）可被 60 整除的歌曲对的数量。形式上，我们希望下标数 字 i 和 j 满足  i < j 且有 (time[i] + time[j]) % 60 == 0。
//  
// 示例 1：
// 输入：time = [30,20,150,100,40]
// 输出：3
// 解释：这三对的总持续时间可被 60 整除：
// (time[0] = 30, time[2] = 150): 总持续时间 180
// (time[1] = 20, time[3] = 100): 总持续时间 120
// (time[1] = 20, time[4] = 40): 总持续时间 60
// 示例 2：
// 输入：time = [60,60,60]
// 输出：3
// 解释：所有三对的总持续时间都是 120，可以被 60 整除。
//  
// 提示：
//  * 1 <= time.length <= 6 * 104
//  * 1 <= time[i] <= 500

// #v1
int numPairsDivisibleBy60(int* time, int timeSize) {
  int ht[60] = {0}, c, r, ret = 0;

  for (int i = 0; i < timeSize; i++) {
    r = time[i] % 60;
    c = (60 - r) % 60;
    ret += ht[c];
    ++ht[r];
  }

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
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", numPairsDivisibleBy60(a, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
