#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

ll n;


ll mypow( ll a, ll b, ll n )
{
    ll res = 1;
    for( int i = 1; i <= b; ++ i )
    {
        if( res * a > n ) return n + 1;
        res *= a;
    }
    return res;
}

void solve( )
{
    cin >> n;
    
    for( int k = 31; k >= 1; -- k )
    {
        ll tmp = 0;
        int m = 0;
        for( int i = 1; ; ++ i )
        {
            tmp += mypow( i, k, n );
            m = i;
            if( tmp >= n ) break;
        }

        if( tmp == n )
        {
            for( int i = 1; i <= m; ++ i )
            {
                cout << i << '^' << k;
                if( i != m ) cout << '+';
            }
            cout << '\n';
            return ;
        }
    }
    cout << "Impossible for " << n << ".\n"; 
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}