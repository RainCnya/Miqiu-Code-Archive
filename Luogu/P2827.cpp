#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;
const int inf = 0x3f3f3f3f;

int n, m, q, u, v, t;
deque<int> qs[3];
int a[maxn], offset;

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

void find( int &idx, ll &val )
{
    for( int j = 0; j < 3; ++ j )
    {
        if( qs[j].empty( ) ) continue;
        if( qs[j].front( ) > val )
        {
            val = qs[j].front( );
            idx = j;
        }
    }
}

int main( )
{
    n = read( ); m = read( ); q = read( );
    u = read( ); v = read( ); t = read( );

    for( int i = 1; i <= n; ++ i )
    {
        a[i] = read( );
    }

    sort( a + 1, a + n + 1, greater<int>( ) );
    for( int i = 1; i <= n; ++ i )
    {
        qs[0].push_back( a[i] );
    }

    for( int i = 1; i <= m; ++ i )
    {
        int idx = -1;
        ll val = -inf;
        
        find( idx, val );

        qs[idx].pop_front( );
        ll real = val + offset;

        ll left = real * u / v;
        ll right = real - left;
        
        qs[1].push_back( left - (offset + q) );
        qs[2].push_back( right - (offset + q) );
        
        offset += q;
        if( i % t == 0 ) cout << real << " ";
    }
    cout << '\n';
    for( int i = 1; i <= n + m; ++ i )
    {
        int idx = -1;
        ll val = -inf;
        
        find( idx, val );

        qs[idx].pop_front( );
        if( i % t == 0 ) cout << val + q * m << " ";
    }
    return 0;
}