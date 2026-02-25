#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 100 + 5;

int n;
string s;

int calc( string t )
{
    int res = 1;
    int len = t.length( );
    for( int i = 1; i < len; ++ i )
        if( t[i] != t[i - 1] ) res ++;
    return res;
}

void solve( )
{
    cin >> n >> s;
    int ans = 0;
    
    s = s + s;
    for( int i = 0; i < n; ++ i )
    {
        int cnt = calc( s.substr( i, n ) );
        ans = max( ans, cnt );
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