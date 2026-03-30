#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp( int a, int b ) { return a > b; }

void solve( )
{
    string s;
    cin >> s;
    int n = s.length( );

    ll cnt = 0;
    vector< int > a;
    for( int i = 0; i < n; ++ i )
    {
        int d = s[i] - '0';
        cnt += d;
        if( i == 0 ) a.push_back( d - 1 );
        else a.push_back( d );
    }

    if( cnt <= 9 )
    {
        cout << 0 << '\n';
        return;
    }
    sort( a.begin( ), a.end( ), cmp );

    int ans = 0;
    for( int x : a )
    {
        cnt -= x;
        ans ++;
        if( cnt <= 9 ) break;
    }
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