#include <bits/stdc++.h>

using namespace std;

void solve(){
    int price;  cin >> price;
    int n;      cin >> n;
    vector<int>dp(price + 20001, 1e9);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        int c; cin >> c;

        for(int j = price + 20000; j >= c; j--){
            dp[j] = min(dp[j], dp[j - c] + 1);
        }
    }

    for(int i = price; i <= price + 20000; i++){
        if(dp[i] != 1e9){
            cout << i << " " << dp[i] << endl;
            return;
        }
    }
}

int main(){
    int tc; cin >> tc;

    while(tc--){
        solve();
    }

    return 0;
}