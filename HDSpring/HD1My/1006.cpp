#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

struct Item { ll s, d; };
Item a[maxn];
int n;

bool cmp( Item a, Item b ) { 
    if( a.s != b.s ) return a.s < b.s;
    return a.d < b.d;
}

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i].s >> a[i].d;
    }

    sort( a + 1, a + n + 1, cmp );
    ll timer = 1;
    for( int i = 1; i <= n; ++ i )
    {
        if( timer >= a[i].s ) timer += a[i].d;
        else timer = a[i].s + a[i].d;
    }
    cout << timer << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}