#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int maxn = 2e6 + 50;
const int maxlg = 30;

int f[maxn][maxlg];
int n, k, ans = inf;

std::pair<int, int> a[maxn];

int main()
{	
    cin >> n >> k;
    for( int i = 1; i <= k; ++ i )
    {
        cin >> a[i].first >> a[i].second;
        if( a[i].first > a[i].second )
            a[i].second += n;
    }
    
    sort( a + 1, a + k + 1 );

    int cnt = 1, r = 0;
    for( int i = 1; i <= 2 * n; ++ i )
    {
        while( cnt <= k && a[cnt].first <= i )
        {
            r = max( r, a[cnt].second + 1 );
            cnt ++;
        }
        f[i][0] = r;
    }
    
    for( int j = 1; j < maxlg; ++ j )
    {
        for( int i = 1; i <= 2 * n; ++ i )
        {
            f[i][j] = f[ f[i][j-1] ][j-1];
        }
    }

    for( int i = 1; i <= 2 * n; ++ i )
    {
        int x = i, res = 0;
        for( int j = maxlg-1; j >= 0; -- j )
        {
            if( f[x][j] - i < n )
            {
                x = f[x][j];
                res += 1 << j;
            }
        }
        x = f[x][0];
        res ++;
        if( x - i >= n )
        {
            ans = min( ans , res );
        }
    }
    if( ans == inf ) {
        cout << "impossible" << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}