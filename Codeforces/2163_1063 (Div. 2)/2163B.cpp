#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

int a[maxn];
int n;

void solve( )
{
    cin >> n;
    int pos1 = 0, posn = 0;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        if( a[i] == 1 ) pos1 = i;
        if( a[i] == n ) posn = i;
    }

    string s;
    cin >> s;
    s = ' ' + s;

    if( s[1] == '1' || s[n] == '1' || s[pos1] == '1' || s[posn] == '1' )
    {
        cout << "-1" << '\n';
        return;
    }

    cout << 5 << '\n';
    cout << 1 << " " << pos1 << '\n';
    cout << 1 << " " << posn << '\n';
    cout << pos1 << " " << n << '\n';
    cout << posn << " " << n << '\n';
    cout << min( pos1, posn ) << " " << max( pos1, posn ) << '\n';
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