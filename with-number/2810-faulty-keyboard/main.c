#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2810. 故障键 盘 - 你的笔记本键盘存在故障，每当你在上面输入字符 'i' 时，它会反转你所 写的字符串。而输入其他字符则可以正常工作。
// 给你一个下标从 0 开始的字符串 s ，请你用故障键盘依次输入每个字符。
// 返回最终笔记本屏幕上输出的字符串。
//  
// 示例 1：
// 输入：s = "string"
// 输出："rtsng"
// 解释：
// 输入第 1 个字符后，屏幕上的文本是："s" 。
// 输入第 2 个字符后，屏幕上的文本是："st" 。
// 输入第 3 个字符后，屏幕上的文本是："str" 。
// 因为第 4 个字符是 'i' ，屏幕上的文本被反转，变成 "rts" 。
// 输入第 5 个字符后，屏幕上的文本是："rtsn" 。
// 输入第 6 个字符后，屏幕上的文本是： "rtsng" 。
// 因此，返回 "rtsng" 。
// 示例 2：
// 输入：s = "poiinter"
// 输出："ponter"
// 解释：
// 输入第 1 个字符后，屏幕上的文本是："p" 。
// 输入第 2 个字符后，屏幕上的文本是："po" 。
// 因为第 3 个字符是 'i' ，屏幕上的文本被反转，变成 "op" 。
// 因为第 4 个字符是 'i' ，屏幕上的文本被反转，变成 "po" 。
// 输入第 5 个字符后，屏幕上的文本是："pon" 。
// 输入第 6 个字符后，屏幕上的文本是："pont" 。
// 输入第 7 个字符后，屏幕上的文本是："ponte" 。
// 输入第 8 个字符后，屏幕上的文本是："ponter" 。
// 因此，返回 "ponter" 。
//  
// 提示：
//  * 1 &lt;= s.length &lt;= 100
//  * s 由小写英文字母组成
//  * s[0] != 'i'

// #v1
void reverse(char *s, char *e) {
  if (!s || !e || s == e) return ;

  char c;
  while (s < e) {
    c = *s;
    *s = *e;
    *e = c;
    ++s;
    --e;
  }
}

char* finalString(char* s) {
  char *ret = (char *)malloc(sizeof(char) * 101), *p = s;
  int retLen = 0;

  while (*p) {
    if (*p == 'i') {
      reverse(ret, ret + retLen - 1);
    } else {
      ret[retLen++] = *p;
    }
    ++p;
  }

  // string end
  ret[retLen] = '\0';

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
  char s[100];
  read_line(s, 99, stdin);
  printf("%s\n", finalString(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
