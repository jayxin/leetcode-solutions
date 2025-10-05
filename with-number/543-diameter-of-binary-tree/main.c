#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 543. 二叉 树的直径 - 给你一棵二叉树的根节点，返回该树的 直径 。
// 二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不 经过根节点 root 。
// 两节点之间路径的 长度 由它们之间边数表示。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg]
// 输入：root = [1,2,3,4,5]
// 输出：3
// 解释：3 ，取路径 [4,2,1,3] 或 [5,2,1,3] 的长度。
// 示例 2：
// 输入：root = [1,2]
// 输出：1
//  
// 提示：
//  * 树中节点数目在范围 [1, 104] 内
//  * -100 <= Node.val <= 100

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

//// #v1
//int maxDepth(struct TreeNode *root) {
  //if (!root) return 0;
  //int l, r;
  //l = r = 0;
  //if (root->left) l = maxDepth(root->left) + 1;
  //if (root->right) r = maxDepth(root->right) + 1;
  //return (l > r) ? l : r;
//}
//
//int _diameterOfBinaryTree(struct TreeNode *root, int prev) {
  //// 递归出口
  //if (!root) return 0;
//
  //int l, r, max, l1, r1, v1, v2, v3;
//
  //// 递归
  //// 左子树最值
  //l = _diameterOfBinaryTree(root->left, 1);
  //// 右子树最值
  //r = _diameterOfBinaryTree(root->right, 1);
//
  //l1 = maxDepth(root->left);
  //r1 = maxDepth(root->right);
//
  //v1 = v2 = v3 = 0;
  //// 连接左子树、root和右子树
  //if (root->left) v3 += l1 + 1;
  //if (root->right) v3 += r1 + 1;
  //// 连接左子树和 root
  //v1 = l1 + prev;
  //// 连接右子树和 root
  //v2 = r1 + prev;
//
  //// determine max value
  //max = v1;
  //if (max < v2) max = v2;
  //if (max < v3) max = v3;
  //if (max < l) max = l;
  //if (max < r) max = r;
//
  //return max;
//}
//
//int diameterOfBinaryTree(struct TreeNode* root) {
  //return _diameterOfBinaryTree(root, 0);
//}
//// #v1

//// #v2
//int maxDepth(struct TreeNode *root) {
  //if (!root) return 0;
//
  //int l = 0, r = 0, ret;
//
  //if (root->left) l = maxDepth(root->left) + 1;
  //if (root->right) r = maxDepth(root->right) + 1;
//
  //ret = l > r ? l : r;
  //// record, 用于连接左子树和右子树
  //root->val = l + r;
//
  //return ret;
//}
//
//int _diameterOfBinaryTree(struct TreeNode *root) {
  //// 递归出口
  //if (!root) return 0;
//
  //int max, l, r, v1, v2, v3;
  //v1 = v2 = v3 = 0;
//
  //v3 = root->val;
//
  //if (root->left) {
    //// 左子树最值
    //v1 = _diameterOfBinaryTree(root->left);
//
    ////l = maxDepth(root->left);
    //// 连接左子树、root和右子树
    ////v3 += l + 1;
  //}
//
  //if (root->right) {
    //// 右子树最值
    //v2 = _diameterOfBinaryTree(root->right);
//
    ////r = maxDepth(root->right);
    //// 连接左子树、root和右子树
    ////v3 += r + 1;
  //}
//
  //// determine max value
  //max = v1;
  //if (max < v2) max = v2;
  //if (max < v3) max = v3;
//
  //return max;
//}
//
//int diameterOfBinaryTree(struct TreeNode* root) {
  //maxDepth(root);
  //return _diameterOfBinaryTree(root);
//}
//// #v2

// #v3
int maxDepth(struct TreeNode *root) {
  if (!root) return 0;

  int l = 0, r = 0, ret;

  // 求左子树的深度
  if (root->left) l = maxDepth(root->left) + 1;
  // 求右子树的深度
  if (root->right) r = maxDepth(root->right) + 1;

  ret = l > r ? l : r;

  // val 字段记录连接左子树、root、右子树的结果
  root->val = l + r;

  return ret;
}

int _diameterOfBinaryTree(struct TreeNode *root) {
  // 递归出口
  if (!root) return 0;

  // v1 是左子树最值
  // v2 是右子树最值
  // v3 是连接左子树、root 和右子树的值
  int v1, v2, v3 = root->val, max = v3;
  v1 = v2 = 0;

  // 递归
  if (root->left) v1 = _diameterOfBinaryTree(root->left);
  if (root->right) v2 = _diameterOfBinaryTree(root->right);

  // determine max value
  if (max < v1) max = v1;
  if (max < v2) max = v2;

  return max;
}

int diameterOfBinaryTree(struct TreeNode* root) {
  // 先求连接左子树、root、右子树的结果
  maxDepth(root);

  return _diameterOfBinaryTree(root);
}
// #v3

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

  printf("%d\n", diameterOfBinaryTree(root));
  //printf("%d\n", maxDepth(root));

  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
