#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 100 + 5;

ll v[maxn];
bool add[maxn];
int n;

ll dpmin[maxn][maxn];
ll dpmax[maxn][maxn];

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for( int i = 1; i <= n; ++ i ) 
    {
        char c;
        cin >> c >> v[i];
        add[i + n] = add[i] = ( c == 't' );
        v[i + n] = v[i];
    }

    memset( dpmin, 0x3f, sizeof( dpmin ) );
    memset( dpmax, -0x3f, sizeof( dpmax ) );

    for( int i = 1; i <= 2 * n; ++ i )
    {
        dpmin[i][i] = dpmax[i][i] = v[i];
    }

    for( int len = 2; len <= n; ++ len )
    {
        for( int i = 1; i + len - 1 <= 2 * n; ++ i )
        {
            int j = i + len - 1;
            for( int k = i; k < j; ++ k )
            {
                if( add[k + 1] )
                {
                    dpmin[i][j] = min( dpmin[i][j], dpmin[i][k] + dpmin[k + 1][j] );
                    dpmax[i][j] = max( dpmax[i][j], dpmax[i][k] + dpmax[k + 1][j] );
                }
                else
                {
                    vector< ll > tmp;
                    tmp.push_back( dpmax[i][k] * dpmin[k + 1][j] );
                    tmp.push_back( dpmax[i][k] * dpmax[k + 1][j] );
                    tmp.push_back( dpmin[i][k] * dpmin[k + 1][j] );
                    tmp.push_back( dpmin[i][k] * dpmax[k + 1][j] );
                    
                    sort( tmp.begin( ), tmp.end( ) );
                    dpmin[i][j] = min( dpmin[i][j], tmp.front( ) );
                    dpmax[i][j] = max( dpmax[i][j], tmp.back( ) );
                }
            }
        }
    }

    vector< int > res;
    ll ans = -1e18;

    for( int i = 1; i <= n; ++ i )
    {
        if( ans < dpmax[i][i + n - 1] )
        {
            ans = dpmax[i][i + n - 1];
            res.clear( );
            res.push_back( i );
        }
        else if( ans == dpmax[i][i + n - 1] )
        {
            res.push_back( i );
        }
    }

    cout << ans << '\n';
    for( int x : res ) cout << x << " ";
    return 0;
}