#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3000 + 5;

struct Function { ll a, b, c; } f[maxn];
vector< int > adj[maxn], radj[maxn];
ll pre[maxn], suf[maxn];
int n;

bool delta( Function f1, Function f2 )
{
    Function diff = { f1.a - f2.a, f1.b - f2.b, f1.c - f2.c };
    if( diff.a == 0 )
    {
        if( diff.b == 0 ) return diff.c > 0;
        return 0;
    }
    else
    {
        if( diff.b * diff.b - 4 * diff.a * diff.c < 0 ) return diff.a > 0;
        return 0;
    }
}

int calc1( int u )
{
    if( pre[u] != -1 ) return pre[u];
    int res = 1;
    for( int v : radj[u] ) res = max( res, calc1( v ) + 1 );
    return pre[u] = res;
}

int calc2( int u )
{
    if( suf[u] != -1 ) return suf[u];
    int res = 1;
    for( int v : adj[u] ) res = max( res, calc2( v ) + 1 );
    return suf[u] = res;
}

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> f[i].a >> f[i].b >> f[i].c;
        adj[i].clear( );
        radj[i].clear( );
        pre[i] = suf[i] = -1;
    }

    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= n; ++ j )
        {
            if( i == j ) continue;
            if( delta( f[i], f[j] ) )
            {
                adj[i].push_back( j );
                radj[j].push_back( i );
            }
        }
    }
    
    for( int i = 1; i <= n; ++ i )
    {
        cout << calc1( i ) + calc2( i ) - 1 << " ";
    }
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}