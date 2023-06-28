#include <iostream>
using namespace std;

float f(float x) {
    return x * x;
}

int main() {
    float dstep = 0.001,
          x = 0, S = 0;

    while (x <= 10) {
        S += f(x) * dstep;
        x += dstep;
    }

    cout << S;
}
