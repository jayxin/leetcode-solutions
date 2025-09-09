#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// 2327.  知道秘密的人数 - 在第 1 天，有一个人发现了一个秘密。
// 给你一个整数 delay ，表示每个人会在发现秘密后的 delay 天之后，每天 给一个新的人  分享 秘密。同时给你一个整数 forget ，表示每个人在发现秘密 forget 天之后会 忘记 这个秘密。一个人 不能 在忘记秘密那一天及之后的日子里分享秘密。
// 给你一个整数 n ，请你返回在第 n 天结束时，知道秘密的人数。由于答案可能会很大，请 你将结果对 109 + 7 取余 后返回。
//  
// 示例 1：
// 输入：n = 6, delay = 2, forget = 4
// 输出：5
// 解释：
// 第 1 天：假设第一个人叫 A 。（一个人知道秘密）
// 第 2 天：A 是唯一一个知道秘密的人。（一个人知道秘密）
// 第 3 天：A 把秘密分享给 B 。（两个人知道秘密）
// 第 4 天：A 把秘密分享给一个新的人 C 。（三个人知道秘密）
// 第 5 天：A 忘记了秘密，B 把秘密分享给一个新的人 D 。（三个人知道秘密）
// 第 6 天：B 把秘密分享给 E，C 把秘密分享给 F 。（五个人知道秘密）
// 示例 2：
// 输入：n = 4, delay = 1, forget = 3
// 输出：6
// 解释：
// 第 1 天：第一个知道秘密的人为 A 。（一个人知道秘密）
// 第 2 天：A 把秘密分享给 B 。（两个人知道秘密）
// 第 3 天：A 和 B 把秘密分享给 2 个新的人 C 和 D 。（四个人知道秘密）
// 第 4 天：A 忘记了秘密，B、C、D 分别分享给 3 个新的人。（六个人知道秘密）
//  
// 提示：
//  * 2 &lt;= n &lt;= 1000
//  * 1 &lt;= delay &lt; forget &lt;= n

//// #v1
//#define min(a, b) ((a) > (b) ? (b) : (a))
//int peopleAwareOfSecret(int n, int delay, int forget) {
  //const int mod = 1000000000 + 7;
  //int i, j, size = n + 1, limit;
  //uint64_t knowSecret;
  //uint64_t *delayArr, *forgetArr;
  //delayArr = (uint64_t *)malloc(sizeof(uint64_t) * size);
  //forgetArr = (uint64_t *)malloc(sizeof(uint64_t) * size);
  //memset(delayArr, 0, sizeof(uint64_t) * size);
  //memset(forgetArr, 0, sizeof(uint64_t) * size);
//
  //knowSecret = 1;
  //limit = min(1+forget, size);
  //for (j = 1+delay; j < limit; j++) {
    //delayArr[j] = 1;
  //}
  //if (1 + forget <= n) {
    //forgetArr[1 + forget] = 1;
  //}
//
  //for (i = 2; i <= n; i++) {
    //knowSecret = knowSecret - forgetArr[i] + delayArr[i];
    ////knowSecret[i] = knowSecret[i-1] + delayArr[i] - forgetArr[i];
//
    //// 不需要分享秘密, 也不需要设定 forget
    //if (delayArr[i] == 0) continue;
//
    //limit = min(i+forget, size);
    //for (j = i + delay; j < limit; j++) {
      //delayArr[j] += delayArr[i] % mod;
      ////delayArr[j] %= mod;
    //}
//
    //if (limit <= n) {
      //forgetArr[limit] += delayArr[i];
    //}
  //}
  //return knowSecret % mod;
//}
//// #v1

//// #v2
//#define min(a, b) ((a) > (b) ? (b) : (a))
//int peopleAwareOfSecret(int n, int delay, int forget) {
  //const int mod = 1000000007;
  //int i, j, size = n + 1, limit;
  //uint64_t knowSecret, f;
  //int *delayArr;
  //delayArr = (int *)malloc(sizeof(int) * size);
  //memset(delayArr, 0, sizeof(int) * size);
//
  //knowSecret = 1;
  //limit = min(1+forget, size);
  //delayArr[1] = 1;
  //for (j = 1 + delay; j < limit; j++) {
    //delayArr[j] = 1;
  //}
//
  //for (i = 2; i <= n; i++) {
    //if (i - forget >= 1) {
      //f = delayArr[i-forget];
    //} else {
      //f = 0;
    //}
    //knowSecret = knowSecret - f + delayArr[i];
//
    //if (delayArr[i] == 0) continue;
//
    //limit = min(i+forget, size);
    //for (j = i + delay; j < limit; j++) {
      //delayArr[j] = (delayArr[j] + delayArr[i]) % mod;
    //}
  //}
//
  //return knowSecret % mod;
//}
//// #v2

