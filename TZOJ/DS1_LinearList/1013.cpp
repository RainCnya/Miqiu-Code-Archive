#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;

void solve( )
{
    cin >> n;
    vector< int > va( n );
    for( int i = 0; i < n; ++ i ) cin >> va[i];

    cin >> m;
    vector< int > vb( m );
    for( int i = 0; i < m; ++ i ) cin >> vb[i];

    vector< int > vc( n + m );
    int pa = 0, pb = 0, pc = 0;
    while( pa < n && pb < m ) {
        if( va[pa] < vb[pb] ) vc[pc ++] = va[pa ++];
        else vc[pc ++] = vb[pb ++];
    }

    while( pa < n ) vc[pc ++] = va[pa ++];

    while( pb < m ) vc[pc ++] = vb[pb ++];

    cout << vc.size( ) << ' ';
    for( int i = 0; i < vc.size(); ++ i ) 
    {
        if( i ) cout << " ";
        cout << vc[i];
    }
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}