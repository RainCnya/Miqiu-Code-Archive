#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;
const int maxv = 1e6 + 5;

int pf[maxv];
int a[maxn], n;

void init( int N )
{
    for( int i = 2; i <= N; ++ i ) pf[i] = i;
    for( int i = 2; i * i <= N; ++ i )
    {
        if( pf[i] != i ) continue;
        for( int j = i * i; j <= N; j += i )
        {
            if( pf[j] == j ) pf[j] = i;
        }
    }
}

bool check( int x, int &p )
{
    if( x == 1 ) return p = 1;
    p = pf[x];
    while( x % p == 0 ) x /= p;
    return x == 1;
}

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> a[i];
    }

    bool increase = 1;
    for( int i = 2; i <= n; ++ i )
    {
        if( a[i - 1] > a[i] ) { increase = 0; break; }
    }

    if( increase ) { cout << "Bob" << '\n'; return; }

    bool ok = 1;
    vector< int > ps;
    for( int i = 1; i <= n; ++ i )
    {
        int p = 0;
        if( !check( a[i], p ) ) ok = 0;
        ps.push_back( p );
    }

    if( !ok ) { cout << "Alice" << '\n'; return; }

    bool ok1 = 1;
    for( int i = 1; i < n; ++ i )
    {
        if( ps[i - 1] > ps[i] ) ok1 = 0;
    }

    cout << ( ok1 ? "Bob" : "Alice" ) << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    init( maxv - 1 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}