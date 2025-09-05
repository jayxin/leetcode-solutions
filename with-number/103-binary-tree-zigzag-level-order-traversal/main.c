#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 103. 二叉树的锯齿形层序遍历 - 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg]
// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[3],[20,9],[15,7]]
// 示例 2：
// 输入：root = [1]
// 输出：[[1]]
// 示例 3：
// 输入：root = []
// 输出：[]
//  
// 提示：
//  * 树中节点数目在范围 [0, 2000] 内
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
    return ;
  }
  printf("%d\n", root->val);
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
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
struct Queue {
  int l; // level
  struct TreeNode *t;
  struct Queue *next;
};

//int mypow(int x, int n) {
//  int ret = 1;
//  while (n) {
//    if (n & 1) {
//      ret *= x;
//    }
//    n >>= 1;
//    if (n) { // avoid overflow
//      x *= x;
//    }
//  }
//  return ret;
//}

struct Queue* newQueueNode(int l, struct TreeNode *t) {
  struct Queue *ret = (struct Queue *)malloc(sizeof(struct Queue));
  ret->l = l;
  ret->t = t;
  ret->next = NULL;
  return ret;
}

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
  *returnSize = 0;
  *returnColumnSizes = NULL;
  if (!root) {
    return NULL;
  }

  int **ret, len;
  int current_level = 0;
  struct Queue *qhead = newQueueNode(current_level, root),
               *qtail = qhead,
               *qq = qhead,
               *tmp, *q;
  struct TreeNode *t;

  // build queue
  while (qhead) {
    current_level = qhead->l;
    t = qhead->t;

    // enqueue
    if (t->left) {
      q = newQueueNode(current_level + 1, t->left);
      qtail->next = q;
      qtail = q;
    }
    if (t->right) {
      q = newQueueNode(current_level + 1, t->right);
      qtail->next = q;
      qtail = q;
    }

    qhead = qhead->next;
  }

  // allocate space
  qhead = qq;
  *returnSize = current_level + 1;
  ret = (int **)malloc(sizeof(int *) * (*returnSize));
  *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
  for (int i = 0; i < *returnSize; i++) {
    // count
    int cnt = 0;
    while (qhead && qhead->l == i) {
      cnt++;
      qhead = qhead->next;
    }

    // allocate
    ret[i] = (int *)malloc(sizeof(int) * cnt);
    (*returnColumnSizes)[i] = cnt;
  }

  // fill array
  len = current_level = 0;
  qhead = qq;
  while (qhead) {
    if (qhead->l > current_level) {
      len = 0;
    }
    current_level = qhead->l;
    t = qhead->t;
    ret[current_level][len++] = t->val;

    // dequeue
    tmp = qhead;
    qhead = qhead->next;
    free(tmp);
  }

  // reverse
  int pp;
  for (int i = 0; i < *returnSize; i++) {
    if (i & 1) {
      int al = (*returnColumnSizes)[i];
      for (int j = 0; j < al / 2; j++) {
        pp = ret[i][j];
        ret[i][j] = ret[i][al - j - 1];
        ret[i][al - j - 1] = pp;
      }
    }
  }

  return ret;
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
  int returnSize, *returnColumnSizes;
  //printTree(root);
  int **result = zigzagLevelOrder(root, &returnSize, &returnColumnSizes);
  if (result) {
    for (i = 0; i < returnSize; i++) {
      for (j = 0; j < returnColumnSizes[i]; j++) {
        if (j) {
          putchar(' ');
        }
        printf("%d", result[i][j]);
      }
      putchar('\n');
    }
  } else {
    putchar('\n');
  }

  // free
  for (i = 0; i < n; i++) {
    free(arr[i]);
  }
  free(arr);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
