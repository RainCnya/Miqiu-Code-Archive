#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e6 + 50;

struct Query {
    int l, r;
    int pos;
    bool operator < ( const Query &other ) {
        return r < other.r;
    }
} qs[maxn];

int a[maxn], c[maxn];
int lst[maxn], ans[maxn];
int n, m;

int lowbit( int x ) {
    return x & -x;
}

void add( int x, int k )
{
    for( int i = x; i <= n; i += lowbit( i ) )
        c[i] += k;
}

int query( int x )
{
    int res = 0;
    for( int i = x; i; i -= lowbit( i ) )
        res += c[i];
    return res;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }
    cin >> m;
    for( int i = 1; i <= m; ++ i )
    {
        int l, r;
        cin >> l >> r;
        qs[i] = { l, r, i };
    }

    sort( qs + 1, qs + m + 1 );

    int nxt = 1;
    for( int i = 1; i <= m; ++ i )
    {
        for( int j = nxt; j <= qs[i].r; ++ j )
        {
            if( lst[a[j]] )
                add( lst[a[j]], -1 );
            add( j, 1 );
            lst[a[j]] = j;
        }
        nxt = qs[i].r + 1;
        ans[qs[i].pos] = query( qs[i].r ) - query( qs[i].l - 1 );
    }

    for( int i = 1; i <= m; ++ i )
    {
        cout << ans[i] << '\n';
    }
    return 0;
}