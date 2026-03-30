#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    
    int n;
    while( cin >> n )
    {
        string s1, s2;
        cin >> s1 >> s2;
        int p2 = 0;

        vector< string > ans;
        stack< char > st;

        for( int i = 0; i < n; ++ i ) 
        {
            st.push( s1[i] );
            ans.push_back("in");

            while( !st.empty( ) && st.top( ) == s2[p2] ) 
            {
                st.pop( );
                ans.push_back("out");
                p2++;
            }
        }

        if( st.empty( ) )
        {
            cout << "Yes." << '\n';
            for( int i = 0; i < ans.size( ); i++ )
            {
                cout << ans[i] << '\n';
            }
        }
        else  cout << "No." << '\n';
        cout << "FINISH" << '\n';
    }

    return 0;
}