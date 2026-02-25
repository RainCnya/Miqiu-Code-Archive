#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

struct Edge { int v, w; };
vector< Edge > radj[maxn];
double f[maxn];
// u -> n 的期望路径长度
int outdeg[maxn];
int deg[maxn]; // 拓扑用 deg
int n, m;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for( int i = 1; i <= m; ++ i )
    {
        int u, v, w;
        cin >> u >> v >> w;
        radj[v].push_back({ u, w });
        outdeg[u] ++;
        deg[u] ++;
    }

    queue< int > q;
    f[n] = 0, q.push( n );
    while( !q.empty( ) )
    {
        int v = q.front( ); q.pop( );
        for( auto [u, w] : radj[v] )
        {
            f[u] += ( f[v] + w ) / outdeg[u];
            deg[u] --;
            if( deg[u] == 0 ) q.push( u );
        }
    }

    cout << setprecision(2) << fixed << f[1] << '\n';
    return 0;
}