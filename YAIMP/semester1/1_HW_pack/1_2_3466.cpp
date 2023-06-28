#include <iostream>
using namespace std;

int main() {
    int a, b, l ,N;
    cin >> a >> b >> l >> N;

    cout << 2 * (l + b * (N-1)) + a * (2*N - 1) << endl;
}
