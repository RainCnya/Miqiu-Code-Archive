#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<string, int> cnt;
    int maxCnt = 0;
    for( int i = 0; i <= n-k; ++ i ) {
        string t = "";
        for( int j = 0; j < k; ++ j ) {
            t += s[i+j];
        }
        cnt[t] ++;
        maxCnt = max( maxCnt, cnt[t] );
    }
    cout << maxCnt << '\n';
    for( auto& s : cnt ) {
        if( s.second == maxCnt ) {
            cout << s.first << " ";
        }
    }
    return 0;
}