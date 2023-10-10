#include <stdio.h>
#include <iostream>
#include <stdlib.h>

#define Maxsize 50
typedef int ElemType;
typedef struct LNode{
    ElemType data;
    struct  LNode *next;
}LNode, *link_list;

void list_head_insert(link_list &L)
{
    L =(link_list)malloc(sizeof(LNode));
    L->next = NULL;
    ElemType x;
    scanf("%d",&x);
    LNode *s;
    while(x!=9999)
    {
        s = (link_list) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
}

void list_tail_insert(link_list &L)
{
    L =(link_list)malloc(sizeof(LNode));
    L->next = NULL;
    ElemType x;
    scanf("%d",&x);
    LNode *s, *r = L;
    while(x!=9999)
    {
        s = (link_list) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
}

void printf_list(link_list L)
{
    L = L->next;
    while(L!=NULL)
    {
        printf("%3d", L->data);
        L = L->next;
    }
    printf("\n");

}

link_list GetElem(link_list L, int SearchPos)
{
    int i = 0;
    while(L && i < SearchPos)
    {
        L = L->next;
        i++;
    }
    return L;
}

link_list  LocateElem(link_list L, ElemType SearchVal)
{
    while (L && L->data != SearchVal)
    {
        L = L->next;
    }
    return L;
}

bool InsertElem(link_list L, int pos, ElemType x)
{
    link_list p;
    p = GetElem(L, pos-1);
    if(p == NULL)
    {
        return false;
    }
    link_list q;
    q = (link_list) malloc(sizeof(LNode));
    q->data = x;
    q->next = p->next;
    p->next = q;
    return true;
}

bool LinkDelete(link_list L, int pos, ElemType &val)
{
    link_list p = GetElem(L, pos-1);
    if(p == NULL)
    {
        return false;
    }
    link_list q;
    q = p->next;
    if(q==NULL){
        return false;
    }
    val = q->data;
    p->next = q->next;
    free(q);
    return true;
}

link_list FindList(link_list L, link_list&L2)
{
    L2 = (link_list) malloc(sizeof (LNode));
    link_list ppre, pcur;
    ppre = L->next;
    pcur = L->next;
    while(pcur !=NULL)
    {
        pcur = pcur->next;
        if(pcur==NULL)
        {
            break;
        }
        pcur = pcur->next;
        if(pcur==NULL)
        {
            break;
        }
        ppre = ppre->next;


    }
    L2->next = ppre->next;
    ppre->next = NULL;
    return L2;
}

link_list Reverse(link_list &L2)
{
    if(L2->next == NULL || L2->next->next == NULL)
    {
        return L2;
    }
    link_list r, s, t;
    r = L2->next;
    s = r->next;
    t = s->next;

    while(t)
    {
        s->next = r;
        r = s;
        s = t;
        t = t->next;
    }
    s->next = r;
    L2->next->next = NULL;
    L2->next = s;
    return L2;
}

link_list merge(link_list &L, link_list L2)
{
    if(L2==NULL)
    {
        return L;
    }
    link_list pcur, p, q;
    pcur = L->next;
    p = L->next->next;
    q = L2->next;
    while(p!=NULL & q!=NULL)
    {
        pcur->next = q;
        q = q->next;
        pcur = pcur->next;
        pcur->next = p;
        p = p->next;
        pcur = pcur->next;
    }
    if(q!=NULL)
    {
        pcur->next = q;
        return L;
    }
    return L;
}

int main() {
    link_list L, L2;
    L2 = NULL;
//    link_list search;
//    list_head_insert(L);
//    printf_list(L);
    list_tail_insert(L);
    printf_list(L);
    FindList(L,L2);
    printf_list(L2);
    Reverse(L2);
    printf_list(L2);
    merge(L, L2);
    free(L2);
    printf_list(L);
//    if(InsertElem(L, 5, 20))
//    {
//        printf_list(L);
//    }
//    ElemType val, ret;
//
//    ret = LinkDelete(L,4,val);
//
//    if(ret)
//    {
//        printf("Search by Val success\n");
//        printf("你所释放结点的值为：%d\n", val);
//    }else{
//        printf("Search by Val failed\n");
//    }
//    printf_list(L);

//    search = GetElem(L, 2);
//    search = LocateElem(L,3);
//    if(search != NULL)
//    {
//        printf("%d", search->data);
//    } else {
//        printf("Search by value failed");
//    }

    return 0;
}
