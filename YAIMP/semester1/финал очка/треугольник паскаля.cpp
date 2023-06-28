#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m; // н - количество строк, м - количество элементов в строке

    auto arr = (int*)calloc(n * m, sizeof(int));

    for (int i = 0; i < m; ++i) { arr[i] = 1; }
    for (int i = 0; i < n; ++i) { arr[m * i] = 1; }

    for (int i = m + 1; i < n * m; ++i) {
        if (i % m != 0) {
            arr[i] = arr[i - 1] + arr[i - m];
        }
    }

    for (int i = 0; i < n * m; ++i) {
        cout << "\t" << arr[i] << " ";
        if ((i + 1) % m == 0) cout << endl;
    }
}
