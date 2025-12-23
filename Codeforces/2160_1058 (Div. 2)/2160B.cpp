#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main( )
{
    int t;  cin >> t;
    while( t -- )
    {
        int n;  cin >> n;
        vector<ll> b(n + 1);
        for( int i = 1; i <= n; ++ i ) {
            cin >> b[i];
        }
        ll cur = 1;
        vector<ll> a(n + 1);
        for( int i = 1; i <= n; ++ i ) {
            ll d = b[i] - b[i-1];
            int k = i - d;
            if( k == 0 ) { // new
                a[i] = cur ++; 
            } else {
                a[i] = a[k];
            }
        }
        for( int i = 1; i <= n; ++ i ) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}