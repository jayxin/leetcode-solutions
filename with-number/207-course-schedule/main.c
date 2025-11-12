#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 207. 课程表 - 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
// 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
//  * 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
//  
// 示例 1：
// 输入：numCourses = 2, prerequisites = [[1,0]]
// 输出：true
// 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
// 示例 2：
// 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
// 输出：false
// 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前 ，你还应先完成课程 1 。这是不可能的。
//  
// 提示：
//  * 1 <= numCourses <= 2000
//  * 0 <= prerequisites.length <= 5000
//  * prerequisites[i].length == 2
//  * 0 <= ai, bi < numCourses
//  * prerequisites[i] 中的所有课程对 互不相同

//// #v1
//// DFS
//int **a, *aLen;
//char *v, *t;
//
//bool dfs(int i) {
  //// 存在环
  //if (v[i]) return false;
//
  //// 标记 i 已被访问
  //v[i] = 1;
//
  //for (int j = 0; j < aLen[i]; j++) {
    //// 课程 i 的前置课程无法完成
    //if (!t[a[i][j]] && !dfs(a[i][j])) return false;
  //}
//
  //// 课程 i 可以完成
  //t[i] = 1;
//
  //return true;
//}
//
//bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
  //// edge case
  //if (!prerequisitesSize) return true;
//
  //char visited[numCourses], isDone[numCourses];
  //int *g[numCourses], gLen[numCourses];
  //int i;
//
  //memset(visited, 0, sizeof(visited));
  //memset(isDone, 0, sizeof(isDone));
  //for (i = 0; i < numCourses; i++) {
    //g[i] = calloc(numCourses, sizeof(int));
    //gLen[i] = 0;
  //}
  //a = g;
  //aLen = gLen;
  //// v 用来标记是否访问过
  //v = visited;
  //// t 用来标记课程是否能完成
  //t = isDone;
//
  //// process prerequisites
  //for (i = 0; i < prerequisitesSize; i++) {
    //int s = prerequisites[i][0], e = prerequisites[i][1];
    //g[s][gLen[s]++] = e;
  //}
//
  //for (i = 0; i < numCourses; i++) {
    //if (!t[i] && !dfs(i)) return false;
  //}
//
  //return true;
//}
//// #v1

// #v2
// topological sort
typedef struct Node {
  int v;
  struct Node *next;
} Node;

// vertex
typedef struct VNode { Node *head; } VNode;

typedef struct Graph {
  VNode *a;
  int n;
} Graph;

int TopoSort(Graph g) {
  // compute in-degree for each node
  int indegree[g.n];
  // init
  memset(indegree, 0, sizeof(indegree));
  // compute
  for (int i = 0; i < g.n; i++) {
    Node *p = g.a[i].head;

    while (p) {
      ++indegree[p->v];
      p = p->next;
    }
  }

  // topological sort
  int queue[g.n], head, tail;

  head = tail = 0;
  for (int i = 0; i < g.n; i++) {
    // enqueue
    if (indegree[i] == 0) queue[tail++] = i;
  }

  while (head < tail) {
    // dequeue
    int u = queue[head++];
    Node *p = g.a[u].head;

    while (p) {
      int v = p->v;
      if (--indegree[v] == 0) queue[tail++] = v;

      p = p->next;
    }
  }

  return tail;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
  // edge case
  if (!prerequisitesSize) return true;

  Graph g;

  // init
  g.n = numCourses;
  g.a = calloc(g.n, sizeof(VNode));
  for (int i = 0; i < g.n; i++) g.a[i].head = NULL;

  // process prerequisites
  for (int i = 0; i < prerequisitesSize; i++) {
    int v = prerequisites[i][0], u = prerequisites[i][1];
    Node *p = calloc(1, sizeof(Node));

    // u-->v
    p->v = v;
    p->next = g.a[u].head;
    g.a[u].head = p;
  }

  int tail = TopoSort(g);

  if (tail < g.n) return false;

  return true;
}
// #v2

// read 2d array
int** read_2d_arr(int rows, int cols) {
  int i, j;
  int **ret = (int **)malloc(sizeof(int *) * rows);
  for (i = 0; i < rows; i++) {
    ret[i] = (int *)malloc(sizeof(int) * cols);
  }

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      scanf("%d", &ret[i][j]);
    }
  }
  return ret;
}

int main(int argc, char *argv[])
{
  int **a, m, n, k;
  scanf("%d%d", &m, &n);
  a = read_2d_arr(m, n);
  scanf("%d", &k);
  if (canFinish(k, a, m, &n))
    printf("true\n");
  else
    printf("false\n");
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
