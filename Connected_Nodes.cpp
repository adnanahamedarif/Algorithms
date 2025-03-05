#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005]; 

int main() {
    int n, e;
    cin >> n >> e; 

    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        sort(adj_list[i].rbegin(), adj_list[i].rend());
    }

    int q;
    cin >> q; 

    while (q--) {
        int n;
        cin >> n; 

        if (adj_list[n].empty()) {
            cout << "-1" << endl;
        } else {
            for (int x : adj_list[n]) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
