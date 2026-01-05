#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;
const int maxlg = 20;

int st[maxn][maxlg];
int lg2[maxn];
int cnt = 0;
int m, d;
ll t;

void lgInit( int n )
{
    lg2[1] = 0;
    for( int i = 2; i <= n; ++ i )
        lg2[i] = lg2[i >> 1] + 1;
}

void add( int val )
{
    cnt ++;
    st[cnt][0] = val;
    for( int j = 1; j < maxlg; ++ j )
    {
        if( (1 << j) > cnt ) break;
        st[cnt][j] = max( st[cnt][j-1], st[cnt - (1 << (j - 1))][j-1] );
    }
}

int query( int l, int r )
{
    if( r == 0 ) return 0;
    int k = lg2[ r - l + 1 ];
    return max( st[r][k], st[l + (1 << k) - 1][k] );
}

int main( )
{	
    lgInit( maxn - 1 );
    cin >> m >> d;
    for( int i = 1; i <= m; ++ i )
    {
        char opt;
        ll k;
        cin >> opt >> k;
        if( opt == 'Q' )
        {
            t = query( cnt - k + 1, cnt );
            cout << t << '\n';
        }
        else
        {
            add( (k + t) % d );
        }
    }   
    return 0;
}