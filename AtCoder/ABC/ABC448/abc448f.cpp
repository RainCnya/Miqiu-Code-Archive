#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 6e4 + 5;

struct Point { int x, y, id; } p[maxn];

int n, sz = 82000;

bool cmp( Point A, Point B )
{
    int a = A.x / sz, b = B.x / sz;
    if( a != b ) return a < b;
    if( a % 2 ) return A.y < B.y;
    return A.y > B.y;
}

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        int x, y; cin >> x >> y;
        p[i] = { x, y, i };
    }

    sort( p + 1, p + n + 1, cmp );

    int st = 1;
    for( int i = 1; i <= n; ++ i )
    {
        if( p[i].id == 1 ) { st = i; break; }
    }

    for( int i = 0; i < n; ++ i )
    {
        int cur = st + i;
        if( cur > n ) cur -= n;
        cout << p[cur].id << ' ';
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}