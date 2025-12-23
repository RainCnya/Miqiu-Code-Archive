#include<bits/stdc++.h>
using namespace std;

int main( )
{
    int t;
    cin >> t;
    while( t -- )
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> a(n);
        for( int i = 0; i < n; ++ i )
            cin >> a[i].first >> a[i].second;
        
        int sum = 0;
        int lastTime = 0;
        int lastSide = 0;
        for( int i = 0; i < n; ++ i )
        {
            int ai = a[i].first;
            int bi = a[i].second;

            int diffTime = ai - lastTime;
            if( lastSide == bi )
            {
                if( diffTime % 2 == 0 )
                    sum += diffTime;
                else
                    sum += diffTime - 1;
            }
            else
            {
                if( diffTime % 2 == 1 )
                    sum += diffTime;
                else
                    sum += diffTime - 1;
            }
            
            lastTime = ai;
            lastSide = bi;
        }
        sum += m - lastTime;
        cout << sum << endl;
    }
    return 0;
}