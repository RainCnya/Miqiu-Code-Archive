#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int inf = 1e9 + 50;
const int maxn = 100 + 5;

int a[maxn];
int n;
int x;

void solve( )
{
    int mx = -inf;
    int mn = inf;
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        mx = max( mx, a[i] );
        mn = min( mn, a[i] );
    }
    cin >> x;
    if( mn <= x && x <= mx ) cout << "YES" << '\n';
    else cout << "NO" << '\n';

}


int main( )
{
    int _t;
    cin >> _t;
    while( _t -- )
    {
        solve();
    }
    return 0;
}