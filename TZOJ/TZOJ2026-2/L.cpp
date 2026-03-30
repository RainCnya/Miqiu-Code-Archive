#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

const int maxn = 2e5 + 5;

int get( char c )
{
    if( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ) return 1;
    return 0;
}

int check( string &s )
{
    int len = s.length( );
    for( int i = 0; i < len - 2; ++ i )
    {
        string tmp = s.substr( i, 3 );
        if( tmp == "000" || tmp == "111" ) return 0;
    }
    return 1;
}

ll qpow( ll a, ll k )
{
    ll res = 1;
    for( ; k; k >>= 1, a = a * a )
        if( k & 1 ) res = res * a;
    return res;
}

void solve( )
{
    string s;
    cin >> s;
    int len = s.length( );
    bool isL = 0;

    vector< int > pos;
    for( int i = 0; i < len; ++ i )
    {
        if( s[i] == '_' ) pos.push_back( i );
        else {
            if( s[i] == 'L' ) isL = 1;
            s[i] = get( s[i] ) + '0';
        }
    }

    int cnt = pos.size( );
    ll ans = 0;
    if( !check( s) ) {
        cout << 0 << '\n';
        return;
    }

    // 0 是辅 1 是元
    for( int i = 0; i < ( 1 << cnt ); ++ i )
    {
        int cnt0 = 0, cnt1 = 0;
        for( int j = 0; j < cnt; ++ j )
        {
            if( i & ( 1 << j ) ) {
                cnt1++;
                s[pos[j]] = '1';
            }
            else {
                cnt0++;
                s[pos[j]] = '0';
            }
        }

        if( !isL && !cnt0 ) continue;
        if( check( s ) ) {
            // cout << s << "----->";
            ll res2 = 0;
            if( isL ) res2 = qpow( 21, cnt0 );
            else res2 = qpow( 21, cnt0 ) - qpow( 20, cnt0 );
            ll res1 = qpow( 5, cnt1 );
            ans += res1 * res2;
            // cout << res1 << " " << res2 << " " << ans << endl;
        }
    }
    // if( check())
    // if( ans == 1 && cnt > 0 ) ans = 0;
    cout << ans << '\n';
}

signed main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    solve( );
    return 0;
}