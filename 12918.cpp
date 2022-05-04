//UVA 12918 - Lucky Thief
//やった！

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(){
    ll n, m; cin >> n >> m;
    ll l = m - n - 1, r = m - 1;
    ll ans = (r * (r + 1))/2 - (l * (l + 1))/2;

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;

    while(tc--){
        solve();
    }

    return 0;
}
