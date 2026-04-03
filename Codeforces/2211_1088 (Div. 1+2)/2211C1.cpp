#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int a[maxn], b[maxn], n, k;
bool vis[maxn], used[maxn];

void fail( ) { cout << "NO" << '\n'; return ; }

void solve( )
{
    cin >> n >> k;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    for( int i = 1; i <= n; ++ i ) cin >> b[i];

    int l = n - k + 1, r = k;

    for( int i = 1; i <= l - 1; ++ i ) {
        if( b[i] != -1 && b[i] != a[i] ) return fail( );
    }
    for( int i = r + 1; i <= n; ++ i ) {
        if( b[i] != -1 && b[i] != a[i] ) return fail( );
    }

    for( int i = 1; i <= n; ++ i ) vis[i] = used[i] = 0;

    if( l <= r ) 
    {
        for( int i = l; i <= r; ++ i ) vis[a[i]] = 1;

        for( int i = l; i <= r; ++ i ) 
        {
            if( b[i] != -1 ) 
            {
                if( !vis[b[i]] || used[b[i]] ) return fail( );
                used[b[i]] = 1;
            }
        }
    }
    else 
    {
        for( int i = r + 1; i <= l - 1; ++ i ) {
            if( b[i] != -1 && b[i] != a[i] ) return fail( );
        }
    }
    cout << "YES" << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}