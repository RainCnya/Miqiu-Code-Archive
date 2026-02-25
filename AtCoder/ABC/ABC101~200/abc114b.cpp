#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main() {
    string s;
    int x = 753;
    int dif = inf;
    cin >> s;
    int len = s.size();
    for( int i = 0; i < len - 2; ++ i ) {
        int cur = 0;
        for( int j = i; j < i + 3; ++ j ) {
            cur = cur * 10 + ( s[j] - '0' );
        }
        //cout << dif << '\n';
        dif = min( dif, abs( cur - x ) );
    }
    cout << dif << "\n";
    return 0;
}