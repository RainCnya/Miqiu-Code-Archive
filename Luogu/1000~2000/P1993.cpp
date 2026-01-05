#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 5e3 + 5;

vector<PII> adj[maxn];
int dist[maxn];
int cnt[maxn];
bool vis[maxn];
int n, m;

void add( int u, int v, int w )
{
    adj[u].push_back({ v, w });
}

bool spfa( )
{
    queue<int> q;
    for( int i = 1; i <= n; ++ i )
    {
        dist[i] = 0;
        vis[i] = 1;
        cnt[i] = 0;
        q.push( i );
    }

    while( !q.empty( ) )
    {
        int u = q.front( );
        q.pop( );
        vis[u] = 0;
        
        for( auto [v, w] : adj[u] )
        {
            if( dist[u] + w < dist[v] )
            {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u] + 1;
                if( cnt[v] > n ) return 1;

                if( !vis[v] )
                {
                    q.push( v );
                    vis[v] = 1;
                }
            }
        }
    }
    return 0;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int k, a, b, c;
        cin >> k;
        if( k == 1 ) 
        {
            cin >> a >> b >> c;
            add( a, b, -c );
        }
        else if( k == 2 ) 
        {
            cin >> a >> b >> c;
            add( b, a, c );
        }
        else 
        {
            cin >> a >> b;
            add( a, b, 0 );
            add( b, a, 0 );
        }
    }

    if( spfa( ) ) cout << "No" << '\n';
    else cout << "Yes" << '\n';
    return 0;
}