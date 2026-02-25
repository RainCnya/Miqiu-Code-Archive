#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e4 + 5;

struct Item { int w, v, p; } a[maxn];
vector< Item > items;

int n, m;
int f[maxn];
// f[i] 表示 时间 i 内最大的价值

void add_item( int w, int v, int c )
{
    for( int k = 1; k <= c; k <<= 1 )
    {
        items.push_back( { w * k, v * k, 1 } );
        c -= k;
    }
    if( c > 0 ) items.push_back( { w * c, v * c, 1 } );
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int h1, m1, h2, m2;
    char tmp;
    cin >> h1 >> tmp >> m1 >> h2 >> tmp >> m2 >> n;

    m = h2 * 60 + m2 - h1 * 60 - m1;
    
    for( int i = 1; i <= n; ++ i )
    {
        int w, v, c;
        cin >> w >> v >> c;
        if( c == 0 ) items.push_back({ w, v, 0 });
        else add_item( w, v, c );
    }

    for( auto &[w, v, p] : items )
    {
        if( p == 0 ) // 完全
        {
            for( int j = w; j <= m; ++ j ) 
                f[j] = max( f[j], f[j - w] + v );
        } 
        else // 01
        {
            for( int j = m; j >= w; -- j ) 
                f[j] = max( f[j], f[j - w] + v );
        }
    }

    cout << f[m] << '\n';
    return 0;
}