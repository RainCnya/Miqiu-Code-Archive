#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
const int maxn = 5e5 + 50;

int a[maxn];

int main() {
    string s;
    cin >> s;
    int len = s.length( );
    int cnt = 1;
    vector<int> a;
    for( int i = 1; i <= len; ++ i ) {
        if( i == len ) {
            if( s[i-1] == '<' )
                a.push_back( cnt );
            else
                a.push_back( -cnt );
        } else if( s[i] != s[i-1] ) {
            if( s[i-1] == '<' )
                a.push_back( cnt );
            else
                a.push_back( -cnt );
            cnt = 1; 
        } else {
            cnt ++;
        }
    }
    int ans = 0;
    int sz = a.size( );
    for( int x : a ) {
        ans += min
        cout << x << ' ';
    }
    return 0;
}


1 -3 2 -1 5 -3 1 
1,3 2 1 0, 1, 2 1 0, 1 2 3 4 5, 3 2 1 0