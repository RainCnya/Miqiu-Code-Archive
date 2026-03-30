#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long
const int maxn = 2e5 + 5;
#define endl '\n'

void solve( ){
    int n;

    cin >> n;

    vector<int> a(n+1),pre(n+1);

    for (int i=1;i<=n;i++){
        cin >> a[i];
    }

    for (int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }

    map<int,int> mp;

    for (int i=1;i<=n;i++){
        for (int j=0;j<=i-1;j++){
            if (mp.count(pre[i]-pre[j])){
                for (int i=1;i<=n;i++){
                    cout << 0 << endl;
                }
                return;
            }
            mp[pre[i]-pre[j]]=1;
        }
    }


    for (int i=1;i<=n;i++){
        vector<int> vec={0};

        int ans=abs(a[i]);
        // 枚举所有可能的差值
        for (int j=1;j<=n;j++){

            for (int k=0;k<=j-1;k++){
                if (j>=i && k<i) continue;

                vec.push_back(pre[j]-pre[k]);
            }
        }
        sort(vec.begin(),vec.end());
        // for (auto &v:vec)
        //     cout << v << ' ';
        // cout << endl;

        for (int j=i;j<=n;j++){
            if (j==n && i-1==0){
                vec.erase(vec.begin());
            }
            int val=pre[j]-pre[i-1];

            auto idx1=lower_bound(vec.begin(),vec.end(),val);

            if (idx1!=vec.end()){
                // cout << *idx1 << ' ' << val << "===" << endl;
                ans=min(ans,abs(*idx1-val));
            }

            auto idx2=upper_bound(vec.begin(),vec.end(),val)-1;

            if (idx2!=vec.begin()-1){
                // cout << *idx2 << ' ' << val << "===" << endl;
                ans=min(ans,abs(*idx2-val));
            }


        
        }

        for (int j=0;j<=i-1;j++){

            int val=pre[i]-pre[j];



            auto idx1=lower_bound(vec.begin(),vec.end(),val);

            if (idx1!=vec.end()){
                // cout << *idx1 << ' ' << val << "===" << endl;
                ans=min(ans,abs(*idx1-val));
            }

            auto idx2=upper_bound(vec.begin(),vec.end(),val)-1;

            if (idx2!=vec.begin()-1){
                // cout << *idx2 << ' ' << val << "===" << endl;
                ans=min(ans,abs(*idx2-val));
            }
        
        }



        cout << ans << endl;

    }

    
}

signed main( )
{
    ios::sync_with_stdio( 0 ); cin.tie( 0 );
    int _t = 1; 
    // cin >> _t;
    while( _t -- ) solve( );
    return 0;
}