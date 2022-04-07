//UVA 11991 - Easy Problem from Rujia Liu?
//やった！

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; 
    
    while(cin >> n >> m){
        vector<int>v[100001];
        vector<int>a(n);
        map<int, int>compress;

        int cur = 1;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(!compress.count(a[i])){
                compress[a[i]] = cur++;
            }
            v[compress[a[i]]].push_back(i + 1);
        }

        while(m--){
            int k, x; cin >> k >> x;
            if(v[compress[x]].size() < k){
                cout << 0 << "\n";
            } else{
                cout << v[compress[x]][k - 1] << "\n";
            }
        }
    }

    return 0;
}
