#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    ll s1 = 0, s2 = 0;
    for( int i = 1; i <= 5; ++ i ) 
    {
        int x;
        cin >> x;
        s1 += x;
    }

    for( int i = 1; i <= 5; ++ i )
    {
        int x;
        cin >> x;
        s2 += x;
    }

    if( s1 >= s2 ) cout << "Blue" << '\n';
    else cout << "Red" << '\n';

    return 0;
}