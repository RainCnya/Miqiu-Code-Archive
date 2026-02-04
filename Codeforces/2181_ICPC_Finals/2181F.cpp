#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 2e5 + 5;

int a[maxn];
int n;

void solve( )
{
    cin >> n;

    int cnt = 0;

    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        if( a[i] == 1 ) cnt ++; 
    }

    if( cnt == n )
    {
        if( cnt % 2 == 1 ) cout << "Alice" << '\n';
        else cout << "Bob" << '\n';
    }
    else
    {
        if( cnt % 2 == 0 ) cout << "Alice" << '\n';
        else cout << "Bob" << '\n';
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