#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    double t = (double) n;
    for( int i = 1; i <= n; ++ i ) {
        if( (i * 108) / 100 == n ) {
            cout << i << '\n';
            return 0;
        } 
    }
    cout << ":(" << '\n';
    return 0;
}