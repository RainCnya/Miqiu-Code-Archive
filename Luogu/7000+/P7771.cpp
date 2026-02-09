#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;

vector<int> adj[maxn];
int cur[maxn];

int ind[maxn];
int outd[maxn];

stack<int> ans;
int n, m;

void dfs( int u )
{
    while( cur[u] < adj[u].size( ) )
    {
        int v = adj[u][cur[u]];
        cur[u] ++;
        dfs( v );
    }
    ans.push( u );
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        outd[u]++;
        ind[v]++;
    }

    for( int i = 1 ; i <= n; ++ i )
    {
        sort( adj[i].begin( ), adj[i].end( ) );
    }

    int start = 1;
    int cnt_start = 0;
    int cnt_end = 0;
    bool flag = 1;
    
    for( int i = 1; i <= n; ++ i )
    {
        if( ind[i] == outd[i] ) continue;

        if( outd[i] == ind[i] + 1 )
        {
            start = i;
            cnt_start++;
        }
        else if( ind[i] == outd[i] + 1 )
        {
            cnt_end++;
        }
        else
        {
            flag = 0;
        }
    }

    bool A = (cnt_start == 0 && cnt_end == 0);
    bool B = (cnt_start == 1 && cnt_end == 1);

    if( flag == 0 || !( A || B ) )
    {
        cout << "No" << '\n';
        return 0;
    }

    dfs( start );

    if( ans.size( ) < m + 1 )
    {
        cout << "No" << '\n';
        return 0;
    }

    while( !ans.empty( ) )
    {
        cout << ans.top( ) <<  " ";
        ans.pop( );
    }
    return 0;
}