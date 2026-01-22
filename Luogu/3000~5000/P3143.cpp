#include<bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 50;

int a[maxn];
int pre[maxn];
int post[maxn];
int n, k;
int l, r;

int main() {
    cin >> n >> k;
    for( int i = 1; i <= n; ++ i ) {
        cin >> a[i];
    }

    sort( a + 1, a + n + 1 );

    l = 1, r = 1;
    while( r <= n )
    {
        while( a[r] - a[l] > k && l <= r ) l ++;
        pre[r] = max( pre[r - 1], r - l + 1 );
        r ++;
    }

    l = n, r = n;
    while( l >= 1 )
    {
        while( a[r] - a[l] > k && l <= r ) r --;
        post[l] = max( post[l + 1], r - l + 1 );
        l --;
    }

    int ans = 0;
    for( int i = 1; i < n; ++ i )
    {
        ans = max( ans, pre[i] + post[i + 1] );
    }

    cout << ans << '\n';
    return 0;
}