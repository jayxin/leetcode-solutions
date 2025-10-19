#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1625. 执行操作后字典序最小的字符串 - 给你一个字符串 s 以及两个整数 a 和 b 。其中，字符串 s 的长度为偶数，且仅由数字 0 到 9 组成。
// 你可以在 s 上按任意顺序多次执行下面两个操作之一：
//  * 累加：将  a 加到 s 中所有下标为奇数的元素上（下标从 0 开始）。数字一旦超过 9  就会变成 0，如此循环往复。例如，s = "3456" 且 a = 5，则执行此操作后 s  变成 "3951"。
//  * 轮转：将 s 向右轮转 b 位。例如，s = "3456" 且 b = 1，则执行此操作后 s 变成 "6345"。
// 请你返回在 s 上执行上述操作任意次后可以得到的 字典序最小 的字符串。
// 如果两个字符串长度相同，那么字符串 a 字典序比字符串 b 小可以这样定义：在 a 和 b  出现不同的第一个位置上，字符串 a 中的字符出现在字母表中的时间早于 b 中的对应字符 。例如，"0158” 字典序比 "0190" 小，因为不同的第一个位置是在第三个 字符，显然 '5' 出现在 '9' 之前。
//  
// 示例 1：
// 输入：s = "5525", a = 9, b = 2
// 输出："2050"
// 解释：执行操作如下：
// 初态："5525"
// 轮转："2555"
// 累加："2454"
// 累加："2353"
// 轮转："5323"
// 累加："5222"
// 累加："5121"
// 轮转："2151"
// 累加："2050"​​​​​
// 无法获得字典序小于 "2050" 的字符串。
// 示例 2：
// 输入：s = "74", a = 5, b = 1
// 输出："24"
// 解释：执行操作如下：
// 初态："74"
// 轮转："47"
// 累加："42"
// 轮转："24"​​​​​
// 无法获得字典序小于 "24" 的字符串。
// 示例 3：
// 输入：s = "0011", a = 4, b = 2
// 输出："0011"
// 解释：无法获得字典序小于 "0011" 的字符串。
//  
// 提示：
//  * 2 &lt;= s.length &lt;= 100
//  * s.length 是偶数
//  * s 仅由数字 0 到 9 组成
//  * 1 &lt;= a &lt;= 9
//  * 1 &lt;= b &lt;= s.length - 1

// #v1
// 枚举, 排序
char* findLexSmallestString(char* s, int a, int b) {
  int n = strlen(s), i, j, k, l, m;
  char *ret = (char *)malloc(sizeof(char)*(n+1)), v[n], tmp[2*n+1], p[n+1];

  // init
  memset(v, 0, sizeof(char)*n);
  sprintf(ret, "%s", s);
  // 延长 s, 方便轮转
  sprintf(tmp, "%s%s", s, s);

  // compute
  for (i = 0; !v[i]; i = (i+b)%n) { // 枚举轮转次数
    // 标记 i 位置已被轮转过
    v[i] = 1;

    for (j = 0; j < 10; j++) { // 枚举奇数索引的累加次数
      m = (b & 1) ? 9 : 0;

      for (k = 0; k <= m; k++) { // 枚举偶数索引的累加次数
        // 复制轮转后的结果到 p
        strncpy(p, tmp+i, n);
        // string end
        p[n] = '\0';

        // 对奇数索引的数字进行累加
        for (l = 1; l < n; l += 2) {
          p[l] = (p[l] - '0' + j * a) % 10 + '0';
        }

        // 对偶数索引的数字进行累加
        for (l = 0; l < n; l += 2) {
          p[l] = (p[l] - '0' + k * a) % 10 + '0';
        }

        // 若 p < ret 则取而代之
        if (strcmp(p, ret) < 0) sprintf(ret, "%s", p);
      }
    }
  }

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
  int a, b;
  char s[100];
  scanf("%d%d\n", &a, &b);
  read_line(s, 98, stdin);
  printf("%s\n", findLexSmallestString(s, a, b));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
