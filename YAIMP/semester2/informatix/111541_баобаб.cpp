#include <iostream>
using namespace std;

int N;
bool graph[100][100];
bool visited[100];

void dfs(int v, int parent) {
    visited[v] = true;

    for (int i = 0; i < N; i++) {
        if (graph[v][i]) {

            if (i == parent) continue;

            if (visited[i]) {
                cout << "NO";
                exit(0);
            }
            dfs(i, v);
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    dfs(0, -1);

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}

// https://informatics.msk.ru/mod/statements/view.php?chapterid=111541#1
