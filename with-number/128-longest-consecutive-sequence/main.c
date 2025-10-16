#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 128. 最长 连续序列 - 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
// 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
//  
// 示例 1：
// 输入：nums = [100,4,200,1,3,2]
// 输出：4
// 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
// 示例 2：
// 输入：nums = [0,3,7,2,5,8,4,6,0,1]
// 输出：9
// 示例 3：
// 输入：nums = [1,0,1,2]
// 输出：3
//  
// 提示：
//  * 0 <= nums.length <= 105
//  * -109 <= nums[i] <= 109

// #v1
struct HashNode {
  int val, idx;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
  struct HashNode **table;
};

struct HashNode* NewHashNode(int idx, int val) {
  struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  ret->idx = idx;
  ret->val = val;
  ret->next = NULL;
  return ret;
}

struct HashTable* NewHashTable(int capacity) {
  struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
  ret->capacity = capacity;
  int table_bytes = sizeof(struct HashNode *) * capacity;
  ret->table = (struct HashNode **)malloc(table_bytes);
  memset(ret->table, 0, table_bytes);
  return ret;
}

int HashFunc(struct HashTable *t, int key) {
  int ret = key % t->capacity;
  if (ret < 0) {
    ret += t->capacity;
  }
  return ret;
}

struct HashNode* HashTableFind(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *p = (t->table)[h];
  while (p) {
    if (p->val == val) return p;
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, int idx, int val) {
  int h = HashFunc(t, val);
  struct HashNode *n, *p = (t->table)[h];
  n = NewHashNode(idx, val);
  if (!p) {
    (t->table)[h] = n;
  } else {
    n->next = p;
    (t->table)[h] = n;
  }
}

int *p;
struct HashTable *h;

// 寻找 idx 所在树的根
int numFind(int idx) {
  // 递归出口, idx 是树的根
  if (p[idx] == -1) return idx;

  // idx 的祖先直接指向树的根
  p[idx] = numFind(p[idx]);

  return p[idx];
}

// 将 nums[idx] 合并至并查集, v 是 nums[idx] 的值
void numUnion(int idx, int v) {
  struct HashNode *x = HashTableFind(h, v), *y = NULL;

  // 不重复添加
  if (x) return ;

  HashTableAdd(h, idx, v);

  // v-1 分支
  x = HashTableFind(h, v-1);
  // v+1 树
  y = HashTableFind(h, v+1);

  if (x && !y) { // 单分支
    // idx 对应节点挂到 x 的根
    p[idx] = numFind(x->idx);
  } else if (!x && y) { // 单分支
    // idx 对应节点挂到 y 的根
    p[idx] = numFind(y->idx);
  } else if (x && y) { // 两个分支进行合并
    int xParent = numFind(x->idx);
    p[idx] = xParent;
    // 将 x 所在树挂到 y 所在的树
    // 必须是 x 所在树的根挂到 y 所在树
    p[xParent] = numFind(y->idx);
  }
}

int longestConsecutive(int* nums, int numsSize) {
  if (numsSize <= 1) return numsSize;

  int parent[numsSize], i, t, ret = 0;
  struct HashTable *h1 = NewHashTable(1331);
  struct HashNode *q = NULL;

  // init
  h = NewHashTable(10111);
  // parent[i] 初始化为 -1, 即最初状态为 numsSize 棵树
  memset(parent, 0xff, numsSize * sizeof(int));
  p = parent;

  // 将 nums[i] 加入并查集
  for (i = 0; i < numsSize; i++) numUnion(i, nums[i]);

  // 统计并查集中每棵树的节点的数量, 取最大值
  for (i = 0; i < numsSize; i++) {
    if (p[i] >= 0) { // 非根节点
      t = numFind(p[i]); // 寻找 p[i] 所在树的根节点
      q = HashTableFind(h1, t); // 查找根节点是否在哈希表中出现

      if (q) { // 根节点在哈希表中出现, 出现的次数 +1
        q->idx += 1;
        if (ret < q->idx) ret = q->idx;
      } else { // 根节点第一次出现, 记录到哈希表中
        HashTableAdd(h1, 1, t);

        // 特殊情况, 比如数组 [1,2] 对应 parent 数组为 [-1,0]
        if (!ret) ret = 1;
      }
    }
  }

  // 将根节点(p[i] == -1)计入结果
  ++ret;

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

int main(int argc, char *argv[])
{
  int n, *a;
  scanf("%d", &n);
  a = read_1d_arr(n);
  printf("%d\n", longestConsecutive(a, n));
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
