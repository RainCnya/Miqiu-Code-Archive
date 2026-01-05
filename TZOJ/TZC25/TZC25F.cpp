#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 50;
const int maxmask = 512;

struct Item { int type, v; } items[ 50 ];
int cnt;
int n;

ll dp[ maxmask ];
int shape_mask[ 6 ][ 20 ];
int shape_cnt[ 6 ];

int get_mask( int r, int c, int h, int w )
{
	int mask = 0;
	for( int i = 0; i < h; ++ i )
	{
		for( int j = 0; j < w; ++ j )
		{
			mask |= ( 1 << ( ( r + i ) * 3 + ( c + j ) ) );
		}
	}
	return mask;
}

void init( int id, int h, int w )
{
	if( h > 3 || w > 3 ) return;
	for( int r = 0; r <= 3 - h; ++ r )
	{
		for( int c = 0; c <= 3 - w; ++ c )
		{
			shape_mask[ id ][ shape_cnt[id] ++ ] = get_mask( r, c, h, w );
		}
	}
}

void pre_init( )
{
	init( 0, 1, 1 );
	init( 1, 1, 2 );	init( 1, 2, 1 );
	init( 2, 1, 3 );	init( 2, 3, 1 );
	init( 3, 2, 2 );
	init( 4, 2, 3 );	init( 4, 3, 2 );
	init( 5, 3, 3 );
}

vector< int > pools[ 6 ];

void solve( )
{
	cin >> n;

	for( int i = 0; i < 6; ++ i ) pools[ i ].clear( );
	cnt = 0;

	for( int i = 1; i <= n; ++ i )
	{
		int _l, _r, _v;
		cin >> _l >> _r >> _v;
		
		if( _l > _r ) swap( _l, _r );

		int id = -1;

		if( _l == 1 && _r == 1 ) id = 0;
		else if( _l == 1 && _r == 2 ) id = 1;
		else if( _l == 1 && _r == 3 ) id = 2;
		else if( _l == 2 && _r == 2 ) id = 3;
		else if( _l == 2 && _r == 3 ) id = 4;
		else if( _l == 3 && _r == 3 ) id = 5;
		
		if( id == -1 ) continue;
		pools[ id ].push_back( _v );
	}

	int limits[ 6 ] = { 9, 4, 3, 1, 1, 1 };

	for( int i = 0; i < 6; ++ i )
	{
		sort( pools[ i ].begin( ), pools[ i ].end( ), greater< ll >( ) );
		int limit = min( limits[ i ], ( int )pools[ i ].size( ) );

		for( int j = 0; j < limit; ++ j )
		{
			items[ cnt ++ ] = { i, pools[ i ][ j ] };
		}
	}

	for( int i = 0; i < maxmask; ++ i ) dp[ i ] = -1;
	dp[ 0 ] = 0;

	for( int i = 0; i < cnt; ++ i )
	{
		auto [ type, v ] = items[ i ];

		for( int mask = maxmask - 1; mask >= 0; -- mask )
		{
			if( dp[ mask ] == -1 ) continue;

			for( int p = 0; p < shape_cnt[ type ]; ++ p )
			{
				int p_mask = shape_mask[ type ][ p ];
				if( ( mask & p_mask ) == 0 )
				{
					int nxt = mask | p_mask;
					dp[ nxt ] = max( dp[ nxt ], dp[ mask ] + v );
				}
			}
		}
	}
	
	ll ans = 0;
	for( int i = 0; i < maxmask; ++ i ) ans = max( ans, dp[ i ] );
	cout << ans << '\n';
}

int main( )
{	
	ios::sync_with_stdio( 0 );
	cin.tie( 0 ), cout.tie( 0 );

	pre_init( );
	
	int t;
	cin >> t;
	
	while( t -- )
	{
		solve( );
	}
	return 0;
}
