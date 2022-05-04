//UVA 11094 - Continents
//やった！

#include <bits/stdc++.h>

using namespace std;

const int N = 25;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
char grid[N][N];
bool vis[N][N];
char c;
int n, m;

bool ok(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m && grid[x][y] == c && !vis[x][y]);
}

int bfs(int x, int y){
    queue<pair<int, int>>q; 
    q.emplace(x, y); vis[x][y] = true;
    int ret = 1;

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(ny > m) ny = 1;
            else if(ny < 1) ny = m;

            if(ok(nx, ny)){
                vis[nx][ny] = true;
                q.emplace(nx, ny);
                ret++;
            }
        }
    }

    return ret;
}

void solve(){
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }

    int x, y; cin >> x >> y;
    x++; y++;
    c = grid[x][y];
    bfs(x, y);

    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(grid[i][j] == c && !vis[i][j]){
                ans = max(ans, bfs(i, j));
            }
        }
    }

    cout << ans << '\n';
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin >> n >> m){
        solve();
    }

    return 0;
}
