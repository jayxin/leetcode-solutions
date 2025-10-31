#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1641. 统计字典序元音字符串的数目 - 给你一个整数 n，请返回长度为 n 、仅由元音 (a, e, i, o, u) 组成且按 字典序排列 的字符串数量。
// 字符串 s 按 字典序排列 需要满足：对于所有有效的 i，s[i] 在字母表中的位置总是与 s[i+1] 相同或在 s[i+1] 之前。
//  
// 示例 1：
// 输入：n = 1
// 输出：5
// 解释：仅由元音组成的 5 个字典序字符串为 ["a","e","i","o","u"]
// 示例 2：
// 输入：n = 2
// 输出：15
// 解释：仅由元音组成的 15 个字典序字符串为
// ["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"]
// 注意，"ea" 不是符合题意的字符串，因为 'e' 在字母表中的位置比 'a' 靠后
// 示例 3：
// 输入：n = 33
// 输出：66045
//  
// 提示：
//  * 1 <= n <= 50 

//// #v1
//// 前缀和
//// 1. 以 'a' 结尾时有多少种 +
//// 2. 以 'e' 结尾时有多少种 +
//// 3. 以 'i' 结尾时有多少种 +
//// 4. 以 'o' 结尾时有多少种 +
//// 5. 以 'u' 结尾时有多少种
//// ==
//// f(n)
//// f(n-1) -> f(n)
//// n=1: a-1, e-1, i-1, o-1, u-1
//// n=2: a-1, e-2, i-3, o-4, u-5
//// n=3: a-1, e-3, i-6, o-10, u-15
//// ...
//int countVowelStrings(int n) {
  //// edge case
  //if (n == 1) return 5;
//
  //int a0[5], a1[5], *p, *q, i, ret = 0;
//
  //// init
  //// 这里 a0 的值是 n==2 时的结果
  //for (i = 0; i < 5; i++) {
    //a0[i] = i + 1;
  //}
  //p = a0;
  //q = a1;
  //--n;
//
  //while (--n) {
    //// prefix sum
    //q[0] = p[0];
    //for (i = 1; i < 5; i++) {
      //q[i] = q[i-1] + p[i];
    //}
//
    //// swap
    //int *tmp = p;
    //p = q;
    //q = tmp;
  //}
//
  //// summation
  //for (i = 0; i < 5; i++) {
    //ret += p[i];
  //}
//
  //return ret;
//}
//// #v1

//// #v2
//// 前缀和
//// 空间优化
//// 1. 以 'a' 结尾时有多少种 +
//// 2. 以 'e' 结尾时有多少种 +
//// 3. 以 'i' 结尾时有多少种 +
//// 4. 以 'o' 结尾时有多少种 +
//// 5. 以 'u' 结尾时有多少种
//// ==
//// f(n)
//// f(n-1) -> f(n)
//// n=1: a-1, e-1, i-1, o-1, u-1
//// n=2: a-1, e-2, i-3, o-4, u-5
//// n=3: a-1, e-3, i-6, o-10, u-15
//// ...
//int countVowelStrings(int n) {
  //// edge case
  //if (n == 1) return 5;
//
  //int a0[5], i, ret = 0;
//
  //// init
  //// 这里 a0 的值是 n==2 时的结果
  //for (i = 0; i < 5; i++) {
    //a0[i] = i + 1;
  //}
  //--n;
//
  //while (--n) {
    //// prefix sum
    //for (i = 1; i < 5; i++) {
      //a0[i] += a0[i-1];
    //}
  //}
//
  //// summation
  //for (i = 0; i < 5; i++) ret += a0[i];
//
  //return ret;
//}
//// #v2

// #v3
// 组合数学
// 等价于求方程 x1+x2+x3+x4+x5=n 非负整数解的个数
// 隔板法
// 求把 n 个球放到 5 个篮子的所有放法（允许空篮），
// 先添加 5 个虚拟球转化为不允许空篮的做法，再用隔板法，
// 共 n+5−1 个位置，放 4 个隔板
// C(n+4, 4)
int countVowelStrings(int n) {
  return (n + 4) * (n + 3) * (n + 2) * (n + 1) / 24;
}
// #v3

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d\n", countVowelStrings(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
