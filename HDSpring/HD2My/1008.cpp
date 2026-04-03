#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
const ll inf = 1e18;

ll a[maxn], sum[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    
    ll sum = 0, neg = 0;
    ll k = 1;

    for( int i = 1; i < n; ++ i )
    {
        sum += a[i];
        if( sum < neg ) { neg = sum, k = i + 1; }
    }
    cout << k << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}