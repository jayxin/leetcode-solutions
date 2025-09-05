#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 15. 三数之和 - 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有 和为 0 且不重复的三元组。
// 注意：答案中不可以包含重复的三元组。
//  
//  
// 示例 1：
// 输入：nums = [-1,0,1,2,-1,-4]
// 输出：[[-1,-1,2],[-1,0,1]]
// 解释：
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
// 不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
// 注意，输出的顺序和三元组的顺序并不重要。
// 示例 2：
// 输入：nums = [0,1,1]
// 输出：[]
// 解释：唯一可能的三元组和不为 0 。
// 示例 3：
// 输入：nums = [0,0,0]
// 输出：[[0,0,0]]
// 解释：唯一可能的三元组和为 0 。
//  
// 提示：
//  * 3 <= nums.length <= 3000
//  * -105 <= nums[i] <= 105

//// #v1
//// 正确但超时
//struct HashNode {
  //int val;
  //int index;
  //struct HashNode *next;
//};
//
//struct HashTable {
  //int capacity;
  //int size;
  //struct HashNode **table;
//};
//
//struct HashNode* NewHashNode(int val, int index) {
  //struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  //ret->val = val;
  //ret->index = index;
  //ret->next = NULL;
  //return ret;
//}
//
//struct HashTable* NewHashTable(int capacity) {
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
  //int ret = key % t->capacity;
  //if (ret < 0) {
    //ret += t->capacity;
  //}
  //return ret;
//}
//
//struct HashNode* HashTableFind(struct HashTable *t, int val) {
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
//struct HashNode* HashTableFind1(struct HashTable *t, int val, int index) {
  //int h = HashFunc(t, val);
  //if ((t->table)[h] == NULL) {
    //return NULL;
  //}
  //struct HashNode *p = (t->table)[h];
  //while (p) {
    //if (p->val == val && p->index == index) {
      //return p;
    //}
    //p = p->next;
  //}
  //return NULL;
//}
//
//struct HashNode* HashTableFind2(struct HashTable *t, int val, int index) {
  //int h = HashFunc(t, val);
  //if ((t->table)[h] == NULL) {
    //return NULL;
  //}
  //struct HashNode *p = (t->table)[h];
  //while (p) {
    //if (p->val == val && p->index >= index) {
      //return p;
    //}
    //p = p->next;
  //}
  //return NULL;
//}
//
//void HashTableAdd(struct HashTable *t, int val, int index) {
  //int h = HashFunc(t, val);
  //struct HashNode *n, *p = (t->table)[h];
  //n = NewHashNode(val, index);
  //if (p == NULL) {
    //(t->table)[h] = n;
  //} else {
    ////if (val == p->val) {
    ////  free(n);
    ////  return ;
    ////}
    //n->next = p;
    //(t->table)[h] = n;
  //}
//}
//
//void DestroyHashTable(struct HashTable *t) {
  //for (int i = 0; i < t->capacity; i++) {
    //if (t->table[i]) {
      //free(t->table[i]);
    //}
  //}
  //free(t->table);
  //free(t);
//}
//
//void HashTableRemove(struct HashTable *t, int val, int index) {
  //int h = HashFunc(t, val);
  //struct HashNode *p = (t->table)[h];
  //if (!p) {
    //return ;
  //} else {
    //struct HashNode *prev = NULL;
    //while (p) {
      //if (p->val == val && p->index == index) {
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
//int* alloc_1d_arr(int n) {
  //int *ret = (int *)malloc(sizeof(int) * n);
  //return ret;
//}
//
//struct vector {
  //int **arr;
  //int rows;
  //int *cols;
  //int maxRows;
//};
//
//struct vector* NewVector() {
  //struct vector* ret = (struct vector *)malloc(sizeof(struct vector));
  //ret->rows = 0;
  //ret->maxRows = 20000;
  //ret->cols = alloc_1d_arr(ret->maxRows);
  //ret->arr = (int **)malloc(sizeof(int *) * ret->maxRows);
  //for (int i = 0; i < ret->maxRows; i++) {
    //(ret->arr)[i] = alloc_1d_arr(3);
  //}
  //return ret;
//}
//
//void FreeVector(struct vector *v) {
  //free(v->cols);
  //for (int i = 0; i < v->maxRows; i++) {
    //free((v->arr)[i]);
  //}
  //free(v->arr);
  //free(v);
