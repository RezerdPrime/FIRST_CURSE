#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector<int> arr;

bool f(int a, int b) {
    return arr[a] == arr[b] ? a > b : arr[a] > arr[b];
};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m, a, b;
    fin >> n >> m;
    arr.resize(n + m);
    priority_queue<int, vector<int>, decltype(&f)> pq(f);

    for (int i = 0; i < n; i++) {
        fin >> arr[i];
        pq.push(i);
    }

    for (int i = 0; i < m; i++) {
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();

        arr[n + i] = arr[a] + arr[b];
        pq.push(n + i);

        arr[a] = -10001;
        arr[b] = -10001;
    }

    for (int i = 0; i < n + m; i++) {
        if (arr[i] != -10001) {
            fout << arr[i] << ' ';
        }
    }
}
