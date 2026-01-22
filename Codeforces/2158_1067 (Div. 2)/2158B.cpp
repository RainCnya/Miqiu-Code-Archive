#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int a[maxn << 1];
int n;

void solve( )
{
    cin >> n;
    map<int, int> cnts;
    for( int i = 1; i <= 2 * n; ++ i )
    {
        cin >> a[i];
        cnts[ a[i] ] ++;
    }

    int odd = 0;
    int even = 0;

    for( auto [num, cnt] : cnts )
    {
        if( cnt & 1 ) odd ++;
        else even ++;
    }

    ll ans = 0;
    if( odd ) 
    {
        ans = odd + 2 * even;
    }
    else 
    {
        if( even % 2 == n % 2 )
            ans = 2 * even;   
        else
            ans = 2 * ( even - 1 );
    }

    cout << ans << '\n';
}

int main( )
{
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
