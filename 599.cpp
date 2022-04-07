//UVA 599 - The Forrest for the Trees
//やった！

#include <bits/stdc++.h>

using namespace std;

bool vis[26];
vector<int>adj[26];

int bfs(int x){
    queue<int>q; q.push(x);
    vis[x] = true;
    int ret = 1;

    while(!q.empty()){
        int now = q.front(); q.pop();
        
        for(auto &x: adj[now]){
            if(!vis[x]){
                q.push(x);
                vis[x] = true;
                ret++;
            }
        }
    }

    return ret;
}

void init(){
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < 26; i++) adj[i].clear();
}

void solve(){
    init();
    string s;

    while(cin >> s){
        if(s[0] == '*') break;
        adj[s[1] - 'A'].push_back(s[3] - 'A');
        adj[s[3] - 'A'].push_back(s[1] - 'A');
    }

    cin >> s;
    vector<int>v;
    for(int i = 0; i < s.length(); i += 2){
        v.push_back(s[i] - 'A');
    }   

    int tree = 0, acorn = 0;

    for(auto &x: v){
        if(!vis[x]){
            int res = bfs(x);
            if(res == 1) acorn++;
            else tree++;
        }   
    }

    cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s)." << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tc; cin >> tc;
    while(tc--){
        solve();
    }

    return 0;
}
