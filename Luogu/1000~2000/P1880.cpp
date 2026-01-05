#include<bits/stdc++.h>
using namespace std;

const int maxn = 200 + 50;
const int inf = 1e9;

int mindp[maxn][maxn];
int maxdp[maxn][maxn];
long long sum[maxn];
int a[maxn];
int n;

int main( )
{	
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        a[i + n] = a[i];
    }

    for( int i = 1; i <= n * 2; ++ i )
    {
        sum[i] = sum[i-1] + a[i];
        mindp[i][i] = maxdp[i][i] = 0;
    }

    for( int len = 2; len <= n; ++ len )
    {
        for( int i = 1; i + len - 1 <= 2 * n; ++ i )
        {
            int j = i + len - 1;
            mindp[i][j] = inf;
            maxdp[i][j] = -inf;
            
            int cur = sum[j] - sum[i-1];

            for( int k = i; k < j; ++ k )
            {
                mindp[i][j] = min( mindp[i][j], mindp[i][k] + mindp[k+1][j] + cur );
                maxdp[i][j] = max( maxdp[i][j], maxdp[i][k] + maxdp[k+1][j] + cur );
            }
        }
    }

    int minans = inf, maxans = -inf;
    for( int i = 1; i <= n; ++ i )
    {
        minans = min( minans, mindp[i][i + n - 1] );
        maxans = max( maxans, maxdp[i][i + n - 1] );
    }

    cout << minans << '\n';
    cout << maxans << '\n';
    return 0;
}