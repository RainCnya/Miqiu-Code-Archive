#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 50;

int pre[maxn];
int post[maxn];
int a[maxn];

void solve( )
{
    memset( pre, 128, sizeof( pre ) );
    memset( post, 127, sizeof( post ) );
    int n;
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }
    pre[1] = a[1];
    for( int i = 2; i <= n; ++ i )
        pre[i] = min( pre[i-1], a[i] );
    
    post[n] = a[n];
    for( int i = n-1; i >= 1; -- i )
        post[i] = max( post[i+1], a[i] );

    bool ok = 1;
    for( int i = 1; i < n; ++ i )
    {
        if( pre[i] > post[i+1] )
        {
            ok = 0;
            break;
        }
    }
    if( ok ) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main( )
{	
    int _t;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}