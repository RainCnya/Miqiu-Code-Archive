#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;

void solve( )
{
    cin >> n >> m;

    vector< vector< int > > a( n + 5, vector< int >( m + 5 ) );
    ll total = 0;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = 1; j <= m; ++ j )
        {
            cin >> a[i][j];
            total += a[i][j];
        }
    }

    vector< vector< int > > pre( n + 5, vector< int >( m + 5 ) );
    for( int j = 1; j <= m; ++ j )
    {
        for( int i = 1; i <= n; ++ i )
        {
            pre[i][j] = pre[i - 1][j] + a[i][j];
        }
    }

    vector< vector< int > > suf( n + 5, vector< int >( m + 5 ) );
    for( int i = 0; i <= n; ++ i )
    {
        for( int j = m; j >= 1; -- j )
        {
            suf[i][j] = suf[i][j + 1] + pre[i][j];
        }
    }

    int A = total / 2;
    int B = total - A;
    
    cout << (ll)A * B << '\n';
    string res = "";

    int cr = 0, cl = 0, cnt = 0;

    while( cr < n || cl < m )
    {
        bool ok = 0;
      
        if( cr < n )
        {
            if( cl == m )
            {
                ok = 1;
            }
            else
            {
                int need = A - cnt;
                if( need >= suf[cr + 1][cl + 1] ) ok = 1;
            }
        }

        if( ok )
        {
            res += 'D';
            cr ++;
        }
        else
        {
            res += 'R';
            cl ++;
            cnt += pre[cr][cl];
        }
    } 
    cout << res << '\n';
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