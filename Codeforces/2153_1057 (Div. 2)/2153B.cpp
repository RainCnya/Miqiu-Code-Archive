#include<bits/stdc++.h>
using namespace std;

int main( )
{
    int t;  cin >> t;
    while( t -- )
    {
        int x, y, z;
        cin >> x >> y >> z;
        int a = x | z, b = x | y, c = y | z;
        if( (a & b) == x && (b & c) == y && (a & c) == z )
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}