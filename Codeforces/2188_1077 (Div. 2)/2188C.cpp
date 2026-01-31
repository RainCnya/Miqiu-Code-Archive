#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int a[maxn];
int b[maxn];
int n;

void solve( )
{
    cin >> n;
    int mn = inf, mx = 0;
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> a[i];
        b[i] = a[i];
        mn = min( mn, a[i] );
        mx = max( mx, a[i] );
    }

    sort( b + 1, b + n + 1 );
    
    vector< int > pos;
    for( int i = 1; i <= n; ++ i )
    {
        if( a[i] != b[i] ) pos.push_back( i );
    }

    if( pos.empty( ) )
    {
        cout << -1 << '\n';
        return;
    }

    int k = inf;
    for( int i = 0; i < pos.size( ); ++ i )
    {
        k = min( k, max( mx - a[pos[i]], a[pos[i]] - mn ) );
    }
    cout << k << '\n';
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