#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 10 + 5;

int n, m;
int st, ed;
int ans = 0;

vector< int > adj[maxn];
bool vis[maxn];

void dfs( int u, int fa, int len )
{
	//cout << u << " ";
	if( u == ed )
	{
		ans = max( ans, len );
		return ;
	}
	for( int v : adj[u] )
	{
		if( v == fa ) continue;
		if( vis[v] ) continue;
		
		vis[v] = 1;
		dfs( v, u, len + 1 );
		vis[v] = 0;
	}
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
		adj[u].push_back( v );
		adj[v].push_back( u );
	}
	
	cin >> st >> ed;
	
	vis[st] = 1;
	
	dfs( st, 0, 1 );
	
	cout << ans << '\n';
	return 0;
}
