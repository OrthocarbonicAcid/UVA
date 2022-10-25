//UVa 11550 - Demanding Dilemma

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    vector<vector<bool>>adj(n + 1, vector<bool>(n + 1));
    vector<vector<int>>v(n + 1, vector<int>(m + 1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> v[i][j];
        }
    }

    bool ok = true;
    for(int j = 1; j <= m; j++){
        vector<int>a;
        for(int i = 1; i <= n; i++){
            if(v[i][j]) a.push_back(i);
        }

        ok &= (a.size() == 2);
        if(!ok) break;

        ok &= (!adj[a[0]][a[1]]);
        adj[a[0]][a[1]] = adj[a[1]][a[0]] = true;
    }

    if(ok) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;

    while(tc--){
        solve();
    }

    return 0;
}
