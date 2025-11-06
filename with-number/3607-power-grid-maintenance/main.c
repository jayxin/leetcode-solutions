#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 3607. 电网维 护 - 给你一个整数 c，表示 c 个电站，每个电站有一个唯一标识符 id，从 1 到 c 编号。
// 这些电站通过 n 条 双向 电缆互相连接，表示为一个二维数组 connections，其中每个元素 connections[i] = [ui, vi] 表示电站 ui 和电站 vi 之间的连接。直接或间接连接的电站组成了一个 电网 。
// 最初，所有 电站均处于在线（正常运行）状态。
// 另给你一个二维数组 queries，其中每个查询属于以下 两种类型之一 ：
//  * [1, x]：请求对电站 x 进行维护检查。如果电站 x 在线，则它自行解决检查。如果电站 x 已离线，则检查由与 x 同一 电网 中 编号最小 的在线电站解决。如果该电网中 不存在 任何 在线 电站，则返回 -1。
//  * [2, x]：电站 x 离线（即变为非运行状态）。
// 返回一个整数数组，表示按照查询中出现的顺序，所有类型为 [1, x] 的查询结果。
// 注意：电网的结构是固定的；离线（非运行）的节点仍然属于其所在的电网，且离线操作不 会改变电网的连接性。
//  
// 示例 1：
// 输入： c = 5, connections = [[1,2],[2,3],[3,4],[4,5]], queries = [[1,3],[2,1],[1,1],[2,2],[1,2]]
// 输出： [3,2,3]
// 解释：
// [https://assets.leetcode.com/uploads/2025/04/15/powergrid.jpg]
//  * 最初，所有电站 {1, 2, 3, 4, 5} 都在线，并组成一个电网。
//  * 查询 [1,3]：电站 3 在线，因此维护检查由电站 3 自行解决。
//  * 查询 [2,1]：电站 1 离线。剩余在线电站为 {2, 3, 4, 5}。
//  * 查询 [1,1]：电站 1 离线，因此检查由电网中编号最小的在线电站解决，即电站 2。
//  * 查询 [2,2]：电站 2 离线。剩余在线电站为 {3, 4, 5}。
//  * 查询 [1,2]：电站 2 离线，因此检查由电网中编号最小的在线电站解决，即电站 3。
// 示例 2：
// 输入： c = 3, connections = [], queries = [[1,1],[2,1],[1,1]]
// 输出： [1,-1]
// 解释：
//  * 没有连接，因此每个电站是一个独立的电网。
//  * 查询 [1,1]：电站 1 在线，且属于其独立电网，因此维护检查由电站 1 自行解决。
//  * 查询 [2,1]：电站 1 离线。
//  * 查询 [1,1]：电站 1 离线，且其电网中没有其他电站，因此结果为 -1。
//  
// 提示：
//  * 1 <= c <= 10^5
//  * 0 <= n == connections.length <= min(10^5, c * (c - 1) / 2)
//  * connections[i].length == 2
//  * 1 <= ui, vi <= c
//  * ui != vi
//  * 1 <= queries.length <= 2 * 105
//  * queries[i].length == 2
//  * queries[i][0] 为 1 或 2。
//  * 1 <= queries[i][1] <= c

// #v1
// graph, heap, dfs

// ------------------------------add connection---------------------------------
void AddConnection(int s, int e, int **graph, int *graphLen, int *graphCap) {
    // empty
    if (!graph[s]) {
      graph[s] = calloc(2, sizeof(int));
      graphCap[s] = 2;
    }

    // capacity reaced
    if (graphLen[s] == graphCap[s]) {
      graphCap[s] <<= 1; // double
      graph[s] = reallocarray(graph[s], graphCap[s], sizeof(int));
    }

    graph[s][graphLen[s]++] = e;
}
// ------------------------------add connection---------------------------------

// ------------------------------DFS----------------------------------
int **g, *gLen, *cid;
// n: node number
// c: componentId
// find component id for each node
void dfs(int n, int c) {
  if (cid[n] != -1) return ;

  cid[n] = c;

  for (int i = 0; i < gLen[n]; i++) {
    dfs(g[n][i], c);
  }
}
// ------------------------------DFS----------------------------------

// ------------------------------Min Heap---------------------------------------
void HeapSwap(int *h, int i, int j) {
  int t = h[i];
  h[i] = h[j];
  h[j] = t;
}

void HeapUp(int *h, int p) {
  while (p > 1) {
    if (h[p] < h[p>>1]) {
      HeapSwap(h, p, p>>1);
      p >>= 1;
    } else {
      return ;
    }
  }
}

void HeapDown(int *h, int size, int p) {
  int s = p << 1;

  while (s <= size) {
    if (s < size && h[s] > h[s+1]) s++;
    if (h[s] < h[p]) {
      HeapSwap(h, s, p);
      p = s;
      s = p<<1;
    } else {
      return ;
    }
  }
}

void HeapInsert(int *h, int *size, int v) {
  h[++(*size)] = v;
  // adjust
  HeapUp(h, *size);
}

