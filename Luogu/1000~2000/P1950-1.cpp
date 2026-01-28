#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1000 + 5;

int n, m;
int h[maxn], l[maxn], r[maxn];

ll solve( )
{
    stack< int > stk;
    for( int i = 1; i <= m ; ++ i )
    {
        while( !stk.empty( ) && h[stk.top( )] >= h[i] ) stk.pop( );
        l[i] = stk.empty( ) ? 0 : stk.top( );
        stk.push( i );
    }

    while( !stk.empty( ) ) stk.pop( );
    for( int i = m; i >= 1; -- i )
    {
        while( !stk.empty( ) && h[stk.top( )] > h[i] ) stk.pop( );
        r[i] = stk.empty( ) ? m + 1 : stk.top( );
        stk.push( i );
    }

    ll res = 0;
    for( int i = 1; i <= m; ++ i )
    {
        res += 1ll * h[i] * ( i - l[i] ) * ( r[i] - i );
    }
    return res;
}

int main( )
{
    cin >> n >> m;

    ll ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            char c;
            cin >> c;
            if( c == '.' ) h[j] ++;
            else h[j] = 0;
        }
        ans += solve( );
    }
    cout << ans << '\n';
    return 0;
}