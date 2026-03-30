#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    int n, m, l;
    cin >> n >> m >> l;

    vector< int > a( n + 2 );
    for( int i = 1; i <= n; i ++ ) cin >> a[i];
    a[n + 1] = l;
    
    vector< int > d( m, 0 );
    int last = 0;

    for( int i = 1; i <= n + 1; ++ i )
    {
        int cur = a[i];
        int diff = cur - last;

        int cnt = min( m, n - i + 1 + 1 );

        priority_queue< int, vector< int >, greater< int > > pq;
        
        for( int j = 0; j < cnt; j ++ ) 
        {
            pq.push( d[j] );
        }

        for( int j = 0; j < diff; j ++ )
        {
            int val = pq.top( ); pq.pop( );
            pq.push( val + 1 );
        }

        for( int j = 0; j < cnt; j ++ )
        {
            d[j] = pq.top( ); pq.pop( );
        }

        sort( d.begin( ), d.end( ), greater< int >( ) );

        if( i <= n )
        {
            d[0] = 0;
            sort( d.begin( ), d.end( ), greater< int >( ) );
        }
        last = cur;
    }
    cout << d[0] << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}