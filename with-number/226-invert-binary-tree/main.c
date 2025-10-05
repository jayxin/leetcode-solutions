#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 226. 翻转二 叉树 - 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
//  
// 示例 1：
// [https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg]
// 输入：root = [4,2,7,1,3,6,9]
// 输出：[4,7,2,9,6,3,1]
// 示例 2：
// [https://assets.leetcode.com/uploads/2021/03/14/invert2-tree.jpg]
// 输入：root = [2,1,3]
// 输出：[2,3,1]
// 示例 3：
// 输入：root = []
// 输出：[]
//  
// 提示：
//  * 树中节点数目范围在 [0, 100] 内
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

struct QueueNode {
  struct TreeNode *t;
  struct QueueNode *next;
};

struct Queue {
  struct QueueNode *head, *tail;
};

struct Queue* NewQueue() {
  struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
  q->head = q->tail = NULL;
  return q;
}

struct QueueNode* NewQueueNode(struct TreeNode *t) {
  struct QueueNode *q = (struct QueueNode *)malloc(sizeof(struct QueueNode));
  q->t = t;
  q->next = NULL;
  return q;
}

void enqueue(struct Queue* q, struct TreeNode *t) {
  struct QueueNode *n = NewQueueNode(t);

  if (!q->head) {
    q->head = q->tail = n;
    return ;
  }

  q->tail->next = n;
  q->tail = n;
}

struct QueueNode* dequeue(struct Queue *q) {
  if (!q->head) return NULL;

  struct QueueNode *ret = q->head;
  if (q->head == q->tail) {
    q->head = q->tail = NULL;
  } else {
    q->head = q->head->next;
  }

  return ret;
}

void printTree(struct TreeNode *root) {
  if (!root) {
    printf("\n");
    return ;
  }
  struct Queue *q = NewQueue();
  struct QueueNode *qn;
  enqueue(q, root);
  while (q->head) {
    qn = dequeue(q);
    printf("%d\n", qn->t->val);
    if (qn->t->left) enqueue(q, qn->t->left);
    if (qn->t->right) enqueue(q, qn->t->right);
  }
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
struct TreeNode* invertTree(struct TreeNode* root) {
  if (!root) return root;

  struct TreeNode *tmp;

  tmp = root->left;
  root->left = root->right;
  root->right = tmp;

  invertTree(root->left);
  invertTree(root->right);

  return root;
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

  struct TreeNode *root = buildTree(arr, n), *ret;
  ret = invertTree(root);
  printTree(ret);
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
