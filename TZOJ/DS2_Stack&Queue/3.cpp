#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elemtype;

typedef struct SqQueue {
    Elemtype* data;
    int size;
    int front, rear;
} SqQueue;

int Empty( SqQueue *q )
{
    return q->front == q->rear;
}

void EnQueue( SqQueue* q, Elemtype x )
{
    q->data[ q->rear ] = x;
    q->rear ++;
}

int Front( SqQueue* q )
{
    if( Empty(q) ) return -1;
    return q->data[ q->front ];
}

int Back( SqQueue* q )
{
    if( Empty(q) ) return -1;
    return q->data[ q->rear-1 ];
}

int DeQueue( SqQueue* q )
{
    int x = q->data[ q->front ];
    q->front ++;
    return x;
}

void InitQueue( SqQueue* q )
{
    q->size = 500;
    q->data = ( Elemtype* )malloc( sizeof( Elemtype ) * (q->size) );
    q->front = 0;
    q->rear = 0;
}

/* ============================== */

void Destroy(SqQueue* q)
{
	free(q->data);
}

int main()
{
    SqQueue q;
    InitQueue(&q);
    char cmd[10];
    int x, res;
    while(scanf("%s", cmd)!=EOF)
    {
        if(strcmp(cmd, "enq")==0)
        {
            scanf("%d", &x);
            EnQueue(&q, x);
        }
        else if(strcmp(cmd, "front")==0)
        {
            if(Empty(&q))
                printf("EMPTY\n");
            else
                printf("%d\n", Front(&q));
        }
        else if(strcmp(cmd, "back")==0)
        {
            if(Empty(&q))
                printf("EMPTY\n");
            else
                printf("%d\n", Back(&q));
        }
        else
        {
            if(Empty(&q))
                printf("EMPTY\n");
            else
                printf("%d\n", DeQueue(&q));
        }
    }
    Destroy(&q);
    return 0;
}
