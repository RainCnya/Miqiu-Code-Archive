#include<bits/stdc++.h>
using namespace std;

int main() {
    int cnt = 0, maxlen = -1;
    string s;
    cin >> s;
    for( int i = 0; i < s.size(); ++ i ) {
        if( s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T' ) {
            cnt ++;
        } else {
            cnt = 0;
        }
        maxlen = max( maxlen, cnt );
    }
    cout << maxlen << '\n';
    return 0;
}