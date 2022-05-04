//UVA 871 - Counting Cells in a Blob
//やった！

#include <bits/stdc++.h>

using namespace std;

const int N = 30;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool grid[N][N];
bool vis[N][N];
int n;

bool ok(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= n && grid[x][y] && !vis[x][y]);
}

int bfs(int x, int y){
    queue<pair<int, int>>q;
    q.emplace(x, y); vis[x][y] = true;
    int ret = 1;

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();

        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(ok(nx, ny)){
                ret++;
                vis[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
    
    return ret;
}

void solve(){
    memset(vis, 0, sizeof(vis));
    string s; cin >> s;
    n = s.length();
    
    for(int j = 1; j <= n; j++) grid[1][j] = (s[j - 1] == '1');
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c; cin >> c;
            grid[i][j] = (c == '1');
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j] && !vis[i][j]){
                ans = max(ans, bfs(i, j));
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;

    while(tc--){
        solve();
        if(tc > 0) cout << '\n';
    }

    return 0;
}
