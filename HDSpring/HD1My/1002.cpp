#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int fa[maxn];
ll n, k;

int find( int x ) {
    return fa[x] == x ? x : fa[x] = find( fa[x] );
}

void solve( ) 
{
    cin >> n >> k;
    if( n >= k ) { cout << -1 << "\n"; return; }

    for( int i = 0; i < k; ++ i ) fa[i] = i;

    fa[0] = find( 1 ); 

    ll sum = 0;
    ll last = 0;

    for( int i = 1; i <= n; ++ i ) 
    {
        ll mina = last + 1;
        int nxta = ( sum + mina ) % k;

        int res = find( nxta );        
        int diff = ( res - nxta + k ) % k;
        
        ll cura = mina + diff;
        cout << cura << ' ';

        sum += cura;
        last = cura;
        fa[res] = find((res + 1) % k);
    }
    cout << "\n";
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}