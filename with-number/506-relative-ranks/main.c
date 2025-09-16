#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 506. 相对名次 - 给你一个长度为 n 的整数数组 score ，其中 score[i] 是第 i 位运动员在比赛中的得分。所有得分都 互不相同 。
// 运动员将根据得分 决定名次 ，其中名次第 1 的运动员得分最高，名次第 2 的运动员得分 第 2 高，依此类推。运动员的名次决定了他们的获奖情况：
//  * 名次第 1 的运动员获金牌 "Gold Medal" 。
//  * 名次第 2 的运动员获银牌 "Silver Medal" 。
//  * 名次第 3 的运动员获铜牌 "Bronze Medal" 。
//  * 从名次第 4 到第 n 的运动员，只能获得他们的名次编号（即，名次第 x 的运动员获得 编号 "x"）。
// 使用长度为 n 的数组 answer 返回获奖，其中 answer[i] 是第 i 位运动员的获奖情况。
//  
// 示例 1：
// 输入：score = [5,4,3,2,1]
// 输出：["Gold Medal","Silver Medal","Bronze Medal","4","5"]
// 解释：名次为 [1st, 2nd, 3rd, 4th, 5th] 。
// 示例 2：
// 输入：score = [10,3,8,9,4]
// 输出：["Gold Medal","5","Bronze Medal","Silver Medal","4"]
// 解释：名次为 [1st, 5th, 3rd, 2nd, 4th] 。
//  
// 提示：
//  * n == score.length
//  * 1 &lt;= n &lt;= 104
//  * 0 &lt;= score[i] &lt;= 106
//  * score 中的所有值 互不相同

// #v1
char *myAtoI(int n) {
  int a[10], l = 0, retLen;
  char *ret;

  while (n) {
    a[l++] = n % 10;
    n /= 10;
  }

  ret = (char *)malloc(sizeof(char) * (l + 1));
  retLen = l;

  for (int i = 0; i < l; i++) {
    ret[i] = a[l - i - 1] + '0';
  }

  ret[l] = '\0';

  return ret;
}

struct MaxHeap {
  int *val, *idx;
  int size, capacity;
};

struct MaxHeap* NewHeap(int capacity) {
  struct MaxHeap *ret = (struct MaxHeap *)malloc(sizeof(struct MaxHeap));

  ret->val = (int *)malloc(sizeof(int) * capacity);
  ret->idx = (int *)malloc(sizeof(int) * capacity);
  ret->size = 0;
  ret->capacity = capacity;

  return ret;
}

void HeapSwap(struct MaxHeap *h, int i, int j) {
  int t = h->val[i];
  h->val[i] = h->val[j];
  h->val[j] = t;
  t = h->idx[i];
  h->idx[i] = h->idx[j];
  h->idx[j] = t;
}

void HeapUp(struct MaxHeap *h, int p) { // 向上调整
  while (p > 1) {
    if (h->val[p] > h->val[p>>1]) { // 子节点 > 父节点, 不满足大根堆性质
      HeapSwap(h, p, p>>1);
      p >>= 1;
    } else {
      return ;
    }
  }
}

void HeapDown(struct MaxHeap *h, int p) { // 向下调整
  int s = p << 1; // p 的左子节点
  int n = h->size;

  while (s <= n) {
    if (s < n && h->val[s] < h->val[s+1]) s++; //左右子节点取较大
    if (h->val[s] > h->val[p]) { // 子节点 > 父节点
      HeapSwap(h, s, p);
      p = s;
      s = p<<1;
    } else {
      break;
    }
  }
}

void HeapInsert(struct MaxHeap *h, int v, int i) {
  h->val[++(h->size)] = v;
  h->idx[h->size] = i;
  HeapUp(h, h->size);
}

void HeapExtract(struct MaxHeap *h) {
  h->idx[1] = h->idx[h->size];
  h->val[1] = h->val[h->size];
  --(h->size);
  HeapDown(h, 1);
}

void DestroyHeap(struct MaxHeap *h) {
  if (!h) return ;
  free(h->val);
  free(h->idx);
  free(h);
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
  int i, rank = 0;
  char *msg[3] = {"Gold Medal", "Silver Medal", "Bronze Medal"}, **ret;
  *returnSize = scoreSize;
  ret = (char **)malloc(sizeof(char *) * scoreSize);
  struct MaxHeap *h = NewHeap(scoreSize + 1);
  for (i = 0; i < scoreSize; i++) {
    HeapInsert(h, score[i], i);
  }
  while (h->size) {
    i = h->idx[1];
    if (rank < 3) {
      ret[i] = (char *)malloc(sizeof(char) * (strlen(msg[rank]) + 1));
      strcpy(ret[i], msg[rank]);
    } else {
      ret[i] = myAtoI(rank + 1);
    }
    HeapExtract(h);
    ++rank;
  }

  DestroyHeap(h);

  return ret;
}
// #v1

// read 1d array
int* read_1d_arr(int n) {
  int *ret = (int *)malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    scanf("%d", ret + i);
  }
  return ret;
}

void print_1d_arr(char **arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    printf("%s\n", arr[i]);
  }
}

int main(int argc, char *argv[])
{
  int n, *a, s;
  char **ret;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = findRelativeRanks(a, n, &s);
  print_1d_arr(ret, s);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
