#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
vector<int> adj[N];
long long cnt[2];

void dfs( int now, int pre, int color )
{
    cnt[color] ++;
    for( auto next : adj[now] )
    {
        if( next != pre )
            dfs( next, now, !color );
    }
}

int main( )
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> n;
    for( int i = 1; i < n; ++ i )
    {
        int u, v;   cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }
    dfs( 1, 0, 0 );
    long long ans = cnt[0] * cnt[1] - (n - 1);
    cout << ans << endl;
    return 0;
}