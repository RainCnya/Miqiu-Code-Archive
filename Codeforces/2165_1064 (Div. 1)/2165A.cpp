#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 50;

int a[maxn<<1];
int pre[maxn];
int post[maxn];
int n;

void solve( )
{
    memset( pre, 0, sizeof( pre ) );
    memset( post, 0 , sizeof( post ) );
    a[0] = 1e9;

    cin >> n;
    int mx = -1;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        a[i+n] = a[i];
        mx = max( mx, a[i] );
    }

    stack<int> stk;
    for( int i = 1; i <= 2*n; ++ i )
    {
        while( !stk.empty( ) && a[ stk.top( ) ] < a[i] )
        {
            int idx = stk.top( );
            stk.pop( );
            if( idx <= n )
                post[idx] = i;
        }
        stk.push( i );
    }

    while( !stk.empty( ) ) stk.pop( );
    
    for( int i = 2*n; i >= 1; -- i )
    {
        while( !stk.empty( ) && a[ stk.top( ) ] <= a[i] )
        {
            int idx = stk.top( );
            stk.pop( );
            if( idx > n )
                pre[idx - n] = i;
        }
        stk.push( i );
    }

    long long ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        if( a[i] == mx ) ans += mx;
        else ans += min( a[pre[i]], a[post[i]] ); 
    }

    ans -= mx;
    cout << ans << '\n';
}

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while( t -- )
    {
        solve( );
    }
    return 0;
}