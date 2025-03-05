#include <bits/stdc++.h>
using namespace std;

char grid[105][105];  
bool vis[105][105];   

vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
int n, m;

bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return false; 
    if (grid[i][j] == '#') return false; 
    return true;
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : d) {
            int nx = x + dx, ny = y + dy;
            if (valid(nx, ny) && !vis[nx][ny] && grid[nx][ny] == '.') {
                q.push({nx, ny});
                vis[nx][ny] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    int a = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                bfs(i, j);
                a++; 
            }
        }
    }

    cout << a << endl;
    return 0;
}
