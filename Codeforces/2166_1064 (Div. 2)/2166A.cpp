#include<bits/stdc++.h>
using namespace std;

int main()
{	
    int t;
    cin >> t;
    while( t -- )
    {
        int n;
        string s;
        cin >> n >> s;
        char tmp = s[n-1];
        int cnt = 0;
        for( int i = 0; i < n; ++ i )
        {
            if( s[i] == tmp )
                cnt ++;
        }
        cout << n - cnt << '\n';
    }
    return 0;
}