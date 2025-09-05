#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 12. 整数 转罗马数字 - 七个不同的符号代表罗马数字，其值如下：
// 符号 值 I 1 V 5 X 10 L 50 C 100 D 500 M 1000
// 罗马数字是通过添加从最高到最低的小数位值的转换而形成的。将小数位值转换为罗马数字 有以下规则：
//  * 如果该值不是以 4 或 9 开头，请选择可以从输入中减去的最大值的符号，将该符号附加到结果，减去其值，然后将其余部分转换为罗马数字。
//  * 如果该值以 4 或 9 开头，使用 减法形式，表示从以下符号中减去一个符号，例如 4 是 5 (V) 减 1 (I): IV ，9 是 10 (X) 减 1 (I)：IX。仅使用以下减法形式：4 (IV)，9 (IX)，40 (XL)，90 (XC)，400 (CD) 和 900 (CM)。
//  * 只有 10 的次方（I, X, C, M）最多可以连续附加 3 次以代表 10 的倍数。你不能多次 附加 5 (V)，50 (L) 或 500 (D)。如果需要将符号附加4次，请使用 减法形式。
// 给定一个整数，将其转换为罗马数字。
//  
// 示例 1：
// 输入：num = 3749
// 输出： "MMMDCCXLIX"
// 解释：
// 3000 = MMM 由于 1000 (M) + 1000 (M) + 1000 (M)
//  700 = DCC 由于 500 (D) + 100 (C) + 100 (C)
//   40 = XL 由于 50 (L) 减 10 (X)
//    9 = IX 由于 10 (X) 减 1 (I)
// 注意：49 不是 50 (L) 减 1 (I) 因为转换是基于小数位
// 示例 2：
// 输入：num = 58
// 输出："LVIII"
// 解释：
// 50 = L
//  8 = VIII
// 示例 3：
// 输入：num = 1994
// 输出："MCMXCIV"
// 解释：
// 1000 = M
//  900 = CM
//   90 = XC
//    4 = IV
//  
// 提示：
//  * 1 <= num <= 3999

// #v1
int get_weight_map_index(int n) {
  int ret = -1;
  while (n) {
    n /= 10;
    ret++;
  }
  return ret;
}

void set_current(int digit, int weight, char *current) {
  char weight_map[4] = {'I', 'X', 'C', 'M'};
  char five_map[3] = {'V', 'L', 'D'};
  int len = 0, index, i;
  index = get_weight_map_index(weight);

  if (digit <= 3) { // 1 2 3
    for (i = 0; i < digit; i++) {
      current[len++] = weight_map[index];
    }
  } else if (digit == 4) { // 4
    current[len++] = weight_map[index];
    current[len++] = five_map[index];
  } else if (digit == 9) { // 9
    current[len++] = weight_map[index];
    current[len++] = weight_map[index + 1];
  } else { // 5 6 7 8
    current[len++] = five_map[index];
    for (i = 0; i < digit - 5; i++) {
      current[len++] = weight_map[index];
    }
  }

  // string end
  current[len] = '\0';
}

char* intToRoman(int num) {
  int weight[4] = {1, 10, 100, 1000};
  int digits[4], len = 0;
  char *ret = (char *)malloc(sizeof(char) * 80), *p;
  char current[100];
  int retLen = 0;
  while (num) {
    digits[len++] = num % 10;
    num /= 10;
  }
  for (int i = len - 1; i >= 0; i--) {
    if (digits[i]) {
      set_current(digits[i], weight[i], current);
      p = current;
      while (p) {
        if (*p == '\0') break;
        ret[retLen++] = *p;
        p++;
      }
    }
  }
  ret[retLen] = '\0';
  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  printf("%s\n", intToRoman(n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
