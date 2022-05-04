//UVA 11749 - Poor Trade Advisor
//やった！

#include <bits/stdc++.h>

using namespace std;

struct St{
    int u, v, w, idx;
};

bool comp(St &a, St &b){
    if(a.w != b.w) return a.w > b.w;
    return a.idx < b.idx;
}

int bfs(int start, vector<int>adj[], vector<bool>&vis){
    queue<int>q; q.push(start);
    vis[start] = true;
    int ret = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto &v: adj[u]){
            if(!vis[v]){
                ret++;
                q.push(v);
                vis[v] = true;
            }
        }
    }

    if(ret == 0) ret--;
    return ret + 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;

    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        vector<int>adj[n + 2];
        vector<St>edge(m);
        vector<bool>vis(n + 2, 0);
        int maxi = INT_MIN;

        for(int i = 0; i < m; i++){
            cin >> edge[i].u >> edge[i].v >> edge[i].w;
            edge[i].idx = i;
            maxi = max(maxi, edge[i].w);
        }   

        sort(edge.begin(), edge.end(), comp);   
        for(int i = 0; i < m; i++){
            if(edge[i].w != maxi) break;
            adj[edge[i].u].push_back(edge[i].v);
            adj[edge[i].v].push_back(edge[i].u);
        }

        int ans = 0;

        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                ans = max(ans, bfs(i, adj, vis));
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
