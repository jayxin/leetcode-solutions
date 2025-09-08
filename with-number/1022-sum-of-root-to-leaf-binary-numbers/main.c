#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1022. 从根到叶的二进制数之和 - 给出一棵二叉树，其上每个结点的值都是 0 或 1 。每 一条从根到叶的路径都代表一个从最高有效位开始的二进制数。
//  * 例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
// 对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。
// 返回这些数字之和。题目数据保证答案是一个 32 位 整数。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2019/04/04/sum-of-root-to-leaf-binary-numbers.png]
// 输入：root = [1,0,1,0,1,0,1]
// 输出：22
// 解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
// 示例 2：
// 输入：root = [0]
// 输出：0
//  
// 提示：
//  * 树中的节点数在 [1, 1000] 范围内
//  * Node.val 仅为 0 或 1 

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
int _sumRootToLeaf(struct TreeNode* root, int v) {
  if (!root) return 0;
  v = v * 2 + root->val;
  if (!root->left && !root->right) return v;
  return _sumRootToLeaf(root->left, v) + _sumRootToLeaf(root->right, v);
}

int sumRootToLeaf(struct TreeNode* root) {
  if (!root) return 0;
  return _sumRootToLeaf(root, 0);
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
  printf("%d\n", sumRootToLeaf(root));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
