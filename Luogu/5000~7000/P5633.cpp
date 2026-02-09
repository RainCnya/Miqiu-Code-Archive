#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e4 + 50;
const int maxm = 5e5 + 50;
const int inf = 4e4;

struct Edge { int u, v; ll w; int need; } A[maxm], B[maxm], cur[maxm];
bool cmp( const Edge &lhs, const Edge &rhs ) { 
    if( lhs.w != rhs.w ) return lhs.w < rhs.w;
    return lhs.need > rhs.need;
}

int cntA, cntB;
int fa[maxn];
int n, m, s, k;

ll res;
int cnt;

int find( int x )
{
    if( x == fa[x] ) return fa[x];
    else return fa[x] = find( fa[x] );
}

int merge( int u, int v )
{
    int fu = find( u ), fv = find( v );
    if( fu != fv )
    {
        fa[fu] = fv;
        return 1;
    }
    return 0;
}

void merge_sort( int delta )
{
    for( int i = 1; i <= cntA; ++ i ) A[i].w += delta;

    int i = 1, j = 1, kk = 1;

    while( i <= cntA && j <= cntB )
    {
        if( cmp( A[i], B[j] ) ) cur[kk ++] = A[i ++];
        else cur[kk ++] = B[j ++];
    }
    while( i <= cntA ) cur[kk ++] = A[i ++];
    while( j <= cntB ) cur[kk ++] = B[j ++];

    for( int i = 1; i <= cntA; ++ i ) A[i].w -= delta;
    return;
}

bool check( int delta )
{
    merge_sort( delta );
    for( int i = 1; i <= n; ++ i ) fa[i] = i;
    res = cnt = 0;
    for( int i = 1; i <= cntA + cntB; ++ i )
    {
        if( !merge( cur[i].u, cur[i].v ) ) continue;
        cnt += cur[i].need;
        res += cur[i].w;
    }
    return cnt >= k;
}

void solve( )
{
    cin >> n >> m >> s >> k;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v; ll w;
        cin >> u >> v >> w;
        if( u == s || v == s ) A[++ cntA] = { u, v, w, 1 };
        else B[++ cntB] = { u, v, w, 0 };
    }

    sort( A + 1, A + cntA + 1, cmp );
    sort( B + 1, B + cntB + 1, cmp );
    
    if( cntA < k )
    {
        cout << "Impossible" << '\n';
        return;
    }

    for( int i = 1; i <= n; ++ i ) fa[i] = i;

    int block = n;
    for( int i = 1; i <= cntB; ++ i ) block -= merge( B[i].u, B[i].v );

    if( block - 1 > k )
    {
        cout << "Impossible" << '\n';
        return;
    }

    for( int i = 1; i <= cntA; ++ i ) block -= merge( A[i].u, A[i].v );

    if( block != 1 )
    {
        cout << "Impossible" << '\n';
        return;
    }

    int l = -inf, r = inf, ans = -1e9;

    while( l <= r )
    {
        int mid = ( l + r ) >> 1;
        if( check( mid ) ) ans = mid, l = mid + 1;
        else r = mid - 1;
    }

    if( ans == -1e9 )
    {
        cout << "Impossible" << '\n';
        return;
    }

    check( ans );
    cout << res - 1ll * k * ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}