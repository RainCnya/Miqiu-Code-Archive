#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 20 + 5;

int n, m;
double a[maxn];

bool first = 1;

void solve( )
{
    if( first ) first = 0;
    else cout << '\n';
    for( int i = 1; i < maxn; ++ i ) a[i] = 0;
    int maxexp = -1;
    cin >> m;
    for( int i = 1; i <= m; ++ i )
    {
        double cof; int exp;
        cin >> cof >> exp;
        a[exp] += cof;
        maxexp = max( exp, maxexp );
    }
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        double cof; int exp;
        cin >> cof >> exp;
        a[exp] += cof;
        maxexp = max( exp, maxexp );
    }
    for( int i = 1; i <= maxexp; ++ i )
    {
        if( a[i] ) cout << fixed << setprecision( 2 ) << a[i] << " " << i << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}