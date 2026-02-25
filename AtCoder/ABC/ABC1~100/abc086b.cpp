#include<bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    string s = a + b;
    int len = s.length( );
    long long tmp = 0;
    for( int i = 0; i < len; ++ i ) {
        tmp = tmp * 10 + s[i] - '0';
    }   
    int aa = sqrt( tmp );
    if( aa * aa == tmp ) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}