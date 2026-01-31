#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 50;

ll Bit[maxn];
int a[maxn];
int n, Q;

int lowbit( int x ) { return x & -x; }

void update( int idx, int val )
{
    for( int i = idx; i <= n; i += lowbit(i) )
        Bit[i] += val;
}

ll query( int idx )
{
    ll res = 0;
    for( int i = idx; i > 0; i -= lowbit(i) )
        res += Bit[i];
    return res;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> Q;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        update( i, a[i] );
    }

    while( Q -- )
    {
        int opt, x, l, r;
        cin >> opt;
        if( opt == 1 )
        {
            cin >> x;
            update( x, a[x+1] - a[x] );
            update( x+1, a[x] - a[x+1] );
            swap( a[x], a[x+1] );
        }
        else
        {
            cin >> l >> r;
            cout << query(r) - query(l - 1) << "\n";
        }
    }

    return 0;
}