//UVA 11450 - Wedding shopping
//やった！

#include <bits/stdc++.h>

using namespace std;

int m, c;
vector<int>v[21];
int dp[21][205];

int f(int idx, int money){
    if(money < 0) return -1e9;
    if(idx == c) return m - money;

    int &cur = dp[idx][money];

    if(cur != -1) return cur;

    for(int i = 0; i < v[idx].size(); i++){
        cur = max(cur, f(idx + 1, money - v[idx][i]));
    }

    return cur;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    cin >> m >> c;
    for(int i = 0; i < c; i++){
        int k; cin >> k;
        v[i].clear();
        for(int j = 0; j < k; j++){
            int a; cin >> a;
            v[i].push_back(a);
        }
    }

    int ans = f(0, m);
    if(ans == -1) cout << "no solution" << '\n';
    else cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;

    while(tc--){
        solve();
    }
    
    return 0;
}
