#include <iostream>
using namespace std;

float f1(float x) {
    return x * x;
}

float f2(float x) {
    return 4 * cos(x);
}

int main() {
    float dstep = 0.001,
          x = 0, S = 0;

    while (f2(x) > f1(x)) {
        S += f2(x) * dstep - f1(x) * dstep;
        x += dstep;
    }
    cout << S * 2;
}
