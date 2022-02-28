//UVA 11917 - Do Your Own Homework!
//やった！

#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin >> n;
    map<string, int>m;

    for(int i = 0; i < n; i++){
        string s; cin >> s;
        int x; cin >> x;
        m[s] = x;
    }

    int d; cin >> d;
    string hw; cin >> hw;

    if(!m.count(hw) || m[hw] > d + 5) cout << "Do your own homework!" << endl;
    else if(m[hw] > d && m[hw] <= d + 5)  cout << "Late" << endl;
    else cout << "Yesss" << endl;
}

int main(){
    int tc; cin >> tc;

    for(int i = 1; i <= tc; i++){
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}
