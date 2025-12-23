#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<pair<int,int>> res;
    res.push_back({ 0, 0 });
    while( t -- ) 
    {
        int opt;
        cin >> opt;
        if( opt == 1 )
        {
            char c;
            cin >> c;
            auto [dif, m] = res.back( );
            int cur = dif;
            if( c == '(' ) cur ++;
            else cur --;
            int Min = min( cur, m );
            res.push_back({ cur, Min });
        }
        else
        {
            res.pop_back( );
        }
        auto [dif, m] = res.back( );
        if( dif == 0 && m >= 0 )
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
    return 0;
}