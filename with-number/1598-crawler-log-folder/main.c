#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1598. 文件夹操作日志搜集器 - 每当用户执行变更文件夹操作时，LeetCode 文件系统都会保存一条日志记录。
// 下面给出对变更操作的说明：
//  * "../" ：移动到当前文件夹的父文件夹。如果已经在主文件夹下，则 继续停 留在当前文件夹 。
//  * "./" ：继续停留在当前文件夹。
//  * "x/" ：移动到名为 x 的子文件夹中。题目数据 保证总是存在文件夹 x 。
// 给你一个字符串列表 logs ，其中 logs[i] 是用户在 ith 步执行的操作。
// 文件系统启动时位于主文件夹，然后执行 logs 中的操作。
// 执行完所有变更文件夹操作后，请你找出 返回主文件夹所需的最小步数 。
//  
// 示例 1：
// [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/09/26/sample_11_1957.png]
// 输入：logs = ["d1/","d2/","../","d21/","./"]
// 输出：2
// 解释：执行 "../" 操作变更文件夹 2 次，即可回到主文件夹
// 示例 2：
// [https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/09/26/sample_22_1957.png]
// 输入：logs = ["d1/","d2/","./","d3/","../","d31/"]
// 输出：3
// 示例 3：
// 输入：logs = ["d1/","../","../","../"]
// 输出：0
//  
// 提示：
//  * 1 <= logs.length <= 103
//  * 2 <= logs[i].length <= 10
//  * logs[i] 包含小写英文字母，数字，'.' 和 '/'
//  * logs[i] 符合语句中描述的格式
//  * 文件夹名称由小写英文字母和数字组成

// #v1
int minOperations(char** logs, int logsSize) {
  int t = 0;

  for (int i = 0; i < logsSize; i++) {
    if (*(logs[i]) != '.') {
      ++t;
    } else {
      if (t > 0 && strlen(logs[i]) == 3) --t;
    }
  }

  return t;
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
  printf("%d\n", minOperations(s, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
