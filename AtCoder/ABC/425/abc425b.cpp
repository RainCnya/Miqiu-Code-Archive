#include<bits/stdc++.h>
using namespace std;

const int maxn = 15;
int a[maxn];

int main() {
    int n;
    cin >> n;
    for( int i = 1; i <= n; ++ i ) {
        cin >> a[i];
    }
    bool flag = 1;
    set<int> s;
    for( int i = 1; i <= n; ++ i ) {
        if( a[i] == -1 ) continue;
        if( s.count( a[i] ) ) {
            flag = 0;
            break;
        }
        else s.insert( a[i] );
    }
    if( !flag ) {
        cout << "No" << '\n';
        return 0;
    }
    int cur = 1;
    for( int i = 1; i <= n; ++ i ) {
        if( a[i] == -1 ) {
            while( s.count( cur ) ) {
                cur ++;
            }
            a[i] = cur;
            s.insert( cur );
        }
    }
    cout << "Yes" << '\n';
    for( int i = 1; i <= n; ++ i ) {
        cout << a[i] << ' ';
    }
    return 0;
}