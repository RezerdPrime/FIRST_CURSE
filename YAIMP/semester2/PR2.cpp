#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f(float x) {
    return x * x * x + 2 * x * x - 8 * x + 1 - 5 * sin(x) - 12 * cos(x);
}

void sol(float left_, float right_, float eps) {

    float delta = 2 * eps, mid,
          left = left_, 
          right = right_;
    bool cond = 0;

    if ((right - left) / 2 > delta) {
        
        while (right - left > delta) {
            mid = (right + left - eps / 5) / 2;

            if (f(right) * f(mid) <= 0) left = mid, cond = 0;
            else right = mid, cond = 1;
        }
        //cout << f(right) << " " << f(left) << " // " << right << " " << left << "\n";

        if (f(right) * f(left) <= 0) {
            cout << fixed << setprecision(3) << " [" << left << "; " << right + eps << "] -=> " << (left + right + eps) / 2 << "\n\n";

            if (!cond) sol(left + eps, 5, 0.001);
            else sol(-5, right - eps, 0.001);
        }
    }
}

int main() { //-4.133 -0.638 1.941
    sol(-5, 5, 0.001);
}
