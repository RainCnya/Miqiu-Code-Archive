typedef struct node {
    int id;
    struct node* next;
}Node;

Node* DeleteOne( Node *head, int m )
{
    Node* p = head;
    Node* pre = NULL;
    int i;
    for( i = 1; i <= m - 1; ++ i ) {
        pre = p;
        p = p->next;
    }
    printf("%d\n", p->id);
    pre->next = p->next;
    free( p );
    return pre->next;
}