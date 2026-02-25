#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;

ll n, k;

void solve( )
{
    cin >> n >> k;
    if( k < n || k >= 2 * n )
    {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';

    ll m = k - n;

    if( m == 0 )
    {
        for( int i = 1; i <= n; ++ i ) cout << i << " " << i << " ";
        cout << '\n';
        return;
    }

    vector< int > ans;
    ans.push_back( 1 );
    ans.push_back( 2 );
    for( int i = 3; i <= m + 1; ++ i )
    {
        ans.push_back( i );
        ans.push_back( i - 2 );
    }
    ans.push_back( m );
    ans.push_back( m + 1 );

    for( int i = m + 2; i <= n; ++ i ) 
    {
        ans.push_back( i );
        ans.push_back( i );
    }

    for( int i = 0; i < 2 * n; ++ i )
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}