//// #v3
//// 使用两个双端队列 know 和 share，它们分别表示仅知道秘密（但不会分享）和会分享秘密的人。
//// 两个双端队列中的每个元素都是一个二元组 (day,cnt)，其中 day 表示知晓秘密的时间，cnt 表示在第 day 天知晓秘密的总人数。
////
//// 初始时，在第一天只有 1 个人知道秘密，并且不会分享，因此 know=[(1,1)]，share=[]。
////
//// 在第 i (2<=i<=n) 天时：
////
//// 1. 第 i-delay 天知晓秘密的人，会开始分享秘密。因此，如果 know 的首元素是 (i-delay,cnt)，那么将它移除，并加到 share 的末尾；
//// 2. 第 i-forget 天知晓秘密的人，会忘记秘密。因此，如果 share 的首元素是 (i-forget,cnt)，那么将它移除；
//// 3. 所有会分享秘密的人，会给一个新的人分享秘密。因此，需要在 know 的末尾添加 (i,cnt)，其中 cnt 是 share 中所有 cnt 的总和。
////
//// 上述 1 和 2 的时间复杂度都是 O(1)，而 3 的时间复杂度是 O(n)，因为需要对 share 进行一次遍历。
//// 虽然这样已经可以通过本题，但也可以将其优化成 O(1)。我们可以用两个变量 knowcnt 和 sharecnt 分别记录 know 和 share 中所有 cnt 的总和，
//// 这样一来，上述的 1 和 2 的时间复杂度不会发生变化，而 3 可以降低至 O(1)。
//// 最终的答案即为 knowcnt+sharecnt。
//
//#define MOD 1000000007
//
//typedef struct {
    //int day;
    //int count;
//} Pair;
//
//typedef struct {
    //Pair* data;
    //int front;
    //int rear;
    //int capacity;
//} Queue;
//
//Queue* createQueue(int capacity) {
    //Queue* queue = (Queue*)malloc(sizeof(Queue));
    //queue->data = (Pair*)malloc(capacity * sizeof(Pair));
    //queue->front = 0;
    //queue->rear = -1;
    //queue->capacity = capacity;
    //return queue;
//}
//
//int isEmpty(Queue* queue) {
    //return queue->rear < queue->front;
//}
//
//void enqueue(Queue* queue, Pair item) {
    //if (queue->rear == queue->capacity - 1) {
        //queue->capacity *= 2;
        //queue->data = (Pair*)realloc(queue->data, queue->capacity * sizeof(Pair));
    //}
    //queue->data[++queue->rear] = item;
//}
//
//Pair dequeue(Queue* queue) {
    //return queue->data[queue->front++];
//}
//
//Pair peek(Queue* queue) {
    //return queue->data[queue->front];
//}
//
//void freeQueue(Queue *queue) {
    //free(queue->data);
    //free(queue);
//}
//
//int peopleAwareOfSecret(int n, int delay, int forget) {
    //Queue* know = createQueue(n);
    //Queue* share = createQueue(n);
//
    //Pair initial = {1, 1};
    //enqueue(know, initial);
    //int knowCnt = 1, shareCnt = 0;
//
    //for (int i = 2; i <= n; i++) {
        //if (!isEmpty(know) && peek(know).day == i - delay) { // 更新分享秘密的队列
            //Pair first = dequeue(know);
            //knowCnt = (knowCnt - first.count + MOD) % MOD;
            //shareCnt = (shareCnt + first.count) % MOD;
            //enqueue(share, first);
        //}
//
        //if (!isEmpty(share) && peek(share).day == i - forget) { // 忘记秘密
            //Pair first = dequeue(share);
            //shareCnt = (shareCnt - first.count + MOD) % MOD;
        //}
//
        //if (!isEmpty(share)) { // 分享秘密
            //knowCnt = (knowCnt + shareCnt) % MOD;
            //Pair newPair = {i, shareCnt};
            //enqueue(know, newPair);
        //}
    //}
//
    //freeQueue(know);
    //freeQueue(share);
//
    //return (knowCnt + shareCnt) % MOD;
//}
//// #v3

//// #v4
//// 前缀和优化
//#define MOD 1000000007
//
//int peopleAwareOfSecret(int n, int delay, int forget) {
    //// 如果只有第1天，直接返回1（只有最初的那个人知道秘密）
    //if (n == 1) {
        //return 1;
    //}
//
    //// dp[i]：表示在第i天"新知道"秘密的人数
    //// 比如：dp[1]=1（第1天A知道了），dp[3]=1（第3天B知道了）
    //long long *dp = (long long *)calloc(n + 1, sizeof(long long));
//
    //// prefix[i]：表示前i天总共新知道秘密的人数（前缀和）
    //// prefix[i] = dp[1] + dp[2] + ... + dp[i]
    //long long *prefix = (long long *)calloc(n + 1, sizeof(long long));
