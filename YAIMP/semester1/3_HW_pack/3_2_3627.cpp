#include <iostream>
using namespace std;

int main() {
    int N; double x, a, Result = 0;

    cin >> N >> x >> a;

    if (N == 0) {
        cout << a << endl;
        return 0;
    }

    Result += a * x;
    N -= 1;

    while (N > 0){
        cin >> a;
        Result = (Result + a) * x;
        N -= 1;
    }
    cin >> a; Result += a;

    cout << Result << endl;
}
