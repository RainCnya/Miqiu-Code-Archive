#include<bits/stdc++.h>
using namespace std;
//using ll = long long;

const int inf = 1e9;
const int maxn = 3e5 + 50;
const int maxlg = 20;

int n, m;
int a[maxn], b[maxn];
int mx = 0;
int mxweight = 0;

int dep[maxn];
int dis[maxn];
// 深度和距离
int dif[maxn];
int sum[maxn];
// 差分数组
int fa[maxn][maxlg];
int val[maxn][maxlg];
// 倍增数组
int lcas[maxn];
int dist_root[maxn];
vector< pair<int, int> > adj[maxn];

void dfs( int u, int father, int curdist )
{
    fa[u][0] = father;
    dep[u] = dep[father] + 1;
    dist_root[u] = curdist;
    for( auto& [v, w] : adj[u] )
    {
        if( v != father )
        {
            val[v][0] = w;
            dfs( v, u, curdist + w );
        }
    }

}

void stInit( )
{
    for( int j = 1; j < maxlg; ++ j )
    {
        for( int i = 1; i <= n; ++ i )
        {
            fa[i][j] = fa[ fa[i][j-1] ][j-1];
            val[i][j] = val[ fa[i][j-1] ][j-1] + val[i][j-1];
        }
    }
}

int getlca( int u, int v ) 
{
    if( dep[u] < dep[v] ) swap( u, v );
    int diff = dep[u] - dep[v];
    for( int i = 0; i < maxlg; ++ i )
    {
        if( ( 1 << i ) & diff )
            u = fa[u][i];
    }
    if( u == v ) return u;
    for( int i = maxlg-1; i >= 0; -- i )
    {
        if( fa[u][i] != fa[v][i] )
        {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
} 

int getdist( int u, int v, int lca )
{
    return dist_root[u] + dist_root[v] - 2 * dist_root[lca];
}

void getsum( int u, int father )
{
    sum[u] = dif[u];
    for( auto& [v, w] : adj[u] )
    {
        if( v != father )
        {
            getsum( v, u );
            sum[u] += sum[v];
        }
    }
}

bool check( int mid )
{
    int cnt = 0;
    memset( dif, 0, sizeof( dif ) );
    memset( sum, 0, sizeof( sum ) );

    for( int i = 1; i <= m; ++ i )
    {
        if( dis[i] > mid )
        {
            cnt ++;
            dif[ a[i] ] ++, dif[ b[i] ] ++;
            dif[ lcas[i] ] -= 2;
        }
    }
    if( cnt == 0 ) return 1;
    getsum( 1, 0 );
    int mxweight = 0;
    for( int i = 2; i <= n; ++ i )
    {
        if( sum[i] == cnt )
        {
            mxweight = max( mxweight, val[i][0] );
        }
    }
    return (mx - mxweight <= mid);
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    //cin >> n >> m;
    scanf("%d %d", &n, &m);
    for( int i = 1; i <= n-1; ++ i )
    {
        int u, v;
        int w;
        //cin >> u >> v >> w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
        mxweight = max( mxweight, w );
    }    

    val[1][0] = 0;
    dfs( 1, 0, 0 );
    stInit( );

    for( int i = 1; i <= m; ++ i )
    {
        //cin >> a[i] >> b[i];
        scanf("%d %d", &a[i], &b[i]);
        lcas[i] = getlca( a[i], b[i] );
        dis[i] = getdist( a[i], b[i], lcas[i] );
        mx = max( mx, dis[i] );
    }
    
    int l = mx - mxweight;
    if( l < 0 ) l = 0;
    int r = mx;
    int ans = mx;

    while( l <= r )
    {
        int mid = ( l + r ) >> 1;
        if( check( mid ) ) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
    //cout << ans << '\n';
    return 0;
}