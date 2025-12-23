#include<bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;
using PLI = pair<long long, int>;
using ll = long long;

const long long inf = 1e18;
//const int inf = 1e9;
const int N = 2e5 + 5;

struct Edge {
	int u, v;
	long long w;
};

int n, m;
vector<ll> a(N);
vector<Edge> edges;
int fa[N];
int sz[N];

int find( int x ) {
	return fa[x] == x ? x : fa[x] = find( fa[x] );
}

void merge( int x, int y ) {
	int fx = find( x ), fy = find( y );
	if( fx != fy ) {
		if( sz[fx] < sz[fy] ) swap( fx, fy );
		fa[fy] = fx;
		sz[fx] += sz[fy];
	}
}

bool cmp( const Edge& a, const Edge& b ) {
	return a.w < b.w;
}

int main( )
{
	cin >> n >> m;
	ll minCost = inf;
	int minPos = -1;
	for( int i = 1; i <= n; ++ i )
	{
		fa[i] = i;
		sz[i] = 1;
		cin >> a[i];
		if( a[i] < minCost )
		{
			minCost = a[i];
			minPos = i;
		}
	}
	for( int i = 1; i <= m; ++ i )
	{
		int u, v;
		ll w;
		cin >> u >> v >> w;
		edges.push_back({ u, v, w });
	}
	for( int i = 1; i <= n; ++ i )
	{
		if( i != minPos )
			edges.push_back({ minPos, i, a[i] + minCost });
	}
	sort( edges.begin(), edges.end(), cmp );
	long long ans = 0;
	int cnt = 0;
	for( const auto& edge : edges )
	{
		if( find( edge.u ) != find( edge.v ) )
		{
			merge( edge.u, edge.v );
			ans += edge.w;
			cnt ++;
		}
		if( cnt == n - 1 ) break;
	}
	cout << ans << endl;
	return 0;
}