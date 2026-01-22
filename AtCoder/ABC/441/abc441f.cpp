#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxm = 5e4 + 50;
const int maxn = 1e3 + 50;

int n, m;
ll p[maxn], v[maxn];
ll pre[maxn][maxm];
ll post[maxn][maxm];

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;

    for( int i = 1; i <= n; ++ i )
    {
        cin >> p[i] >> v[i];
    }

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 0; j <= m; ++ j )
        {
            pre[i][j] = pre[i - 1][j];
            if( j >= p[i] ) pre[i][j] = max( pre[i][j], pre[i - 1][j - p[i]] + v[i] );
        }
    }

    for( int i = n; i >= 1; -- i )
    {
        for( int j = 0; j <= m; ++ j )
        {
            post[i][j] = post[i + 1][j];
            if( j >= p[i] ) post[i][j] = max( post[i][j], post[i + 1][j - p[i]] + v[i] );
        }
    }

    ll val = pre[n][m];
    string ans = "";

    for( int i = 1; i <= n; ++ i )
    {
        ll CateA = 0;   // 必选
        for( int j = 0; j <= m - p[i]; ++ j )
        {
            CateA = max( CateA, pre[i - 1][j] + post[i + 1][m - p[i] - j] );
        }
        CateA += v[i];

        ll CateC = 0;   // 必不选
        for( int j = 0; j <= m; ++ j )
        {
            CateC = max( CateC, pre[i - 1][j] + post[i + 1][m - j] );
        }

        if( CateA < val ) ans += 'C';
        else if( CateC < val ) ans += 'A';
        else ans += 'B';
    }

    cout << ans;
    return 0;
}