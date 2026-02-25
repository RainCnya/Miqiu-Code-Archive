#include<iostream>
#include<vector>
#include<map>
#include<utility>

using std::pair;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    using namespace std;
    string s;
    cin >> s;
    map<char,int> cnt;
    for( char c : s ) ++ cnt[c];
    char ans;
    for( auto [c, num] : cnt ) {
        if( num == 1 ) {
            ans = c;
            break;
        }
    }
    cout << ans;
    return 0;
}