//UVA 10141 - Request for Proposal
//やった！

#include <bits/stdc++.h>

using namespace std;

void solve(int n, int p){
    string dum; 
    getline(cin, dum);
    for(int i = 1; i <= n; i++){
        getline(cin, dum);
    }

    string ans;
    double maxi = -1, curP = 1e9;

    while(p--){
        string name; getline(cin, name);
        double price, r;
        cin >> price >> r;

        if(r > maxi){
            maxi = r;
            ans = name;
            curP = price;
        } else if(r == maxi && price < curP){
            curP = price;
            ans = name;
        }
        getline(cin, name);
        for(int i = 1; i <= r; i++) getline(cin, name);
    }

    cout << ans << endl;
}

int main(){
    //freopen("out.txt", "w", stdout);
    int n, p; 
    int i = 1;

    while(cin >> n >> p){
        if(n == 0 && p == 0) break;

        if(i != 1) cout << endl;
        cout << "RFP #" << i++ << endl;
        solve(n, p);
    }

    return 0;
}
