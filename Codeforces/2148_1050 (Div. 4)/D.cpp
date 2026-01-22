#include<bits/stdc++.h>
using namespace std;

bool cmp( int a, int b )
{
    return a < b;
}

int main( )
{
    int t;
    cin >> t;
    while( t -- )
    {
        int n;
        cin >> n;
        long long sum = 0;
        vector<int> oddNum ;
        for( int i = 0; i < n; ++ i )
        {
            int a;
            cin >> a;
            if( a % 2 == 1 )
                oddNum.push_back( a );
            sum += a;
        }
        if( oddNum.empty() )
            printf("0\n");
        else
        {
            int oddCnt = oddNum.size();
            int rmvCnt = oddCnt / 2;
            long long rmvSum = 0;            
            sort( oddNum.begin(), oddNum.end(), cmp );
            for( int i = 0 ; i < rmvCnt; ++ i )
                rmvSum += oddNum[i];
            cout << sum - rmvSum << endl;    
        }
    }
    return 0;
}