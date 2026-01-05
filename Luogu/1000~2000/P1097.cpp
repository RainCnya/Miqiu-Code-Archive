#include<bits/stdc++.h>
using namespace std;

map<int, int> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;  cin >> n;
    for( int i = 1; i <= n; ++ i )
    {
        int x;
        cin >> x;
        mp[x] ++;
    }
    for( auto [idx, cnt] : mp )
    {
        cout << idx << " " << cnt << '\n'; 
    }
    return 0;
}