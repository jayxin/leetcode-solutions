#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 682. 棒球比赛 - 你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的 得分可能会影响以后几回合的得分。
// 比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你 需要记录的第 i 项操作，ops 遵循下述规则：
//  1. 整数 x - 表示本回合新获得分数 x
//  2. "+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此 操作时前面总是存在两个有效的分数。
//  3. "D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此 操作时前面总是存在一个有效的分数。
//  4. "C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作 时前面总是存在一个有效的分数。
// 请你返回记录中所有得分的总和。
//  
// 示例 1：
// 输入：ops = ["5","2","C","D","+"]
// 输出：30
// 解释：
// "5" - 记录加 5 ，记录现在是 [5]
// "2" - 记录加 2 ，记录现在是 [5, 2]
// "C" - 使前一次得分的记录无效并将其移除，记录现在是 [5].
// "D" - 记录加 2 * 5 = 10 ，记录现在是 [5, 10].
// "+" - 记录加 5 + 10 = 15 ，记录现在是 [5, 10, 15].
// 所有得分的总和 5 + 10 + 15 = 30
// 示例 2：
// 输入：ops = ["5","-2","4","C","D","9","+","+"]
// 输出：27
// 解释：
// "5" - 记录加 5 ，记录现在是 [5]
// "-2" - 记录加 -2 ，记录现在是 [5, -2]
// "4" - 记录加 4 ，记录现在是 [5, -2, 4]
// "C" - 使前一次得分的记录无效并将其移除，记录现在是 [5, -2]
// "D" - 记录加 2 * -2 = -4 ，记录现在是 [5, -2, -4]
// "9" - 记录加 9 ，记录现在是 [5, -2, -4, 9]
// "+" - 记录加 -4 + 9 = 5 ，记录现在是 [5, -2, -4, 9, 5]
// "+" - 记录加 9 + 5 = 14 ，记录现在是 [5, -2, -4, 9, 5, 14]
// 所有得分的总和 5 + -2 + -4 + 9 + 5 + 14 = 27
// 示例 3：
// 输入：ops = ["1"]
// 输出：1
//  
// 提示：
//  * 1 <= ops.length <= 1000
//  * ops[i] 为 "C"、"D"、"+"，或者一个表示整数的字符 串。整数范围是 [-3 * 104, 3 * 104]
//  * 对于 "+" 操作，题目数据保证记录此操作时前面总是存在两个有效的分数
//  * 对于 "C" 和 "D" 操作，题目数据保证记录此操作时前面总是存在一个有效的分数

// #v1
// stack
int calPoints(char** operations, int operationsSize) {
  int a[operationsSize], top = -1, ret = 0;
  char *s;

  for (int i = 0; i < operationsSize; i++) {
    s = operations[i];

    switch (*s) {
      case 'C':
        --top;
        break;
      case 'D':
        a[++top] = a[top] * 2;
        break;
      case '+':
        a[++top] = a[top] + a[top-1];
        break;
      default:
        int sign = (*s == '-') ? -1 : 1, v = 0;
        if (sign == -1) ++s;
        while (*s) v = v * 10 + (*s++) - '0';
        v *= sign;
        a[++top] = v;
    }
  }

  for (int i = 0; i <= top; i++) ret += a[i];

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
  char **s;
  int n;
  scanf("%d\n", &n);
  s = calloc(n, sizeof(char *));
  for (int i = 0; i < n; i++) {
    s[i] = calloc(50, sizeof(char));
    read_line(s[i], 48, stdin);
  }
  printf("%d\n", calPoints(s, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
