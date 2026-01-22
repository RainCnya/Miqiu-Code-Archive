#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e7 + 50;

int cnt[maxn];

int main( )
{
    int n;
    cin >> n;

    for( ll x = 1; x * x * 2 < n; ++ x )
    {
        for( ll y = x + 1; ; ++ y )
        {
            ll val = x * x + y * y;
            if( val > n ) break;
            cnt[val] ++;
        }
    }

    vector< int > ans;
    for( int i = 1; i <= n; ++ i )
    {
        if( cnt[i] == 1 ) ans.push_back( i );
    }

    cout << ans.size( ) << '\n';
    for( int x : ans )
    {
        cout << x << " ";
    }
    
    return 0;
}