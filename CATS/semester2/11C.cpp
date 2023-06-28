#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 2147483647;

int main() {
    ofstream fout("output.txt");
    ifstream fin("input.txt");

    int n, m, s;
    fin >> n >> m >> s;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    vector<int> dist(n + 1, INF);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d != dist[u]) continue;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) fout << " ";
        else fout << dist[i] << " ";
        //fout << endl;
    }
}
// нахуй идет ваш форд беллман, дейкстра ебашит
