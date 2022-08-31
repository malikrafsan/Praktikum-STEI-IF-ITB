#ifndef BAG_H
#define BAG_H

#include "boolean.h"
#include "stack.h"

typedef struct {
  Stack s;   /* tabel penyimpan elemen */
  int capEff;               /* alamat TOP: elemen puncak */
} Bag;

/* *** Konstruktor/Kreator *** */
void CreateBag(Bag *b);

boolean isEmpty(Stack s);

boolean isFull(Stack s);

void push(Stack *s, ElType val);

void pop(Stack *s, ElType *val);

#endif