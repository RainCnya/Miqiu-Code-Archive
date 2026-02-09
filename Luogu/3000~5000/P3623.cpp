#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e4 + 50;
const int maxm = 1e5 + 50;

struct Edge {
    int u, v, c;
    bool need = false;
} e0[maxm], e1[maxm];
vector<Edge> ans;

int cnt0, cnt1;
int fa[maxn];
int n, m, k;

int find( int x )
{
    if( fa[x] == x ) return fa[x];
    else return fa[x] = find( fa[x] );
}

bool merge( int u, int v )
{
    int fu = find( u ), fv = find( v );
    if( fu != fv )
    {
        fa[fu] = fv;
        return true;
    }
    return false;
}

void solve( )
{
    cin >> n >> m >> k;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v, c;
        cin >> u >> v >> c;
        if( c == 0 ) e0[++ cnt0] = { u, v, c };
        else e1[++ cnt1] = { u, v, c };
    }

    for( int i = 1; i <= n; ++ i ) fa[i] = i;
    for( int i = 1; i <= cnt1; ++ i ) merge( e1[i].u, e1[i].v );

    int cnt_min = 0;
    for( int i = 1; i <= cnt0; ++ i )
    {
        if( merge( e0[i].u, e0[i].v ) )
        {
            e0[i].need = true;
            ++ cnt_min;
        }
    }

    if( cnt_min > k )
    {
        cout << "no solution" << '\n';
        return ;
    }

    for( int i = 1; i <= n; ++ i ) fa[i] = i;
    int cnt_cur = 0, total = 0;
    
    for( int i = 1; i <= cnt0; ++ i )
    {
        if( !e0[i].need ) continue;
        if( merge( e0[i].u, e0[i].v ) )
        {
            ans.push_back( e0[i] );
            ++ cnt_cur;
            ++ total;
        }
    }

    for( int i = 1; i <= cnt0; ++ i )
    {
        if( e0[i].need ) continue;
        if( cnt_cur >= k ) break;
        if( merge( e0[i].u, e0[i].v ) )
        {
            ans.push_back( e0[i] );
            ++ cnt_cur;
            ++ total;
        }
    }

    if( cnt_cur < k )
    {
        cout << "no solution" << '\n';
        return ;
    }

    for( int i = 1; i <= cnt1; ++ i )
    {
        if( merge( e1[i].u, e1[i].v ) )
        {
            ans.push_back( e1[i] );
            total ++;
        }
    }

    if( total != n - 1 )
    {
        cout << "no solution" << '\n';
        return ;
    }
    for( auto &e : ans ) cout << e.u << ' ' << e.v << ' ' << e.c << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}