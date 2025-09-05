#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 219. 存在重复元素 II - 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同 的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
//  
// 示例 1：
// 输入：nums = [1,2,3,1], k = 3
// 输出：true
// 示例 2：
// 输入：nums = [1,0,1,1], k = 1
// 输出：true
// 示例 3：
// 输入：nums = [1,2,3,1,2,3], k = 2
// 输出：false
//  
//  
// 提示：
//  * 1 <= nums.length <= 105
//  * -109 <= nums[i] <= 109
//  * 0 <= k <= 105

//// #v1
//// 超时
//bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
  //int i, j;
  //for (i = 0; i < numsSize; i++) {
    //for (j = 1; j <= k; j++) {
      //if (i + j >= numsSize) {
        //break;
      //}
      //if (nums[i] == nums[i + j]) {
        //return true;
      //}
    //}
  //}
  //return false;
//}
//// #v1

//// #v2
//struct HashNode {
  //int val;
  //struct HashNode *next;
//};
//
//struct HashTable {
  //int capacity;
  //int size;
  //struct HashNode **table;
//};
//
//struct HashNode* NewHashNode(int val) {
  //struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  //ret->val = val;
  //ret->next = NULL;
  //return ret;
//}
//
//struct HashTable* NewHashTable(int capacity) {
  //if (capacity <= 0) {
    //return NULL;
  //}
//
  //struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
  //ret->capacity = capacity;
  //ret->size = 0;
  //int table_bytes = sizeof(struct HashNode *) * capacity;
  //ret->table = (struct HashNode **)malloc(table_bytes);
  //memset(ret->table, 0, table_bytes);
//
  //return ret;
//}
//
//int HashFunc(struct HashTable *t, int key) {
  //if (!t) return 0;
  //int ret = key % t->capacity;
  //if (ret < 0) {
    //ret += t->capacity;
  //}
  //return ret;
//}
//
//struct HashNode* HashTableFind(struct HashTable *t, int val) {
  //if (!t) return NULL;
  //int h = HashFunc(t, val);
  //if ((t->table)[h] == NULL) {
    //return NULL;
  //}
  //struct HashNode *p = (t->table)[h];
  //while (p) {
    //if (p->val == val) {
      //return p;
    //}
    //p = p->next;
  //}
  //return NULL;
//}
//
//void HashTableAdd(struct HashTable *t, int val) {
  //if (!t) return ;
  //int h = HashFunc(t, val);
  //struct HashNode *n, *p = (t->table)[h];
  //n = NewHashNode(val);
  //if (p == NULL) {
    //(t->table)[h] = n;
  //} else {
    //n->next = p;
    //(t->table)[h] = n;
  //}
//}
//
//void HashTablePrint(struct HashTable *t) {
  //if (!t) return ;
  //struct HashNode *p;
  //int i;
  //for (i = 0; i < t->capacity; i++) {
    //if (t->table[i] == NULL) {
      //continue;
    //}
    //p = t->table[i];
    //while (p) {
      //printf("%d ", t->table[i]->val);
      //p = p->next;
    //}
    //putchar('\n');
  //}
//}
//
//void HashTableRemove(struct HashTable *t, int val) {
  //if (!t) return ;
  //int h = HashFunc(t, val);
  //struct HashNode *p = (t->table)[h];
  //if (p == NULL) {
    //return ;
  //} else {
    //struct HashNode *prev = NULL;
    //while (p) {
      //if (p->val == val) {
        //break;
      //}
      //prev = p;
      //p = p->next;
    //}
    //if (p) {
      //if (prev) {
        //prev->next = p->next;
      //} else {
        //(t->table)[h] = (t->table)[h]->next;
      //}
      //free(p);
    //}
  //}
//}
//
//bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
  //int i, j;
  //struct HashTable *t = NewHashTable(10017);
  //for (j = 1; j <= k; j++) {
    //if (0 + j >= numsSize) {
      //break;
    //}
    //HashTableAdd(t, nums[j]);
  //}
  //for (i = 0; i < numsSize; i++) {
    //if (i != 0) {
      //HashTableRemove(t, nums[i]);
      //if (i + k < numsSize && k != 0) {
        //HashTableAdd(t, nums[i + k]);
      //}
    //}
    //if (HashTableFind(t, nums[i]) != NULL) {
      //return true;
    //}
  //}
  //return false;
//}
//// #v2

// #v3
struct HashNode {
  int val;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
  int size;
  struct HashNode **table;
};

struct HashNode* NewHashNode(int val) {
  struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  ret->val = val;
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

void HashTableAdd(struct HashTable *t, int val) {
  if (!t) return ;
  int h = HashFunc(t, val);
  struct HashNode *n, *p = (t->table)[h];
  n = NewHashNode(val);
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

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
  int i, j;
  struct HashTable *t = NewHashTable(10017);
  for (j = 1; j <= k; j++) {
    if (j >= numsSize) {
      break;
    }
    HashTableAdd(t, nums[j]);
  }
  if (HashTableFind(t, nums[0]) != NULL) {
    return true;
  }
  for (i = 1; i < numsSize; i++) {
    HashTableRemove(t, nums[i]);
    if (i + k < numsSize && k != 0) {
      HashTableAdd(t, nums[i + k]);
    }
    if (HashTableFind(t, nums[i]) != NULL) {
      return true;
    }
  }
  return false;
}
// #v3

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
  int n, k;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  scanf("%d", &k);
  if (containsNearbyDuplicate(arr, n, k)) {
    printf("true\n");
  } else {
    printf("false\n");
  }
  free_1d_arr(arr);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
