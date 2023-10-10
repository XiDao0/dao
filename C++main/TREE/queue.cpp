//
// Created by 侬憨憨 on 2023/5/7.
//
#include "funcion.h"

void InitNode(link_queue &Q)
{
    Q.front = Q.rear = (link_node*)malloc(sizeof (link_node));
    Q.front->next = NULL;
}

bool IsEmpty(link_queue Q)
{
    if(Q.front == Q.rear)
    {
        return true;
    }
    return false;
}

void EnQueue(link_queue &Q, ElemType val)
{
    link_node *p = (link_node*) malloc(sizeof (link_node));
    p->data = val;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = Q.rear->next;
}

bool DeQueue(link_queue &Q,ElemType &val)
{
    if(Q.front == Q.rear)
    {
        return false;
    }
    link_node *q = Q.front->next;
    val = q->data;
    Q.front->next = q->next;
    if(Q.rear == q)
    {
        Q.rear = Q.front;
    }
    free(q);
    return true;
}