#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1331. 数 组序号转换 - 给你一个整数数组 arr ，请你将数组中的每个元素替换为它们排序后的序号 。
// 序号代表了一个元素有多大。序号编号的规则如下：
//  * 序号从 1 开始编号。
//  * 一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。
//  * 每个数字的序号都应该尽可能地小。
//  
// 示例 1：
// 输入：arr = [40,10,20,30]
// 输出：[4,1,2,3]
// 解释：40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。
// 示例 2：
// 输入：arr = [100,100,100]
// 输出：[1,1,1]
// 解释：所有元素有相同的序号。
// 示例 3：
// 输入：arr = [37,12,28,9,100,56,80,5,12]
// 输出：[5,3,4,2,8,6,7,1,3]
//  
// 提示：
//  * 0 &lt;= arr.length &lt;= 105
//  * -109 &lt;= arr[i] &lt;= 109
// #v1
int cmp(const void *a, const void *b) {
  return *(int *)a - *(int *)b;
}

struct HashNode {
  int val;
  int idx;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
  int size;
  struct HashNode **table;
};

struct HashNode* NewHashNode(int val, int idx) {
  struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  ret->val = val;
  ret->idx = idx;
  ret->next = NULL;
  return ret;
}

struct HashTable* NewHashTable(int capacity) {
  if (capacity <= 0) {
    return NULL;
  }

  struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
  ret->capacity = capacity;
  ret->size = 0;
  int table_bytes = sizeof(struct HashNode *) * capacity;
  ret->table = (struct HashNode **)malloc(table_bytes);
  memset(ret->table, 0, table_bytes);

  return ret;
}

int HashFunc(struct HashTable *t, int key) {
  if (!t) return 0;
  int ret = key % t->capacity;
  if (ret < 0) {
    ret += t->capacity;
  }
  return ret;
}

struct HashNode* HashTableFind(struct HashTable *t, int val) {
  if (!t) return NULL;
  int h = HashFunc(t, val);
  if ((t->table)[h] == NULL) {
    return NULL;
  }
  struct HashNode *p = (t->table)[h];
  while (p) {
    if (p->val == val) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, int val, int idx) {
  if (!t) return ;
  int h = HashFunc(t, val);
  struct HashNode *n, *p = (t->table)[h];
  n = NewHashNode(val, idx);
  if (p == NULL) {
    (t->table)[h] = n;
  } else {
    n->next = p;
    (t->table)[h] = n;
  }
}

void HashTablePrint(struct HashTable *t) {
  if (!t) return ;
  struct HashNode *p;
  int i;
  for (i = 0; i < t->capacity; i++) {
    if (t->table[i] == NULL) {
      continue;
    }
    p = t->table[i];
    while (p) {
      printf("%d ", t->table[i]->val);
      p = p->next;
    }
    putchar('\n');
  }
}

void HashTableRemove(struct HashTable *t, int val) {
  if (!t) return ;
  int h = HashFunc(t, val);
  struct HashNode *p = (t->table)[h];
  if (p == NULL) {
    return ;
  } else {
    struct HashNode *prev = NULL;
    while (p) {
      if (p->val == val) {
        break;
      }
      prev = p;
      p = p->next;
    }
    if (p) {
      if (prev) {
        prev->next = p->next;
      } else {
        (t->table)[h] = (t->table)[h]->next;
      }
      free(p);
    }
  }
}

int* arrayRankTransform(int* arr, int arrSize, int* returnSize) {
  if (!arr || arrSize == 0) {
    *returnSize = 0;
    return NULL;
  }

  *returnSize = arrSize;

  int *ret, cur, i, rank = 1;
  struct HashTable *ht = NewHashTable(1007); // 存储数组元素值和索引的映射关系
  ret = (int *)malloc(sizeof(int) * arrSize); // 返回值

  // 建立数组元素值和索引的映射关系
  for (i = 0; i < arrSize; i++) {
    HashTableAdd(ht, arr[i], i);
  }

  // 数组排序
  qsort(arr, arrSize, sizeof(int), cmp);

  // 首个元素
  struct HashNode *p = HashTableFind(ht, arr[0]);
  ret[p->idx] = rank;
  cur = arr[0];
  HashTableRemove(ht, arr[0]);

  for (i = 1; i < arrSize; i++) {
    if (arr[i] != cur) {
      rank++;
      cur = arr[i];
    }
    // 查找元素
    p = HashTableFind(ht, arr[i]);
    ret[p->idx] = rank;
    HashTableRemove(ht, arr[i]);
  }

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

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int n, *a, *ret, s;
  scanf("%d", &n);
  a = read_1d_arr(n);
  ret = arrayRankTransform(a, n, &s);
  print_1d_arr(ret, s);
  free(ret);
  free(a);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
