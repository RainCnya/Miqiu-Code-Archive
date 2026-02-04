#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxm = 2e3 + 5;
const int maxn = 1e5 + 5;
const int inf = 1e9;


struct Line {
    int x, y1, y2, id ,type;
    bool operator < ( const Line &oth ) const {
        return x < oth.x;
    }
} lines[maxn << 1];

struct Node {
    int l, r;
    priority_queue< int > maxq;
    priority_queue< int, vector< int >, greater< int > > minq;
} tr[maxn << 2];

struct Query {
    int s, t, id;
    bool operator < ( const Query &oth ) const {
        return t < oth.t;
    }
} qs[maxn];
ll ans[maxn];

vector< PII > points[maxn];
bool vis[maxn];
ll Bit[maxn];
int n, q;
ll sum;

void update( int idx, int val )
{
    for( int i = idx; i <= n; i += i & -i )
        Bit[i] += val;
}

ll query( int idx )
{
    ll res = 0;
    for( int i = idx; i > 0; i -= i & -i )
        res += Bit[i];
    return res;
}

#define ls ( u << 1 )
#define rs ( u << 1 | 1 )

void build( int u, int l, int r )
{
    tr[u] = { l, r };
    while( !tr[u].maxq.empty( ) ) tr[u].maxq.pop( );
    while( !tr[u].minq.empty( ) ) tr[u].minq.pop( );

    if( l == r ) return;
    int mid = ( l + r ) >> 1;
    build( ls, l, mid );
    build( rs, mid + 1, r );
}

void modify( int u, int l, int r, int id )
{
    if( l <= tr[u].l && tr[u].r <= r )
    {
        tr[u].maxq.push( id );
        tr[u].minq.push( id );
        return ;
    }
    int mid = ( tr[u].l + tr[u].r ) >> 1;
    if( l <= mid ) modify( ls, l, r, id );
    if( mid < r ) modify( rs, l, r, id );
}

void dfs( int u, int minid, int maxid, int &cnt ) 
{
    while( !tr[u].maxq.empty( ) && vis[tr[u].maxq.top( )] ) tr[u].maxq.pop( );
    while( !tr[u].minq.empty( ) && vis[tr[u].minq.top( )] ) tr[u].minq.pop( );
    
    if( !tr[u].maxq.empty( ) )
    {
        minid = min( minid, tr[u].minq.top( ) );
        maxid = max( maxid, tr[u].maxq.top( ) );
    }

    if( tr[u].l == tr[u].r )
    {
        if( minid <= n )
        {
            cnt ++;
            points[maxid].push_back({ minid, 1 });
        }
        return;
    }

    dfs( ls, minid, maxid, cnt );
    dfs( rs, minid, maxid, cnt );
}

void solve( )
{
    cin >> n >> q;

    int len = 0;
    for( int i = 1; i <= n; ++ i )
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines[++ len] = { x1, y1, y2, i, 1 };
        lines[++ len] = { x2, y1, y2, i, -1 };
    }
    sort( lines + 1, lines + 1 + len );

    build( 1, 0, 2000 );

    int cur = 1;
    for( int x = 0; x <= 2000; ++ x )
    {
        while( cur <= len && lines[cur].x == x )
        {
            if( lines[cur].type == 1 ) 
                modify( 1, lines[cur].y1, lines[cur].y2 - 1, lines[cur].id );
            else 
                vis[lines[cur].id] = 1;
            cur ++;
        }
        int xcnt = 0;
        dfs( 1, inf, -inf, xcnt );
        sum += xcnt;
    }

    for( int i = 1; i <= q; ++ i )
    {
        cin >> qs[i].s >> qs[i].t;
        qs[i].id = i;
    }

    sort( qs + 1, qs + 1 + q );

    int r = 1;
    for( int i = 1; i <= q; ++ i )
    {
        while( r <= qs[i].t ) 
        {
            for( auto [l, cnt] : points[r] )
            {
                update( l, cnt );
            }
            r ++;
        }
        ll res = query( n ) - query( qs[i].s - 1 );
        ans[qs[i].id] = sum - res;
    }

    for( int i = 1; i <= q; ++ i )
    {
        cout << ans[i] << '\n';
    }
}

int main( )
{  
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve( );
    return 0;
}