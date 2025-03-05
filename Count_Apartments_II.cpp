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

int dfs(int si, int sj) {
    stack<pair<int, int>> s;
    s.push({si, sj});
    vis[si][sj] = true;
    int roomCount = 1;  
    while (!s.empty()) {
        auto [x, y] = s.top();
        s.pop();

        for (auto [dx, dy] : d) {
            int nx = x + dx, ny = y + dy;
            if (valid(nx, ny) && !vis[nx][ny] && grid[nx][ny] == '.') {
                s.push({nx, ny});
                vis[nx][ny] = true;
                roomCount++;  
            }
        }
    }
    return roomCount;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));
    vector<int> a;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !vis[i][j]) {
                int r = dfs(i, j);
                a.push_back(r);
            }
        }
    }

    if (a.empty()) {
        cout << endl;  
    } else {
        sort(a.begin(), a.end());  
        for (int size : a) {
            cout << size << " ";
        }
        cout << endl;
    }

    return 0;
}
