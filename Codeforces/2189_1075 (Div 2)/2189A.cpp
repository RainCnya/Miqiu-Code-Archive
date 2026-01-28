#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1000 + 5;

int a[maxn];
int h, l;
int n;

void solve( )
{
    cin >> n >> h >> l;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }

    int cnt1 = 0, cnt2 = 0, total = 0;
    
    for( int i = 1; i <= n; ++ i )
    {
        if( a[i] <= h ) cnt1 ++;
        if( a[i] <= l ) cnt2 ++;
        if( a[i] <= h || a[i] <= l ) total ++;
    }

    cout << min( min( cnt1, cnt2 ), total / 2 ) << '\n';
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