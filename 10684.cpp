//UVA 10684 - The jackpot
//やった！

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;

    while(cin >> n){
        if(n == 0) break;
        int a[n + 1], dp[n + 1]; a[0] = dp[0] = 0;
        int maxi = 0;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            dp[i] = max(dp[i - 1] + a[i], a[i]);
            maxi = max(maxi, dp[i]);
        }

        if(maxi == 0) cout << "Losing streak." << '\n';
        else cout << "The maximum winning streak is " << maxi << ".\n";
    }
    
    return 0;
}