//}
//
//struct vector* ResizeVector(struct vector *v) {
  //struct vector* ret = (struct vector *)malloc(sizeof(struct vector));
  //ret->rows = v->rows;
  //ret->maxRows = v->maxRows * 2;
  //ret->cols = alloc_1d_arr(ret->maxRows);
  //ret->arr = (int **)malloc(sizeof(int *) * ret->maxRows);
  //for (int i = 0; i < ret->maxRows; i++) {
    //(ret->arr)[i] = alloc_1d_arr(3);
  //}
  //for (int i = 0; i < v->maxRows; i++) {
    //(ret->cols)[i] = (v->cols)[i];
    //for (int j = 0; j < (ret->cols)[i]; j++) {
      //(ret->arr)[i][j] = (v->arr)[i][j];
    //}
  //}
  //FreeVector(v);
  //return ret;
//}
//
//struct vector* VectorAddEl(struct vector *v, int *arr, int n) {
  //if (v->rows == v->maxRows) {
    //v = ResizeVector(v);
  //}
  //int *r = (v->arr)[v->rows];
  //for (int i = 0; i < n; i++) {
    //r[i] = arr[i];
  //}
  //(v->cols)[v->rows] = n;
  //v->rows += 1;
  //return v;
//}
//
//struct vector *vv;
//int *tmp;
//struct HashTable *twosumht;
//
//bool VectorCheck() {
  //int f, i, j;
  //for (i = 0; i < vv->rows; i++) {
    //f = 0;
//
    //for (j = 0; j < 3; j++) {
      //if (tmp[j] != (vv->arr)[i][j]) {
        //f = 1;
        //break;
      //}
    //}
//
    //if (!f) {
      //return false;
    //}
  //}
  //return true;
//}
//
//void twoSum(int* nums, int numsSize, int target, int start) {
  //int i, t, m;
  //struct HashTable *ht = twosumht;
//
  //for (i = start; i < numsSize; i++) {
    //t = target - nums[i];
//
    //// 查找值为 t 且索引 >= start
    //struct HashNode *result = HashTableFind2(ht, t, start);
    //if (result && result->index != i) { // 索引必须不等
      //tmp[0] = target * (-1);
      //tmp[1] = nums[result->index];
      //tmp[2] = nums[i];
//
      //// sort
      //if (tmp[0] > tmp[1]) {
        //m = tmp[0];
        //tmp[0] = tmp[1];
        //tmp[1] = m;
      //}
      //if (tmp[0] > tmp[2]) {
        //m = tmp[0];
        //tmp[0] = tmp[2];
        //tmp[2] = m;
      //}
      //if (tmp[1] > tmp[2]) {
        //m = tmp[1];
        //tmp[1] = tmp[2];
        //tmp[2] = m;
      //}
//
      //if (VectorCheck()) {
        //vv = VectorAddEl(vv, tmp, 3);
      //}
    //}
//
    //if (HashTableFind1(ht, nums[i], i) == NULL)
      //HashTableAdd(ht, nums[i], i);
  //}
  //HashTableRemove(ht, nums[start], start);
//}
//
//int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  //int **ret, a[3];
  //vv = NewVector();
  //tmp = a;
//
  //twosumht = NewHashTable(3007);
  //struct HashTable *ht = NewHashTable(3007);
//
  //for (int i = 0; i < numsSize - 2; i++) {
    //if (HashTableFind(ht, nums[i])) continue;
    //twoSum(nums, numsSize, -1 * nums[i], i + 1);
    //HashTableAdd(ht, nums[i], i);
  //}
//
  //ret = vv->arr;
  //*returnSize = vv->rows;
  //*returnColumnSizes = vv->cols;
  //return ret;
//}
//// #v1

// #v2
// 哈希表
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
  struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
  ret->capacity = capacity;
  ret->size = 0;
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

