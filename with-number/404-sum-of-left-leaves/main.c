#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 404. 左叶子 之和 - 给定二叉树的根节点 root ，返回所有左叶子之和。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg]
// 输入: root = [3,9,20,null,null,15,7]
// 输出: 24
// 解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
// 示例 2:
// 输入: root = [1]
// 输出: 0
//  
// 提示:
//  * 节点数在 [1, 1000] 范围内
//  * -1000 &lt;= Node.val &lt;= 1000

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
int sumOfLeftLeaves(struct TreeNode* root) {
  if (!root) return 0;
  int s = 0;
  if (root->left && (!root->left->left) && (!root->left->right))
    s += root->left->val;
  s += sumOfLeftLeaves(root->left);
  s += sumOfLeftLeaves(root->right);
  return s;
}
// #v1

int main(int argc, char *argv[])
{
  int n, i, j;
  scanf("%d\n", &n);

  char **arr = (char **)malloc(sizeof(char *) * n);
  for (i = 0; i < n; i++) {
    arr[i] = (char *)malloc(sizeof(char) * 10);
    read_line(arr[i], 9, stdin);
  }

  struct TreeNode *root = buildTree(arr, n);
  printf("%d\n", sumOfLeftLeaves(root));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
