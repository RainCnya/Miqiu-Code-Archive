#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 50;

int cnt[maxn];
int a[maxn];
int n, k;

void solve( )
{
    cin >> n >> k;

    for( int i = 0; i <= n + 1; ++ i )
    {
        cnt[i] = 0;
    }
    
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        cnt[ a[i] ] ++;
    }

    int ans = 0;

    while( cnt[ans] > 0 ) ans ++;

    cout << min( ans, k - 1 ) << '\n';
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