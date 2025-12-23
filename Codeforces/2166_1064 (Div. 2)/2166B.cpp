#include<bits/stdc++.h>
using namespace std;

int main()
{	
    int t;
    cin >> t;
    while( t -- )
    {
        int a, b, n;
        cin >> a >> b >> n;
        if( n <= a / b )
        {
            cout << 1 << '\n';
        }
        else
        {
            if( a == b ) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
    }   
    return 0;
}