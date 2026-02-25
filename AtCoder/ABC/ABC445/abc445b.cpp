#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;

string s[maxn];
int n;

void solve( )
{
    cin >> n;
    int m = 0;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> s[i];
        m = max( m, (int)s[i].length( ) );
    }

    for( int i = 1; i <= n; ++ i )
    {
        int cur = s[i].length( );
        int cnt = ( m - cur ) / 2;
        cout << string( cnt, '.' ) << s[i] << string( cnt, '.' ) << '\n';
    }

}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}