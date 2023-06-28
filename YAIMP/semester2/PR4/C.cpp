#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

float f(float x) {
    return 3. / 2 * sqrt(4 - x * x);
}

int main() {
    float dstep = 0.23,
          S = 0, x = 0;

    while (x < 2 and (x + dstep) * (x + dstep) < 4) {
        S += f(x) * dstep;
        x += dstep;
    }

    float disk = S * 4 - 2 * dstep;
    float formul = M_PI * 6;

    cout << disk << " " << formul << "\n\n";
    cout << (formul - disk) / formul * 100 << "%" << endl;
}
