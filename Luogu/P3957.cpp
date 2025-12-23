#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 50;
const long long inf = 1e18;

long long n, d, k;
long long x[maxn];
long long s[maxn];
long long dp[maxn];

bool check( long long g )
{
    long long l = max( 1ll, d - g );
    long long r = d + g;

    for( int i = 1; i <= n; ++ i )
        dp[i] = -inf;
    dp[0] = 0;
    
    deque<int> q;
    //q.push_back( 0 );

    int j = 0;
    for( int i = 1; i <= n; ++ i )
    {
        while( j < i && x[j] <= x[i] - l )
        {
            if( dp[j] != -inf )
            {
                while( !q.empty( ) && dp[ q.back( ) ] <= dp[j] )
                    q.pop_back( );
                q.push_back( j );
            }
            j ++;
        }
        while( !q.empty( ) && x[ q.front( ) ] < x[i] - r ) 
            q.pop_front( );
        
        if( !q.empty( ) )
            dp[i] = dp[ q.front( ) ] + s[i];
        
        if( dp[i] >= k )
            return 1;
    }
    return 0;
}

int main()
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> d >> k;

    long long sum = 0;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> x[i] >> s[i];
        if( s[i] > 0 ) sum += s[i];
    }

    if( sum < k )
    {
        cout << -1 << '\n';
        return 0;
    }

    long long l = 0, r = x[n] + d;
    long long ans = -1;

    while( l <= r )
    {
        long long mid = ( l + r ) >> 1;
        if( check( mid ) )
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }

    cout << ans << '\n';
    return 0;
}