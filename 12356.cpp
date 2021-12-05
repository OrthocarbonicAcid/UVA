//UVA 12356 - Army Buddies
//やった！

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int l[N+5], r[N+5];
int s, b;

void init(){
    for(int i = 1; i <= N; i++){
        l[i] = i - 1;
        r[i] = i + 1;
    }

    l[0] = l[1] = r[s] = -1;
}

void solve(){
    init();
    for(int i = 0; i < b; i++){
        int x, y; cin >> x >> y;
        
        l[r[y]] = l[x];
        r[l[x]] = r[y];

        if((l[x] == -1)? cout << "* " : cout << l[x] << " ");
        if((r[y] == -1)? cout << "*\n" : cout << r[y] << "\n");
    }

    cout << "-" << endl;
}

int main(){
    while(cin >> s >> b){
        if(s == b && s == 0)
            break;
        
        solve();
    }

    return 0;
}
