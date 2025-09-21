#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 257.  二叉树的所有路径 - 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
// 叶子节点 是指没有子节点的节点。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/03/12/paths-tree.jpg]
// 输入：root = [1,2,3,null,5]
// 输出：[&quot;1-&gt;2-&gt;5&quot;,&quot;1-&gt;3&quot;]
// 示例 2：
// 输入：root = [1]
// 输出：[&quot;1&quot;]
//  
// 提示：
//  * 树中节点的数目在范围 [1, 100] 内
//  * -100 &lt;= Node.val &lt;= 100

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

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

void printTree(struct TreeNode *root) {
  if (!root) {
    printf("#\n");
    return ;
  }
  printf("%d\n", root->val);
  if (!root->left && !root->right) return ;
  printTree(root->left);
  printTree(root->right);
}

struct TreeNode* newTreeNode(int val) {
  struct TreeNode *ret = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  ret->val = val;
  ret->left = NULL;
  ret->right = NULL;
  return ret;
}

struct TreeNode* buildTree(char **arr, int len) {
  if (!len) {
    return NULL;
  }

  int i, val;
  struct TreeNode *root = NULL;
  struct TreeNode **queue = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * len);
  int head = -1, tail = -1, cnt = 0;
  for (i = 0; i < len; i++) {
    if (arr[i][0] == '#') {
      if (cnt == 0) {
        queue[head]->left = NULL;
        cnt = 1;
      } else if (cnt == 1) {
        queue[head]->right = NULL;
        head++;
        cnt = 0;
      }
    } else {
      val = atoi(arr[i]);
      struct TreeNode *node = newTreeNode(val);
      queue[++tail] = node;
      if (!root) {
        root = node;
        head = 0;
        continue;
      }
      if (cnt == 0) {
        queue[head]->left = node;
        cnt = 1;
      } else if (cnt == 1) {
        queue[head]->right = node;
        cnt = 0;
        head++;
      }
    }
  }
  return root;
}


// #v1
struct Vector {
  char **a;
  int size, capacity;
};

struct Vector* NewVector(int c) {
  struct Vector *v = (struct Vector *)malloc(sizeof(struct Vector));

  v->capacity = c;
  v->size = 0;
  v->a = (char **)malloc(sizeof(char *) * c);

  return v;
}

void VectorAddEl(struct Vector *v, char *s) {
  if (v->size == v->capacity) {
    v->capacity <<= 1;
    char **t = (char **)malloc(sizeof(char *) * v->capacity);
    for (int i = 0; i < v->size; i++) {
      t[i] = v->a[i];
    }
    free(v->a);
    v->a = t;
  }
  v->a[v->size] = s;
  ++v->size;
}

struct String {
  char *s;
  int size, capacity;
};

struct String* NewString(int c) {
  struct String *s = (struct String *)malloc(sizeof(struct String));
  s->s = (char *)malloc(sizeof(char) * c);
  s->s[0] = '\0';
  s->size = 0;
  s->capacity = c;
  return s;
}

void StringAppend(struct String *s, char *t) {
  int l = strlen(t);
  if (s->size + l >= s->capacity) {
    int m = (s->size + l + s->capacity) << 1;
    s->capacity = m;
    char *q = (char *)malloc(sizeof(char) * m);
    strcpy(q, s->s);
    free(s->s);
    s->s = q;
  }
  strcat(s->s, t);
  s->size += l;
}

struct Vector *vv;
struct String *ss;
struct TreeNode *r;
int digitalValLen;
char digitalVal[8];

char* itoa(int x) {
  // init
  digitalValLen = 0;
  char *s = digitalVal, *e, c;

  if (x < 0) {
    digitalVal[digitalValLen++] = '-';
    x = -x;
    ++s;
  }

  while (x) {
    digitalVal[digitalValLen++] = x % 10 + '0';
    x /= 10;
  }

  e = digitalVal+ digitalValLen - 1;

  // string end
  digitalVal[digitalValLen] = '\0';

  // reverse
  while (s < e) {
    c = *s;
    *s = *e;
    *e = c;
    ++s;
    --e;
  }

  return digitalVal;
}

void _binaryTreePaths(struct TreeNode *root) {
  if (!root) return ;

  int isRoot = (root == r ? 1 : 0), len = 2;
  char t[12] = {'-', '>', '\0'}, *q = itoa(root->val), *res = NULL;

  // 往结果字符串追加内容
  if (isRoot) { // 根节点只添加数字
    StringAppend(ss, q);
  } else { // 当前节点非根, 添加箭头和数字
    len += strlen(q); // 记录追加的字符串长度, 用于恢复现场
    strcat(t, q); // 箭头和数字连接
    StringAppend(ss, t); // 追加到结果字符串
  }

  // leaf, 非根叶子节点
  if (!root->left && !root->right) { // 收集结果字符串
    res = (char *)malloc(sizeof(char) * (ss->size + 1));
    strcpy(res, ss->s);
    VectorAddEl(vv, res);
  }

  // recursion
  if (root->left) _binaryTreePaths(root->left);
  if (root->right) _binaryTreePaths(root->right);

  // restore, 恢复现场
  if (!isRoot) {
    ss->size -= len;
    (ss->s)[ss->size] = '\0';
  }
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
  if (!root) return NULL;

  char **ret = NULL;

  r = root;
  vv = NewVector(32);
  ss = NewString(64);

  _binaryTreePaths(root);

  *returnSize = vv->size;
  ret = vv->a;

  free(vv);
  free(ss->s);
  free(ss);

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n, i, s;
  scanf("%d\n", &n);

  char **arr = (char **)malloc(sizeof(char *) * n);
  for (i = 0; i < n; i++) {
    arr[i] = (char *)malloc(sizeof(char) * 10);
    read_line(arr[i], 9, stdin);
  }

  struct TreeNode *root = buildTree(arr, n);
  char **ret = binaryTreePaths(root, &s);
  for (i = 0; i < s; i++) {
    printf("%s\n", ret[i]);
  }
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
