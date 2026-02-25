#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 350 + 5;
const int maxm = 120 + 5;

ll f[41][41][41][41];
int s[maxn];
int cnt[5];
int n, m, b;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    for( int i = 1; i <= n; ++ i ) cin >> s[i];

    for( int i = 1; i <= m; ++ i )
    {
        cin >> b;
        cnt[ b ] ++;
    }

    f[0][0][0][0] = s[1];

    for( int a = 0; a <= cnt[1]; ++ a )
    {
        for( int b = 0; b <= cnt[2]; ++ b )
        {
            for( int c = 0; c <= cnt[3]; ++ c )
            {
                for( int d = 0; d <= cnt[4]; ++ d )
                {
                    int cur = 1 + a * 1 + b * 2 + c * 3 + d * 4;
                    if( cur > n ) continue;

                    ll &val = f[a][b][c][d];
                    if( a > 0 ) val = max( val, f[a - 1][b][c][d] + s[cur] );
                    if( b > 0 ) val = max( val, f[a][b - 1][c][d] + s[cur] );
                    if( c > 0 ) val = max( val, f[a][b][c - 1][d] + s[cur] );
                    if( d > 0 ) val = max( val, f[a][b][c][d - 1] + s[cur] );
                }
            }
        }
    }

    cout << f[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << '\n';
    return 0;
}