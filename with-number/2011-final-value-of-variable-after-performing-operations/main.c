#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 2011. 执行操作后的变量值 - 存在一种仅支持 4 种操作和 1 个变量 X 的编程语言：
//  * ++X 和 X++ 使变量 X 的值 加 1
//  * --X 和 X-- 使变量 X 的值 减 1
// 最初，X 的值是 0
// 给你一个字符串数组 operations ，这是由操作组成的一个列表，返回执行所有操作后， X 的 最终值 。
//  
// 示例 1：
// 输入：operations = ["--X","X++","X++"]
// 输出：1
// 解释：操作按下述步骤执行：
// 最初，X = 0
// --X：X 减 1 ，X =  0 - 1 = -1
// X++：X 加 1 ，X = -1 + 1 =  0
// X++：X 加 1 ，X =  0 + 1 =  1
// 示例 2：
// 输入：operations = ["++X","++X","X++"]
// 输出：3
// 解释：操作按下述步骤执行：
// 最初，X = 0
// ++X：X 加 1 ，X = 0 + 1 = 1
// ++X：X 加 1 ，X = 1 + 1 = 2
// X++：X 加 1 ，X = 2 + 1 = 3
// 示例 3：
// 输入：operations = ["X++","++X","--X","X--"]
// 输出：0
// 解释：操作按下述步骤执行：
// 最初，X = 0
// X++：X 加 1 ，X = 0 + 1 = 1
// ++X：X 加 1 ，X = 1 + 1 = 2
// --X：X 减 1 ，X = 2 - 1 = 1
// X--：X 减 1 ，X = 1 - 1 = 0
//  
// 提示：
//  * 1 <= operations.length <= 100
//  * operations[i] 将会是 "++X"、"X++"、"--X" 或 "X--"

// #v1
int finalValueAfterOperations(char** operations, int operationsSize) {
  int x = 0;

  for (int i = 0; i < operationsSize; i++) {
    if (operations[i][1] == '-') --x;
    else ++x;
  }

  return x;
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
  s = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    s[i] = (char *)malloc(sizeof(char) * 100);
    read_line(s[i], 98, stdin);
  }
  printf("%d\n", finalValueAfterOperations(s, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
