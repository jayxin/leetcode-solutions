struct HashNode {
  int val;
  struct HashNode *next;
};

struct HashTable {
  int c;
  struct HashNode **a;
};

struct HashNode* NewHashNode(int val) {
  struct HashNode *ret = calloc(1, sizeof(struct HashNode));

  ret->val = val;

  return ret;
}

struct HashTable* NewHashTable(int c) {
  struct HashTable *ret = calloc(1, sizeof(struct HashTable));

  ret->c = c;
  ret->a = calloc(c, sizeof(struct HashNode *));
  for (int i = 0; i < c; i++) ret->a[i] = NULL;

  return ret;
}

int HashFunc(struct HashTable *t, int key) {
  int ret = key % t->capacity;
  if (ret < 0) {
    ret += t->capacity;
  }
  return ret;
}

struct HashNode* HashTableFind(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *p = t->a[h];
  while (p) {
    if (p->val == val) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *n, *p = t->a[h];

  n = NewHashNode(val);
  t->a[h] = n;
  n->next = p;
}

void HashTablePrint(struct HashTable *t) {
  struct HashNode *p;

  for (int i = 0; i < t->c; i++) {
    if (t->a[i] == NULL) {
      continue;
    }
    p = t->a[i];
    while (p) {
      printf("%d ", t->a[i]->val);
      p = p->next;
    }
    putchar('\n');
  }
}

void HashTableRemove(struct HashTable *t, int val) {
  int h = HashFunc(t, val);
  struct HashNode *p = t->a[h];
  if (!p) {
    return ;
  } else {
    struct HashNode *prev = NULL;
    while (p) {
      if (p->val == val) {
        break;
      }
      prev = p;
      p = p->next;
    }
    if (p) {
      if (prev) {
        prev->next = p->next;
      } else {
        t->a[h] = t->a[h]->next;
      }
      free(p);
    }
  }
}
