//UVA 11624 - Fire!
//やった！

#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
char grid[N][N];
bool fire[N][N];
int t[N][N];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
deque<pair<int, int>>q;

int r, c;

bool check(int x, int y){
    return (x >= 1 && x <= r && y >= 1 && y <= c);
}

int bfs(){
    while(!q.empty()){
        auto now = q.front(); q.pop_front();

        if(fire[now.first][now.second]){
            for(int i = 0; i < 4; i++){
                int nx = now.first + dx[i];
                int ny = now.second + dy[i];

                if(check(nx, ny) && !fire[nx][ny]){
                    fire[nx][ny] = true;
                    q.emplace_back(nx, ny);
                }
            }
        } else{
            if(now.first == 1 || now.first == r || now.second == 1 || now.second == c) return t[now.first][now.second] + 1;
            
            for(int i = 0; i < 4; i++){
                int nx = now.first + dx[i];
                int ny = now.second + dy[i];
                
                if(check(nx, ny) && !fire[nx][ny] && grid[nx][ny] == '.' && t[nx][ny] == -1){
                    t[nx][ny] = t[now.first][now.second] + 1;
                    q.emplace_back(nx, ny);
                }
            }
        }
    }

    return -1;
}

void solve(){
    q.clear();
    cin >> r >> c;

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> grid[i][j];
            fire[i][j] = false;
            t[i][j] = -1;

            if(grid[i][j] == 'F'){
                q.emplace_back(i, j);
                fire[i][j] = true;
            } else if(grid[i][j] == 'J'){
                q.emplace_front(i, j);
                t[i][j] = 0;
            }
        }
    }

    int ans = bfs();

    if(ans == -1)
        cout << "IMPOSSIBLE" << endl;
    
    else
        cout << ans << endl;
}

int main(){
    int tc; cin >> tc;

    while(tc--){
        solve();
    }

    return 0;
}
