#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Elemtype;

typedef struct LinkStack {
    Elemtype data;
    struct LinkStack *next;
} LinkStack;

LinkStack* Push( LinkStack* head, Elemtype x )
{
    LinkStack* p = (LinkStack*)malloc(sizeof(LinkStack));
    p->data = x;
    p->next = head;
    return p;
}

int GetTop( LinkStack* head, Elemtype *x )
{
    if( head == NULL ) return 0;
    *x = head->data;
    return 1;
}

LinkStack* Pop( LinkStack* head )
{
    if( head == NULL ) {
        printf("EMPTY\n");
        return NULL;
    }
    printf("%d\n", head->data);
    LinkStack* p = head;
    head = head->next;
    free( p );
    return head;
}


LinkStack* InitStack( )
{
    return NULL;
}

/* ============================== */

void Destroy(LinkStack *head)
{
    LinkStack *p = head;
    while(p)
    {
        head = head->next;
        free(p);
        p=head;
    }
}

int main()
{
    LinkStack *linkStack;
    linkStack = InitStack();
    char cmd[10];
    int x, res;
    while(scanf("%s", cmd)!=EOF)
    {
        if(strcmp(cmd, "push")==0)
        {
            scanf("%d", &x);
            linkStack = Push(linkStack, x);
        }
        else if(strcmp(cmd, "top")==0)
        {
            res = GetTop(linkStack, &x);
            if(res==0)
                printf("EMPTY\n");
            else
                printf("%d\n", x);
        }
        else
            linkStack = Pop(linkStack);
    }
    Destroy(linkStack);
    return 0;
}
