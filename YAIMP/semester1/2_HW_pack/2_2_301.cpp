#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, D, x1, x2; cin >> a >> b >> c;

    D = pow(b, 2) - (4 * a * c);

    if (D < 0) { return 0; }

    if (D == 0) {
        x1 = -b / (2 * a); x1 = (x1 == 0) ? abs(x1) : x1;
        cout << x1 << endl;
        return 0;
    }

    if (D > 0) {
        x1 = (-b + sqrt(D)) / (2 * a); x1 = (x1 == 0) ? abs(x1) : x1;
        x2 = (-b - sqrt(D)) / (2 * a); x2 = (x2 == 0) ? abs(x2) : x2;

        cout << x1 << " " << x2 << endl;
        return 0;
    }
}
