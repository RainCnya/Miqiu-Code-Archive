#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 50;

int BIT[maxn << 1];
string s;
int offset = maxn;
int n;

int lowbit( int x )
{
    return x & -x;
}

void add( int idx, int val )
{
    for( ; idx <= maxn << 1; idx += lowbit( idx ) )
        BIT[idx] += val;
}

ll query( int idx )
{
    ll res = 0;
    for( ; idx; idx -= lowbit( idx ) )
        res += BIT[idx];
    return res;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> s;
    s = ' ' + s;

    ll ans = 0;
    int cnt = 0;
    add( offset, 1 );

    for( int i = 1; i <= n; ++ i )
    {
        if( s[i] == 'A' ) cnt ++;
        else if( s[i] == 'B' ) cnt --;

        ans += query( cnt + offset - 1 );
        add( cnt + offset, 1 );
    }

    cout << ans << '\n';

    return 0;
}