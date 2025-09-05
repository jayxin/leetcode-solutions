#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 114.  二叉树展开为链表 - 给你二叉树的根结点 root ，请你将它展开为一个单链表：
//  * 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点， 而左子指针始终为 null 。
//  * 展开后的单链表应该与二叉树 先序遍历 [https://baike.baidu.com/item/%E5%85%88%E5%BA%8F%E9%81%8D%E5%8E%86/6442839?fr=aladdin] 顺序相同。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg]
// 输入：root = [1,2,5,3,4,null,6]
// 输出：[1,null,2,null,3,null,4,null,5,null,6]
// 示例 2：
// 输入：root = []
// 输出：[]
// 示例 3：
// 输入：root = [0]
// 输出：[0]
//  
// 提示：
//  * 树中结点数在范围 [0, 2000] 内
//  * -100 &lt;= Node.val &lt;= 100
//  
// 进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？

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
void _flatten(struct TreeNode *root, struct TreeNode **prev) {
  if (!root) return ;

  struct TreeNode *l = root->left, *r = root->right;
  root->left = NULL;

  if ((*prev)) {
    (*prev)->right = root;
  }

  *prev = root;

  _flatten(l, prev);
  _flatten(r, prev);
}

void flatten(struct TreeNode* root) {
  if (!root) return ;
  if (!root->left && !root->right) return ;

  struct TreeNode *prev = NULL;
  _flatten(root, &prev);
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
  flatten(root);
  printTree(root);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
