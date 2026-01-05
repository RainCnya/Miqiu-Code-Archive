#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 50;
const int mod = 998244353;

int id, n, m;
long long E[maxn];
// E[i] 表示 1 -> i 的期望
vector<int> adj[maxn];

int main()
{	
    cin >> id >> n >> m;
    for( int i = 1; i <= n; ++ i )
    {
        adj[i].push_back( i + 1 );
    }

    for( int i = 1; i <= m; ++ i )
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
    }

    E[1] = 0;
    for( int x = 1; x <= n; ++ x )
    {
        long long Ex = E[x];
        long long tmp = 0;
        for( int y : adj[x] ) 
        {
            if( y == x + 1 ) continue;
            tmp = (tmp + Ex - E[y] + 1 + mod) % mod;
        } 
        E[x + 1] = (Ex + 1 + tmp) % mod;
    }

    cout << E[n + 1] << '\n';
    return 0;
}