#include <bits/stdc++.h>
using namespace std;

bool has[5][20];
int cnt[20];

void solve( )
{
    memset( has, 0, sizeof( has ) );
    memset( cnt, 0, sizeof( cnt ) );
    
    int curSuit = 0;
    string line;
    int lines = 4;

    while( lines -- )
    {
        getline( cin, line );
        stringstream ss( line );
        string s1;

        while( ss >> s1 )
        {
            if( s1 == "HEITAO" ) curSuit = 1;
            else if( s1 == "HONGTAO" ) curSuit = 2;
            else if( s1 == "MEIHUA" ) curSuit = 3;
            else if( s1 == "FANGKUAI" ) curSuit = 4;
            else
            {
                for( char c : s1 )
                {
                    int tmp = -1;
                    if( isdigit( c ) ) tmp = c - '0';
                    else if( c == 'T' ) tmp = 10;
                    else if( c == 'Z' ) tmp = 11;
                    else if( c == 'O' ) tmp = 12;
                    else if( c == 'J' ) tmp = 13;
                    if( curSuit >= 1 && curSuit <= 4 && tmp >= 1 && tmp <= 13 )
                    {
                        has[curSuit][tmp] = 1;
                        cnt[tmp] ++;
                    }
                }
            }
        }
    }

    int ans = 0;

    for( int i = 13; i >= 1; -- i )
    {
        if( cnt[i] >= 1 ) ans = max( ans, 1 );
        if( cnt[i] >= 2 ) ans = max( ans, i * 2 );
        if( cnt[i] >= 3 ) ans = max( ans, i * 3 * 4 );
        if( cnt[i] >= 4 ) ans = max( ans, i * 4 * 8 );
    }

    int sum = 0;
    int count = 0;
    for( int i = 13; i >= 1; -- i )
    {
        if( cnt[i] >= 2 )
        {
            int cur = cnt[i] / 2;
            for( int k = 0; k < cur && count < 2; ++ k )
            {
                sum += i * 2;
                count ++;
            }
        }
        if( count == 2 ) break;
    }
    if( count == 2 ) ans = max( ans, sum * 2 );

    for( int i = 1; i <= 9; ++ i )
    {
        bool ok = 1;
        sum = 0;
        for( int k = 0; k < 5 && ok; ++ k )
        {
            if( cnt[i+k] == 0 ) ok = 0;
            sum += i + k;
        }
        if( ok ) ans = max( ans, sum * 5 );
    }

    for( int s = 1; s <= 4; ++ s )
    {
        for( int i = 1; i <= 9; ++ i )
        {
            bool ok = 1;
            sum = 0;
            for( int k = 0; k < 5 && ok; ++ k )
            {
                if( has[s][i+k] == 0 ) ok = 0;
                sum += i + k;
            }
            if( ok ) ans = max( ans, sum * 20 );
        }
    }

    cout << ans << '\n';
}

int main( )
{
    string s;
    getline( cin, s );
    stringstream ss( s );
    
    int _t = 1;
    ss >> _t;
    
    while( _t -- )
    {
        solve( );
    }
    return 0;
}


