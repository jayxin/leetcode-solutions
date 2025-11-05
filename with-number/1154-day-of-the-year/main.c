#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 1154.  一年中的第几天 - 给你一个字符串 date ，按 YYYY-MM-DD 格式表示一个 现行公元纪年法 [https://baike.baidu.com/item/公元/17855] 日期。返回该日期是当年的第几天。
//  
// 示例 1：
// 输入：date = "2019-01-09"
// 输出：9
// 解释：给定日期是2019年的第九天。
// 示例 2：
// 输入：date = "2019-02-10"
// 输出：41
//  
// 提示：
//  * date.length == 10
//  * date[4] == date[7] == '-'，其他的 date[i] 都是数字
//  * date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日

// #v1
int isLeapYear(int y) {
  if (!(y % 100)) {
    if (y % 400) return 0;
    else return 1;
  }

  if (!(y % 4)) return 1;

  return 0;
}

int dayOfYear(char* date) {
  char month2DayMap[13];
  int year, month, day, ret = 0;

  month2DayMap[1] = 31;
  month2DayMap[3] = 31;
  month2DayMap[5] = 31;
  month2DayMap[7] = 31;
  month2DayMap[8] = 31;
  month2DayMap[10] = 31;
  month2DayMap[12] = 31;

  month2DayMap[4] = 30;
  month2DayMap[6] = 30;
  month2DayMap[9] = 30;
  month2DayMap[11] = 30;

  year = 0;
  while (*date && *date != '-') {
    year = year * 10 + *date - '0';
    ++date;
  }
  ++date;

  month = 0;
  while (*date && *date != '-') {
    month = month * 10 + *date - '0';
    ++date;
  }
  ++date;

  day = 0;
  while (*date) {
    day = day * 10 + *date - '0';
    ++date;
  }

  month2DayMap[2] = 28 + isLeapYear(year);

  --month;
  for (int i = 1; i <= month; i++) {
    ret += month2DayMap[i];
  }

  ret += day;

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  char s[100];
  scanf("%s", s);
  printf("%d\n", dayOfYear(s));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
