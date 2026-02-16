#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn =3e5 + 5;

ll f[maxn];
ll df[maxn];
ll ddf[maxn];
ll a[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> f[i];

    ll Sn = ( f[1] + f[n] ) / ( n - 1 );

    for( int i = 1; i <= n; ++ i ) df[i] = f[i + 1] - f[i];

    for( int i = 1; i <= n; ++ i ) ddf[i] = df[i] - df[i - 1];

    a[1] = ( Sn + df[1] ) / 2;

    for( int i = 2; i <= n - 1; ++ i ) a[i] = ddf[i] / 2;

    a[n] = ( Sn - df[n - 1] ) / 2;
    
    for( int i = 1; i <= n; ++ i ) cout << a[i] << " ";
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