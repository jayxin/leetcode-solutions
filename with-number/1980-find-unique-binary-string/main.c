#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1980. 找出不同的二进制字符串 - 给你一个字符串数组 nums ，该数组由 n 个 互不相同 的二进制字符串组成，且每个字符串长度都是 n 。请你找出并返回一个长度为 n 且 没有出现 在 nums 中的二进制字符串。如果存在多种答案，只需返回 任意一个 即可。
//  
// 示例 1：
// 输入：nums = ["01","10"]
// 输出："11"
// 解释："11" 没有出现在 nums 中。"00" 也是正确答案。
// 示例 2：
// 输入：nums = ["00","01"]
// 输出："11"
// 解释："11" 没有出现在 nums 中。"10" 也是正确答案。
// 示例 3：
// 输入：nums = ["111","011","001"]
// 输出："101"
// 解释："101" 没有出现在 nums 中。"000"、"010"、"100"、"110" 也是正确答案。
//  
// 提示：
//  * n == nums.length
//  * 1 <= n <= 16
//  * nums[i].length == n
//  * nums[i] 为 '0' 或 '1'
//  * nums 中的所有字符串 互不相同

// #v1
int binaryString2Integer(char *s) {
  int x = 0;
  while (*s) x = (x << 1) + (*s++) - '0';
  return x;
}

struct HashNode {
  int val;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
  struct HashNode **table;
};

struct HashNode* NewHashNode(int val) {
  struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  ret->val = val;
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

#define HashFunc(t, k) ((k) % (t->capacity))

struct HashNode* HashTableFind(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *p = (t->table)[h];
  while (p) {
    if (p->val == val) return p;
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *n, *p = (t->table)[h];
  n = NewHashNode(val);
  (t->table)[h] = n;
  n->next = p;
}

struct HashTable *ht;
char *ret, *t;
int n;

bool gen(int len) {
  if (len == n) {
    int v = binaryString2Integer(t);

    if (HashTableFind(ht, v)) return false;

    for (int i = 0; i < len; i++) ret[i] = t[i];

    return true;
  }

  t[len] = '0';
  if (gen(len+1)) return true;

  t[len] = '1';
  return gen(len+1);
}

char* findDifferentBinaryString(char** nums, int numsSize) {
  ht = NewHashTable(131);
  n = numsSize;
  ret = (char *)malloc(sizeof(char) * (n+1));
  // string end
  ret[n] = '\0';

  char tmp[n+1];
  t = tmp;
  // string end
  t[n] = '\0';

  for (int i = 0; i < n; i++) HashTableAdd(ht, binaryString2Integer(nums[i]));

  gen(0);

  return ret;
}
// #v1

// read one line from stream
char* read_line(char *buffer, size_t size, FILE *stream) {
  if (fgets(buffer, size, stream) == NULL) {
    return NULL;
  }

  size_t len = strlen(buffer);
  if (len > 0 && buffer[len - 1] == '\n') {
    buffer[len - 1] = '\0';
  }

  return buffer;
}

int main(int argc, char *argv[])
{
  int n;
  char **s;
  scanf("%d\n", &n);
  s = (char **)malloc(sizeof(char *) * n);
  for (int i = 0; i < n; i++) {
    s[i] = (char *)malloc(sizeof(char) * 100);
    read_line(s[i], 98, stdin);
  }
  printf("%s\n", findDifferentBinaryString(s, n));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
