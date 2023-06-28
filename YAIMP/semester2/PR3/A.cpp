#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float f(float x) { return x * x; }

int main() {
	float dstep = 0.1,
		  len = 0, x = 0;

	while (x <= 10) {

		len += sqrt( (f(x + dstep) - f(x)) * (f(x + dstep) - f(x)) + (dstep * dstep) );
		x += dstep;
	}
	cout << len;
}
