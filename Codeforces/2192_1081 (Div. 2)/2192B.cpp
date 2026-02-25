#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

int n;
string s;

void solve( )
{
    cin >> n >> s;
    s = ' ' + s;

    vector< int > ones, zeros;
    for( int i = 1; i <= n; ++ i )
    {
        if( s[i] == '1' ) ones.push_back( i );
        else zeros.push_back( i );
    }

    int cnt1 = ones.size( );
    int cnt0 = zeros.size( );

    if( cnt1 % 2 == 0 )
    {
        cout << cnt1 << '\n';
        for( int i = 0; i < cnt1; ++ i )
            cout << ones[i] << ' ';
        cout << '\n';
    }
    else if( n % 2 == 0 )
    {
        cout << cnt0 << '\n';
        for( int i = 0; i < cnt0; ++ i )
            cout << zeros[i] << ' ';
        cout << '\n';
    }
    else 
    {
        cout << -1 << '\n';
    }
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