#include <iostream>
using namespace std;


void DFS(int** graph, int* visited, int v, int n) {

    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 and !visited[i]) {
            DFS(graph, visited, i, n);
        }
    }
}

int main() {
    int N, S, count = 0;
    cin >> N >> S;

    int** graph = (int**)malloc(N * sizeof(int*));

    for (int i = 0; i < N; i++) {
        graph[i] = (int*)malloc(N * sizeof(int));

        for (int j = 0; j < N; j++) cin >> graph[i][j];
    }

    int* visited = (int*)calloc(N, sizeof(int));
    DFS(graph, visited, S - 1, N);
    for (int i = 0; i < N; i++) if (visited[i]) count++;

    cout << count;
}

// https://informatics.msk.ru/mod/statements/view.php?chapterid=164#1
