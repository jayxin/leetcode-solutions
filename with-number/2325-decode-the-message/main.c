#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 2325. 解密消 息 - 给你字符串 key 和 message ，分别表示一个加密密钥和一段加密消息。解密 message 的步骤如下：
//  1. 使用 key 中 26 个英文小写字母第一次出现的顺序作为替换表中的字母 顺序 。
//  2. 将替换表与普通英文字母表对齐，形成对照表。
//  3. 按照对照表 替换 message 中的每个字母。
//  4. 空格 ' ' 保持不变。
//  * 例如，key = "happy boy"（实际的加密密钥会包含字母表中每个字母 至少一次），据此，可以得到部分对照表（'h' -> 'a'、'a' -> 'b'、'p' -> 'c'、'y' -> 'd'、'b' -> 'e'、'o' -> 'f'） 。
// 返回解密后的消息。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2022/05/08/ex1new4.jpg]
// 输入：key = "the quick brown fox jumps over the lazy dog", message = "vkbs bs t suepuv"
// 输出："this is a secret"
// 解释：对照表如上图所示。
// 提取 "the quick brown fox jumps over the lazy dog" 中每个字母的首次出现可以得到替换表。
// 示例 2：
// [https://assets.leetcode.com/uploads/2022/05/08/ex2new.jpg]
// 输入：key = "eljuxhpwnyrdgtqkviszcfmabo", message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb"
// 输出："the five boxing wizards jump quickly"
// 解释：对照表如上图所示。
// 提取 "eljuxhpwnyrdgtqkviszcfmabo" 中每个字母的首次出现可以得到替换表。
//  
// 提示：
//  * 26 <= key.length <= 2000
//  * key 由小写英文字母及 ' ' 组成
//  * key 包含英文字母表中每个字符（'a' 到 'z'）至少一次
//  * 1 <= message.length <= 2000
//  * message 由小写英文字母和 ' ' 组成

// #v1
char* decodeMessage(char* key, char* message) {
  int set = 0, cnt = 0, pos;
  char map[26], *s = message;

  while (*key) {
    if (*key & 0x40) { // 非空格(字母)
      pos = *key & 0x1f;

      if (((set >> pos) & 1) == 0) { // *key 还未出现过
        // construct map
        map[*key - 'a'] = cnt++;

        // add *key to set
        set |= 1 << pos;

        if (cnt == 26) break;
      }
    }

    // forward
    ++key;
  }

  while (*s) {
    if (*s & 0x40) { // 字母
      *s = map[*s-'a'] + 'a';
    }

    ++s;
  }

  return message;
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
  char s1[200], s2[200];
  read_line(s1, 198, stdin);
  read_line(s2, 198, stdin);
  printf("%s\n", decodeMessage(s1, s2));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
