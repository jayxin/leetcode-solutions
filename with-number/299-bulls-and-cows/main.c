#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 299. 猜数字 游戏 - 你在和朋友一起玩 猜数字（Bulls and Cows） [https://baike.baidu.com/item/%E7%8C%9C%E6%95%B0%E5%AD%97/83200?fromtitle=Bulls+and+Cows&amp;fromid=12003488&amp;fr=aladdin]游戏，该游戏规则如下：
// 写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，你就会给他一个包含下 述信息的提示：
//  * 猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls"，公牛），
//  * 有多少位属于数字猜对了但是位置不对（称为 "Cows"，奶牛）。也就是说， 这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。
// 给你一个秘密数字 secret 和朋友猜测的数字 guess ，请你返回对朋友这次猜测的提示。
// 提示的格式为 "xAyB" ，x 是公牛个数， y 是奶牛个数，A 表示公牛，B 表示奶牛。
// 请注意秘密数字和朋友猜测的数字都可能含有重复数字。
//  
// 示例 1：
// 输入：secret = "1807", guess = "7810"
// 输出："1A3B"
// 解释：数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
// "1807"
//   |
// "7810"
// 示例 2：
// 输入：secret = "1123", guess = "0111"
// 输出："1A1B"
// 解释：数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
// "1123"        "1123"
//   |      or     |
// "0111"        "0111"
// 注意，两个不匹配的 1 中，只有一个会算作奶牛（数字猜对位置不对）。通过重新排列非公牛数字，其中仅有一个 1 可以成为公牛数字。
//  
// 提示：
//  * 1 <= secret.length, guess.length <= 1000
//  * secret.length == guess.length
//  * secret 和 guess 仅由数字组成

// #v1
// 哈希表, 计数
int myItoa(char **s, int n) {
  char *p = *s, *a, *b, c;
  int l = 0;

  // n == 0
  if (!n) {
    p[l++] = '0';
  }

  while (n) {
    p[l++] = '0' + n % 10;
    n /= 10;
  }

  // string end
  p[l] = '\0';

  // reverse
  a = *s;
  b = a + l - 1;
  while (a < b) {
    // swap
    c = *a;
    *a = *b;
    *b = c;

    // forward
    ++a;
    --b;
  }

  // return length of s
  return l;
}

char* getHint(char* secret, char* guess) {
  int map[10] = {0}, x, y, l1, l2, retLen;
  char *s, *g, xs[12], ys[12], *ret;

  // count
  s = secret;
  while (*s) ++map[*s++ - '0'];

  // find x and y
  s = secret;
  g = guess;
  x = 0;
  while (*s) {
    // compare
    if (*s == *g) {
      ++x;
      --map[*s - '0'];
    }

    // forward
    ++s;
    ++g;
  }

  s = secret;
  g = guess;
  y = 0;
  while (*s) {
    // compare
    if (*s != *g && map[*g - '0']) {
      ++y;
      --map[*g - '0'];
    }

    // forward
    ++s;
    ++g;
  }

  // int to ascii
  s = xs;
  l1 = myItoa(&s, x);
  s = ys;
  l2 = myItoa(&s, y);

  ret = (char *)malloc(sizeof(char) * (l1 + l2 + 3));
  retLen = 0;

  // copy
  s = xs;
  while (*s) {
    ret[retLen++] = *s;
    ++s;
  }
  ret[retLen++] = 'A';

  // copy
  s = ys;
  while (*s) {
    ret[retLen++] = *s;
    ++s;
  }
  ret[retLen++] = 'B';

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
  char s[100], g[100];
  read_line(s, 98, stdin);
  read_line(g, 98, stdin);
  printf("%s\n", getHint(s, g));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
