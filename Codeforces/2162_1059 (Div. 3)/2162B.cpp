#include<bits/stdc++.h>
using namespace std;

bool check1( string s ) {
    bool ok = 0;
    for( int i = 0; i < s.length( ); ++ i ) {
        if( s[i] == '1' ) {
            ok = 1;
        } else if( ok ) {
            return 0;
        }
    }
    return 1;
}

bool check2( string s ) {
    if( s.empty( )) {
        return 1;
    }
    string s1 = s;
    reverse( s1.begin( ), s1.end( ));
    return s == s1;
}

int main( ) {
    int t;  cin >> t;
    while( t -- ) {
        int n;
        string s;
        cin >> n >> s;
        bool find = 0;

        for( int i = 0; i < (1 << n); ++ i ) {
            string s1 = "";
            string s2 = "";
            vector<int> ans;

            for( int j = 0; j < n; ++ j ) {
                if( (i >> j) & 1 ) {
                    s1 += s[j];
                    ans.push_back( j + 1 );
                }
                else {
                    s2 += s[j];
                }
            }
            
            if( check1( s1 ) && check2( s2 ) ) {
                cout << s1.length( ) << endl;
                for( int idx : ans ) {
                    cout << idx;
                    if( idx != ans.back( )) {
                        cout << " ";
                    }
                }
                cout << endl;
                find = 1;
                break;
            }
        }
        if( !find ) {
            cout << "-1" << endl;
        }
    }
    return 0;
}