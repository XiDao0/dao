#include "funcion.h"

void EnTree(BiTree &tree,ptag_t &phead){
    BiTree pnew;
    BiElemType c;
    ptag_t ptail = NULL, listpnew = NULL, pcur = NULL;
    while(scanf("%c", &c))
    {
        if(c =='\n')
        {
            break;
        }
        pnew = (BiTree) calloc(1,sizeof(BiTNode));
        pnew->c = c;
        listpnew = (ptag_t) calloc(1,sizeof (tag_t));
        listpnew->p = pnew;

        if(tree == NULL)
        {
            tree = pnew;
            phead = listpnew;
            ptail = listpnew;
            pcur = listpnew;
        }else{
            ptail->pnext = listpnew;
            ptail = listpnew;
            if(pcur->p->lchild == NULL)            {
                pcur->p->lchild = pnew;
            }else if(pcur->p->rchild == NULL){
                pcur->p->rchild = pnew;
                pcur = pcur->pnext;
            }
        }
    }
}

void Preorder(BiTree p){
    if(p!=NULL){
        printf("preorder %c\t",p->c);
        Preorder((p->lchild));
        Preorder((p->rchild));
    }
    return ;
}

void Inorder(BiTree p){
    if(p!=NULL){
        Inorder((p->lchild));
        printf("Inorder %c\t",p->c);
        Inorder((p->rchild));
    }
    return ;
}

void Postorder(BiTree p){
    if(p!=NULL){
        Postorder((p->lchild));
        Postorder((p->rchild));
        printf("Postorder %c\t",p->c);
    }
    return ;
}

void MidOrder(ptag_t head)
{
    ptag_t ptail;
    ptail= head;
    while(ptail != NULL)
    {
        printf("%c",ptail->p->c);
        ptail = ptail->pnext;
    }

}

void LeverOrder(BiTree T)
{
    link_queue Q;
    InitNode(Q);
    BiTree p;
    EnQueue(Q,T);
    while(!IsEmpty(Q))
    {
        DeQueue(Q,p);
        putchar(p->c);
        if(p->lchild!=NULL)
        {
            EnQueue(Q,p->lchild);
        }
        if(p->rchild!=NULL)
        {
            EnQueue(Q,p->rchild);
        }
    }
}

int wpl_Preorder(BiTree p,int deep){
    static int wpl = 0;
    if(p->lchild == NULL && p->rchild == NULL)
    {
        wpl = wpl + p->c * deep;
    }
    if(p->lchild != NULL)
        wpl_Preorder((p->lchild), deep+1);
    if(p->rchild != NULL)
        wpl_Preorder((p->rchild), deep+1);
    return wpl ;
}

int WPL(BiTree F)
{
    return wpl_Preorder(F,0);
}

int main() {
    BiTree tree = NULL;
    ptag_t  phead = NULL;
    EnTree(tree,phead);
    printf("wpl = %d",WPL(tree));
//    LeverOrder(tree);
//    MidOrder(phead);
//    Preorder(tree);
//    printf("\n");
//    Inorder(tree);
//    printf("\n");
//    Postorder(tree);
//    printf("\n");



    return 0;
}
