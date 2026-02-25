#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 2e5 + 50;

struct Point {
    ll x, y;
} p[maxn];

struct Dir {
    ll x, y;
    int cnt;
    ld angle;
};

ll s[maxn << 1];
int n, Q;

bool cmp( const Dir& a, const Dir& b )
{
    return a.angle > b.angle;
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> Q;

    map< pair< ll, ll >, int > cnts;
    for( int i = 1; i <= n; ++ i )
    {
        ll x, y;
        cin >> x >> y;
        ll g = __gcd( abs(x), abs(y) );
        x /= g, y /= g;

        cnts[{x, y}] ++;
        p[i] = {x, y};
    }

    vector< Dir > vec;
    for( auto& [dir, cnt] : cnts )
    {
        ld angle = atan2l( dir.second, dir.first );
        vec.push_back({ dir.first, dir.second, cnt, angle });
    }
    sort( vec.begin( ), vec.end( ), cmp );
    int m = vec.size( );

    map< pair< ll, ll >, int > idx;
    for( int i = 0; i < m; ++ i )
    {
        idx[{ vec[i].x, vec[i].y }] = i;
    }

    for( int i = 1; i <= m * 2; ++ i )
    {
        s[i] = s[i-1] + vec[(i-1) % m].cnt;
    }

    while( Q -- )
    {
        int a, b;
        cin >> a >> b;
        int st = idx[{ p[a].x, p[a].y }];
        int ed = idx[{ p[b].x, p[b].y }];
        if( ed < st ) ed += m;
        cout << s[ed + 1] - s[st] << "\n";
    }

    return 0;
}