#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 50;

int to[maxn];
int a[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];

    for( int i = n; i >= 1; -- i )
    {
        if( a[i] == i ) to[i] = i;
        else to[i] = to[ a[i] ];
    }

    for( int i = 1; i <= n; ++ i ) cout << to[i] << ' ';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}