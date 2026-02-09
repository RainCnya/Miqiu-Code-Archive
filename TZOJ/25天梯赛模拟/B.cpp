#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

int n;

void solve( )
{
    cin >> n;
    // cout << __gcd( 2160, 1024 );
    double ans = 1.0 * 3840 * 2160 * 3 * 30 * 60 * n;
    double ans2 = ans / 1024.0 / 1024.0 / 1024.0;
    cout << fixed << setprecision( 1 ) << ans2 << endl; 
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}