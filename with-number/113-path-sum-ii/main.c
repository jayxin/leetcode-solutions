#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 113. 路径总和 II - 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到 叶子节点 路径总和等于给定目标和的路径。
// 叶子节点 是指没有子节点的节点。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/01/18/pathsumii1.jpg]
// 输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// 输出：[[5,4,11,2],[5,8,4,5]]
// 示例 2：
// [https://assets.leetcode.com/uploads/2021/01/18/pathsum2.jpg]
// 输入：root = [1,2,3], targetSum = 5
// 输出：[]
// 示例 3：
// 输入：root = [1,2], targetSum = 0
// 输出：[]
//  
// 提示：
//  * 树中节点总数在范围 [0, 5000] 内
//  * -1000 &lt;= Node.val &lt;= 1000
//  * -1000 &lt;= targetSum &lt;= 1000

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
int **ret, retLen, *cols, a[5000], tSum;

void _pathSum(struct TreeNode* root, int sum, int aLen) {
  if (!root) return ;

  sum += root->val;
  // 存在负数, 不能回溯
  //if (tSum >= 0 && sum > tSum) return ;

  a[aLen++] = root->val;

  if (!root->left && !root->right && sum == tSum) {
    ret[retLen] = (int *)malloc(sizeof(int) * aLen);
    cols[retLen] = aLen;

    for (int i = 0; i < aLen; i++) ret[retLen][i] = a[i];

    ++retLen;
    return ;
  }

  _pathSum(root->left, sum, aLen);
  _pathSum(root->right, sum, aLen);
}

int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes) {
  ret = (int **)malloc(sizeof(int *) * 4500);
  cols = (int *)malloc(sizeof(int) * 4500);
  retLen = 0;
  tSum = targetSum;

  _pathSum(root, 0, 0);

  *returnColumnSizes = cols;
  *returnSize = retLen;

  return ret;
}
// S = 1 + q + q^2 + ... + q^n
// qS = q + q^2 + + ... + q^(n+1)
// S = 1-q^(n+1)/(1-q)
// #v1

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
  int n, i, j, **ret, r, *c, targetSum;
  scanf("%d\n", &targetSum);
  scanf("%d\n", &n);

  char **arr = (char **)malloc(sizeof(char *) * n);
  for (i = 0; i < n; i++) {
    arr[i] = (char *)malloc(sizeof(char) * 10);
    read_line(arr[i], 9, stdin);
  }


  struct TreeNode *root = buildTree(arr, n);
  ret = pathSum(root, targetSum, &r, &c);
  print_2d_arr(ret, r, c);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
