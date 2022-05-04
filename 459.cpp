//UVA 459 - Graph Connectivity
//やった！

#include <bits/stdc++.h>

using namespace std;

vector<int>adj[26];
vector<bool>vis(26);
int n;

void bfs(int start){
    queue<int>q;
    q.push(start);
    vis[start] = true;

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(auto &v: adj[u]){
            if(!vis[v]){
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void init(){
    for(int i = 0; i < 26; i++){
        adj[i].clear();
        vis[i] = false;
    }
}

void solve(){
    init();
    int nxtn = 0;
    string s;

    while(cin >> s){
        if(s.length() == 1){
            nxtn = (s[0] - 'A');
            break;
        }

        int u = (s[0] - 'A');
        int v = (s[1] - 'A');

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;

    for(int i = 0; i <= n; i++){
        if(!vis[i]){
            ans++;
            bfs(i);
        }
    }

    cout << ans << '\n';
    n = nxtn;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    char c; cin >> c;
    n = c - 'A';

    while(tc--){
        solve();
        if(tc != 0) cout << '\n';
    }

    return 0;
}
