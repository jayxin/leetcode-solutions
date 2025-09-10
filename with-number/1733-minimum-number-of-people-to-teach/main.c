#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1733. 需要教语言的最少人数 - 在一个由 m 个用户组成的社交网络里，我们获取到一些用户之间的好友关系。两个用户之间可以相互沟通的条件是他们都掌握同一门语言。
// 给你一个整数 n ，数组 languages 和数组 friendships ，它们的含义如下：
//  * 总共有 n 种语言，编号从 1 到 n 。
//  * languages[i] 是第 i 位用户掌握的语言集合。
//  * friendships[i] = [u i , v i] 表示 u i 和 vi 为好友关系。
// 你可以选择 一门 语言并教会一些用户，使得所有好友之间都可以相互沟通。请返回你 最少 需要教会多少名用户。
// 请注意，好友关系没有传递性，也就是说如果 x 和 y 是好友，且 y 和 z 是好友， x 和 z 不一定是好友。
//  
// 示例 1：
// 输入：n = 2, languages = [[1],[2],[1,2]], friendships = [[1,2],[1,3],[2,3]]
// 输出：1
// 解释：你可以选择教用户 1 第二门语言，也可以选择教用户 2 第一门语言。
// 示例 2：
// 输入：n = 3, languages = [[2],[1,3],[1,2],[3]], friendships = [[1,4],[1,2],[3,4],[2,3]]
// 输出：2
// 解释：教用户 1 和用户 3 第三门语言，需要教 2 名用户。
//  
// 提示：
//  * 2 <= n <= 500
//  * languages.length == m
//  * 1 <= m <= 500
//  * 1 <= languages[i].length <= n
//  * 1 <= languages[i][j] <= n
//  * 1 <= u i < v i <= languages.length
//  * 1 <= friendships.length <= 500
//  * 所有的好友关系 (u i, v i) 都是唯一的。
//  * languages[i] 中包含的值互不相同。

void print_2d_arr(int **arr, int rows, int *cols);

//// #v1
//void print_range(int **a, int startRow, int endRow, int startCol, int endCol) {
  //for (int i = startRow; i <= endRow; i++) {
    //for (int j = startCol; j <= endCol; j++) {
      //printf("%d ", a[i][j]);
    //}
    //putchar('\n');
  //}
  //putchar('\n');
//}
//
//int *tab, nn, mm;
//
//bool intersect(int *a, int aLen, int *b, int bLen, int l, int r) {
  //int i;
  //memset(tab, 0, nn * sizeof(int));
  //for (i = 0; i < aLen; i++) {
    //tab[a[i]] = 1;
  //}
  //for (i = 0; i < bLen; i++) {
    //if (tab[b[i]]) {
      //return true; // 存在交集
    //}
  //}
  //return false; // 不存在交集, 需要教授语言
//}
//
//// n 种语言, m 个用户
//int minimumTeachings(int n, int** languages, int languagesSize, int* languagesColSize, int** friendships, int friendshipsSize, int* friendshipsColSize) {
  //int m = languagesSize, i, j, l, r, t, ret = 0;
  //mm = m + 1;
  //nn = n + 1;
//
  //// allocate and init
  //// tab
  //tab = (int *)malloc(sizeof(int) * nn);
//
  //// people, 记录哪些用户和好友沟通是需要教授语言的
  //int *people = (int *)malloc(sizeof(int) * mm);
  //memset(people, 0, sizeof(int) * mm);
//
  //// map1, 建立用户和会的语言之间的映射关系
  //int **map1 = (int **)malloc(sizeof(int *) * nn);
  //for (i = 0; i <= n; i++) {
    //map1[i] = (int *)malloc(sizeof(int) * mm);
    //memset(map1[i], 0, sizeof(int) * mm);
  //}
//
  //for (j = 1; j <= m; j++) {
    //for (i = 0; i < languagesColSize[j-1]; i++) {
      //map1[languages[j-1][i]][j] = 1;
    //}
  //}