struct HashNode* HashTableFind1(struct HashTable *t, int val, int index) {
  int h = HashFunc(t, val);
  if ((t->table)[h] == NULL) {
    return NULL;
  }
  struct HashNode *p = (t->table)[h];
  while (p) {
    if (p->val == val && p->index == index) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

struct HashNode* HashTableFind2(struct HashTable *t, int val, int index) {
  int h = HashFunc(t, val);
  if ((t->table)[h] == NULL) {
    return NULL;
  }
  struct HashNode *p = (t->table)[h];
  while (p) {
    if (p->val == val && p->index >= index) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, int val, int index) {
  int h = HashFunc(t, val);
  struct HashNode *n, *p = (t->table)[h];
  n = NewHashNode(val, index);
  if (!p) {
    (t->table)[h] = n;
  } else {
    n->next = p;
    (t->table)[h] = n;
  }
}

void HashTableRemove(struct HashTable *t, int val, int index) {
  int h = HashFunc(t, val);
  struct HashNode *p = (t->table)[h];
  if (!p) {
    return ;
  } else {
    struct HashNode *prev = NULL;
    while (p) {
      if (p->val == val && p->index == index) {
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

int* alloc_1d_arr(int n) {
  int *ret = (int *)malloc(sizeof(int) * n);
  return ret;
}

struct vector {
  int **arr;
  int rows;
  int *cols;
  int maxRows;
};

struct vector* NewVector() {
  struct vector* ret = (struct vector *)malloc(sizeof(struct vector));
  ret->rows = 0;
  ret->maxRows = 50;
  ret->cols = alloc_1d_arr(ret->maxRows);
  ret->arr = (int **)malloc(sizeof(int *) * ret->maxRows);
  for (int i = 0; i < ret->maxRows; i++) {
    (ret->arr)[i] = alloc_1d_arr(3);
  }
  return ret;
}

void FreeVector(struct vector *v) {
  free(v->cols);
  //for (int i = 0; i < v->maxRows; i++) {
  //  free((v->arr)[i]);
  //}
  free(v->arr);
  free(v);
}

struct vector* ResizeVector(struct vector *v) {
  struct vector* ret = (struct vector *)malloc(sizeof(struct vector));
  ret->rows = v->rows;
  ret->maxRows = v->maxRows * 2;
  ret->cols = alloc_1d_arr(ret->maxRows);
  ret->arr = (int **)malloc(sizeof(int *) * ret->maxRows);

  // copy data
  for (int i = 0; i < ret->rows; i++) {
    (ret->arr)[i] = (v->arr)[i];
    (ret->cols)[i] = (v->cols)[i];
  }
  for (int i = ret->rows; i < ret->maxRows; i++) {
    (ret->cols)[i] = 3;
    (ret->arr)[i] = alloc_1d_arr(3);
  }
  FreeVector(v);
  return ret;
}

struct vector* VectorAddEl(struct vector *v, int *arr, int n) {
  if (v->rows == v->maxRows) {
    v = ResizeVector(v);
  }
  int *r = (v->arr)[v->rows];
  for (int i = 0; i < n; i++) {
    r[i] = arr[i];
  }
  (v->cols)[v->rows] = n;
  v->rows += 1;
  return v;
}

struct vector *vv;
int *tmp;
struct HashTable *twosumht;
struct HashTable *targetht;
struct HashTable *sumht;
int *gnums, gnumsSize;

#define abs(x) (x >= 0 ? x : -x)

void twoSum(int target, int start) {
  int i, t, m;
  struct HashTable *ht = twosumht;

  for (i = start; i < gnumsSize; i++) {
    t = target - gnums[i];

    // 查找值为 t 且索引 >= start
    struct HashNode *result = HashTableFind2(ht, t, start);
    if (result && result->index != i) { // 索引必须不等
      tmp[0] = target * (-1);
      tmp[1] = gnums[result->index];
      tmp[2] = gnums[i];

      long long absval = (long long)tmp[0] * tmp[1] * tmp[2];
      int idx = abs(tmp[0]) + abs(tmp[1]) + abs(tmp[2]);
      struct HashNode *n = HashTableFind1(sumht, absval, idx);
      if (!n) {
        vv = VectorAddEl(vv, tmp, 3);
        HashTableAdd(sumht, absval, idx);
      }
    }

    if (start == 1)
      HashTableAdd(ht, gnums[i], i);
  }
  HashTableRemove(ht, gnums[start], start);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  int **ret, a[3], l = numsSize - 2;
  vv = NewVector();
  tmp = a;
  gnums = nums;
  gnumsSize = numsSize;

  twosumht = NewHashTable(numsSize + 7);
  targetht = NewHashTable(numsSize + 7);
  sumht = NewHashTable(numsSize + 7);

  for (int i = 0; i < l; i++) {
    if (HashTableFind(targetht, nums[i])) continue;
    twoSum(-1 * nums[i], i + 1);
    HashTableAdd(targetht, nums[i], i);
  }

  ret = vv->arr;
  *returnSize = vv->rows;
  *returnColumnSizes = vv->cols;
  return ret;
}
// #v2

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

int main(int argc, char *argv[])
{
  int n, retSize, *retColSize;
  scanf("%d", &n);
  int *arr = read_1d_arr(n);
  int **ret = threeSum(arr, n, &retSize, &retColSize);
  print_2d_arr(ret, retSize, retColSize);
  free_1d_arr(arr);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
