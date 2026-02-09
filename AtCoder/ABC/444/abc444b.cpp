#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

int calc( int x )
{
    int res = 0;
    while( x )
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}

void solve( )
{
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for( int i = 1; i <= n; ++ i )
    {
        if( calc( i ) == k ) cnt ++;
    }
    cout << cnt << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}