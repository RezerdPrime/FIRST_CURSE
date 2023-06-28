#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float f(float x) {
    return x * x * x + 2 * x * x - 8 * x + 1 — 5 * sin(x) - 12 * cos(x);
}

void solution(float a, float b, float e) {
    float x = a;
    float d = 2 * e;
    int counter = 3;

    while (counter) {

        while (f(x) * f(x + d) > 0) {
            x += d;
        }
        cout << fixed << setprecision(3) << "["<<x-d<<"; "<< x +d <<" ] -> " << x + e << endl;
        x += e;
        counter--;
    }
}
