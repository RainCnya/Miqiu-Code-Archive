#include<bits/stdc++.h>
using namespace std;

int main() {
    long long h;
    cin >> h;
    for( int i = 1; i <= 62; ++ i ) {
        if( (1ll << i) > h ) {
            cout << ( (1ll << i) - 1 ) << '\n';
            break;
        }
    }
    return 0;
}