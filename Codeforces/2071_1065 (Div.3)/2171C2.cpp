#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

int a[maxn], b[maxn], c[maxn];
int n;

void solve( )
{
    cin >> n;
    int xor_sum = 0;
    for( int i = 1; i <= n; ++ i ) cin >> a[i];
    for( int i = 1; i <= n; ++ i ) cin >> b[i];
    for( int i = 1; i <= n; ++ i )
    {
        c[i] = a[i] ^ b[i];
        xor_sum ^= c[i];
    }

    if( xor_sum == 0 ) {
        cout << "Tie" << '\n';
        return;
    }

    int p = 0;
    for( int i = 30; i >= 0; -- i )
    {
        if( xor_sum >> i & 1 )
        {
            p = i;
            break;
        }
    }

    int idx = 0;

    for( int i = n; i >= 0; -- i )
    {
        if( c[i] >> p & 1 )
        {
            idx = i;
            break;
        }
    }
    
    if( idx % 2 == 1 ) cout << "Ajisai" << '\n';
    else cout << "Mai" << '\n';

    return ;
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