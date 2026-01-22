#include<bits/stdc++.h>
using namespace std;

int getOne( long long x ) 
{
    if( x == 0 ) return 0;
    for( int i = 62; i >= 0; -- i ) 
    {
        if( ( x >> i ) & 1 )
            return i;
    }
    return 0;
}

int main( ) 
{
    int t;  
    cin >> t;
    while( t -- ) 
    {
        long long a, b;
        cin >> a >> b;

        if( a == b ) 
        {
            cout << "0" << '\n';
            continue;
        }

        int lena = getOne( a );
        int lenb = getOne( b );

        if( lena < lenb ) 
        {
            cout << "-1" << '\n';
            continue;
        } 

        long long asd = a ^ b;
        if( asd <= a ) 
        {
            cout << "1" << '\n';
            cout << asd << '\n';
        } 
        else 
        {
            long long t = a | asd;
            long long x1 = t ^ a;
            long long x2 = t ^ b;

            if( x1 <= a && x2 <= t ) 
            {
                cout << "2" << '\n';
                cout << x1 << " " << x2 << '\n';
            } 
            else 
            {
                cout << "-1" << '\n';
            }
        }
    }
    return 0;
}