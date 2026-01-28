#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;

void solve( )
{
    cin >> n;
    if( (n & ( n - 1 )) == 0 )
    {
        cout << -1 << endl;
        return;
    }

    vector< int > ans( n + 1 );

    if( n % 2 == 0 )
    {
        ans[1] = n;
        for( int i = 2; i <= n - 1; i += 2 )
        {
            ans[i] = i + 1;
            ans[i+1] = i;
        }
        ans[n] = 1;

        int k = 1;
        while( ( k << 1 ) <= n ) k <<= 1;
        int r = n - k;

        swap( ans[1], ans[r] );
    }
    else
    {
        ans[1] = n - 1;
        for( int i = 2; i <= n - 2; i += 2 )
        {
            ans[i] = i + 1;
            ans[i+1] = i;
        }
        ans[n-1] = n, ans[n] = 1;
    }
    
    for( int i = 1; i <= n; ++ i )
    {
        cout << ans[i] << " " ;
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

