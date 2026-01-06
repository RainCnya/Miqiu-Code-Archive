#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;

struct Point {
    int id, x, y;
} ps[maxn];

bool vis[maxn];
int n;

int cross( Point a, Point b, Point c ) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int dist( Point a, Point b ) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve( )
{
    cin >> n;
    memset( vis, 0, sizeof( vis ) );

    int start = 1;
    for( int i = 1; i <= n; i ++ )
    {
        cin >> ps[i].id >> ps[i].x >> ps[i].y;
        if( ps[i].y < ps[start].y ) start = i;
    }

    Point cur = ps[start];
    vector<int> ans;

    vis[start] = 1;
    ans.push_back( cur.id );
    
    for( int i = 1; i < n; ++ i )
    {
        int nxt = -1;

        for( int j = 1; j <= n; ++ j )
        {
            if( vis[j] ) continue;
        
            if( nxt == -1 )
            {
                nxt = j;
                continue;
            }

            int cp = cross( cur, ps[nxt], ps[j] );

            if( cp < 0 )
            {
                nxt = j;
            }
            else if( cp == 0 )
            {
                if( dist( cur, ps[j] ) > dist( cur, ps[nxt] ) ) 
                    nxt = j;
            }
        }

        vis[nxt] = 1;
        cur = ps[nxt];
        ans.push_back( cur.id );
    }

    cout << ans.size( ) << " ";
    for( int i = 0; i < ans.size( ); ++ i )
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

int main( )
{
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
