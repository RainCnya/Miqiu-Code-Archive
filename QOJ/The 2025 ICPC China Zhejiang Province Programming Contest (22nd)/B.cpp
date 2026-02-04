#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
bool vis[maxn];
int n, m, x;

void solve( )
{
    cin >> n >> m;

    for( int i = 1; i <= n; ++ i ) vis[i] = 0;

    for( int i = 1; i <= m; ++ i )
    {
        cin >> x;
        if( vis[x] ) cout << "the lights are already on!" << '\n';
        else {
            int cnt = 0;
            for( int j = x; j <= n; j += x )
            {
                if( !vis[j] ) vis[j] = 1, cnt ++;
            }
            cout << cnt << '\n';
        }
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}