#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e7 + 50;
const int maxa = 1e5 + 50;

int q1[maxn];
ll q2[maxn];
int h1 = 1, t1 = 0, h2 = 1, t2 = 0;
int cnt[maxa];
int n;
ll ans;

int read( )
{
    int x = 0, f = 1;
    char ch = getchar( );
    while( ch < '0'|| ch > '9' )
    {
        if( ch == '-' ) f = -1;
        ch = getchar( );
    }
    while( '0' <= ch && ch <= '9' )
    {
        x = x * 10 + ch - '0';
        ch = getchar( );
    }
    return x * f;
}

ll get( ) 
{
    if( h1 > t1 ) return q2[h2 ++];
    if( h2 > t2 ) return q1[h1 ++];
    return q1[h1] < q2[h2] ? q1[h1 ++] : q2[h2 ++];
}

int main( )
{
    n = read( );
    int mx = -1;

    for( int i = 1; i <= n; ++ i )
    {
        int x = read( );
        cnt[ x ] ++;
        mx = max( mx, x );
    }
    
    for( int i = 1; i <= mx; ++ i )
    {
        while( cnt[i] ) 
        {
            q1[++ t1] = i;
            cnt[i] --;
        }
    }

    for( int i = 1; i < n; ++ i )
    {
        ll x = get( );
        ll y = get( );
        ans += x + y;
        q2[++ t2] = x + y;
    }

    cout << ans << '\n';
    return 0;
}