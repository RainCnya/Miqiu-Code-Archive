#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;

int fa[maxn];
int sz[maxn];
int n, q;

int find( int x )
{
	if( fa[x] == x ) return fa[x];
	else return fa[x] = find( fa[x] );
}

void merge( int u, int v )
{
	fa[v] = u;
	sz[u] += sz[v];
}

int main( )
{
	cin >> n >> q;
	
	for( int i = 1; i <= n; ++ i )
	{
		fa[i] = i;
		sz[i] = 1;
	}
	
	while( q -- )
	{
		int x;
		cin >> x;
		
		if( x == 1 )
		{
			int u, v;
			cin >> u >> v;
			
			int ru = find( u );
			int rv = find( v );
			
			if( ru == rv ) continue;
			
			int cnt_u = sz[ ru ];
			int cnt_v = sz[ rv ];
			
			if( cnt_u == cnt_v )
			{
				if( ru < rv ) merge( ru, rv );
				else merge( rv, ru );
			}
			else
			{
				if( cnt_u > cnt_v ) merge( ru, rv );
				else merge( rv, ru );
			}
		}
		else 
		{
			int u;
			cin >> u;
			cout << sz[find(u)] << '\n';
		}
	}
	if( fa[1] == 1 ) cout << sz[1] << '\n';
	else cout << "HO NO!" << '\n';
//	for( int i = 1; i <= n; ++ i )
//	{
//		cout << fa[i] << " " << sz[i] << '\n';
//	}
}
