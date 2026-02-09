#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 50;

int n;

void solve( )
{
    cin >> n;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;

    for( int i = 1; i <= n; ++ i )
    {
        int x, y, z;
        cin >> x >> y >> z;
        int cnt = ( x >= 60 ) + ( y >= 60 ) + ( z >= 60 );
        if( cnt == 1 ) cnt1 ++;
        else if( cnt == 2 ) cnt2 ++;
        else if( cnt == 3 ) cnt3 ++;
    }

    cout << cnt3 << ' ' << cnt2 << ' ' << cnt1 << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve( );
    return 0;
}