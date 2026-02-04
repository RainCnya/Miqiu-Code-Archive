#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

vector< PII > edges;

void solve( )
{
    int k;
    cin >> k;
    int c = k + 2;
    int n = 2 * c;

    for( int i = 1; i <= c; ++ i )
    {
        for( int j = 1; j < i; ++ j )
        {
            edges.push_back({ 2 * i - 1, 2 * j });
            edges.push_back({ 2 * i, 2 * j - 1 });
        }
    }

    cout << n << ' ' << edges.size( ) << ' ' << 2 << '\n';

    for( int i = 1; i <= n; ++ i )
    {
        if( i % 2 == 1 ) cout << 1 << ' ';
        else cout << 2 << ' ';
    }
    cout << '\n';

    for( auto [u, v] : edges )
    {
        cout << u << ' ' << v << '\n';
    }
    return ;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}