#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    int n;
    cin >> n;
    vector<int> p( n + 1 );

    int l = 1, r = n;

    for( int i = n; i >= 1; -- i )
    {
        if( ( n - i ) % 2 == 0 ) p[i] = l ++;
        else p[i] = r --;
    }

    for( int i = 1; i <= n; ++ i )
    {
        cout << p[i] << ' ';
    }
    cout << '\n';
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