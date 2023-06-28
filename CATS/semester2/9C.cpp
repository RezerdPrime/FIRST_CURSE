#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m; fin >> n >> m;

    vector<vector<int>> G(n + 1);
    vector<int> deg(n + 1, 0);
    queue<int> que;
    vector<int> ans;

    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        G[a].emplace_back(b);
        deg[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) que.push(i);
    }

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        ans.emplace_back(v);

        for (int u : G[v]) {
            deg[u]--;
            if (deg[u] == 0) que.push(u);
        }
    }

    if (ans.size() != n) fout << -1;

    else {
        for (int v : ans) fout << v << " ";

        fout << endl;
    }
}
