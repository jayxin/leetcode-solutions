#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 412. Fizz Buzz - 给你一个整数 n ，返回一个字符串数组 answer（下标从 1 开始），其中：
//  * answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
//  * answer[i] == "Fizz" 如果 i 是 3 的倍数。
//  * answer[i] == "Buzz" 如果 i 是 5 的倍数。
//  * answer[i] == i （以字符串形式）如果上述条件全不满足。
//  
// 示例 1：
// 输入：n = 3
// 输出：["1","2","Fizz"]
// 示例 2：
// 输入：n = 5
// 输出：["1","2","Fizz","4","Buzz"]
// 示例 3：
// 输入：n = 15
// 输出：["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
//  
// 提示：
//  * 1 &lt;= n &lt;= 104

//// #v1
//void myItoA(int x, char *s) {
  //int len = 0;
  //char *l = s, *r, c;
  //while (x) {
    //s[len++] = (x % 10) + '0';
    //x /= 10;
  //}
  //s[len] = '\0';
  //r = s + len - 1;
  //while (l < r) {
    //c = *l;
    //*l = *r;
    //*r = c;
    //l++;
    //r--;
  //}
//}
//
//char** fizzBuzz(int n, int* returnSize) {
  //*returnSize = n;
  //char **ret = (char **)malloc(sizeof(char *) * n), *s;
  //int i, r1, r2, retLen = 0;
  //for (i = 1; i <= n; i++) {
    //r1 = i % 3;
    //r2 = i % 5;
//
    //s = (char *)malloc(sizeof(char) * 12);
//
    //if (r1 == 0 && r2 == 0) {
      //if (i > 15) {
        //free(s);
        //s = ret[14];
      //} else {
        //strncpy(s, "FizzBuzz", 8);
      //}
    //} else if (r1 == 0) {
      //if (i > 3) {
        //free(s);
        //s = ret[2];
      //} else {
        //strncpy(s, "Fizz", 4);
      //}
    //} else if (r2 == 0) {
      //if (i > 5) {
        //free(s);
        //s = ret[4];
      //} else {
        //strncpy(s, "Buzz", 4);
      //}
    //} else {
      //myItoA(i, s);
    //}
//
    //ret[retLen++] = s;
  //}
//
  //return ret;
//}
//// #v1

// #v2
char** fizzBuzz(int n, int* returnSize) {
  *returnSize = n;
  char **answer = (char **)malloc(sizeof(char *) * n), *s;
  int i, r1, r2;

  for (i = 0; i < n; i++) {
    answer[i] = (char *)malloc(sizeof(char) * 9);
  }

  for (i = 1; i <= n; i++) {
    r1 = i % 3;
    r2 = i % 5;

    if (r1 == 0 && r2 == 0) {
      strcpy(answer[i-1], "FizzBuzz");
    } else if (r1 == 0) {
      strcpy(answer[i-1], "Fizz");
    } else if (r2 == 0) {
      strcpy(answer[i-1], "Buzz");
    } else {
      sprintf(answer[i-1], "%d", i);
    }
  }

  return answer;
}
// #v2

int main(int argc, char *argv[])
{
  int n, s;
  char **r;
  scanf("%d", &n);
  r = fizzBuzz(n, &s);
  for (int i = 0; i < s; i++) {
    printf("%s\n", r[i]);
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
