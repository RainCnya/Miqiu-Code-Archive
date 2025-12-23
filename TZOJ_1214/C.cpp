#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

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

    // for( int i = 1; i <= n; ++ i )
    // {
    //     cout << offset[i] << " ";
    // }
    // cout << '\n';

    if( res > k || ok == 0 ) cout << -1 << '\n';
    else
    {
        cout << res << '\n';
        string t1 = a;
        string t2 = a;
        for( int k = 1; k <= res; ++ k )
        {
            for( int i = 1; i <= n; ++ i )
            {
                if( offset[i] == 0 ) t2[i] = t1[i];
                else t2[i] = t1[i-1], offset[i] --;
                cout << t2[i];
            }
            t1 = t2;
            cout << '\n';
        }
    }
}

int main( )
{
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
