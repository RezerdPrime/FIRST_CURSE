#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c, Discr, x1, x2; cin >> a >> b >> c;

    if (a == 0 and b == 0 and c == 0) {
        cout << 3 << endl;
        return 0;
      
    } else if (a == 0 and b == 0 and c != 0) { cout << 0 << endl; return 0; }

    if (a == 0 and b != 0){
        x1 = -c / b;
        cout << 1 << " " << x1 << endl;
        return 0;
    }

    Discr = pow(b, 2) - 4 * a * c;

    if (Discr == 0){
        x1 = -b / (2 * a);
        cout << 1 << " " << x1 << endl;
        return 0;
    }

    if (Discr < 0){
        cout << 0 << endl;
        return 0;
    }

    if (Discr > 0){
        x1 = (-b + sqrt(Discr)) / (2 * a);
        x2 = (-b - sqrt(Discr)) / (2 * a);

        cout << 2 << " " << min(x1, x2) << " " << max(x1, x2) << endl;
        return 0;
    }
}
