#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;

struct Ball { int val, id; } a[maxn];
int n, q, k;
int b[10];

bool cmp( Ball a, Ball b ) { 
    if( a.val != b.val ) return a.val < b.val;
    return a.id < b.id; 
}

void solve( )
{
    cin >> n >> q;
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> a[i].val;
        a[i].id = i;
    }

    sort( a + 1, a + n + 1, cmp );

    vector< Ball > tmp;
    int cnt = min( 6, n );
    for( int i = 1; i <= cnt; ++ i ) tmp.push_back( a[i] );

    while( q -- )
    {
        cin >> k;
        for( int i = 1; i <= k; ++ i ) cin >> b[i];

        for( const auto &ball : tmp )
        {
            bool rmv = 0;
            for( int i = 1; i <= k; ++ i )
            {
                if( ball.id == b[i] )
                {
                    rmv = 1;
                    break;
                }
            }
            if( rmv == 0 )
            {
                cout << ball.val << '\n';
                break;
            }
        }
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}