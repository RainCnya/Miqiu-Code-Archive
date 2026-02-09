#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e4 + 50;

// STL
vector< int > adj[maxn];
stack< int > stk;
// Tarjan
int dfn[maxn], low[maxn], idx;
int scc_id[maxn], scc_cnt;
bool in_stk[maxn];
// DAG
int ind[maxn], outd[maxn];
int n;

void tarjan( int u )
{
    dfn[u] = low[u] = ++ idx;
    stk.push( u );
    in_stk[u] = 1;

    for( int v : adj[u] )
    {
        if( !dfn[v] )
        {
            tarjan( v );
            low[u] = min( low[u], low[v] );
        }
        else if( in_stk[v] )
        {
            low[u] = min( low[u], dfn[v] );
        }
    }

    if( dfn[u] == low[u] )
    {
        ++ scc_cnt;
        int v;
        do {
            v = stk.top( );
            stk.pop( );
            in_stk[v] = 0;
            scc_id[v] = scc_cnt;
        } while( v != u );
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        int x;
        while( cin >> x && x != 0 )
        {
            adj[i].push_back(x);
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( !dfn[i] ) tarjan( i );
    }

    for( int u = 1; u <= n; ++ u )
    {
        for( int v : adj[u] )
        {
            if( scc_id[u] != scc_id[v] )
            {
                ind[scc_id[v]]++;
                outd[scc_id[u]]++;
            }
        }
    }
    int ins = 0, outs = 0;

    for( int i = 1; i <= scc_cnt; ++ i )
    {
        if( ind[i] == 0 ) ins++;
        if( outd[i] == 0 ) outs++;
    }
    
    cout << ins << '\n';
    
    if( scc_cnt == 1 ) cout << 0 << '\n';
    else cout << max( ins, outs ) << '\n';

    return 0;
}