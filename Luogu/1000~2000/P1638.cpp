#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 50;

int a[maxn];
int n, m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for( int i = 1; i <= n; ++ i )
        cin >> a[i];
    
    unordered_map< int, int > cnts;
    int cnt = 0;
    int ans = 1e9;
    int ansl = -1, ansr = -1;
    int l = 1, r = 1;

    for( int r = 1; r <= n; ++ r )
    {
        cnts[ a[r] ] ++;
        if( cnts[ a[r] ] == 1 ) cnt ++;
        while( cnt == m )
        {
            int len = r - l + 1;
            if( len < ans ) {
                ans = len;
                ansl = l, ansr = r;
            } 
            cnts[ a[l] ] --;
            if( cnts[ a[l] ] == 0 ) cnt --;
            l ++;
        }
    }
    cout << ansl << " " << ansr << '\n';
    return 0;
}