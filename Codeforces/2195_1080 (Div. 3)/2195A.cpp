#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int a[10];
int n;

void solve( )
{
    cin >> n;
    bool ok67 = 0;
    for( int i = 1; i <= n; ++ i )
    {
        int x; cin >> x;
        if( x == 67 ) ok67 = 1;
    } 
    if( ok67 ) cout << "YES" << '\n';
    else cout << "NO" << '\n';
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