#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 5e5 + 5;

struct node { int ls, rs; } tr[maxn];
int f_min[maxn][2];
int f_max[maxn][2];
// 0 u 绿 | 1 u 不绿

string s;
int cur = 0, cnt = 0;
int build( )
{
    int u = ++ cnt;
    char c = s[cur ++];
    if( c == '2' ) {
        tr[u].ls = build( );
        tr[u].rs = build( );
    } else if ( c == '1' ) {
        tr[u].ls = build( );
    }
    return u;
}

void dfs( int u, int p )
{
    if( u == 0 ) return ;
    int ls = tr[u].ls, rs = tr[u].rs;
    dfs( ls, u ); dfs( rs, u );

    f_max[u][0] = f_max[ls][1] + f_max[rs][1] + 1;
    f_max[u][1] = max( f_max[ls][0] + f_max[rs][1], f_max[ls][1] + f_max[rs][0] );

    f_min[u][0] = f_min[ls][1] + f_min[rs][1] + 1;
    f_min[u][1] = min( f_min[ls][0] + f_min[rs][1], f_min[ls][1] + f_min[rs][0] );

}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> s;

    build( );
    dfs( 1, 0 );
    
    cout << max( f_max[1][0], f_max[1][1] ) << ' ';
    cout << min( f_min[1][0], f_min[1][1] ) << '\n';
    
    return 0;
}