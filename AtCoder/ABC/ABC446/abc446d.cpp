#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;

map< int, int > dp;
int a[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    int len = 0;
    for( int i = 1; i <= n; ++ i )
    {
        dp[ a[i] ] = dp[ a[i] - 1 ] + 1;
        len = max( len, dp[ a[i] ] );
    }
    cout << len << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}