#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 50;
const int maxlg = 20;

int a[maxn];
int st[maxn][maxlg];
int lg2[maxn];
int n, m;

void lgInit( int n )
{
    lg2[1] = 0;
    for( int i = 2; i <= n; ++ i )
        lg2[i] = lg2[i >> 1] + 1;
}

void stInit( int n )
{
    for( int i = 1; i <= n; ++ i )
        st[i][0] = a[i];
    
    for( int j = 1; j < maxlg; ++ j )
        for( int i = 1; i + ( 1 << j ) - 1 <= n; ++ i )
            st[i][j] = max( st[i][j-1], st[i + (1 << (j - 1))][j - 1] );
}

int query( int l, int r )
{
    int k = lg2[ r - l + 1 ];
    return max( st[l][k], st[r - (1 << k) + 1][k] );
}

int main( )
{	
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    
    lgInit( n );

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    stInit( n );
    
    while( m -- )
    {
        int l, r;
        cin >> l >> r;
        int ans = query( l , r );
        cout << ans << '\n';
    }

    return 0;
}