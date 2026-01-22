#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 10;
int a[maxn];
int n;

void solve( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    if( a[1] == 1 || a[n] == 1 ) cout << "Alice" << '\n';
    else cout << "Bob" << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}