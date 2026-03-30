#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 20 + 5;

int a[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    int sum = 0;
    for( int i = 1; i <= n; ++ i ) sum += a[i];

    if( sum % 4 != 0 )
    {
        cout << "no" << '\n';
        return ;
    }

    int len = sum / 4;
    vector< int > dp( 1 << n , -1 );
    dp[0] = 0;
    for( int mask = 0; mask < (1 << n); ++ mask )
    {
        if( dp[mask] == -1 ) continue;
        for( int i = 0; i < n; ++ i )
        {
            if( (mask & (1 << i)) ) continue;
            if( dp[mask] + a[i] <= len ) 
            {
                int nxt = mask | (1 << i);
                dp[nxt] = (dp[mask] + a[i]) % len;
            }
        }
    }
    if( dp[( 1 << n )- 1] == 0 ) cout << "yes" << '\n';
    else cout << "no" << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}