#include <bits/stdc++.h>
using namespace std;

void solve( )
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ss = s + s;
    int ans = 0;
    int cnt = 0;
    for( int i = 0; i < n * 2; ++ i )
    {
        if( ss[i] == '0' ) cnt ++;
        else 
        {
            if( cnt <= n ) ans = max( ans, cnt );
            cnt = 0;
        }
    }
    cout << ans << '\n';
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
