#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElemType;
typedef struct d_arr{
    ElemType *x;
    int len;
}d_arr,*doar;

void init_arr(d_arr &A,int len){
    A.len = len;
    A.x = (ElemType*) malloc(sizeof (ElemType)*A.len);
    srand(time((NULL)));
    for(int i = 0; i < A.len; ++i)
    {
        A.x[i] = rand()%100;
    }
}

void print_arr(d_arr A)
{
    for(int i = 0; i<A.len;++i){
        printf("%3d",A.x[i]);
    }
    printf("\n");
}

//void sort_arr(d_arr &A)
//{
//    int temp;
//    for(int i = 0;i<A.len-1;++i){
//        for(int j = 0; j<A.len; ++j){
//            if(A.x[j]>A.x[j+1]){
//                temp = A.x[j];
//                A.x[j] = A.x[j+1];
//                A.x[j+1] = temp;
//            }
//        }
//    }
//}

int compare(const void *left,const void *right){
    return *(int *)left - *(int *)right;
}

int Search_midval(d_arr A,ElemType y){
    int low = 0;
    int high = A.len-1;
    while(low<high){
        int mid = (low + high)/2;
        if(y == A.x[mid])
        {
            return mid;
        }else if(y < A.x[mid]){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    printf(" find fail");
    return -1;
}

int main() {
    d_arr A;
    int len = 6;
    scanf("%d",&len);
    init_arr(A,len);
    print_arr(A);
    qsort(A.x,A.len,sizeof (ElemType),compare);
//    sort_arr(A);
    print_arr(A);
    ElemType x;
    scanf("%d",&x);
    printf("%d",Search_midval(A,x));

    return 0;
}
