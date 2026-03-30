#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int a[maxn];
int b[maxn];
bool vis[maxn];
bool used[maxn];
int n;

void solve( )
{
    cin >> n;
    
    bool ok = 1;
    a[0] = n;
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> a[i];
        if( a[i] > n || a[i] < n - i || a[i] > a[i-1] ) ok = 0;
    }

    if( !ok ) 
    {
        cout << "NO" << '\n';
        return ;
    }

    cout << "YES" << '\n';

    for( int i = 0; i <= n; ++ i ) vis[i] = used[i] = 0;

    for( int i = 1; i <= n; ++ i ) vis[a[i]] = 1;

    int l = n, r = n + 1;

    for( int i = 1; i <= n; ++ i )
    {
        if( a[i] == a[i-1] )
        {
            l = min( l, a[i ] - 1);
            while( l >= 0 && ( vis[l] || used[l] ) ) l --;
            b[i] = l;
            used[l] = 1;
        }
        else b[i] = r ++;
    }
    
    for( int i = 1; i <= n; ++ i ) cout << b[i] << ' ';
    cout << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}