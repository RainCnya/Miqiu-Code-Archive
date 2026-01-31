#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    ll n, k;
    cin >> n >> k;

    ll sum = n;
    ll cnt = 0;
    while( sum < k )
    {
        cnt ++;
        sum += ( n + cnt );
    }
    cout << cnt << '\n';

}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    // cin >> _t;
    while( _t -- ) solve( );
    return 0;
}