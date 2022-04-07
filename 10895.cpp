//UVA 10895 - Matrix Transpose
//やった！

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int m, n;

    while(cin >> m >> n){
        vector<pair<int, int>>adj[n + 2];
        for(int i = 1; i <= m; i++){
            int k; cin >> k;
            int a[k + 1];
            for(int j = 1; j <= k; j++) cin >> a[j];
            for(int j = 1; j <= k; j++){
                int val; cin >> val;
                adj[a[j]].emplace_back(i, val);
            }
        }

        cout << n << " " << m << endl;

        for(int i = 1; i <= n; i++){
            cout << adj[i].size();
            for(auto &x: adj[i]) cout << " " << x.first;
            cout << endl;
            for(auto &x: adj[i]){
                cout << x.second;
                if(x != adj[i].back()) cout << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
