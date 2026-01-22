#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 5e5 + 50;
const int inf = 0x3f3f3f3f;

int c[maxn];
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
    for( int i = x; i; i -= lowbit( i ) )
        res += c[i];
    return res;
}

int main( )
{
    cin >> n >> m;

    int last = 0;
    for( int i = 1; i <= n; ++ i )
    {
        int curr;
        cin >> curr;
        add( i, curr - last );
        last = curr;
    }

    while( m -- )
    {
        int op;
        cin >> op;
        if( op == 1 )
        {
            int x, y, k;
            cin >> x >> y >> k;
            add( x, k );
            add( y + 1, -k );
        }
        else
        {
            int x;
            cin >> x;
            cout << query( x ) << '\n';
        }
    }
    return 0;
}