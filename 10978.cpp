//UVA 10978 - Let's Play Magic!
//やった！

#include <bits/stdc++.h>

using namespace std;

void solve(int n){
    vector<string>ans(n+1, "");

    int idx = 0;

    for(int i = 0; i < n; i++){
        string a, b; cin >> a >> b;
        
        for(int j = 0; j < b.length(); j++){
            idx++;
            idx %= n;
            if(ans[idx] != ""){
                while(ans[idx] != ""){
                    idx++;
                    idx %= n;
                }
            }
            
            idx %= n;
        }

        ans[idx] = a;
        idx %= n;
        //cout << "place " << a << " at " << idx << endl;
    }
    for(int i = 1; i < n; i++) cout << ans[i] << " ";
    cout << ans[0] << endl;
}

int main(){
    int n;

    while(cin >> n){
        if(n == 0)
            break;

        solve(n);
    }

    return 0;
}
