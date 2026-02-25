#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;

int a[maxn];
int n, t;

void solve( )
{
    cin >> n >> t;
    for( int i = 1; i <= n; i ++ ) cin >> a[i];

    ll sum = 0;
    ll nxt = 0;
    
    for( int i = 1; i <= n; ++ i )
    {
        if( a[i] > nxt )
        {
            sum += a[i] - nxt;
            nxt = a[i] + 100;
        }
    }

    if( t > nxt ) sum += t - nxt;
    cout << sum << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while( _t -- ) solve( );
    return 0;
}