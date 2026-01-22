#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

const int maxn = 1e5 + 50;

int main( )
{
    int n;
    cin >> n;

    int res = n;
    for( int i = 1; i <= 100000; ++ i )
    {
        int tmp = res;
        res = 0;
        while( tmp )
        {
            res += ( tmp % 10 ) * ( tmp % 10 );
            tmp /= 10;
        }
        if( res == 1 ) 
        {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    return 0;
}