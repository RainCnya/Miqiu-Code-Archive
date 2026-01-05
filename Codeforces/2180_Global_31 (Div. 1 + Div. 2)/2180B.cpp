#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    int n;
    cin >> n;
    string s = "";

    for( int i = 1; i <= n; ++ i )
    {
        string tmp;
        cin >> tmp;
        if( tmp + s < s + tmp ) s = tmp + s;
        else s = s + tmp;
    }
    
    cout << s << '\n';
}

int main( )
{
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}
