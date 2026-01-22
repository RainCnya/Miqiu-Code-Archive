#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    int rank = 0;
    int cnt = 0;
    for( int i = 0; i < n; ++ i ) {
        if( s[i] == 'a') {
            if( cnt < a + b ) {
                cnt ++;
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        } else if( s[i] == 'b' ) {
            if( cnt < a + b && rank < b ) {
                cnt ++;
                rank ++;
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        } else {
            cout << "No" << '\n';
        }
    }
    return 0;
}