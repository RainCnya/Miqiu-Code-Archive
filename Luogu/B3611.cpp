#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 50;

bool g[maxn][maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            cin >> g[i][j];
        }
    }

    for( int k = 1; k <= n; ++ k )
    {
        for( int i = 1; i <= n; ++ i )
        {
            for( int j = 1; j <= n; ++ j )
            {
                g[i][j] |= g[i][k] && g[k][j];
            }
        }
    }

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}