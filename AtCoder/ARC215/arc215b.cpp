#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

bool vis[maxn];
bool nxt[maxn << 1];
bool used[maxn];
int a[maxn << 1];
int n;

void solve( )
{
    cin >> n;

    for( int i = 1; i <= 2 * n; ++ i )
    {
        nxt[i] = 0;
    }

    for( int i = 1; i <= n; ++ i )
    {
        vis[i] = used[i] = 0;
    }

    vector< int > ans;
    for( int i = 1; i <= 2 * n; ++ i )
    {
        cin >> a[i];
        if( vis[ a[i] ] ) {
            nxt[i] = 1;
        } else {
            vis[ a[i] ] = 1;
            nxt[i] = 0;
        }
    }

    int opt = 1;

    for( int i = 1; i <= 2 * n; ++ i )
    {
        if( opt == 1 )
        {
            if( used[ a[i] ] )
            {
                ans.push_back( i - 1 );
                opt = 0;
            }
            else
            {
                used[ a[i] ] = 1;
            }
        }
        else
        {
            if( !used[ a[i] ] && nxt[i] )
            {
                ans.push_back( i - 1 );
                opt = 1;
                used[ a[i] ] = 1;
            }
        }
    }

    cout << ans.size( ) << '\n';
    for( int x : ans ) cout << x << " ";
    cout << '\n';
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