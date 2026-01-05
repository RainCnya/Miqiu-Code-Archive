#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;

int n;
int a[maxn], b[maxn];
int mp[maxn], dp[maxn];

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        mp[ a[i] ] = i;
    }
    
    for( int j = 1; j <= n; ++ j )
    {
        cin >> b[j];
    }

    int len = 0;

    for( int i = 1; i <= n; ++ i )
    {
        if( !len || dp[len] < mp[ b[i] ] )
        {
            dp[ ++ len ] = mp[ b[i] ];
        }
        else
        {
            int x = lower_bound( dp + 1, dp + len + 1, mp[ b[i] ] ) - dp;
            dp[x] = mp[ b[i] ];
        }
    }

    cout << len << '\n';
    return 0;
}