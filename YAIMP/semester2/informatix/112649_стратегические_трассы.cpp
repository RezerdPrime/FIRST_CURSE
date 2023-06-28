#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int g[1000][1000];
int visited1[1000], visited2[1000];
int step = 0;
vector<pair<int, int>> edges;

void dfs(int v, int p) {
    visited1[v] = ++step;
    visited2[v] = step;

    for (int u = 0; u < n; u++) {
        if (g[v][u] && u != p) {     // проверка на наличие пути и на цикл
            if (visited1[u] == 0) { // если вершина не была посещена до этого
                dfs(u, v);
                visited2[v] = min(visited2[v], visited2[u]); // находим самое раннее время посещения соседей этой вершины
                if (visited2[u] > visited1[v]) {            // если соседи были посещены на позднем шаге
                                                           // значит, что соседи связаны только с этой вершиной - значит ребро между этими вершинами - мост
                    edges.push_back(make_pair(min(u, v), max(u, v)));
                }
            }
            else {
                        // если же вершина была посещена до этого, то записываем минимальное значение
                       // между шагом, на котором нашли соседей v и певрое упоминание u
                visited2[v] = min(visited2[v], visited1[u]);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (visited1[i] == 0) {
            dfs(i, -1);
        }
    }

    sort(edges.begin(), edges.end());
    cout << edges.size() << endl;
    for (int i = 0; i < edges.size(); i++) {
        cout << edges[i].first + 1 << " " << edges[i].second + 1 << endl;
    }
}

// https://informatics.msk.ru/mod/statements/view.php?chapterid=112649#1
