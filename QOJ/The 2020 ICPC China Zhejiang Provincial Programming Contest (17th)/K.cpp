#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 50 + 5;

int a[maxn], b[maxn];
int m;

void solve( )
{
    cin >> m;
    for( int i = 1; i <= m; ++ i ) cin >> a[i];
    for( int i = 1; i <= m; ++ i ) cin >> b[i];

    for( int i = 1; i <= m; ++ i )
    {
        if( b[i] > 3 * a[i] )
        {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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