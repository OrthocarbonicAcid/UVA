//UVA 352 - The Seasonal War
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

int solve(){
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c; cin >> c;
            grid[i][j] = (c == '1');
        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(grid[i][j] && !vis[i][j]){
                bfs(i, j);
                ans++;
            }
        }
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int i = 1;

    while(cin >> n){
        cout << "Image number " << i++ << " contains " << solve() << " war eagles." << '\n';
    }

    return 0;
}
