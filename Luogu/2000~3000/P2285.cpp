#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e3 + 5;
const int maxm = 1e4 + 5;

struct Point { int t, x, y; } p[maxm];

int f[maxn];
int n, m;

bool check( Point a, Point b )
{
    return abs( a.x - b.x ) + abs( a.y - b.y ) <= a.t - b.t;
}

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i ) cin >> p[i].t >> p[i].x >> p[i].y;

    int ans = 0;
    for( int i = 1; i <= m; ++ i )
    {
        f[i] = 1;
        for( int j = 1; j < i; ++ j )
        {
            if( f[j] + 1 > f[i] && check( p[i], p[j] ) )
                f[i] = f[j] + 1;
        }
        ans = max( ans, f[i] );
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}