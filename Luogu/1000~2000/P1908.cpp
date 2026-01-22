#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 50;

int a[maxn];
int b[maxn];
int c[maxn];
int n;
ll ans;

int lowbit( int x ) {
    return x & -x;
}

void add( int x, int k ) {
    for( int i = x; i <= n; i += lowbit( i ) )
        c[i] += k;
}

ll query( int x ) {
    ll res = 0;
    for( int i = x; i; i -= lowbit( i ) )
        res += c[i];
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
    int len = unique( a + 1, a + n + 1 ) - ( a + 1 );

    for( int i = 1; i <= n; ++ i )
    {
        b[i] = lower_bound( a + 1, a + len + 1, b[i] ) - ( a + 1 ) + 1;
    }

    for( int i = 1; i <= n; ++ i )
    {
        ans += ( i - 1 ) - query( b[i] );
        add( b[i], 1 );
    }

    cout << ans << '\n';
    return 0;
}