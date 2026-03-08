#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxm = 1e6 + 5;
const int maxn = 15 + 5;

int c[maxn], p[maxn], l[maxn];
int n;

ll exgcd( ll a, ll b, ll &x, ll &y )
{
    if( b == 0 ) { x = 1, y = 0; return a; }
    ll d = exgcd( b, a % b, y, x );
    y -= a / b * x;
    return d;
}

int main( )
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    int ma = -1;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> c[i] >> p[i] >> l[i];
        ma = max( ma, c[i] );
    }

    for( int M = ma; M <= maxm; ++ M )
    {
        bool ok = 1;
        for( int i = 1; i <= n && ok; ++ i )
        {
            for( int j = i + 1; j <= n && ok; ++ j )
            {
                ll a = p[i] - p[j], b = M, cc = c[j] - c[i], x, y;
                ll d = exgcd( a, b, x, y );
                if( cc % d != 0 ) continue;
                b = abs( b / d ), cc = cc / d;
                x = ( x * cc % b + b ) % b;
                if( x <= l[i] && x <= l[j] ) ok = 0;
            }
        }
        if( ok )
        {
            cout << M << '\n';
            break;
        }
    }
    return 0;
}