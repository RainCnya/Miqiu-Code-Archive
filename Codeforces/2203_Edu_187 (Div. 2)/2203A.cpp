#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int n, m, d;

void solve( )
{
    cin >> n >> m >> d;
    int k = ( d / m ) + 1;
    int ans = ( n + k - 1) / k;
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