#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e4 + 50;
const int maxm = 1e5 + 50;

struct Edge{
    int u, v;
    int cost;
};

Edge a[maxm];
int fa[maxn << 1];
int n, m;

bool cmp( Edge a, Edge b )
{
    return a.cost > b.cost;
}

void init( int _n )
{
    for( int i = 1; i <= _n; ++ i )
        fa[i] = i;
}

int find( int x )
{
    if( fa[x] == x ) return x;
    else return fa[x] = find( fa[x] );
}

void merge( int x, int y )
{
    int fx = find( x );
    int fy = find( y );
    fa[fx] = fy;
}

bool check( int x, int y )
{
    int fx = find( x );
    int fy = find( y );
    return fx == fy;
}

int main( )
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    init( n * 2 );

    for( int i = 1; i <= m; ++ i )
    {
        cin >> a[i].u >> a[i].v >> a[i].cost;
    }

    sort( a + 1, a + m + 1, cmp );

    for( int i = 1; i <= m; ++ i )
    {
        auto [u, v, c] = a[i];
        if( check( u, v ) )
        {
            cout << c;
            return 0;
        }
        else
        {
            merge( u + n, v );
            merge( u, v + n );
        }
    }
    cout << 0;
    return 0;
}