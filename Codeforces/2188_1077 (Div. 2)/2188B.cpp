#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;
string s;
int n;

void solve( )
{
    cin >> n >> s;
    s = "10" + s + "01";
    
    int ans = 0;
    vector< int > pos;
    for( int i = 0; i < s.length( ); ++ i )
    {
        if( s[i] == '1' ) 
        {
            pos.push_back( i );
            if( 2 <= i && i <= n + 1 ) ans ++;
        }
    }
    
    int cnt = 0;
    for( int i = 0; i < pos.size( ) - 1; ++ i )
    {
        cnt += ( pos[i+1] - pos[i] - 1 ) / 3;
    }

    cout << ans + cnt << '\n';
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