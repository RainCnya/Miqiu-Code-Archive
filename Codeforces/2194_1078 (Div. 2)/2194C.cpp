#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 5;

int exist[maxn];
int n, k;

void get_divs( int n, vector< int > &fac )
{
    for( int i = 1; i * i <= n; ++ i )
    {
        if( n % i == 0 )
        {
            fac.push_back( i );
            if( i * i != n ) fac.push_back( n / i );
        }
    }
    sort( fac.begin( ), fac.end( ) );
}

void solve( )
{
    cin >> n >> k;

    for( int i = 1; i <= n; ++ i ) exist[i] = 0;

    for( int i = 1; i <= k; ++ i )
    {
        string s;
        cin >> s;
        for( int j = 1; j <= n; ++ j )
        {
            exist[j] |= ( 1 << ( s[j - 1] - 'a' ) );
        }
    }

    vector< int > fac;
    get_divs( n, fac );

    for( int d : fac )
    {
        string ans = "";
        bool ok = 1;

        for( int j = 1; j <= d; ++ j )
        {
            int cur = ( 1 << 26 ) - 1;

            for( int pos = j; pos <= n; pos += d )
            {
                cur &= exist[pos];
            }

            if( cur == 0 )
            {
                ok = 0;
                break;
            }

            for( int c = 0; c < 26; ++ c )
            {
                if( ( cur >> c ) & 1 )
                {
                    ans += (char)( 'a' + c );
                    break;
                }
            }
        }
        if( ok )
        {
            for( int i = 1; i <= n / d; ++ i ) cout << ans;
            cout << '\n';
            return ;
        }
    }
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