#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    int n;
    cin >> n;
    vector< int > ans( n + 1 );
    vector< bool > vis( n + 1, 0 );

    ans[n] = 1;
    vis[1] = 1;
    for( int i = 2; i <= n - 1; ++ i )
    {
        ans[i] = i ^ 1;
        vis[ans[i]] = 1;
    }

    int pos = 1;
    while( vis[pos] ) pos ++;
    ans[1] = pos;

    for( int i = 1; i <= n; ++ i )
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
    while( _t -- )
    {
        solve( );
    }
    return 0;
}