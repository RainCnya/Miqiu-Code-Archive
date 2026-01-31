#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e6 + 5;

struct State {
    int rem, dig;
} pre[maxn][10];

bool vis[maxn][10];

int n;

void solve( )
{
    cin >> n;

    queue< State > q;
    for( int d = 1; d <= 9; ++ d )
    {
        int r = d % n;
        if( vis[r][d] ) continue;
        vis[r][d] = 1;
        q.push({ r, d });
        pre[r][d] = { -1, -1 };
    }

    State ans = { -1, -1 };  

    while( !q.empty( ) )
    {
        auto [r, d] = q.front( );
        q.pop( );

        if( r == 0 )
        {
            ans = { r, d };
            break;
        }

        for( int nd = d; nd <= 9; ++ nd )
        {
            int nr = ( r * 10 + nd ) % n;
            if( vis[nr][nd] ) continue;
            vis[nr][nd] = 1;
            q.push({ nr, nd });
            pre[nr][nd] = { r, d };
        }
    }

    if( ans.rem == -1 )
    {
        cout << -1 << '\n';
        return;
    }

    vector< int > res;
    while( ans.rem != -1 )
    {
        res.push_back( ans.dig );
        ans = pre[ans.rem][ans.dig];
    }
    reverse( res.begin( ), res.end( ) );
    for( int d : res ) cout << d;
    cout << '\n';

}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while( _t -- ) solve( );
    return 0;
}