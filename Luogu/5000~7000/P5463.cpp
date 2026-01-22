#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 50;

int a[maxn];
int b[maxn];
ll c[maxn];

int n;
__int128 ans;

void print( __int128 x )
{
    if( x < 0 ) {
        putchar('-');
        x = -x;
    }
    if( x > 9 ) print( x / 10 );
    putchar( x % 10 + '0' );
}

int lowbit( int x ) {
    return x & -x;
}

void add( int x, int k ) {
    for( int i = x; i <= n; i += lowbit( i ) ) {
        c[i] += k;
    }
}

ll query( int x ) {
    ll res = 0;
    for( int i = x; i; i -= lowbit( i ) ) {
        res += c[i];
    }
    return res;
}

int main( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        b[i] = a[i];
    }

    sort( a + 1, a + n + 1 );
    int m = unique( a + 1, a + n + 1 ) - ( a + 1 );

    for( int i = 1; i <= n; ++ i )
    {
        b[i] = lower_bound( a + 1, a + m + 1, b[i] ) - ( a + 1 ) + 1;
    }

    ll cur = 0;
    for( int i = 1; i <= n; ++ i )
    {
        ans += ( __int128 )(n - i + 1) * ( cur - query( b[i] ) );
        add( b[i], i );
        cur += i;
    }
    print( ans );
    return 0;
}