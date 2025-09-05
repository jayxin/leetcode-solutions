#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// 对称二叉树
// 给你一个二叉树的根节点 root ， 检查它是否轴对称。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

// #v1
bool _isSymmetric(struct TreeNode *left, struct TreeNode *right) {
  if (!left && !right) {
    return true;
  } else if (left && right) {
    if (left->val != right->val) {
      return false;
    }
    return _isSymmetric(left->left, right->right) && \
      _isSymmetric(left->right, right->left);
  }
  return false;
}

bool isSymmetric(struct TreeNode *root) {
  return _isSymmetric(root->left, root->right);
}
// #v1

struct TreeNode* new_node(int val) {
  struct TreeNode *ret = (struct TreeNode *)malloc(sizeof(struct TreeNode));
  ret->val = val;
  ret->left = ret->right = NULL;
  return ret;
}

int main(int argc, char *argv[])
{
  struct TreeNode *root = new_node(1);

  root->left = new_node(2);
  root->right = new_node(2);

  root->left->left = new_node(3);
  root->left->right = new_node(4);
  root->right->left = new_node(4);
  root->right->right = new_node(2);
  printf("%d\n", isSymmetric(root));

  struct TreeNode *root1 = new_node(1);

  root1->left = new_node(2);
  root1->right = new_node(2);

  root1->left->left = NULL;
  root1->left->right = new_node(3);
  root1->right->left = NULL;
  root1->right->right = new_node(3);
  printf("%d\n", isSymmetric(root1));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
