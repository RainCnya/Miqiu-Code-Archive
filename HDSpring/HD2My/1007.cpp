#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int a[maxn];
int pre[maxn];
ll n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    for( int i = 1; i <= n; ++ i ) pre[i] = pre[i - 1] ^ a[i];
    ll tot = n * ( n + 1 ) / 2;

    ll res = 0; // 奇数长度区间个数
    for( int r = 1; r <= n; ++ r ) res += ( r + 1 ) / 2;

    map< int, ll > mp1, mp2;
    for( int i = 0; i <= n; ++ i )
    {
        if( i & 1 ) mp1[ pre[i] ] ++;
        else mp2[ pre[i] ] ++;
    }

    ll sum = 0;
    for( auto &[val, cnt] : mp1 ) sum += cnt * ( cnt - 1 ) / 2;
    for( auto &[val, cnt] : mp2 ) sum += cnt * ( cnt - 1 ) / 2;

    ll B = res + sum;
    ll A = tot - B;
    cout << A << " " << B << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}