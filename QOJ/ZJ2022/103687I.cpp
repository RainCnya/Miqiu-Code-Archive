#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e6 + 5;

int n, q;
string s;

int dist[maxn];

void mancher( string &s, int n )
{
    s = ' ' + s;

    int l = 1, r = 0;
    for( int i = 1; i <= n; ++ i )
    {
        int k = 1;
        if( i <= r ) k = min( dist[l + r - i], r - i + 1);  
        while( 1 <= i - k && i + k <= n && s[i-k] == s[i+k] ) k ++;

        dist[i] = k --;
        if( i + k > r )
        {
            l = i - k;
            r = i + k;
        }
    }
}

void solve( )
{
    cin >> n >> q;
    cin >> s;
    mancher( s, n );
    
    for( int i = 1; i <= q; ++ i )
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        if( len % 2 == 0 ) 
        {
            cout << "Budada" << '\n';
            continue;
        }
        int mid = (l + r) >> 1;
        if( dist[mid] > len / 2 ) cout << "Budada" << '\n';
        else cout << "Putata" << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}