//
  //// 遍历 friendships
  //for (i = 0; i < friendshipsSize; i++) {
    //l = friendships[i][0];
    //r = friendships[i][1];
//
    //if (l > r) {
      //t = l;
      //l = r;
      //r = t;
    //}
//
    //bool b = intersect(languages[l-1], languagesColSize[l-1], languages[r-1],
        //languagesColSize[r-1], l, r);
//
    //if (!b) {
      //if (people[l] == 0) {
        //people[l] = 1;
      //}
      //if (people[r] == 0) {
        //people[r] = 1;
      //}
    //}
  //}
//
  //int cntt;
  //for (i = 1; i <= n; i++) {
    //cntt = 0;
    //for (j = 1; j <= m; j++) {
      //if (map1[i][j] == 0 && people[j])
        //cntt++;
    //}
    //if (!ret || ret > cntt) ret = cntt;
  //}
//
  ////print_range(map1, 1, n, 0, m);
  ////print_range(langFriendMap, 1, n, 1, m);
//
  //return ret;
//}
//// #v1

//// #v2
//int *tab, nn, mm;
//
//bool intersect(int *a, int aLen, int *b, int bLen, int l, int r) {
  //int i;
  //memset(tab, 0, nn * sizeof(int));
  //for (i = 0; i < aLen; i++) {
    //tab[a[i]] = 1;
  //}
  //for (i = 0; i < bLen; i++) {
    //if (tab[b[i]]) {
      //return true; // 存在交集
    //}
  //}
  //return false; // 不存在交集, 需要教授语言
//}
//
//// n 种语言, m 个用户
//int minimumTeachings(int n, int** languages, int languagesSize, int* languagesColSize, int** friendships, int friendshipsSize, int* friendshipsColSize) {
  //int m = languagesSize, i, j, l, r, ret = 0;
  //mm = m + 1;
  //nn = n + 1;
//
  //// allocate and init
  //// tab
  //tab = (int *)malloc(sizeof(int) * nn);
//
  //// people, 标记哪些用户和好友沟通是需要教授语言的
  //int *people = (int *)malloc(sizeof(int) * mm);
  //memset(people, 0, sizeof(int) * mm);
//
  //// map1, 建立用户和会的语言之间的映射关系
  //int **map1 = (int **)malloc(sizeof(int *) * nn);
  //for (i = 0; i <= n; i++) {
    //map1[i] = (int *)malloc(sizeof(int) * mm);
    //memset(map1[i], 0, sizeof(int) * mm);
  //}
//
  //for (j = 1; j <= m; j++) {
    //for (i = 0; i < languagesColSize[j-1]; i++) {
      //map1[languages[j-1][i]][j] = 1;
    //}
  //}
//
  //// 遍历 friendships
  //for (i = 0; i < friendshipsSize; i++) {
    //l = friendships[i][0];
    //r = friendships[i][1];
//
    //// 已经检测出需要教授, 无需再次检测
    //if (people[l] && people[r]) continue;
//
    //// 检测两个用户的语言是否存在交集
    ////bool b = intersect(languages[l-1], languagesColSize[l-1], languages[r-1],
    ////    languagesColSize[r-1], l, r);
    //bool b = false;
    //for (j = 1; j <= n; j++) {
      //if (map1[j][l] == 1 && map1[j][l] == map1[j][r]) {
        //b = true;
        //break;
      //}
    //}
//
    //if (!b) {
      //people[l] = 1;
      //people[r] = 1;
    //}
  //}
//
  //int cntt;
  //for (i = 1; i <= n; i++) {
    //cntt = 0;
    //for (j = 1; j <= m; j++) {
      //if (map1[i][j] == 0 && people[j])
        //cntt++;
    //}
    //if (!ret || ret > cntt) ret = cntt;
  //}
//
  //return ret;
//}
//// #v2

