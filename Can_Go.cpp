#include <bits/stdc++.h>
using namespace std;

char grid[105][105]; 
bool vis[105][105];   
int level[105][105];  

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
int n, m;

bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) 
    return false; 
    if (grid[i][j] == '#')
     return false; 
    return true;
}

bool bfs(int si, int sj, int di, int dj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == di && y == dj) 
        return true; 
        for (auto [dx, dy] : d) {
            int nx = x + dx, ny = y + dy;
            if (valid(nx, ny) && !vis[nx][ny]) {
                q.push({nx, ny});
                vis[nx][ny] = true;
                level[nx][ny] = level[x][y] + 1;
            }
        }
    }
    return false; 
}

int main() {
    cin >> n >> m;
    
    int si, sj, di, dj;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') si = i, sj = j;
            if (grid[i][j] == 'B') di = i, dj = j;
        }
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));

    if (bfs(si, sj, di, dj)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
