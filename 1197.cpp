//UVA 1197 - The Suspects
//やった！

#include <bits/stdc++.h>

using namespace std;

const int N = 30002;
int p[N], sz[N];

int par(int x){
    if(p[x] == x) return x;
    return p[x] = par(p[x]);
}

void join(int a, int b){
    a = par(a);
    b = par(b);

    if(a != b){
        sz[a] += sz[b];
        p[b] = a;
    }
}

void solve(int n, int m){
    for(int i = 0; i < n; i++){
        p[i] = i;
        sz[i] = 1;
    }

    while(m--){
        int k; cin >> k;
        if(k == 0) continue;
        int a; cin >> a;

        for(int i = 1; i < k; i++){
            int b; cin >> b;
            join(a, b);
        }
    }
    
    cout << sz[par(0)] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; 

    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        solve(n, m);
    }

    return 0;
}
