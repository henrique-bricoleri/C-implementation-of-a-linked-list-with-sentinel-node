#ifndef LIST_H
#define LIST_H

typedef enum {true,false} bool;

typedef struct _node{
  void* data;
  struct _node *next, *prev;
} Node;

typedef struct _list{
  unsigned data_size;
  Node *sentinel;
} List;

List* initialize(unsigned);

bool insert_front(List *, void *);
bool insert_rear(List *, void *);

bool remove_front(List *, void*);
bool remove_rear(List *, void*);

void destroy(List *);

#endif
