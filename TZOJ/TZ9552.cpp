#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;

int n, m;

void solve( )
{
    cin >> n >> m;

    string s;
    cin >> s;
    s = ' ' + s;
    
    vector<int> pos; 
    ll sum = 0;

    for( int i = 1; i <= n; ++ i )
    {
        if( s[i] == '0' ) sum += i;
        if( s[i] == '1' ) pos.push_back( i );
    }

    int r = n;
    ll cnt = 0;
    for( int i = pos.size( ) - 1; i >= 0; -- i )
    {
        int l = pos[i];
        cnt += r - l;
        r --;
    }
    
    ll ans = 0;

    if( m <= cnt ) ans = ( sum + sum - m + 1 ) * m / 2;
    else ans = ( sum + sum - cnt + 1 ) * cnt / 2 + ( sum - cnt ) * ( m - cnt );

    cout << ans << '\n';
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