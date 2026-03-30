Node* Add (Node* hA, Node* hB ) 
{
    Node* hC = ( Node* )malloc( sizeof( Node ) );
    hC->next = NULL;
    Node* pc = hC;

    Node* pa = hA->next;
    Node* pb = hB->next;

    while( !(pa == NULL && pb == NULL) ) 
    {
        Node* t = ( Node* )malloc( sizeof( Node ) );
        t->next = NULL;

        if( pa != NULL && (pb == NULL || pa->exp < pb->exp) ) 
        {
            t->coef = pa->coef;
            t->exp = pa->exp;
            pa = pa->next;
        } 
        else if( pb != NULL && (pa == NULL || pb->exp < pa->exp) ) 
        {
            t->coef = pb->coef;
            t->exp = pb->exp;
            pb = pb->next;
        } 
        else 
        {
            int sum = pa->coef + pb->coef;
            if( sum == 0 ) 
            {
                free( t );
                pa = pa->next;
                pb = pb->next;
                continue;
            }
            t->coef = sum;
            t->exp = pa->exp;
            pa = pa->next;
            pb = pb->next;
        }
        pc->next = t;
        pc = t;
    }
    return hC;
}