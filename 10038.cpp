//UVA 10038 - Jolly Jumpers
//やった！

#include <bits/stdc++.h>

using namespace std;

void solve(int n){
    map<int, int>m;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(i > 0)
            m[abs(a[i]-a[i-1])]++;
    }

    for(int i = 1; i < n; i++){
        if(m[i] == 0){
            cout << "Not jolly" << endl;
            return;
        }
    }

    cout << "Jolly" << endl;
}
int main(){
    int n;

    while(cin >> n){
        solve(n);
    }

    return 0;
}
