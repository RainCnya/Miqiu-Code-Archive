#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;

int main( )
{
    ll x, y;
    cin >> x >> y;
    if( x > y ) swap( x, y );
    
    ll ans = 0;
    for( int i = 1; i <= x; ++ i )
    {
        ans += ( x - i + 1 ) * ( y - i + 1 ); 
    }
    cout << ans << '\n';
    return 0;
}