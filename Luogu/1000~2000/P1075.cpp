#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main( )
{
    ll n;
    cin >> n;
    
    for( ll i = 2; i * i <= n; ++ i )
    {
        if( n % i == 0 )
        {
            cout << n / i << '\n';
            return 0;
        }
    }
    return 0;
}