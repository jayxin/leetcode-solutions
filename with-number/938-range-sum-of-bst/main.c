#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 938. 二叉搜索树的范围和 - 给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之 间的所有结点的值的和。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2020/11/05/bst1.jpg]
// 输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
// 输出：32
// 示例 2：
// [https://assets.leetcode.com/uploads/2020/11/05/bst2.jpg]
// 输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
// 输出：23
//  
// 提示：
//  * 树中节点数目在范围 [1, 2 * 104] 内
//  * 1 &lt;= Node.val &lt;= 105
//  * 1 &lt;= low &lt;= high &lt;= 105
//  * 所有 Node.val 互不相同

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int l, h, ret;

void _rangeSumBST(struct TreeNode *root) {
  if (!root) return ;

  int v = root->val, leftMax = v - 1, rightMin = v + 1;
  if (v >= l && v <= h) ret += v;
  if (leftMax >= l) _rangeSumBST(root->left);
  if (rightMin <= h) _rangeSumBST(root->right);
}

int rangeSumBST(struct TreeNode* root, int low, int high) {
  l = low;
  h = high;
  ret = 0;

  _rangeSumBST(root);

  return ret;
}
// #v1

int main(int argc, char *argv[])
{
  int n, i, j, l, h;
  scanf("%d%d\n", &l, &h);
  scanf("%d\n", &n);

  char **arr = (char **)malloc(sizeof(char *) * n);
  for (i = 0; i < n; i++) {
    arr[i] = (char *)malloc(sizeof(char) * 10);
    read_line(arr[i], 9, stdin);
  }

  struct TreeNode *root = buildTree(arr, n);
  printf("%d\n", rangeSumBST(root, l, h));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
