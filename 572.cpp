//UVA 572 - Oil Deposits
//やった！

#include <bits/stdc++.h>

using namespace std;

const int N = 102;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
char grid[N][N];
bool vis[N][N];
int n, m;

bool ok(int x, int y){
    return (1 <= x && x <= n && 1 <= y && y <= m && grid[x][y] == '@' && !vis[x][y]);
}

void bfs(int x, int y){
    queue<pair<int, int>>q;
    q.emplace(x, y); vis[x][y] = true;

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(ok(nx, ny)){
                vis[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin >> n >> m){
        if(m == 0) break;
        memset(vis, 0, sizeof(vis));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++)
                cin >> grid[i][j];
        }
        
        int ans = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(grid[i][j] == '@' && !vis[i][j]){
                    bfs(i, j);
                    ans++;
                }
            }
        }
        
        cout << ans << '\n';
    }

    return 0;
}
