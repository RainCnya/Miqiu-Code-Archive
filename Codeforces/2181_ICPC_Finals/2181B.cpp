#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

int a[maxn], b[maxn];

void solve( )
{
    int n, m;
    cin >> n >> m;

    priority_queue< ll > a, b;

    for( int i = 1; i <= n; ++ i )
    {
        ll x;   cin >> x;
        a.push( x );
    }

    for( int j = 1; j <= m; ++ j )
    {
        ll x;   cin >> x;
        b.push( x );
    }

    while( !a.empty( ) && !b.empty( ) )
    {
        ll aa = a.top( ), bb = b.top( );
        b.pop( );
        if( aa < bb ) b.push( bb - aa );
        if( b.empty( ) )
        {
            cout << "Alice" << '\n';
            return;
        }

        bb = b.top( ), aa = a.top( );
        a.pop( );
        if( bb < aa ) a.push( aa - bb );
        if( a.empty( ) )
        {
            cout << "Bob" << "\n";
            return;
        }
    }
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