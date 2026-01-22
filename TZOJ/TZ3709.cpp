#include<bits/stdc++.h>
using namespace std;

const int maxn = 12;
const int inf = 0x3f3f3f3f;

int n, s, t;
int mat[maxn][maxn];
int dist[maxn][maxn][maxn][maxn];
int ans;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool check( int x, int y, int sum )
{
	if( 1 <= x && x <= n && 1 <= y && y <= n )
	{
		if( mat[x][y] == 0 ) return 0;
		if( sum % mat[x][y] == 0 ) return 1;
	}
	return 0;
}

struct Node {
	int cx, cy;
	int px, py;
};

void bfs( int x, int y )
{
	queue<Node> q;
	
	q.push({ 1, 1, 1, 0 });

	while( !q.empty( ) )
	{
		auto [cx, cy, px, py] = q.front( );
		q.pop( );
		
		int cur_d = dist[cx][cy][px][py];
		int sum = mat[px][py] + mat[cx][cy];
		
		if( cx == n && cy == n )
		{
			if( sum % t == 0 )
			{
				ans = min( ans, cur_d + 1 );
			}
		}
		
		for( int dir = 0 ; dir < 4; ++ dir )
		{			
			int nx = cx + dx[dir];
			int ny = cy + dy[dir];
			if( nx == px && ny == py ) continue;

			if( check( nx, ny, sum ) && dist[nx][ny][cx][cy] == inf )
			{
				dist[nx][ny][cx][cy] = cur_d + 1;
				q.push({ nx, ny, cx, cy });
			}

		}
	}
}

int main( )
{
	while( cin >> n >> s >> t )
	{
		memset( dist, 0x3f, sizeof( dist ) );
		ans = inf;
		
		for( int i = 1; i <= n; ++ i )
		{
			for( int j = 1; j <= n; ++ j )
			{
				cin >> mat[i][j];
			}
		}
		
		mat[1][0] = s;
		dist[1][1][1][0] = 1;
		mat[n][n+1] = t;
		
		bfs( 1, 1 );
		
		if( ans == inf ) cout << "Impossible" << '\n';
		else cout << ans << '\n';
	}
}
