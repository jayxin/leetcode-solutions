#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2469. 温度转 换 - 给你一个四舍五入到两位小数的非负浮点数 celsius 来表示温度，以 摄氏度（Celsius）为单位。
// 你需要将摄氏度转换为 开氏度（Kelvin）和 华氏度（Fahrenheit），并以数组 ans = [kelvin, fahrenheit] 的形式返回结果。
// 返回数组 ans 。与实际答案误差不超过 10-5 的会视为正确答案。
// 注意：
//  * 开氏度 = 摄氏度 + 273.15
//  * 华氏度 = 摄氏度 * 1.80 + 32.00
//  
// 示例 1 ：
// 输入：celsius = 36.50
// 输出：[309.65000,97.70000]
// 解释：36.50 摄氏度：转换为开氏度是 309.65 ，转换为华氏度是 97.70 。
// 示例 2 ：
// 输入：celsius = 122.11
// 输出：[395.26000,251.79800]
// 解释：122.11 摄氏度：转换为开氏度是 395.26 ，转换为华氏度是 251.798 。
//  
// 提示：
//  * 0 &lt;= celsius &lt;= 1000

// #v1
double* convertTemperature(double celsius, int* returnSize) {
  double *ret = (double *)malloc(sizeof(double) * 2);

  *returnSize = 2;

  ret[0] = 273.15 + celsius;
  ret[1] = 32.00 + celsius * 1.80;

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  double n, *ret;
  int s;
  scanf("%lf", &n);
  ret = convertTemperature(n, &s);
  printf("%.5lf %.5lf\n", ret[0], ret[1]);
  free(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
