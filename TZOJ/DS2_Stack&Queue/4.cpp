#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef int Elemtype;

typedef struct QNode {
    Elemtype data;
    struct QNode *next;
} QNode;

typedef struct {
    QNode* front;
    QNode* tail;
} LinkQueue;

int Empty( LinkQueue &q )
{
    return q.front == q.tail;
}

void EnQueue( LinkQueue &q, Elemtype x )
{
    QNode* p = (QNode*)malloc(sizeof(QNode));
    p->data = x;
    p->next = NULL;
    q.tail->next = p;
    q.tail = p;
}

int DeQueue( LinkQueue &q )
{
    QNode* p = q.front->next;
    int x = p->data;
    q.front->next = p->next;
    if( q.tail == p ) q.tail = q.front;
    free( p );
    return x;
}

int Front( LinkQueue &q )
{
    return q.front->next->data;
}

int Back( LinkQueue &q )
{
    return q.tail->data;
}

/* ============================== */

void InitQueue(LinkQueue &q)
{
    q.front = (QNode*)malloc(sizeof(QNode));
    q.front->next=NULL;
    q.tail = q.front;
}

void Destroy(LinkQueue &q)
{
    QNode *p = q.front, *t;
    while(p)
    {
        t = p;
        p = p->next;
        free(t);
    }
}

int main()
{
    LinkQueue q;
    InitQueue(q);
    char cmd[10];
    int x, res;
    while(scanf("%s", cmd)!=EOF)
    {
        if(strcmp(cmd, "enq")==0)
        {
            scanf("%d", &x);
            EnQueue(q, x);
        }
        else if(strcmp(cmd, "front")==0)
        {
            if(Empty(q))
                printf("EMPTY\n");
            else
                printf("%d\n", Front(q));
        }
        else if(strcmp(cmd, "back")==0)
        {
            if(Empty(q))
                printf("EMPTY\n");
            else
                printf("%d\n", Back(q));
        }
        else
        {
            if(Empty(q))
                printf("EMPTY\n");
            else
                printf("%d\n", DeQueue(q));
        }
    }
    Destroy(q);
    return 0;
}