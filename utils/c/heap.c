struct MaxHeap {
  int *a;
  int size, capacity;
};

struct MaxHeap* NewHeap(int capacity) {
  struct MaxHeap *ret = (struct MaxHeap *)malloc(sizeof(struct MaxHeap));

  ret->a = (int *)malloc(sizeof(int) * capacity);
  ret->size = 0;
  ret->capacity = capacity;

  return ret;
}

void HeapSwap(struct MaxHeap *h, int i, int j) {
  int t = h->a[i];
  h->a[i] = h->a[j];
  h->a[j] = t;
}

void HeapUp(struct MaxHeap *h, int p) { // 向上调整
  while (p > 1) {
    if (h->a[p] > h->a[p>>1]) { // 子节点 > 父节点, 不满足大根堆性质
      HeapSwap(h, p, p>>1);
      p >>= 1;
    } else {
      break;
    }
  }
}

void HeapDown(struct MaxHeap *h, int p) { // 向下调整
  int s = p << 1; // p 的左子节点
  int n = h->size;

  while (s <= n) {
    if (s < n && h->a[s] < h->a[s+1]) s++; //左右子节点取较大
    if (h->a[s] > h->a[p]) { // 子节点 > 父节点
      HeapSwap(h, s, p);
      p = s;
      s = p<<1;
    } else {
      break;
    }
  }
}

void HeapInsert(struct MaxHeap *h, int v) {
  h->a[++(h->size)] = v;
  HeapUp(h, h->size);
}

int HeapTop(struct MaxHeap *h) {
  return h->a[1];
}

void HeapExtract(struct MaxHeap *h) {
  h->a[1] = h->a[(h->size)--];
  HeapDown(h, 1);
}

void HeapRemove(struct MaxHeap *h, int p) {
  h->a[p] = h->a[(h->size)--];
  HeapUp(h, p);
  HeapDown(h, p);
}

void DestroyHeap(struct MaxHeap *h) {
  if (!h) return ;
  free(h->a);
  free(h);
}
