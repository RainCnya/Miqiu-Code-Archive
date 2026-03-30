#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int Elemtype;

typedef struct SqQueue {
    Elemtype* base;
    int front, rear;
    int size;
} SqQueue;

void InitQueue( SqQueue *q )
{
    q->size = 5;
    q->base = ( Elemtype* )malloc( sizeof( Elemtype ) * (q->size) );
    q->front = 0;
    q->rear = 0;
}

int EnQueue( SqQueue *q, Elemtype x )
{
    if( ( q->rear + 1 ) % q->size == q->front ) return 0;
    q->base[ q->rear ] = x;
    q->rear = ( q->rear + 1 ) % q->size;
    return 1;
}

int DeQueue( SqQueue *q, Elemtype *x )
{
    if( q->front == q->rear ) return 0;
    *x = q->base[ q->front ];
    q->front = ( q->front + 1 ) % q->size;
    return 1;
}

int Destroy( SqQueue *q )
{
    free(q->base);
}

int QueueLength( SqQueue q )
{
    return ( q.rear - q.front + q.size ) % q.size;
}

/* ============================== */

int main()
{
    SqQueue q;
    char ss[10]; 
    int x, sta,l; 
    InitQueue(&q); 
    while(scanf("%s", ss)!=EOF) 
    {
        if(strcmp(ss, "enter")==0)
        {
            scanf("%d", &x);
            sta= EnQueue(&q,x);
            if(sta==0)
                printf("FULL\n"); 
        }
        else if(strcmp(ss, "length")==0)
        {
            l=QueueLength(q); 
            printf("%d\n", l);
        }
        else
        {
            sta = DeQueue(&q,&x);
            if(sta==0)
                printf("EMPTY\n"); 
            else
                printf("%d\n", x);
        } 
    }
    return 0;
}