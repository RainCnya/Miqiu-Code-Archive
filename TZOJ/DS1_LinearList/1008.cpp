void Add( Node* head, int m, int x )
{
    Node* p = head;
    while( p->next != NULL && p->next->cost < x ) p = p->next;
    if( p->next != NULL && p->next->cost == x ) p->next->num += m;
    else {
        Node* t = ( Node* )malloc( sizeof( Node ) );
        t->num = m;
        t->cost = x;
        t->next = p->next;
        p->next = t;
    }
}