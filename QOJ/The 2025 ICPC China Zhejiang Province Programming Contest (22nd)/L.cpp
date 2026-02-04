#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 5;

int fa[maxn];
int ind[maxn];
bool vis[maxn];
bool Nai[maxn];
int n;

void solve( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i )
    {
        ind[i] = 0;
        vis[i] = Nai[i] = 0;
    }

    for( int i = 1; i <= n; ++ i )
    {
        cin >> fa[i];
        ind[fa[i]] ++;
    }

    int cnt = 0;

    queue<int> q;
    for( int i = 1; i <= n; ++ i )
    {
        if( ind[i] == 0 ) q.push(i);
    }

    while( q.size( ) )
    {
        int u = q.front( ); q.pop( );
        vis[u] = 1;

        if( Nai[u] == 0 )
        {
            cnt ++;
            Nai[fa[u]] = 1;
        }

        ind[fa[u]] --;
        if( ind[fa[u]] == 0 ) q.push(fa[u]);
    }

    for( int i = 1; i <= n; ++ i )
    {
        if( vis[i] ) continue;

        vector< int > cycle;
        int cur = i;

        while( !vis[cur] )
        {
            vis[cur] = 1;
            cycle.push_back(cur);
            cur = fa[cur];
        }

        int st = -1;
        for( int j = 0; j < cycle.size( ); ++ j )
        {
            if( Nai[ cycle[j] ] )
            {
                st = j;
                break;
            }
        }

        int m = cycle.size( );

        if( st == -1 ) {
            cnt += m / 2;
        } else {
            bool flag = 0;
            for( int j = 1; j < m; ++ j )
            {
                int u = cycle[( st + j ) % m];

                if( Nai[u] == 0 && flag == 0 ) cnt ++, flag = 1;
                else flag = 0;
            }
        }
    }
    
    cout << cnt << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}