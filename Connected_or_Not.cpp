#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;  
    cin >> n >> m;  

    unordered_map<int, unordered_set<int>> adj;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
    }

    int q;
    cin >> q;

    while (q--) {
        int a, b;
        cin >> a >> b;

        if (a == b || adj[a].count(b))  
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
