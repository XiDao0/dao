#include <stdio.h>
#include <stdlib.h>

#define Maxsize 5
typedef int ElemType;
typedef struct SqQueue{
    ElemType data[Maxsize];
    int front,rear;
}SqQueue;

void InitSqQueue(SqQueue &S)
{
    S.front  = S.rear = 1;
}

bool SqQueueEmpty(SqQueue S)
{
    if(S.front == S.rear)
    {
        return true;
    }else{
        return false;
    }
}

bool EnQueue(SqQueue &S, ElemType val)
{
    if((S.rear+1)%Maxsize == S.front)
    {
        return false;
    }
    S.data[S.rear] = val;
    S.rear = (S.rear+1)%Maxsize;
    return true;
}

bool getTop(SqQueue S, ElemType &m)
{
    if (SqQueueEmpty(S))
    {
        return false;
    }
    m = S.data[S.front];
    return true;
}

bool DeQueue(SqQueue &S,ElemType &m)
{
    if(SqQueueEmpty(S))
    {
        return false;
    }
    m = S.data[S.front];
    S.front = (S.front+1)%Maxsize;
    return true;
}

int main() {

    SqQueue S;
    InitSqQueue(S);
    ElemType flag;
    flag = SqQueueEmpty(S);
    if(flag)
    {
        printf("stack is empty\n");
    }

    EnQueue(S, 3);
    EnQueue(S, 2);
    EnQueue(S, 1);
    ElemType m;
    flag = getTop(S,m);
    if(flag)
    {
        printf("Stack by top is %d\n",m);
    }
    while(flag)
    {
        flag = DeQueue(S, m);
        if(flag)
        {
            printf("get top by Queue out is %d\t\n", m);
        }else{
            printf("Queue is empty");
        }
    }

    return 0;
}
