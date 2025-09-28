#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 290. 单词规律 - 给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
// 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之 间存在着双向连接的对应规律。具体来说：
//  * pattern 中的每个字母都 恰好 映射到 s 中的一个唯一单词。
//  * s 中的每个唯一单词都 恰好 映射到 pattern 中的一个字母。
//  * 没有两个字母映射到同一个单词，也没有两个单词映射到同一个字母。
//  
// 示例1:
// 输入: pattern = "abba", s = "dog cat cat dog"
// 输出: true
// 示例 2:
// 输入:pattern = "abba", s = "dog cat cat fish"
// 输出: false
// 示例 3:
// 输入: pattern = "aaaa", s = "dog cat cat dog"
// 输出: false
//  
// 提示:
//  * 1 &lt;= pattern.length &lt;= 300
//  * pattern 只包含小写英文字母
//  * 1 &lt;= s.length &lt;= 3000
//  * s 只包含小写英文字母和 ' '
//  * s 不包含 任何前导或尾随对空格
//  * s 中每个单词都被 单个空格 分隔

// #v1
bool wordPattern(char* pattern, char* s) {
  char *t[26] = {NULL}, *p, *start, *end, *e;
  int len = strlen(s), idx, i;

  e = s + len;
  p = pattern;
  start = s;

  while (start < e) {
    // s 字符串中有剩余但 pattern 已经匹配完毕
    if (*p == '\0') return false;

    // 寻找单词的开头
    while (*start == ' ') ++start;

    // 寻找单词的结尾的后一个位置
    end = start;
    while (*end != ' ' && *end != '\0') ++end;

    idx = *p - 'a';
    if (t[idx] == NULL) { // 哈希表中不存在映射关系
      // NOTE: 在记录到哈希表前应该先判断单词是否已在哈希表中出现
      // 因为 idx 和单词应该是一一对应的关系, 不能是多对一
      char *q, *x;

      for (i = 0; i < 26; i++) {
        if (t[i]) {
          x = t[i];
          q = start;

          while (q < end && *x) {
            if (*q != *x) break;
            ++q;
            ++x;
          }

          // 哈希表中已经存在该单词, 存在多对一的关系
          if (q == end && *x == '\0') return false;
        }
      }

      // 记录字符串的映射关系
      t[idx] = (char *)malloc(sizeof(char) * (end - start + 1));
      i = 0;
      while (start < end) t[idx][i++] = *start++;
      // string end
      t[idx][i] = '\0';
    } else { // 哈希表中存在映射关系
             // 检查单词与哈希表中的字符串是否相等
      char *q = t[idx];

      while (start < end && *q) {
        if (*start != *q) return false;
        ++start;
        ++q;
      }

      // 字符串未匹配完成
      if (start < end || *q) return false;
    }

    ++p;
  }

  // pattern 未匹配完
  if (*p) return false;

  return true;
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
  char p[100], s[100];
  read_line(p, 99, stdin);
  read_line(s, 99, stdin);
  if (wordPattern(p, s)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
