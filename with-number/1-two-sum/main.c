#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1. 两数之和 - 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
// 你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。
// 你可以按任意顺序返回答案。
//  
// 示例 1：
// 输入：nums = [2,7,11,15], target = 9
// 输出：[0,1]
// 解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
// 示例 2：
// 输入：nums = [3,2,4], target = 6
// 输出：[1,2]
// 示例 3：
// 输入：nums = [3,3], target = 6
// 输出：[0,1]
//  
// 提示：
//  * 2 <= nums.length <= 104
//  * -109 <= nums[i] <= 109
//  * -109 <= target <= 109
//  * 只会存在一个有效答案
//  
// 进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？

// #v1
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct HashNode {
  int val;
  int index;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
  int size;
  struct HashNode **table;
};

struct HashNode* NewHashNode(int val, int index) {
  struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  ret->val = val;
  ret->index = index;
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

void HashTableAdd(struct HashTable *t, int val, int index) {
  if (!t) return ;
  int h = HashFunc(t, val);
  struct HashNode *n, *p = (t->table)[h];
  n = NewHashNode(val, index);
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

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
  int *ret = (int *)malloc(sizeof(int) * 2);
  int i, t;
  *returnSize = 2;
  struct HashTable *ht = NewHashTable(10007);
  HashTableAdd(ht, nums[0], 0);
  for (i = 1; i < numsSize; i++) {
    t = target - nums[i];

    struct HashNode *result = HashTableFind(ht, t);
    if (result) {
      ret[0] = result->index;
      ret[1] = i;
      break;
    }

    HashTableAdd(ht, nums[i], i);
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

// free 1d array
void free_1d_arr(int *arr) {
  if (!arr) {
    return;
  }
  free(arr);
}

int main(int argc, char *argv[])
{
  int n, target, retSize;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  scanf("%d", &target);
  int *ret = twoSum(arr, n, target, &retSize);
  print_1d_arr(ret, retSize);
  free_1d_arr(arr);
  free_1d_arr(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
