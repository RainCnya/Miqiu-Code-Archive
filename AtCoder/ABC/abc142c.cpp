#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;

int main() {
    int n;
    cin >> n;
    vector< pair<int, int> > a(n+1);
    for( int i = 1; i <= n; ++ i ) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort( a.begin() + 1, a.end() );
    for( int i = 1; i <= n; ++ i ) {
        cout << a[i].second << ' ';
    }
    return 0;
}