#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e3 + 50;
const int inf = 1e9;

struct State {
	int u, d, type;
	bool operator < ( const State &oth ) const {
		return d > oth.d;
	}
};

int n, m;
vector< int > adj[maxn];
int dist[maxn][2];
int cnt[maxn][2];

void dijkstra( )
{
	for( int i = 1; i <= n; ++ i )
	{
		dist[i][0] = dist[i][1] = inf;
		cnt[i][0] = cnt[i][1] = 0;
	}

	priority_queue< State > pq;

	pq.push({ 1, 0, 0 });

	dist[1][0] = 0;
	cnt[1][0] = 1;
	
	while( !pq.empty( ) )
	{
		auto [u, d, type] = pq.top( );
		pq.pop( );

		if( d > dist[u][type] ) continue;
		
		for( int v : adj[u] )
		{
			int nd = d + 1;

			if( nd < dist[v][0] )
			{
				dist[v][1] = dist[v][0];
				cnt[v][1] = cnt[v][0];
				pq.push( {v, dist[v][1], 1} );

				dist[v][0] = nd;
				cnt[v][0] = cnt[u][type];
				pq.push( {v, dist[v][0], 0} );
			}
			else if( nd == dist[v][0] )
			{
				cnt[v][0] += cnt[u][type];
			}
			else if( nd < dist[v][1] )
			{
				dist[v][1] = nd;
				cnt[v][1] = cnt[u][type];
				pq.push( {v, dist[v][1], 1} );
			}
			else if( nd == dist[v][1] )
			{
				cnt[v][1] += cnt[u][type];
			}

		}
	}
}

int main( )
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for( int i = 1; i <= m; ++ i )
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back( v );
		adj[v].push_back( u );
	}
	
	dijkstra( );
	
	if( dist[n][1] == inf ) cout << -1 << '\n';
	else cout << cnt[n][1] << '\n';
	
	return 0;
}

