#include<bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 50;

struct stick{
    int l, w;
}a[maxn];

int dp[maxn];
int n;

bool cmp( const stick a, const stick b )
{
    if( a.l != b.l ) return a.l < b.l;
    else return a.w < b.w;
}

int main( )
{	
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i].l >> a[i].w;
        dp[i] = 1;
    }

    sort( a + 1, a + n + 1, cmp );
    
    for( int i = 2; i <= n; ++ i )
    {
        for( int j = 1; j < i; ++ j )
        {
            if( a[j].w > a[i].w ) 
                dp[i] = max( dp[i], dp[j] + 1 ); 
        }
    }

    int ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        ans = max( ans, dp[i] );
    }

    cout << ans << '\n';
    return 0;
}