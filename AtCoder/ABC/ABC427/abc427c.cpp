#include<iostream>
#include<vector>
#include<utility>

int main() {
    using namespace std;
    int m, n;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    for( int i = 1; i <= m; ++ i ) {
        int u, v;
        cin >> u >> v;
        edges.push_back({--u, --v});
    }
    int ans = m;
    for( int bit = 0; bit < (1 << n); ++ bit ) {
        int del = 0;
        for( const auto& [u, v] : edges ) {
            if( (bit >> u & 1) == (bit >> v & 1) ) {
                ++ del;
            }
        }
        ans = min(ans, del);
    }
    cout << ans;
    return 0;
}