#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 567. 字符 串的排列 - 给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的 排列。如 果是，返回 true ；否则，返回 false 。
// 换句话说，s1 的排列之一是 s2 的 子串 。
//  
// 示例 1：
// 输入：s1 = "ab" s2 = "eidbaooo"
// 输出：true
// 解释：s2 包含 s1 的排列之一 ("ba").
// 示例 2：
// 输入：s1= "ab" s2 = "eidboaoo"
// 输出：false
//  
// 提示：
//  * 1 <= s1.length, s2.length <= 104
//  * s1 和 s2 仅包含小写字母

//// #v1
//// 双指针, 滑动窗口, 哈希表, 计数, 集合
//bool checkInclusion(char* s1, char* s2) {
  //int s1Set = 0, s1Cnts[26] = {0}, s2Set = 0, s2Cnts[26] = {0};
  //int s1Len = 0, i, t;
  //char *p, *q;
//
  //p = s1;
  //while (*p) {
    //t = *p - 'a';
    //// 记录 s1 中出现的字母
    //s1Set |= 1 << t;
    //// 记录 s1 中字母出现的频率
    //++s1Cnts[t];
    //// 记录 s1 的长度
    //++s1Len;
//
    //++p;
  //}
//
  //q = p = s2;
  //i = 0;
  //while (*q) {
    //if (i == s1Len) {
      //if (s1Set == s2Set) { // 检查 s1 和 s2 的子串是否包含同样的字母
        //int f = 1;
        //for (int j = 0; j < 26; j++) { // 检查 s1 和 s2 的子串字母频率是否相等
          //if (s1Cnts[j] != s2Cnts[j]) {
            //f = 0;
            //break;
          //}
        //}
        //if (f) return true;
      //}
//
      //t = *p - 'a';
      //// 减少 *p 的计数
      //--s2Cnts[t];
      //// 是否将 *p 从集合中移除
      //if (s2Cnts[t] == 0) s2Set &= ~(1 << t);
      //// 窗口长度减少
      //--i;
      //// 窗口的左边界增加
      //++p;
    //} else {
      //t = *q - 'a';
      //// 增加 *q 的计数
      //++s2Cnts[t];
      //// 是否将 *p 加入集合
      //if (s2Cnts[t] == 1) s2Set |= 1 << t;
      //// 窗口的右边界增加
      //++q;
      //// 窗口的长度增加
      //++i;
    //}
  //}
//
  //// edge cases, 比如 s1=="a" s2=="a"
  //if (i == s1Len && s1Set == s2Set) {
    //int f = 1;
    //for (int j = 0; j < 26; j++) { // 检查 s1 和 s2 的子串字母频率是否相等
      //if (s1Cnts[j] != s2Cnts[j]) {
        //f = 0;
        //break;
      //}
    //}
    //if (f) return true;
  //}
//
  //return false;
//}
//// #v1

// #v2
// 双指针, 滑动窗口, 哈希表, 计数, 集合
// 减少冗余代码
bool checkInclusion(char* s1, char* s2) {
  int s1Set = 0, s1Cnts[26] = {0}, s2Set = 0, s2Cnts[26] = {0};
  int s1Len = 0, i, t;
  char *p, *q;

  p = s1;
  while (*p) {
    t = *p - 'a';
    // 记录 s1 中出现的字母
    s1Set |= 1 << t;
    // 记录 s1 中字母出现的频率
    ++s1Cnts[t];
    // 记录 s1 的长度
    ++s1Len;

    ++p;
  }

  q = p = s2;
  i = 0;
  while (*q) {
    t = *q - 'a';
    // 增加 *q 的计数
    ++s2Cnts[t];
    // 是否将 *p 加入集合
    if (s2Cnts[t] == 1) s2Set |= 1 << t;
    // 窗口的右边界增加
    ++q;
    // 窗口的长度增加
    ++i;

    if (i == s1Len) {
      if (s1Set == s2Set) { // 检查 s1 和 s2 的子串是否包含同样的字母
        int f = 1;
        for (int j = 0; j < 26; j++) { // 检查 s1 和 s2 的子串字母频率是否相等
          if (s1Cnts[j] != s2Cnts[j]) {
            f = 0;
            break;
          }
        }
        if (f) return true;
      }

      t = *p - 'a';
      // 减少 *p 的计数
      --s2Cnts[t];
      // 是否将 *p 从集合中移除
      if (s2Cnts[t] == 0) s2Set &= ~(1 << t);
      // 窗口长度减少
      --i;
      // 窗口的左边界增加
      ++p;
    }
  }

  return false;
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
  char s1[100], s2[100];
  read_line(s1, 98, stdin);
  read_line(s2, 98, stdin);
  if (checkInclusion(s1, s2)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
