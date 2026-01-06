#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e6 + 5;

int offset[maxn];
int n, k;
string a, b;

void solve( )
{
    cin >> n >> k;
    for( int i = 1; i <= n; ++ i )
    {
        offset[i] = -1;
    }

    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;

    bool ok = 1;
    int res = 0;
    int i = n;
    
    for( int j = n; j >= 1 && i >= 1; -- j )
    {
        i = min( i, j );
        
        while( i >= 1 && a[i] != b[j] ) i --;
        if( a[i] == b[j] ) offset[j] = j - i;

        res = max( res, offset[j] );
        if( offset[j] == -1 ) ok = 0;
    }

    if( res > k || ok == 0 ) 
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << res << '\n';
        string row = string( n, ' ' );
        for( int step = 1; step <= res; ++ step )
        {
            for( int j = 1; j <= n; ++ j )
            {
                int idx = max( j - offset[j], j - step );
                row[j-1] = a[idx];
            }
            cout << row << '\n';
        }
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
