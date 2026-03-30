#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5000 + 5;

ll a[maxn];
ll large[maxn], small[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) large[i] = small[i] = 0;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = i + 1; j <= n; ++ j )
        {
            if( a[j] > a[i] ) large[i] ++;
            else if( a[j] < a[i] ) small[i] ++;
        }
    }
    for( int i = 1; i <= n; ++ i )
    {
        cout << max( large[i], small[i] ) << ' ';
    }
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}