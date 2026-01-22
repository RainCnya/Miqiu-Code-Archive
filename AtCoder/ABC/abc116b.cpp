#include<bits/stdc++.h>
using namespace std;

int f( int x ) {
    if( x % 2 ) {
        return 3 * x + 1;
    } else {
        return x / 2;
    }
}

int main() {
    int s;  cin >> s;
    set<int> st;
    int a1 = s;
    int m = 1;
    st.insert( a1 );
    while( 1 ) {
        int a2 = f( a1 );
        if( st.find(a2) != st.end() ) {
            m ++;
            break;
        } else {
            st.insert( a2 );
            m ++;
        }
        a1 = a2;
    }
    cout << m << '\n';
    return 0;
}