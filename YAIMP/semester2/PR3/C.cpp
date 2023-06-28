#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

float f(float x) {
    return 3. / 2 * sqrt(4 - x * x);
}

float sol() {
	float dstep = 0.05,
		  len = 0, x = 0;

	while (x <= 2 and (x + dstep) * (x + dstep) < 4) {

		len += sqrt((f(x + dstep) - f(x)) * (f(x + dstep) - f(x)) + (dstep * dstep));
		x += dstep;
	}
	//cout << len * 4 << endl;
	return len * 4;
}

int main() {
	float disk = sol();
	float ram = M_PI * (15 - sqrt(99));

	cout << disk << " " << ram << endl;
	cout << (ram - disk) / ram * 100 << "%";
}
