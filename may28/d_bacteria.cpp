#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int tp;
        vector<int> x(n);
        for(int i= 0; i < n; i++){
            cin >> x[i];
        }

        for(int i = 0; i < n; i++){
            cin >>tp;
        }

        sort(x.begin(), x.end());
        vector<int> dp(n,0);
        int ans =0;
        for(int i = 0; i < n; i++){
            // choosing x of 1st plank

            auto it = upper_bound(x.begin(), x.end(),x[i]+k);
            if(it == x.end()){
                dp[i] = n-i;
                for(int j = i; j < n; j++){
                    dp[j] = n-j;
                }
                break;
            }
            dp[i] = distance(x.begin(),it)-i;

        }  
        
		// for(auto x : dp) cout << x << " ";
        // cout << endl;

        vector<int> suffmax(n,0);
        suffmax[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            suffmax[i] = max(suffmax[i+1], dp[i]);
        }

        ans =0;
        for(int i = 0; i < n; i++){
            if(i+dp[i] < n){
                ans = max(ans, dp[i]+suffmax[i+dp[i]]);
            }
            else{
                ans = max(ans, dp[i]);
            }

        }

        cout << ans << '\n';

    }
}