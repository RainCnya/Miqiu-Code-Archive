#include<bits/stdc++.h>
using namespace std;

const int maxn = 60 + 5;
const int maxw = 2e5 + 50;
int dp[maxn][maxw];
int n, m;

struct node{
    int v, w, q, f1, f2; 
}a[maxn];

int calc( int i ) {
    return a[i].v * a[i].w;
}

int main()
{	
    cin >> n >> m;
    for( int i = 1; i <= m; ++ i )
    {
        cin >> a[i].w >> a[i].v >> a[i].q;
        if( a[i].q )
        {
            if( !a[ a[i].q ].f1 ) a[ a[i].q ].f1 = i;
            else a[ a[i].q ].f2 = i;
        }
    }

    for( int i = 1; i <= m; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            if( a[i].q )
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                int f1 = a[i].f1, f2 = a[i].f2;
                int t = dp[i-1][j];
                if( j >= a[i].w )
                    t = max( t, dp[i-1][j - a[i].w] + calc( i ) );
                if( f1 && j >= a[i].w + a[f1].w )
                    t = max( t, dp[i-1][j - a[i].w - a[f1].w ] + calc( i ) + calc( f1 ) );
                if( f2 && j >= a[i].w + a[f2].w )
                    t = max( t, dp[i-1][j - a[i].w - a[f2].w ] + calc( i ) + calc( f2 ) );
                if( f1 && f2 && j >= a[i].w + a[f1].w + a[f2].w )
                    t = max( t, dp[i-1][j - a[i].w - a[f1].w - a[f2].w ] + calc( i ) + calc( f1 ) + calc( f2 ) );
                dp[i][j] = t;
            }
        }
    }
    
    cout << dp[m][n];
    return 0;
}