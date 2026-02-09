#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1000 + 50;


struct Node {
    int x, y; ll v;
    bool operator < ( const Node &oth ) const { return v > oth.v; }
};

vector<Node> a;
ll G[maxn][maxn];

bool delx[maxn], dely[maxn];
int n, m, k;

void solve( )
{
    cin >> n >> m >> k;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            cin >> G[i][j];
            a.push_back({ i, j, G[i][j] });
        }
    }

    sort( a.begin( ), a.end( ) );
    int idx = a.size( );
    int cnt = 0;

    for( int i = 0; i < idx && cnt < k; ++ i )
    {
        auto [x, y, v] = a[i];
        if( delx[x] || dely[y] ) continue;
        delx[x] = dely[y] = 1;
        cnt ++;
    }

    vector< int > ans;

    for( int i = 1; i <= n; ++ i )
    {
        ans.clear( );
        if( delx[i] ) continue;
        for( int j = 1; j <= m; ++ j )
        {
            if( dely[j] ) continue;
            ans.push_back( G[i][j] );
        }
        int sz = ans.size( );
        for( int j = 0; j < sz; ++ j )
        {
            cout << ans[j];
            if( j != sz - 1 ) cout << ' ';
        }
        cout << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}