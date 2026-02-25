#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;

ll dp[maxn];
int a[maxn];
int n;

void solve( )
{
    cin >> n;
    dp[0] = 0;

    for( int i = 1; i <= n; i ++ ) cin >> a[i];

    ll ans = 0;
    vector< int > st;
    for( int i = 1; i <= n; ++ i )
    {
        while( !st.empty( ) && a[st.back( )] >= a[i] ) st.pop_back( );

        int idx = 0;
        if( !st.empty( ) && a[st.back( )] == a[i] - 1 )
        {
            idx = st.back( );
        }
        dp[i] = dp[i - 1] + (ll)( i - idx );
        ans += dp[i];

        if( st.empty( ) || a[st.back( )] != a[i] - 1 ) st.clear( );
        st.push_back( i );
    }
    
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}