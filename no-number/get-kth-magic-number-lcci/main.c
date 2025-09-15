#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 面试题 17.09. 第 k 个数 - 有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。
// 示例 1：
// 输入：k = 5
// 输出：9

//// #v1
//// 小根堆, 弹出 k 个
//int size;
//int64_t *h, tmp;
//
//void HeapSwap(int i, int j) {
  //tmp = h[i];
  //h[i] = h[j];
  //h[j] = tmp;
//}
//
//void HeapUp(int p) { // 向上调整
  //while (p > 1) {
    //if (h[p] < h[p>>1]) {
      //HeapSwap(p, p>>1);
      //p >>= 1;
    //} else {
      //return ;
    //}
  //}
//}
//
//void HeapDown(int p) { // 向下调整
  //int s = p << 1;
//
  //while (s <= size) {
    //if (s < size && h[s] > h[s+1]) s++;
    //if (h[s] < h[p]) {
      //HeapSwap(s, p);
      //p = s;
      //s <<= 1;
    //} else {
      //return ;
    //}
  //}
//}
//
//void HeapInsert(int64_t v) {
  //h[++size] = v;
  //HeapUp(size);
//}
//
//void HeapExtract() {
  //h[1] = h[size--];
  //HeapDown(1);
//}
//
//int getKthMagicNumber(int k) {
  //if (k == 1) return 1;
//
  //int i, j, a[3] = {3, 5, 7}, tLen = 0;
  //int64_t v, t[5000], ret = 0LL;
//
  //// heap init
  //h = (int64_t *)malloc(sizeof(int64_t) * (k + 1));
  //size = 0;
//
  //// init
  //i = 1;
  //HeapInsert(1);
//
  //while (i < k) {
    //for (j = 0; j < 3; j++) {
      //// 堆满了
      //if (size == k) break;
//
      //v = h[1] * a[j];
//
      //// 确保不重复
      //bool b = true;
      //for (int l = 0; l < tLen; l++) {
        //if (t[l] == v) {
          //b = false;
          //break;
        //}
      //}
      //if (!b) continue;
//
      //t[tLen++] = v;
      //HeapInsert(v);
    //}
//
    //HeapExtract();
    //// 取 k - 1 个即可
    //ret = h[1];
    //i++;
  //}
//
  //return ret;
//}
//// #v1

// #v2
// 动态规划
int min(int a, int b) {
  return (a > b ? b : a);
}

int getKthMagicNumber(int k) {
  int dp[k + 1], v1, v2, v3, idx1, idx2, idx3, i;

  dp[1] = 1;
  idx1 = idx2 = idx3 = 1;

  for (i = 2; i <= k; i++) {
    v1 = dp[idx1] * 3;
    v2 = dp[idx2] * 5;
    v3 = dp[idx3] * 7;

    // select minimum value
    dp[i] = min(v1, min(v2, v3));

    // update
    // 注意 3*5 和 5*3, 这里 dp[i]==15 时, idx1 和 idx2 会同时 +1
    if (v1 == dp[i]) ++idx1;
    if (v2 == dp[i]) ++idx2;
    if (v3 == dp[i]) ++idx3;
  }

  return dp[k];
}
// #v2

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", getKthMagicNumber(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
