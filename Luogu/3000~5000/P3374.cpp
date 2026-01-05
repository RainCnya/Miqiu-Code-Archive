#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 5e5 + 50;
const int inf = 0x3f3f3f3f;

ll c[maxn];
int n, m;

int lowbit( int x )
{
    return x & -x;
}

void add( int x, int k )
{
    for( int i = x; i <= n; i += lowbit( i ) )
        c[i] += k;
}

ll query( int x )
{
    ll res = 0;
    for( int i = x; i > 0; i -= lowbit( i ) )
        res += c[i];
    return res;
}

int main( )
{
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i )
    {
        int x;
        cin >> x;
        add( i, x );
    }    

    while( m -- )
    {
        int op, x, y;
        cin >> op >> x >> y;
        if( op == 1 ) add( x, y );
        else cout << query( y ) - query( x - 1 ) << '\n';
    }

    return 0;
}