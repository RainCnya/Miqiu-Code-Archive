#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

void solve( )
{
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    int cnt = 0;
    int nxt = -1;
    for( int i = 0; i < n; ++ i )
    {
        if( s[i] == '1' ) nxt = max( nxt, i + k );
        else if( i > nxt ) cnt ++;
    }
    cout << cnt << '\n';
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
