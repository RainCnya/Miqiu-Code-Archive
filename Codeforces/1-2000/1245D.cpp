#include<bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
using PLL = pair<long long, long long>;
using PLI = pair<long long, int>;
using ll = long long;

const long long inf = 1e18;
const int N = 2000 + 5;

int n;
vector<PLL> nodes(N);
vector<ll> c(N);
vector<ll> k(N);
vector<PLI> adj[N];
ll dist[N];
bool vis[N];
int fa[N];

vector<int> res1;
vector<PII> res2;

ll cost( int u, int v ) {
	ll dis = abs( nodes[u].first - nodes[v].first ) + abs( nodes[u].second - nodes[v].second );
	return dis * (k[u] + k[v]);
}

ll prim( int start )
{
	for( int i = 0; i <= n; ++ i )
	{
		dist[i] = inf;
		vis[i] = false;
		fa[i] = -1;
	}
	dist[start] = 0;

	priority_queue<PLI, vector<PLI>, greater<PLI>> pq;
	pq.push({ 0, start });
	ll sum = 0;
	int cnt = 0;
	while( !pq.empty( ) && cnt < n + 1 )
	{
		auto [d, u] = pq.top( );	pq.pop( );
		if( vis[u] )	continue;
		vis[u] = true;
		sum += d, cnt ++; 

		if( fa[u] != -1 )
		{
			if( fa[u] == 0 )
				res1.push_back( u );
			else
				res2.push_back({ u, fa[u] });
		}
		for( const auto& [w, v] : adj[u] )
		{
			if( !vis[v] && w < dist[v] )
			{
				dist[v] = w;
				fa[v] = u;
				pq.push({ dist[v], v });
			}
		}
	}
	return sum;
}

int main( )
{
	cin >> n;
	for( int i = 1; i <= n; ++ i ) {
		cin >> nodes[i].first >> nodes[i].second;
	}
	for( int i = 1; i <= n; ++ i ) {
		cin >> c[i];
		adj[0].push_back({ c[i], i });
		adj[i].push_back({ c[i], 0 });
	}

	for( int i = 1; i <= n; ++ i ) {
		cin >> k[i];
	}

	for( int i = 1; i <= n; ++ i ) {
		for( int j = 1; j <= n; ++ j ) {
			if( i == j ) continue;
			ll nowCost = cost( i, j );
			adj[i].push_back({ nowCost, j });
			adj[j].push_back({ nowCost, i });
		}
	}

	long long ans = 0;
	ans = prim( 0 );
	cout << ans << endl;

	cout << res1.size( ) << endl;
	for( int x : res1 )
		cout << x << " ";
	cout << endl;
	cout << res2.size( ) << endl;
	for( const auto& x : res2 )
		cout << x.first << " " << x.second << endl;
	return 0;
}