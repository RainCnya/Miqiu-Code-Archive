#include<bits/stdc++.h>
using namespace std;

bool isprime( int x ) {
    for( int i = 2;  i * i <= x; ++ i ) {
        if( x % i == 0 ) {
            return false;
        }
    }
    return true;
}

int main() {
    int x;  cin >> x;
    if( x < 2 ) {
        cout << 2 << '\n';
        return 0;
    }
    for( int i = x; ; ++ i ) {
        if( isprime( i ) ) {
            cout << i << '\n';
            return 0;
        }
    }   
    return 0;
}