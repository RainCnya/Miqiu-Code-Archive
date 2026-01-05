#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 50;

int ps[maxn], ts[maxn];
int dp[maxn];
int n, k;

vector<int> v[maxn];

int main( )
{	
    cin >> n >> k;
    for( int i = 1; i <= k; ++ i )
    {
        cin >> ps[i] >> ts[i];
        v[ ps[i] ].push_back( ts[i] );
    }

    for( int i = n; i >= 1; -- i )
    {
        if( !v[i].empty( ) )
        {
            for( int k : v[i] )
            {
                dp[i] = max( dp[i], dp[ i + k ] );
            }
        }
        else
        {
            dp[i] = dp[i + 1] + 1;
        }
    }

    cout << dp[1] << '\n';
    return 0;
}