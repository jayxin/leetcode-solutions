#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3227.  字符串元音游戏 - 小红和小明在玩一个字符串元音游戏。
// 给你一个字符串 s，小红和小明将轮流参与游戏，小红 先 开始：
//  * 在小红的回合，她必须移除 s 中包含 奇数 个元音的任意 非空 子字符串。
//  * 在小明的回合，他必须移除 s 中包含 偶数 个元音的任意 非空 子字符串。
// 第一个无法在其回合内进行移除操作的玩家输掉游戏。假设小红和小明都采取 最优策略 。
// 如果小红赢得游戏，返回 true，否则返回 false。
// 英文元音字母包括：a, e, i, o, 和 u。
//  
// 示例 1：
// 输入： s = &quot;leetcoder&quot;
// 输出： true
// 解释：
// 小红可以执行如下移除操作来赢得游戏：
//  * 小红先手，她可以移除加下划线的子字符串 s = &quot;leetcoder&quot;，其中包含 3  个元音。结果字符串为 s = &quot;der&quot;。
//  * 小明接着，他可以移除加下划线的子字符串 s = &quot;der&quot;，其中包含 0 个元音 。结果字符串为 s = &quot;er&quot;。
//  * 小红再次操作，她可以移除整个字符串 s = &quot;er&quot;，其中包含 1 个元音。
//  * 又轮到小明，由于字符串为空，无法执行移除操作，因此小红赢得游戏。
// 示例 2：
// 输入： s = &quot;bbcd&quot;
// 输出： false
// 解释：
// 小红在她的第一回合无法执行移除操作，因此小红输掉了游戏。
//  
// 提示：
//  * 1 <= s.length <= 105
//  * s 仅由小写英文字母组成。

//// #v1
//// 元音字母个数为奇数则小红必然赢
//// 元音字母为偶数,
////    若为 0, 则小红必输;
////    非 0, 则小红可通过保持元音字母个数为奇数取胜
//bool doesAliceWin(char* s) {
  //char vowels[5] = {'a', 'e', 'i', 'o', 'u'}, *p;
  //int vowelCnt = 0, i, l, r, m;
//
  //p = s;
  //while (*p) {
    //// binary search
    //l = 0;
    //r = 4;
    //while (l < r) {
      //m = (l + r + 1) >> 1;
      //if (vowels[m] <= *p) {
        //l = m;
      //} else {
        //r = m - 1;
      //}
    //}
    //if (vowels[l] == *p) ++vowelCnt;
//
    //p++;
  //}
//
  //if (vowelCnt == 0) return false;
//
  //return true;
//}
//// #v1

// #v2
bool doesAliceWin(char* s) {
  char *p, f = 0;

  p = s;
  while (*p) {
    if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u') {
      // 存在元音字母且非 0
      f = 1;
      break;
    }

    p++;
  }

  if (f == 0) return false;

  // 奇数和非零偶数
  return true;
}
// #v2

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
  if (doesAliceWin(s)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
