#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1000 + 5;
const int maxm = 1000 + 5;

bool edge[maxn][maxn];
int stop[maxn];
bool is_stop[maxn];
int indeg[maxn];
int dep[maxn];
int n, m, s;

void solve( )
{
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        cin >> s;
        for( int j = 1; j <= n; ++ j ) is_stop[j] = 0;
        for( int j = 1; j <= s; ++ j )
        {
            cin >> stop[j];
            is_stop[stop[j]] = 1;
        }

        for( int j = stop[1]; j <= stop[s]; ++ j )
        {
            if( is_stop[j] ) continue;

            for( int k = 1; k <= s; ++ k )
            {
                if( !edge[j][stop[k]] )
                {
                    edge[j][stop[k]] = 1;
                    indeg[stop[k]] ++;
                }
            }
        }
    }

    queue< int > q;
    for( int i = 1; i <= n; ++ i )
    {
        if( indeg[i] == 0 ) 
        {
            q.push( i );
            dep[i] = 1;
        }
    }

    while( !q.empty( ) )
    {
        int u = q.front( );
        q.pop( );

        for( int v = 1; v <= n; ++ v )
        {
            if( edge[u][v] )
            {
                dep[v] = dep[u] + 1;
                indeg[v] --;
                if( indeg[v] == 0 ) q.push( v );
            }
        }
    }

    int ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        ans = max( ans, dep[i] );
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}