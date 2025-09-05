struct HashNode {
  int val;
  struct HashNode *next;
};

struct HashTable {
  int capacity;
  int size;
  struct HashNode **table;
};

struct HashNode* NewHashNode(int val) {
  struct HashNode *ret = (struct HashNode *)malloc(sizeof(struct HashNode));
  ret->val = val;
  ret->next = NULL;
  return ret;
}

struct HashTable* NewHashTable(int capacity) {
  if (capacity <= 0) {
    return NULL;
  }

  struct HashTable *ret = (struct HashTable *)malloc(sizeof(struct HashTable));
  ret->capacity = capacity;
  ret->size = 0;
  int table_bytes = sizeof(struct HashNode *) * capacity;
  ret->table = (struct HashNode **)malloc(table_bytes);
  memset(ret->table, 0, table_bytes);

  return ret;
}

int HashFunc(struct HashTable *t, int key) {
  if (!t) return 0;
  int ret = key % t->capacity;
  if (ret < 0) {
    ret += t->capacity;
  }
  return ret;
}

struct HashNode* HashTableFind(struct HashTable *t, int val) {
  if (!t) return NULL;
  int h = HashFunc(t, val);
  if ((t->table)[h] == NULL) {
    return NULL;
  }
  struct HashNode *p = (t->table)[h];
  while (p) {
    if (p->val == val) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

void HashTableAdd(struct HashTable *t, int val) {
  if (!t) return ;
  int h = HashFunc(t, val);
  struct HashNode *n, *p = (t->table)[h];
  n = NewHashNode(val);
  if (p == NULL) {
    (t->table)[h] = n;
  } else {
    n->next = p;
    (t->table)[h] = n;
  }
}

void HashTablePrint(struct HashTable *t) {
  if (!t) return ;
  struct HashNode *p;
  int i;
  for (i = 0; i < t->capacity; i++) {
    if (t->table[i] == NULL) {
      continue;
    }
    p = t->table[i];
    while (p) {
      printf("%d ", t->table[i]->val);
      p = p->next;
    }
    putchar('\n');
  }
}

void HashTableRemove(struct HashTable *t, int val) {
  if (!t) return ;
  int h = HashFunc(t, val);
  struct HashNode *p = (t->table)[h];
  if (p == NULL) {
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
        (t->table)[h] = (t->table)[h]->next;
      }
      free(p);
    }
  }
}
