#include <iostream>
using namespace std;

int main() {
    int v, t;
    cin >> v >> t;

    if (v > 0)
    {
        cout << (v*t)%109 << endl;
    }
    if (v < 0)
    {
        cout << (109-(-v*t)%109)%109 << endl;
    }
}
