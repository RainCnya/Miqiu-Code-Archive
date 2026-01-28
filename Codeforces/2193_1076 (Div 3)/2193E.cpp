#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;

ll a[maxn];
int d[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> a[i];
    }

    sort( a + 1, a + n + 1 );
    int m = unique( a + 1, a + n + 1 ) - (a + 1);

    for( int i = 1; i <= n; ++ i ) d[i] = -1;

    queue< ll > q;
    for( int i = 1; i <= m; ++ i )
    {
        if( d[ a[i] ] == -1 )
        {
            d[ a[i] ] = 1;
            q.push( a[i] );
        }
    }

    while( !q.empty( ) )
    {
        int u = q.front( );
        q.pop( );

        for( int j = 1; j <= m; ++ j )
        {
            if( a[j] == 1 ) continue;

            ll v = u * a[j];
            if( v > n ) break;

            if( d[v] == -1 )
            {
                d[v] = d[u] + 1;
                q.push( v );
            }
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        cout << d[i] << " ";
    }
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}