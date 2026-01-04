#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 105;

struct Point {
    int id, x, y;
} points[maxn];

bool used[maxn];
int n;

int cross( Point a, Point b, Point c )
{
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

int dist( Point a, Point b )
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve( )
{
    cin >> n;
    memset( used, false, sizeof( used ) );

    int startIdx = 1;
    for( int i = 1; i <= n; i ++ )
    {
        cin >> points[i].id >> points[i].x >> points[i].y;
        if( points[i].y < points[startIdx].y ) startIdx = i;
    }

    Point cur = points[startIdx];
    vector<int> ans;
    used[startIdx] = 1;
    ans.push_back( cur.id );
    
    for( int i = 1; i < n; ++ i )
    {
        int idx = -1;

        for( int j = 1; j <= n; ++ j )
        {
            if( used[j] ) continue;
        
            if( idx == -1 )
            {
                idx = j;
                continue;
            }

            Point nxt = points[j];
            Point bst = points[idx];

            int vec = cross( cur, bst, nxt );
            if( vec < 0 ) idx = j;
            else if( vec == 0 )
            {
                if( dist( cur, nxt ) < dist( cur, bst ) )
                    idx = j;
            }
        }
        used[idx] = 1;
        cur = points[idx];
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
