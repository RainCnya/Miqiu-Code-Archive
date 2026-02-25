#include<bits/stdc++.h>
using namespace std;

long long k[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };

int main() {
    int n;
    cin >> n;
    int a[10], b[10];
    for( int i = 1; i <= n; ++ i ) {
        cin >> a[i];
    }
    for( int i = 1; i <= n; ++ i ) {
        cin >> b[i];
    }
    long long ansa = 1;
    long long ansb = 1;

    for( int i = 1; i <= n; ++ i ) {
        int cur = a[i];
        int cnt = 0;
        for( int j = i + 1; j <= n; ++ j ) {
            if( a[j] < cur ) {
                cnt ++;
            }
        }
        ansa += k[ n - i ] * cnt;
    }
    for( int i = 1; i <= n; ++ i ) {
        int cur = b[i];
        int cnt = 0;
        for( int j = i + 1; j <= n; ++ j ) {
            if( b[j] < cur ) {
                cnt ++;
            }
        }
        ansb += k[ n - i ] * cnt;
    }
    cout << abs( ansa - ansb ) << '\n';
    return 0;
}