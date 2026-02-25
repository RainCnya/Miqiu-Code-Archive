#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 4e5 + 50;

multiset< ll > s;
ll a[maxn], D;
int n;

void solve( )
{
    cin >> n >> D;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    ll ans = 0;
    ll l = 1; 
    for( ll r = 1; r <= n; ++ r )
    {
        while( 1 )
        {
            auto it = s.lower_bound( a[r] - D + 1 );
            if( it != s.end( ) && *it < a[r] + D ) s.erase( s.find( a[l ++] ) );
            else break;
        }

        ans += r - l + 1;
        s.insert( a[r] );
    }

    cout << ans << endl;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}