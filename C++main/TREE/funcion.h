//
// Created by 侬憨憨 on 2023/5/6.
//

#ifndef TREE_FUNCION_H
#define TREE_FUNCION_H

#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;

typedef struct BiTNode{
    BiElemType c;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;

typedef struct tag{
    BiTree p;
    struct tag *pnext;
}tag_t,*ptag_t;

typedef BiTree ElemType;
typedef struct link_node{
    ElemType data;
    link_node *next;
}link_node;
typedef struct {
    link_node *front, *rear;
}link_queue;

void InitNode(link_queue &Q);
bool IsEmpty(link_queue Q);
void EnQueue(link_queue &Q, ElemType val);
bool DeQueue(link_queue &Q,ElemType &val);


#endif //TREE_FUNCION_H
