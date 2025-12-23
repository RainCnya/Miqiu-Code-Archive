#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int a[maxn];

void solve( )
{
    int n;
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }
    int ans = 0;
    int mx = -1;

    for( int i = 1; i <= n; ++ i )
    {
        if( a[i] < mx ) ans ++;
        else mx = a[i];
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
