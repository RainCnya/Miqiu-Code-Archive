#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;

int n, m;
int a[maxn];
int ans[maxn];

vector< pair<int, int> > g[maxn];

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    for( int i = 1; i <= m; ++ i )
    {
        int l, r;
        cin >> l >> r;
        g[r].push_back({ l, i });
    }
    
    deque<int> q;
    for( int i = 1; i <= n; ++ i )
    {
        while( !q.empty( ) && a[ q.back( ) ] >= a[i] )
            q.pop_back( );
        q.push_back( i );

        for( auto& p : g[i] )
        {
            int l = p.first;
            int idx = p.second;
            auto it = lower_bound( q.begin( ), q.end( ), l );
            ans[ idx ] = a[ *it ];
        }
    }

    for( int i = 1; i <= m; ++ i )
    {
        cout << ans[i] << " ";
    }
    
    return 0;
}