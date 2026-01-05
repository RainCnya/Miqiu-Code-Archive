#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 2000 + 5;

int a[maxn];
int n;

int main( )
{
    cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        cin >> a[i];
    }    

    ll ans = 0;
    for( int i = 1; i <= n; ++ i )
    {
        for( int j = i + 1; j <= n; ++ j )
        {
            if( a[i] > a[j] ) ans ++;
        }
    }
    
    cout << ans << '\n';
    return 0;
}