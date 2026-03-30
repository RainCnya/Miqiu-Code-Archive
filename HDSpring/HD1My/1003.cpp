#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2000 + 5;

ll f[maxn][maxn];
ll cnts[maxn], cntt[maxn];
ll sums[maxn], sumt[maxn];

string s, t;
int n;

void calc( string &S, ll *cnt, int type )
{
    for( int i = 0; i < n; ++ i )
    {
        int l = i, r = i;
        while( l >= 0 && r < n && S[l] == S[r] )
        {
            if( type == 1 ) cnt[r] ++;
            else cnt[l] ++;
            l --, r ++;
        }
        l = i, r = i + 1;
        while( l >= 0 && r < n && S[l] == S[r] )
        {
            if( type == 1 ) cnt[r] ++;
            else cnt[l] ++;
            l --, r ++;
        }
    }
}

void solve( )
{
    cin >> s >> t;
    n = s.length( );

    for( int i = 0; i <= n + 2; ++ i )
    {
        cnts[i] = cntt[i] = 0;
        sums[i] = sumt[i] = 0;
        for( int j = 0; j <= n + 2; ++ j ) f[i][j] = 0;
    }

    calc( s, cnts, 0 ), calc( t, cntt, 1 );
    
    for( int i = 0; i <= n; ++ i ) sums[i+1] = sums[i] + cnts[i];
    for( int i = 0; i <= n; ++ i ) sumt[i+1] = sumt[i] + cntt[i];

    for( int i = n - 1; i >= 0; -- i )
    {
        for( int j = 0; j < n; ++ j )
        {
            if( s[i] == t[j] ) f[i][j] = f[i+1][j-1] + 1;
        }
    }

    ll ans = 0;
    for( int i = 0; i < n; ++ i )
    {
        for( int j = 0; j < n; ++ j )
        {
            if( s[i] == t[j] )
            {
                int len = f[i][j];
                ans += len;
                ans += sums[i + len + 1] - sums[i + 1];
                ans += sumt[j] - sumt[max(0, j - len)];
            }
        }
    }
    cout << ans << '\n';
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}