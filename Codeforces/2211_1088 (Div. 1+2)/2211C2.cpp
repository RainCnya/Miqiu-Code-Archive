#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int a[maxn], b[maxn], n, k;
int fv[maxn], fa[maxn];

bool flag;

int find( int x ) {
    if( fa[x] == x ) return x;
    return fa[x] = find( fa[x] );
}

void merge( int x, int y ) {
    int rx = find( x ), ry = find( y );
    if( rx == ry ) return;
    fa[rx] = ry;
    if( fv[rx] != -1 && fv[ry] != -1 ) {
        if( fv[rx] != fv[ry] ) flag = 0;
    }
    if( fv[rx] != -1 ) fv[ry] = fv[rx];
}

void upd( int x, int val ) {
    int rx = find( x );
    if( fv[rx] != -1 && fv[rx] != val ) flag = 0;
    fv[rx] = val;
}

void fail( ) { cout << "NO" << '\n'; return ; }

void solve( )
{
    cin >> n >> k;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    for( int i = 1; i <= n; ++ i ) cin >> b[i];

    for( int i = 1; i <= n; ++ i ) fa[i] = i, fv[i] = -1;

    flag = 1;

    for( int i = 1; i <= n - k; ++ i ) {
        if( a[i] == a[i + k] ) merge( i, i + k );
        else upd( i, a[i] ), upd( i + k, a[i + k] );
    }

    for( int i = 1; i <= n; ++ i ) {
        if( b[i] != -1 ) upd( i, b[i] );
    }

    if( !flag ) return fail( );

    map< int, int > cnt;
    for( int i = 1; i <= k; ++ i ) cnt[a[i]] ++;

    for( int i = 1; i <= k; ++ i )
    {
        int rt = find( i );
        if( fv[rt] != -1 ) {
            if( cnt[fv[rt]] == 0 ) return fail( );
            cnt[fv[rt]] --;
        }
    }

    cout << "YES" << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}