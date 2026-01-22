#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 50;

int n;
ll a[maxn];
ll sum[maxn];
ll xsum[maxn];

int main( ) 
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        xsum[i] = xsum[i - 1] ^ a[i];
    }
    
    long long ans = 0;
    int l = 1, r = 1;
    for( r = 1; r <= n; ++ r )
    {
        while( l <= r && ( sum[r] - sum[l - 1] ) != ( xsum[r] ^ xsum[l - 1] ) )
            l ++;
        ans += r - l + 1;
    }
    cout << ans << '\n';
    return 0;
}