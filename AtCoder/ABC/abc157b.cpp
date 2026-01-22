#include<bits/stdc++.h>
using namespace std;

int a[5][5];

int main() {
    for( int i = 1; i <= 3; ++ i ) {
        for( int j = 1; j <= 3; ++ j ) {
            cin >> a[i][j];
        }
    }
    int n;
    cin >> n;
    for( int k = 1; k <= n; ++ k ) {
        int b;  cin >> b;
        for( int i = 1; i <= 3; ++ i ) {
            for( int j = 1; j <= 3; ++ j ) {
                if( a[i][j] == b ) {
                    a[i][j] = 0;
                }
            }
        }
    }
    if( a[1][1] + a[2][2] + a[3][3] == 0 ) {
        cout << "Yes" << '\n';
        return 0;
    } else if( a[3][1] + a[2][2] + a[1][3] == 0 ) {
        cout << "Yes" << '\n';
        return 0;
    } else {
        for( int i = 1; i <= 3; ++ i ) {
            if( a[i][1] + a[i][2] + a[i][3] == 0 ) {
                cout << "Yes" << '\n';
                return 0;
            }
        }
        for( int j = 1; j <= 3; ++ j ) {
            if( a[1][j] + a[2][j] + a[3][j] == 0 ) {
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}