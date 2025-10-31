#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 2001. 可互换矩形的组数 - 用一个下标从 0 开始的二维整数数组 rectangles 来表示 n 个矩形 ，其中 rectangles[i] = [widthi, heighti] 表示第 i 个矩形的宽度和高度。
// 如果两个矩形 i 和 j（i < j）的宽高比相同，则认为这两个矩形 可互换 。更规范的说法是，两个矩形满足 widthi/heighti == widthj/heightj（使用实数除法而非整数除法），则认为这两个矩形 可互换 。
// 计算并返回 rectangles 中有多少对 可互换 矩形。
//  
// 示例 1：
// 输入：rectangles = [[4,8],[3,6],[10,20],[15,30]]
// 输出：6
// 解释：下面按下标（从 0 开始）列出可互换矩形的配对情况：
// - 矩形 0 和矩形 1 ：4/8 == 3/6
// - 矩形 0 和矩形 2 ：4/8 == 10/20
// - 矩形 0 和矩形 3 ：4/8 == 15/30
// - 矩形 1 和矩形 2 ：3/6 == 10/20
// - 矩形 1 和矩形 3 ：3/6 == 15/30
// - 矩形 2 和矩形 3 ：10/20 == 15/30
// 示例 2：
// 输入：rectangles = [[4,5],[7,8]]
// 输出：0
// 解释：不存在成对的可互换矩形。
//  
// 提示：
//  * n == rectangles.length
//  * 1 <= n <= 105
//  * rectangles[i].length == 2
//  * 1 <= widthi, heighti <= 105

//// #v1
//struct HashNode {
  //int val, cnt, h;
  //struct HashNode *next;
//};
//
//struct HashTable {
  //int c;
  //struct HashNode **a;
//};
//
//struct HashNode* NewHashNode(int val, int h) {
  //struct HashNode *ret = calloc(1, sizeof(struct HashNode));
//
  //ret->val = val;
  //ret->h = h;
  //ret->cnt = 1;
//
  //return ret;
//}
//
//struct HashTable* NewHashTable(int c) {
  //struct HashTable *ret = calloc(1, sizeof(struct HashTable));
//
  //ret->c = c;
  //ret->a = calloc(c, sizeof(struct HashNode *));
  //for (int i = 0; i < c; i++) ret->a[i] = NULL;
//
  //return ret;
//}
//
//#define HashFunc(t, k) ((k) % (t->c))
//
//void HashTableAdd(struct HashTable *t, int val, int height) {
  //int h = HashFunc(t, val);
  //struct HashNode *n, *p = t->a[h], *q = p;
//
  //while (q) {
    //if (q->val == val && q->h == height) break;
    //q = q->next;
  //}
//
  //if (q) {
    //q->cnt += 1;
    //return ;
  //}
//
  //n = NewHashNode(val, height);
  //t->a[h] = n;
  //n->next = p;
//}
//
//int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
//
//long long interchangeableRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize) {
  //struct HashTable *ht = NewHashTable(3727);
  //struct HashNode *p;
//
  //long long ret = 0LL;
  //int i, w, h, v;
//
  //for (i = 0; i < rectanglesSize; i++) {
    //w = rectangles[i][0], h = rectangles[i][1];
    //v = gcd(w, h);
    //w /= v;
    //h /= v;
    //HashTableAdd(ht, w*10 + h, h);
  //}
//
  //for (i = 0; i < ht->c; i++) {
    //p = ht->a[i];
//
    //while (p) {
      //ret += (long long)p->cnt * (p->cnt-1) / 2;
      //p = p->next;
    //}
  //}
//
  //return ret;
//}
//// #v1

// #v2
struct HashNode {
  int val, cnt, h;
  struct HashNode *next;
};

struct HashTable {
  int c;
  struct HashNode **a;
};

struct HashTable* NewHashTable(int c) {
  struct HashTable *ret = calloc(1, sizeof(struct HashTable));

  ret->c = c;
  ret->a = calloc(c, sizeof(struct HashNode *));
  for (int i = 0; i < c; i++) ret->a[i] = NULL;

  return ret;
}

int HashTableAdd(struct HashTable *t, int val, int height) {
  int h = val % t->c;
  struct HashNode *p = t->a[h], *q = p;

  while (q) {
    if (q->h == height && q->val == val) break;
    q = q->next;
  }

  if (q) {
    q->cnt += 1;
    return q->cnt - 1;
  }

  struct HashNode *n = calloc(1, sizeof(struct HashNode));

  n->val = val;
  n->h = height;
  n->cnt = 1;

  // add to hash table
  t->a[h] = n;
  n->next = p;

  return 0;
}

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

long long interchangeableRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize) {
  struct HashTable *ht = NewHashTable(7919);
  struct HashNode *p;

  long long ret = 0LL;

  for (int i = 0; i < rectanglesSize; i++) {
    int w = rectangles[i][0], h = rectangles[i][1];
    int v = gcd(w, h);
    w /= v, h /= v;
    ret += HashTableAdd(ht, (w<<1)+(h>>2), h);
  }

  return ret;
}
// #v2

// read 2d array
int** read_2d_arr(int rows, int cols) {
  int i, j;
  int **ret = (int **)malloc(sizeof(int *) * rows);
  for (i = 0; i < rows; i++) {
    ret[i] = (int *)malloc(sizeof(int) * cols);
  }

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      scanf("%d", &ret[i][j]);
    }
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int n, **a, m = 2;
  scanf("%d", &n);
  a = read_2d_arr(n, m);
  printf("%lld\n", interchangeableRectangles(a, n, &m));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
