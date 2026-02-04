#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve( )
{
    string A, B;
    cin >> A >> B;

    stringstream ssA(A), ssB(B);
    vector< ll > sa, sb;
    string tmp;
    while( getline( ssA, tmp, '.' ) ) sa.push_back(stoll(tmp));
    while( getline( ssB, tmp, '.' ) ) sb.push_back(stoll(tmp));

    for( int i = 0; i < sa.size( ); ++ i )
    {
        if( sa[i] > sb[i] )
        {
            cout << "A" << '\n';
            return;
        }
        else if( sa[i] < sb[i] )
        {
            cout << "B" << '\n';
            return;
        }
    }
    cout << "Equal" << '\n';
}

int main( )
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _t = 1;
    cin >> _t;
    while( _t -- )
    {
        solve( );
    }
    return 0;
}