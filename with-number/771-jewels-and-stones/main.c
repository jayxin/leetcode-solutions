#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 771. 宝石与 石头 -  给你一个字符串 jewels 代表石头中宝石的类型，另有一个字符串 stones 代表你 拥有的石头。 stones 中每个字符代表了一种你拥有的石头的类型，你想知道你拥有的石头 中有多少是宝石。
// 字母区分大小写，因此 "a" 和 "A" 是不同类型的石头。
//  
// 示例 1：
// 输入：jewels = "aA", stones = "aAAbbbb"
// 输出：3
// 示例 2：
// 输入：jewels = "z", stones = "ZZ"
// 输出：0
//  
// 提示：
//  * 1 &lt;= jewels.length, stones.length &lt;= 50
//  * jewels 和 stones 仅由英文字母组成
//  * jewels 中的所有字符都是 唯一的

//// #v1
//// hash map
//int numJewelsInStones(char* jewels, char* stones) {
  //int ret = 0;
  //char tab[52] = {0};
//
  //while (*jewels) {
    //if (((*jewels) | 0x20) == *jewels) {
      //tab[*jewels - 'a'] = 1;
    //} else {
      //tab[*jewels - 'A' + 26] = 1;
    //}
//
    //++jewels;
  //}
//
  //while (*stones) {
    //if (((*stones) | 0x20) == *stones) {
      //if (tab[*stones - 'a']) ++ret;
    //} else {
      //if (tab[*stones - 'A' + 26]) ++ret;
    //}
//
    //++stones;
  //}
//
  //return ret;
//}
//// #v1

// #v2
// bit operation
int numJewelsInStones(char* jewels, char* stones) {
  int ret = 0;
  int64_t mask = 0;

  while (*jewels) {
    mask |= 1LL << ((*jewels) & 63);
    ++jewels;
  }

  while (*stones) {
    ret += (mask >> ((*stones) & 63)) & 1;
    ++stones;
  }

  return ret;
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
  char s[100], p[100];
  read_line(s, 99, stdin);
  read_line(p, 99, stdin);
  printf("%d\n", numJewelsInStones(s, p));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
