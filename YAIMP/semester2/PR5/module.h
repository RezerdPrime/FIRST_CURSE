#include <iostream>
#include <iomanip>
#include <numbers>
#define phi 1.618033988749895
using namespace std;


float f(float x) {
	return x * x * x + 2 * x * x - 8 * x + 1 - 5 * sin(x) - 12 * cos(x); // max:(-2.601,30.604) min:( 0.691,-15.677)
}


void С_task(float a_, float b_, float eps, bool cond) {
	float a = a_, b = b_;

	while (fabs(b - a) > eps) {

		float x1 = b - (b - a) / phi,
			  x2 = a + (b - a) / phi,
			y1 = f(x1) * (cond ? 1 : -1), y2 = f(x2) * (cond ? 1 : -1);
		
		if (y1 >= y2) a = x1;
		else b = x2;
	}

	if (!cond) cout << " Max is:\n\n";
	else cout << " Min is:\n\n";

	cout << fixed << setprecision(3);

	cout << "   x = " << (a + b) / 2 - eps / 3 << endl
	     << "   y = " << f((a + b) / 2 - eps) << "\n\n"
	     << "   [" << a - eps << "; " << b + eps << "]\n\n";
}
