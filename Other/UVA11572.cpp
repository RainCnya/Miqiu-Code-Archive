#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 50;

int a[maxn];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;  cin >> t;
    while( t -- )
    {
        cin >> n;
        for( int i = 1; i <= n; ++ i )
            cin >> a[i];
        
        unordered_map< int, int > cnts;
        int l = 1, r = 1;
        int ans = 0;

        for( int r = 1; r <= n; ++ r )
        {
            cnts[ a[r] ] ++;
            while( cnts[ a[r] ] > 1 )
            {
                cnts[ a[l] ] --;
                l ++;
            }
            int len = r - l + 1;
            ans = max( ans, len );
        }

        cout << ans << '\n';
    }    
    return 0;
}