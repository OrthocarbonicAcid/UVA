//UVA 11991 - Easy Problem from Rujia Liu?
//やった！

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    while(cin >> n >> m){
        vector<int>a[N];
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            a[x].push_back(i);
        }

        while(m--){
            int k, v; cin >> k >> v;
            if(k > a[v].size()) cout << 0 << '\n';
            else cout << a[v][k - 1] << '\n';
        }
    }

    return 0;
}
