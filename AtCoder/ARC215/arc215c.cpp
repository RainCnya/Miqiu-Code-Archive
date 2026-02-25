#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
const int inf = 1e9;

struct Name { int x, y, z; } name[maxn];

int sufy[maxn], sufz[maxn];
int n;

bool cmp( Name a, Name b ) { return a.x > b.x; }

void solve( )
{
    cin >> n;
    
    for( int i = 1; i <= n; ++ i )
    {
        int x, y, z;
        cin >> x >> y >> z;
        name[i] = { x, y, z };
    }
    sort( name + 1, name + n + 1, cmp );

    sufy[n + 1] = sufz[n + 1] = 0;
    for( int i = n; i >= 1; -- i )
    {
        sufy[i] = max( sufy[i + 1], name[i].y );
        sufz[i] = max( sufz[i + 1], name[i].z );
    }
    
    int miny = inf, minz = inf;
    int ans = n;
    for( int k = 1; k <= n; ++ k )
    {
        miny = min( miny, name[k].y );
        minz = min( minz, name[k].z );
        if( name[k].x > name[k + 1].x && miny > sufy[k + 1] && minz > sufz[k + 1] )
        {
            ans = k;
            break;
        }
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}