//
    //// 初始化：第1天有1个人新知道秘密
    //dp[1] = 1;
    //prefix[1] = 1;
//
    //// 从第2天开始计算到第n天
    //for (int i = 2; i <= n; i++) {
        ///*
        //计算第i天新知道秘密的人数：
        //这些人是由哪些人分享的呢？
        //- 分享者必须：已经过了delay天（可以分享了）
        //- 分享者必须：还没到forget天（还没忘记）
//
        //具体来说：第j天知道秘密的人，在第i天可以分享的条件是：
        //j + delay <= i （已经可以分享了）
        //j + forget > i  （还没忘记）
//
        //即：j 的范围是 [i-forget+1, i-delay]
//
        //用前缀和表示就是：prefix[i-delay] - prefix[i-forget]
        //*/
//
        //// L：左边界（i-forget），对应前缀和的下标
        //int L = (i - forget) > 0 ? (i - forget) : 0;
//
        //// R：右边界（i-delay），对应前缀和的下标
        //int R = (i - delay) > 0 ? (i - delay) : 0;
//
        //// 计算第i天新知道秘密的人数
        //dp[i] = (prefix[R] - prefix[L]) % MOD;
//
        //// 处理负数（因为取模后可能为负）
        //if (dp[i] < 0) {
            //dp[i] += MOD;
        //}
//
        //// 更新前缀和：前i天的新知道总人数 = 前i-1天 + 第i天
        //prefix[i] = (prefix[i - 1] + dp[i]) % MOD;
    //}
//
    ///*
    //计算第n天结束时知道秘密的总人数：
    //只有最近 (forget-1) 天内知道秘密的人还记得
    //具体来说：从第 (n-forget+1) 天到第n天知道秘密的人还记得
//
    //用前缀和表示：prefix[n] - prefix[n-forget]
    //*/
    //int boundary = (n - forget) > 0 ? (n - forget) : 0;
    //long long ans = (prefix[n] - prefix[boundary]) % MOD;
//
    //// 处理负数
    //if (ans < 0) {
        //ans += MOD;
    //}
//
    //// 释放内存
    //free(dp);
    //free(prefix);
//
    //return (int)ans;
//}
//
//
//// prefix[i-delay] = dp[1] + dp[2] + ... + dp[i-delay]
//// prefix[i-forget] = dp[1] + dp[2] + ... + dp[i-forget]
//
//// 所以：
//// prefix[i-delay] - prefix[i-forget] = dp[i-forget+1] + ... + dp[i-delay]
//// #v4

// #v5
int peopleAwareOfSecret(int n, int delay, int forget) {
  const int mod = 1000000007;
  int i, j, size = n + 1, i1, i2, i3, t;
  uint64_t knowSecret; // 知道秘密的人数
  int *delayArr; // delayArr[i] 表示 1-i 新知道的人数之和, delayArr 是前缀和
  delayArr = (int *)malloc(sizeof(int) * size);
  memset(delayArr, 0, sizeof(int) * size);

  knowSecret = 1;
  delayArr[0] = 0; // 边界设置
  delayArr[1] = 1; // 第一天新知道的人数为 1 个

  for (i = 2; i <= n; i++) {
    // 第 i 天, 为第 i-1 天加上新知道秘密的人和减去忘记秘密的人
    // 忘记秘密: 在第 i-forget 天新增的知道秘密的人
    // 新知道秘密: 在第 [i-forget+1, i-delay] 天的人会分享秘密

    // index: [i-forget+1, i-delay] (分享秘密), [i-forget-1,i-forget] (忘记秘密)
    i1 = (i - forget > 0) ? i - forget : 0;
    i2 = (i - delay > 0) ? i - delay : 0;
    i3 = (i - forget - 1 > 0) ? i - forget - 1 : 0;

    t = (delayArr[i2] - delayArr[i1] - (delayArr[i1] - delayArr[i3])) % mod ;
    // 负数矫正
    if (t < 0) t += mod;

    // 更新第 i 天知道秘密的人数
    knowSecret = (knowSecret + t) % mod;
    // 负数矫正
    if (knowSecret < 0) knowSecret += mod;

    // 更新从 1-i 天所有新知道的人数之和
    delayArr[i] = (delayArr[i-1] + delayArr[i2] - delayArr[i1]) % mod;
    // 负数矫正
    if (delayArr[i] < 0) delayArr[i] += mod;
  }

  return knowSecret % mod;
}
// #v5

int main(int argc, char *argv[])
{
  int n, delay, forget;
  scanf("%d%d%d", &n, &delay, &forget);
  printf("%d\n", peopleAwareOfSecret(n, delay, forget));
  return EXIT_SUCCESS;
}

/* vim: set fdm=marker fmr={,}: */
