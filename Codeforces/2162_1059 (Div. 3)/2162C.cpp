#include<bits/stdc++.h>
using namespace std;

int getOne( long long x ) {
    if( x == 0 ) return 0;
    for( int i = 62; i >= 0; -- i ) {
        if( x & (1LL << i) )
            return i;
    }
    return 0;
}

int main( ) {
    int t;  cin >> t;
    while( t -- ) {
        long long a, b;
        cin >> a >> b;

        if( a == b ) {
            cout << "0" << endl;
            continue;
        }

        int lena = getOne( a );
        int lenb = getOne( b );

        if( lena < lenb ) {
            cout << "-1" << endl;
            continue;
        } 

        long long asd = a ^ b;
        if( asd <= a ) {
            cout << "1" << endl;
            cout << asd << endl;
        } else {
            long long t = a | asd;
            long long x1 = t ^ a;
            long long x2 = t ^ b;

            if( x1 <= a && x2 <= t ) {
                cout << "2" << endl;
                cout << x1 << " " << x2 << endl;
            } else {
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}