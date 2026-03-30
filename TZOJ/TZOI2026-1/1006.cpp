#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

int n;

struct People {
    ll id;
    int y, m, d;
    ll score;
    int ori;
} a[maxn];

int ans[maxn];

bool cmp( People x, People y )
{
    if( x.score != y.score ) return x.score > y.score;
    if( x.y != y.y ) return x.y < y.y;
    if( x.m != y.m ) return x.m < y.m;
    if( x.d != y.d ) return x.d < y.d;
    return x.id < y.id;
}

void solve( )
{
    cin >> n;
    int pos = 0;
    for( int i = 1; i <= n; ++ i )
    {
        int y, m, d; char c;
        cin >> a[i].id;
        cin >> a[i].y >> c >> a[i].m >> c >> a[i].d;
        cin >> a[i].score;
        a[i].ori = i;
        if( a[i].score > 0 ) ++ pos;
    }

    int lv6 = pos * 3 / 100;
    int lv5 = pos * 7 / 100;
    int lv4 = pos * 20 / 100;
    int lv3 = pos * 30 / 100;

    sort( a + 1, a + n + 1, cmp );

    for( int i = 1; i <= n; ++ i )
    {
        if( lv6 ) ans[a[i].ori] = 6, lv6 --;
        else if( lv5 ) ans[a[i].ori] = 5, lv5 --;
        else if( lv4 ) ans[a[i].ori] = 4, lv4 --;
        else if( lv3 ) ans[a[i].ori] = 3, lv3 --;
        else if( a[i].score == 0 ) ans[a[i].ori] = 1;
        else ans[a[i].ori] = 2;
    }

    for( int i = 1; i <= n; ++ i )
    {
        cout << "LV" << ans[i] << '\n';
    }
}

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; cin >> _t;
    while( _t -- ) solve( );
    return 0;
}