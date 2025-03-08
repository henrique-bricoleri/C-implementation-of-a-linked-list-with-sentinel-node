#include <stdlib.h>
#include <string.h>
#include "list.h"

List* initialize(unsigned data_size){
  List *l = (List*)malloc(sizeof(List));

  l->sentinel = (Node*)malloc(sizeof(Node));
  l->sentinel->next = l->sentinel->prev = l->sentinel;
  l->data_size = data_size;

  return l;
}

bool insert_front(List *l, void* data){
  Node *new_node = (Node*)malloc(sizeof(Node));
  if(new_node == NULL) return false;

  new_node->data = malloc(l->data_size);
  memcpy(new_node->data, data, l->data_size);

  if(l->sentinel->next == l->sentinel){
    l->sentinel->next = l->sentinel->prev = new_node;
    new_node->next = new_node->prev = l->sentinel;
  }
  else{
    new_node->next = l->sentinel->next;
    new_node->prev = l->sentinel;

    l->sentinel->next->prev = new_node;
    l->sentinel->next = new_node;
  }

  return true;
}

bool insert_rear(List *l, void* data){
  Node *new_node = (Node*)malloc(sizeof(Node));
  if(new_node == NULL) return false;

  new_node->data = malloc(l->data_size);
  memcpy(new_node->data, data, l->data_size);

  if(l->sentinel->prev == l->sentinel){
    l->sentinel->next = l->sentinel->prev = new_node;
    new_node->next = new_node->prev = l->sentinel;
  }
  else{
    new_node->next = l->sentinel;
    new_node->prev = l->sentinel->prev;

    l->sentinel->prev->next = new_node;
    l->sentinel->prev = new_node;
  }

  return true;
}

bool remove_front(List *l, void* data_removed){
  if(l->sentinel->next == l->sentinel) return false;

  Node *first = l->sentinel->next;
  if(data_removed) memcpy(data_removed, first->data, l->data_size);

  l->sentinel->next = first->next;
  first->next->prev = l->sentinel;

  free(first->data);
  free(first);

  return true;
}

bool remove_rear(List *l, void* data_removed){
  if(l->sentinel->prev == l->sentinel) return false;

  Node *last = l->sentinel->prev;
  if(data_removed) memcpy(data_removed, last->data, l->data_size);

  l->sentinel->prev = last->prev;
  last->prev->next = l->sentinel;

  free(last->data);
  free(last);

  return true;
}

void destroy(List *l){
  Node *actual = l->sentinel->next;

  while(actual != l->sentinel){
    Node *temp = actual;
    actual = actual->next;

    free(temp->data);
    free(temp);
  }

  free(l->sentinel);
  free(l);
}
