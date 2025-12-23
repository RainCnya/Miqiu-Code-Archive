#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 50;
const int inf = 1e9;

struct DP{
    int val;
    int l;
    int r;
};

DP dp[maxn];
int a[maxn];
int n;

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while( cin >> n )
    {
        if( n == 0 ) break;
        
        bool flag = 0;
        for( int i = 1; i <= n; ++ i )
        {
            cin >> a[i];
            if( a[i] >= 0 ) flag = 1;
        }
        
        if( !flag ) 
        {
            cout << 0 << " " << a[1] << " " << a[n] << '\n';
            continue;
        }

        dp[1].val = a[1];
        dp[1].l = dp[1].r = a[1];

        for( int i = 2; i <= n; ++ i )
        {
            if( dp[i-1].val < 0 )
            {
                dp[i].val = a[i];
                dp[i].l = a[i];
                dp[i].r = a[i];
            }
            else
            {
                dp[i].val = dp[i-1].val + a[i];
                dp[i].l = dp[i-1].l;
                dp[i].r = a[i];
            }
        }   

        DP ans = dp[1];
        for( int i = 2; i <= n; ++ i )
        {
            if( dp[i].val > ans.val )
            {
                ans = dp[i];
            }
        }

        cout << ans.val << " " << ans.l << " " << ans.r << '\n';
    }
    return 0;
}