#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 正则表达式匹配
// 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
//
//     '.' 匹配任意单个字符
//     '*' 匹配零个或多个前面的那一个元素
//
// 所谓匹配，是要涵盖 整个 字符串 s 的，而不是部分字符串。
//  1 <= s.length <= 20
//  1 <= p.length <= 20
//  s 只包含从 a-z 的小写字母。
//  p 只包含从 a-z 的小写字母，以及字符 . 和 *。
//  保证每次出现字符 * 时，前面都匹配到有效的字符


/*
// se 和 pe 指向的内容都为 '\0'
bool _isMatch(char *ss, char *se, char *ps, char *pe) {
  if (ps >= pe && ss >= se) { // pattern 和 string 都结束说明匹配成功
    return true;
  }

  char *next = ps + 1;
  int result = 0;
  // a*: [当前位置, 第一个不等于 a]
  // .*: [当前位置, 字符串结束]
  // 存在 '*', 尝试零次或多次匹配
  if (next < pe && *next == '*') {
    char cur = *ps;

    if (cur == '.') { // 尝试匹配 .*
      // 逐个扩展, 耗时部分
      for (int i = 0; i <= se - ss; i++) {
        result = _isMatch(ss + i, se, ps + 2, pe);
        if (result) {
          return true;
        }
      }
    } else { // 尝试匹配 [a-z]*
      // 逐个扩展, 耗时部分
      int cnt = 0;
      while (ss + cnt < se && *(ss + cnt) == cur) {
        result = _isMatch(ss + cnt, se, ps + 2, pe);
        if (result) {
          return true;
        }
        cnt++;
      }
      return _isMatch(ss + cnt, se, ps + 2, pe);
    }
  }

  // 尝试匹配单个 '.' 或单个 a-z 的字母
  // 需要确保两个指针都在范围内
  if ((*ps == '.' && ss < se) || *ps == *ss) {
    return _isMatch(ss + 1, se, ps + 1, pe);
  }

  return false;
}
*/

char *text, *pat;
int match_table[25][25];

bool _isMatch(char *ss, char *se, char *ps, char *pe) {
  if (ps >= pe && ss >= se) { // pattern 和 string 都结束说明匹配成功
    return true;
  }

  char *next = ps + 1;
  int j, k;
  // a*: [当前位置, 第一个不等于 a]
  // .*: [当前位置, 字符串结束]
  // 存在 '*', 尝试零次或多次匹配
  if (next < pe && *next == '*') {
    char cur = *ps;

    if (cur == '.') { // 尝试匹配 .*
      // 逐个扩展, 耗时部分
      k = ps + 2 - pat;
      for (int i = 0; i <= se - ss; i++) {
        j = ss + i - text;
        if (match_table[j][k] < 0) {
          if (_isMatch(ss + i, se, ps + 2, pe)) {
            match_table[j][k] = 1;
            return true;
          } else {
            match_table[j][k] = 0;
          }
        } else {
          return match_table[j][k];
        }
      }
    } else { // 尝试匹配 [a-z]*
      // 逐个扩展, 耗时部分
      int cnt = 0;
      k = ps + 2 - pat;
      while (ss + cnt < se && *(ss + cnt) == cur) {
        j = ss + cnt - text;
        if (match_table[j][k] < 0) {
          if (_isMatch(ss + cnt, se, ps + 2, pe)) {
            match_table[j][k] = 1;
            return true;
          } else {
            match_table[j][k] = 0;
          }
        } else {
          return match_table[j][k];
        }
        cnt++;
      }

      j = ss + cnt - text;
      if (match_table[j][k] < 0) {
        if (_isMatch(ss + cnt, se, ps + 2, pe)) {
          match_table[j][k] = 1;
          return true;
        } else {
          match_table[j][k] = 0;
        }
      } else {
        return match_table[j][k];
      }
    }
  }

  // 尝试匹配单个 '.' 或单个 a-z 的字母
  // 需要确保两个指针都在范围内
  if ((*ps == '.' && ss < se) || *ps == *ss) {
    j = ss + 1 - text;
    k = ps + 1 -pat;
    if (match_table[j][k] < 0) {
      if (_isMatch(ss + 1, se, ps + 1, pe)) {
        match_table[j][k] = 1;
        return true;
      } else {
        match_table[j][k] = 0;
      }
    } else {
      return match_table[j][k];
    }
  }

  return false;
}

bool isMatch(char *s, char *p) {
  // se 和 pe 指向的内容都为 '\0'
  char *se = s + strlen(s), *pe = p + strlen(p);
  text = s;
  pat = p;
  memset(match_table, 0xff, sizeof(int) * 23 * 23);
  return _isMatch(s, se, p, pe);
}

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
  char str[24] = { '\0' }, pattern[24] = { '\0' };
  int l1, l2;

  read_line(str, 21, stdin);
  read_line(pattern, 21, stdin);

  l1 = strlen(str);
  l2 = strlen(pattern);

  printf("%d\n", isMatch(str, pattern));

  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
