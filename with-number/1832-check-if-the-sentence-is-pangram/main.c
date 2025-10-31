#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1832. 判断句子是否为全字母句 - 全字母句 指包含英语字母表中每个字母至少一次的句子。
// 给你一个仅由小写英文字母组成的字符串 sentence ，请你判断 sentence 是否为 全字母句 。
// 如果是，返回 true ；否则，返回 false 。
//  
// 示例 1：
// 输入：sentence = "thequickbrownfoxjumpsoverthelazydog"
// 输出：true
// 解释：sentence 包含英语字母表中每个字母至少一次。
// 示例 2：
// 输入：sentence = "leetcode"
// 输出：false
//  
// 提示：
//  * 1 <= sentence.length <= 1000
//  * sentence 由小写英语字母组成

// #v1
#define STD_SET 134217726

bool checkIfPangram(char* sentence) {
  int set = 0;
  //int stdSet = 0;

  //for (int i = 1; i <= 26; i++) {
  //  stdSet |= 1 << i;
  //}
  //printf("%d\n", stdSet);

  while (*sentence) {
    set |= 1 << (*sentence & 0x1f);
    ++sentence;
  }

  return set == STD_SET;
}
// #v1

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  if (checkIfPangram(s)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
