#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 717. 1 比特与 2 比特字符 - 有两种特殊字符：
//
//  * 第一种字符可以用一比特 0 表示
//  * 第二种字符可以用两比特（10 或 11）表示
//
// 给你一个以 0 结尾的二进制数组 bits ，如果最后一个字符必须是一个一比特字符，则返回 true 。
//  
//
// 示例 1:
//
//
// 输入: bits = [1, 0, 0]
// 输出: true
// 解释: 唯一的解码方式是将其解析为一个两比特字符和一个一比特字符。
// 所以最后一个字符是一比特字符。
//
//
// 示例 2:
//
// 输入：bits = [1,1,1,0]
// 输出：false
// 解释：唯一的解码方式是将其解析为两比特字符和两比特字符。
// 所以最后一个字符不是一比特字符。
//
// 提示:
//
//  * 1 &lt;= bits.length &lt;= 1000
//  * bits[i] 为 0 或 1

// #v1
bool isOneBitCharacter(int* bits, int bitsSize) {
  int i = 0, type = -1;
  while (i < bitsSize) {
    if (bits[i] == 1) {
      i += 2;
      type = 2;
    } else {
      i++;
      type = 1;
    }
  }
  if (type == 1) {
    return true;
  }
  return false;
}
// #v1

int main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);
  int *bits = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", bits + i);
  }
  printf("%d\n", isOneBitCharacter(bits, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
