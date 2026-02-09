#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 8000 + 50;
const int maxm = 20000 + 50;

map< string, int > id;
vector< int > adj[maxn];
vector< pair< int, int > > couples;
stack< int > st;

int dfn[maxn], low[maxn], timer;
bool in_stack[maxn];
int scc[maxn], scc_cnt;

string boy, girl;
int n, m;

void tarjan( int u )
{
    dfn[u] = low[u] = ++ timer;
    st.push( u );
    in_stack[u] = true;

    for( int v : adj[u] )
    {
        if( !dfn[v] )
        {
            tarjan( v );
            low[u] = min( low[u], low[v] );
        }
        else if( in_stack[v] )
        {
            low[u] = min( low[u], dfn[v] );
        }
    }

    if( dfn[u] == low[u] )
    {
        scc_cnt ++;
        int v;
        do {
            v = st.top( ); st.pop( );
            in_stack[v] = false;
            scc[v] = scc_cnt;
        } while( v != u );
    }
}

void solve( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i )
    {
        cin >> girl >> boy;
        id[girl] = i;
        id[boy] = i + n;
        couples.push_back({ i, i + n });
        adj[i].push_back( i + n );
    }
    cin >> m;
    for( int i = 1; i <= m; ++ i )
    {
        cin >> girl >> boy;
        int u = id[girl], v = id[boy];
        adj[v].push_back( u );
    }

    for( int i = 1; i <= n * 2; ++ i )
    {
        if( !dfn[i] ) tarjan( i );
    }

    for( int i = 0; i < n; ++ i )
    {
        auto [u, v] = couples[i];
        if( scc[u] == scc[v] ) cout << "Unsafe" << '\n';
        else cout << "Safe" << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}