void HeapExtract(int *h, int *size) {
  h[1] = h[(*size)--];
  // adjust
  HeapDown(h, *size, 1);
}
// ------------------------------Min Heap---------------------------------------

int* processQueries(int c, int** connections, int connectionsSize, int* connectionsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
  int *ret = calloc(queriesSize, sizeof(int)), retLen = 0;
  int *graph[c+1], graphLen[c+1], graphCap[c+1];
  int componentId[c+1], maxComponentId;
  int **components = NULL, *componentsLen = NULL, *componentsCap = NULL;
  char isOnline[c+1];

  // ------------------------------build graph------------------------------
  // init
  memset(graphLen, 0, sizeof(graphLen));
  memset(graphCap, 0, sizeof(graphCap));
  memset(graph, 0, sizeof(graph));

  // compute
  for (int i = 0; i < connectionsSize; i++) {
    int s = connections[i][0], e = connections[i][1];

    // add connection s--->e
    AddConnection(s, e, graph, graphLen, graphCap);
    // add connection e--->s
    AddConnection(e, s, graph, graphLen, graphCap);
  }

  g = graph;
  gLen = graphLen;
  // ------------------------------build graph------------------------------


  // --------------------find component id for each node--------------------
  // init
  memset(componentId, 0xff, sizeof(componentId));
  maxComponentId = 0;
  cid = componentId;

  // compute
  for (int i = 1; i <= c; i++) {
    if (componentId[i] == -1) { // if node `i` is not visited
      ++maxComponentId; // a new component
      dfs(i, maxComponentId); // find all nodes that is reachable from node `i`
    }
  }
  // --------------------find component id for each node------------------------

  // ------------------------------build component------------------------------
  // init
  // a component is a min heap
  components = calloc(maxComponentId+1, sizeof(int *));
  // length
  componentsLen = calloc(maxComponentId+1, sizeof(int));
  memset(componentsLen, 0, sizeof(int) * maxComponentId);
  // capacity
  componentsCap = calloc(maxComponentId+1, sizeof(int));
  memset(componentsCap, 0, sizeof(int) * maxComponentId);

  // compute
  for (int i = 1; i <= c; i++) {
    // add i to components[componentId[i]]
    int id = componentId[i];

    // empty
    if (componentsCap[id] == 0) {
      componentsCap[id] = 4;
      components[id] = calloc(componentsCap[id], sizeof(int));
    }

    // capacity reached
    if (componentsCap[id] == componentsLen[id] + 1) {
      componentsCap[id] <<= 1;
      components[id] = reallocarray(components[id], componentsCap[id], sizeof(int));
    }

    HeapInsert(components[id], &componentsLen[id], i);
  }
  // ------------------------------build component------------------------------

  // -------------------------process queries-----------------------------------
  // init
  // Initially, all stations are online(operational).
  memset(isOnline, 1, sizeof(isOnline));

  // compute
  for (int i = 0; i < queriesSize; i++) {
    int queryType = queries[i][0], queryNode = queries[i][1];

    if (queryType == 1) { // maintenance check
      if (isOnline[queryNode]) // station is online
        ret[retLen++] = queryNode;
      else { // station is offline
        int id = componentId[queryNode];

        // remove offline station from components[id]
        while (componentsLen[id] > 0 && !isOnline[components[id][1]])
          HeapExtract(components[id], &componentsLen[id]);

        // no operational station exists in components
        if (componentsLen[id] == 0) ret[retLen++] = -1;
        // choose the smallest id in the same power grid
        else ret[retLen++] = components[id][1];
      }
    } else { // station goes offline
      isOnline[queryNode] = 0;
    }
  }

  *returnSize = retLen;
  // -------------------------process queries-----------------------------------

  // ------------------------------free memory----------------------------------
  for (int i = 1; i <= c; i++)
    if (graph[i]) free(graph[i]);

  for (int i = 1; i <= maxComponentId; i++)
    if (components[i]) free(components[i]);

  free(components);
  free(componentsCap);
  free(componentsLen);
  // ------------------------------free memory----------------------------------

  return ret;
}
// #v1

// read 2d array
int** read_2d_arr(int rows, int cols) {
  if (!rows) return NULL;
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

void print_1d_arr(int *arr, int n) {
  if (!arr) {
    putchar('\n');
    return ;
  }
  for (int i = 0; i < n; i++) {
    if (i) {
      putchar(' ');
    }
    printf("%d", arr[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int *ret, returnSize;
  int c, **connections, connectionsSize, connectionsColSize;
  int **queries, queriesSize, queriesColSize;

  connectionsColSize = queriesColSize = 2;

  scanf("%d", &c);
  scanf("%d", &connectionsSize);
  connections = read_2d_arr(connectionsSize, connectionsColSize);

  scanf("%d", &queriesSize);
  queries = read_2d_arr(queriesSize, queriesColSize);

  ret = processQueries(c, connections, connectionsSize, &connectionsColSize,
      queries, queriesSize, &queriesColSize, &returnSize);

  print_1d_arr(ret, returnSize);

  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
