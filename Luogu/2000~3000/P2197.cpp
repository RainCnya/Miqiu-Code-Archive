#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 5;
int a[maxn];
int n;

void solve( )
{
    cin >> n;
    int s = 0;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        s ^= a[i];
    }

    if( s == 0 ) cout << "No" << "\n";
    else cout << "Yes" << "\n";
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
