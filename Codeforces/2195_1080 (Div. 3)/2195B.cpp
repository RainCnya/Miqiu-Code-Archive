#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int fa[maxn];
int a[maxn];
int n;

int find( int x )
{
    if( fa[x] == x ) return fa[x];
    else return fa[x] = find( fa[x] );
}

void merge( int x, int y )
{
    int rx = find( x ), ry = find( y );
    if( rx != ry ) fa[rx] = ry;
}

void solve( )
{
    cin >> n;

    for( int i = 1; i <= n; ++ i ) fa[i] = i;

    for( int i = 1; i <= n / 2; ++ i ) merge( i, 2 * i );
    
    bool ok = 1;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        if( find( i ) != find( a[i] ) ) ok = 0;
    }
    
    if( ok ) cout << "YES" << '\n';
    else cout << "NO" << '\n';
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