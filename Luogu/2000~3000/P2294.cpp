#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;

int fa[maxn];
int dist[maxn];
int n, m;

int find( int x )
{
    if( fa[x] == x ) return fa[x];
    int root = find( fa[x] );
    dist[x] += dist[fa[x]];
    return fa[x] = root;
}

void solve( )
{
    cin >> n >> m;
    for( int i = 0; i <= n; ++ i ) fa[i] = i, dist[i] = 0;
    for( int i = 1; i <= m; ++ i ) 
    {
        int s, t, v;
        cin >> s >> t >> v;
        int rs = find( s-1 ), rt = find( t );
        if( rs != rt ) 
        {
            fa[rs] = rt;
            dist[rs] = dist[t] - dist[s-1] - v;
        }
        else
        {
            if( dist[t] - dist[s-1] != v )
            {
                cout << "false" << endl;
                return;
            }
        }
    }
    cout << "true" << endl;
    return;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}