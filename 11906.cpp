//UVA 11906 - Knight in a War Grid
//やった！

#include <bits/stdc++.h>

using namespace std;

const int N = 102;
bool water[N][N];
bool vis[N][N];

int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
int r, c, m, n;

bool ok(int x, int y){
    return (0 <= x && x < r && 0 <= y && y < c && !water[x][y]);
}

void solve(){
    cin >> r >> c >> m >> n;
    memset(water, 0, sizeof(water));
    memset(vis, 0, sizeof(vis));

    int w; cin >> w;

    while(w--){
        int x, y; cin >> x >> y;
        water[x][y] = true;
    }

    int odd = 0, even = 0;

    queue<pair<int, int>>q;
    q.emplace(0, 0); vis[0][0] = true;

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        set<pair<int, int>>s;
        for(int i = 0; i < 4; i++){
            int nx = x + (n * dx[i]);
            int ny = y + (m * dy[i]);

            if(ok(nx, ny)){
                if(!vis[nx][ny]){
                    vis[nx][ny] = true;
                    q.emplace(nx, ny);
                }

                s.insert({nx, ny});
            }

            nx = x + (m * dx[i]);
            ny = y + (n * dy[i]);

            if(ok(nx, ny)){
                if(!vis[nx][ny]){
                    vis[nx][ny] = true;
                    q.emplace(nx, ny);
                }

                s.insert({nx, ny});
            }
        }

        if(s.size() & 1) odd++;
        else even++;
    }

    cout << even << " " << odd << '\n';
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;

    for(int i = 1; i <= tc; i++){
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}
