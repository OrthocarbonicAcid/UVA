//UVA 661 - Blowing Fuses
//やった！

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve(ll n, ll m, ll c){
    ll a[n + 1];
    ll maxi = 0;
    ll cur = 0;
    bool blown = false;

    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<bool>mark(n + 1, 0);

    for(int i = 1; i <= m; i++){
        ll x; cin >> x;
        if(mark[x]) cur -= a[x];
        else cur += a[x];

        mark[x] = !mark[x];

        if(cur > c){
            blown = true;
        }

        maxi = max(maxi, cur);
    }

    if(blown){
        cout << "Fuse was blown." << endl;
        return;
    }

    cout << "Fuse was not blown." << endl;
    cout << "Maximal power consumption was " << maxi << " amperes." << endl;
}

int main(){
    //freopen("out.txt", "w", stdout);
    ll n, m, c; 
    ll t = 1;

    while(cin >> n >> m >> c){
        if(n == 0) break;
        cout << "Sequence " << t++ << endl;
        solve(n, m, c);
        cout << endl;
    }

    return 0;
}