// #v3
// n 种语言, m 个用户
int minimumTeachings(int n, int** languages, int languagesSize, int* languagesColSize, int** friendships, int friendshipsSize, int* friendshipsColSize) {
  int m = languagesSize, mm = m + 1, nn = n + 1, i, j, l, r, ret = 1000;
  bool b;

  // allocate and init
  // people, 标记哪些用户和好友沟通是需要教授语言的
  char people[510] = {0};

  // map1, 建立用户和会的语言之间的映射关系
  char **map1 = (char **)malloc(sizeof(char *) * nn);
  for (i = 0; i <= n; i++) {
    map1[i] = (char *)malloc(sizeof(char) * mm);
    memset(map1[i], 0, sizeof(char) * mm);
  }

  for (j = 1; j <= m; j++) {
    for (i = 0; i < languagesColSize[j-1]; i++) {
      map1[languages[j-1][i]][j] = 1;
    }
  }

  // 遍历 friendships
  for (i = 0; i < friendshipsSize; i++) {
    l = friendships[i][0];
    r = friendships[i][1];

    // 已经检测出需要教授, 无需再次检测
    if (people[l] && people[r]) continue;

    // 检测两个用户的语言是否存在交集
    b = false;
    for (j = 1; j <= n; j++) {
      if (map1[j][l] == 1 && map1[j][r] == 1) { // 存在共通语言
        b = true;
        break;
      }
    }

    if (!b) {
      people[l] = 1;
      people[r] = 1;
    }
  }

  // 遍历每种语言
  int cntt;
  for (i = 1; i <= n; i++) {
    cntt = 0;
    for (j = 1; j <= m; j++) { // 针对第 i 种语言, 对需要教授的用户进行计数
      if (map1[i][j] == 0 && people[j]) // 用户 j 需要被教授, 且 j 不会语言 i
        cntt++;
    }
    // 更新最小值
    if (ret > cntt) ret = cntt;
  }

  return ret;
}
// #v3

// read 2d array
int** read_2d_arr(int *rows, int **cols) {
  scanf("%d", rows);
  int i, j, c;
  int **ret = (int **)malloc(sizeof(int *) * (*rows));
  *cols = (int *)malloc(sizeof(int) * (*rows));
  for (i = 0; i < *rows; i++) {
    scanf("%d", &c);
    ret[i] = (int *)malloc(sizeof(int) * c);
    (*cols)[i] = c;
  }

  for (i = 0; i < *rows; i++) {
    for (j = 0; j < (*cols)[i]; j++) {
      scanf("%d", &ret[i][j]);
    }
  }
  return ret;
}

void print_2d_arr(int **arr, int rows, int *cols) {
  if (!arr || rows <= 0) {
    putchar('\n');
    return ;
  }
  int i, j;

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols[i]; j++) {
      if (j) {
        putchar(' ');
      }
      printf("%d", arr[i][j]);
    }
    putchar('\n');
  }
}

void free_2d_arr(int **arr, int rows) {
  if (!arr) {
    return;
  }
  for (int i = 0; i < rows; i++) {
    free(arr[i]);
  }
  free(arr);
}

int main(int argc, char *argv[])
{
  // definition
  int n,
      **languages, languagesSize, *languagesColSize,
      **friendships, friendshipsSize, *friendshipsColSize;

  // input
  scanf("%d", &n);
  languages = read_2d_arr(&languagesSize, &languagesColSize);
  friendships = read_2d_arr(&friendshipsSize, &friendshipsColSize);
  //printf("languages: \n");
  //print_2d_arr(languages, languagesSize, languagesColSize);
  //printf("friendships:\n");
  //print_2d_arr(friendships, friendshipsSize, friendshipsColSize);

  // compute and output
  printf("%d\n", minimumTeachings(n, languages, languagesSize, languagesColSize,
        friendships, friendshipsSize, friendshipsColSize));

  free_2d_arr(languages, languagesSize);
  free_2d_arr(friendships, friendshipsSize);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
