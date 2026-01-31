#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 3e5 + 5;

ll R[maxn], RR[maxn];
int n;

void solve( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i ) 
    {
        cin >> R[i];
        RR[i] = R[i];
    }

    for( int i = 2; i <= n; ++ i ) 
    {
        RR[i] = min( RR[i], RR[i - 1] + 1 );
    }

    for( int i = n - 1; i >= 1; -- i ) 
    {
        RR[i] = min( RR[i], RR[i + 1] + 1 );
    }

    ll sum = 0;
    for( int i = 1; i <= n; ++ i ) 
    {
        sum += R[i] - RR[i];
    }
    cout << sum << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- ) solve( );
    return 0;
}