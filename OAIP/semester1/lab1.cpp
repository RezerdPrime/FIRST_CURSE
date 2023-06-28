//--------------------------------------------------------------------------------------№1
//
//#include <stdio.h>
//
//int main() {
//	int num;
//	scanf_s("%d", &num);
//
//	if (num / 100 != 0){
//		num = num % 100;
//	}
//
//	if (num % 10 > num / 10) {
//		printf("%d is more; %d is less", num % 10, num /10);
//
//	}
//	else {
//		printf("%d is more; %d is less", num / 10, num % 10);
//	}
//}
//
//--------------------------------------------------------------------------------------№2
//
//#include <stdio.h>
//
//int main() {
//	int num;
//
//	scanf_s("%d", &num);
//
//	if (num > 10) {
//		printf("it's a very big number, plz set num <= 10\n");
//		return 0;
//	}
//
//	for (int i = num-1; i > 0; i--) {
//		num *= i;
//	}
//
//	printf("result is: %d", num);
//}
//
//
//--------------------------------------------------------------------------------------№3
//
//#include <stdio.h>
//#include <cmath>
//
//int main(){
//	int n, k, result = 0;
//
//	printf("\nset count of elements: ");
//	scanf_s("%d", &n);
//
//	printf("\nset powers value: ");
//	scanf_s("%d", &k);
//
//	for (int i = 1; i < n+1; i++) {
//		result += pow(i, k);
//	}
//
//	printf("%d", result); //1^3 + 2^3 + 3^3 = 1 + 8 + 27
//}
//
//
//--------------------------------------------------------------------------------------№4
//
//#include <stdio.h>
//#include <math.h>
//
//int main() {
//	float a, b;
//	int sym;
//
//	printf("set zwei numbers: \n");
//	scanf_s("%f", &a); scanf_s("%f", &b);
//
//	printf("set number of math operation\n1) +\n2) - \n3) *\n4) /\n5) ^\n");
//	scanf_s("%d", &sym);
//
//	switch (sym) {
//		case (1): {
//			printf("%f + %f = %f", a, b, a + b);
//			break;
//		}
//		case (2): {
//			printf("%f - %f = %f", a, b, a - b);
//			break;
//		}
//		case (3): {
//			printf("%f * %f = %f", a, b, a * b);
//			break;
//		}
//		case (4): {
//			if (b == 0) {
//				printf("error: division by zero\n");
//				break;
//			}
//			else {
//				printf("%f / %f = %f", a, b, a / b);
//				break;
//			}
//		}
//		case (5): {
//			printf("%f ^ %f = %f", a, b, pow(a,b));
//			break;
//		}
//	}
//}
//
//
//--------------------------------------------------------------------------------------№5
//
//#include <stdio.h>
//#include <math.h>
//
//int main() {
//	printf("ax^2 + bx + c = 0\n");
//
//	float a, b, c, discr, x1, x2;
//	printf("set a, b, c arguments:\n");
//
//	scanf_s("%f", &a); scanf_s("%f", &b); scanf_s("%f", &c);
//
//	if (a == 0) {
//		printf("this is already a linear equation\n");
//		return 0;
//	}
//
//	discr = pow(b, 2) - (4 * a * c);
//	printf("discriminant is: %f\n", discr);
//
//	if (discr == 0) {
//		x1 = (-b + pow(discr, 0.5)) / (2 * a);
//		printf("only one solution: %f\n", x1); /// 4 4 1
//		return 0;
//	}
//	if (discr > 0) {
//		x1 = (-b + pow(discr, 0.5)) / (2 * a); x2 = (-b - pow(discr, 0.5)) / (2 * a);
//		printf("two solutions: %f and %f\n", x1, x2); /// 1 5 6
//		return 0;
//	}
//	if (discr < 0) {
//		printf("no solutions\n"); /// 1 1 1
//		return 0;
//	}
//}
//
//
//
//--------------------------------------------------------------------------------------№6
//
//note: https://www.desmos.com/ can be helpful
//
//#include <stdio.h>
//#include <math.h>
//
//int main() {
//	float a1, b1, c1, a2, b2, xfl; bool condition = false;
//	printf("y = a1 * x^2 + b1 * x + c1\ny = a2 * x + b2\n\nset a1, b1, c1: ");
//
//	scanf_s("%f", &a1); scanf_s("%f", &b1); scanf_s("%f", &c1);
//
//	printf("set a2, b2: ");
//
//	scanf_s("%f", &a2); scanf_s("%f", &b2);
//
//
//	for (int x = -100000; x < 100000; x++) {
//		xfl = x * 0.0001;
//		//printf("%f <> %f <> %f\n", round((a1 * pow(xfl, 2) + b1 * xfl + c1) * 100) / 100, round((a2 * xfl + b2) * 100) / 100, xfl);///
//		if (round((a1 * pow(xfl,2) + b1 * xfl + c1) * 100) / 100 == round((a2 * xfl + b2) * 100) / 100){
//			condition = true;
//			break;
//		}
//	}
//
//	if (condition == true) {
//		printf("yes\n");
//	}
//	else {
//		printf("no\n");
//	}
//}
// 
// 
// 
//--------------------------------------------------------------------------------------№7
//
//#include <stdio.h>
//
//int main() {
//
//	int a, n, A = 1;
//	scanf_s("%d", &a); scanf_s("%d", &n);
//
//	for (int i = 1; i < n+1; i++) {
//		A *= a;
//		if (A < 0) {
//			printf("error.event_: DATA_OVERFLOW\n"); return 0;
//		}
//	}
//	printf("%d", A);
//}
// 
// 
// 
//--------------------------------------------------------------------------------------№8
//
//#include <stdio.h>
//using namespace std;
//
//int main() {
//    int a, b;
//    scanf_s("%d", &a); scanf_s("%d", &b);
//    int maximum = (a > b) ? a : b, minimum = (a < b) ? a : b;
//
//    while ((maximum > 0) and (minimum > 0))
//    {
//        maximum %= minimum; a = maximum; b = minimum;
//        maximum = (a > b) ? a : b;
//        minimum = (a < b) ? a : b;
//    }
//    printf("%d", maximum);
//}
//
//
//
//--------------------------------------------------------------------------------------№9
//
//#include <stdio.h>
//#include <math.h>
//
//int main() {
//
//	int m, num, count = 0, condition;
//	scanf_s("%d", &m); printf("List of %d prime numbers: \n\n", m);
//
//	for (num = 2; num <= 1000000000; num++) {
//		condition = 1;
//		for (int i = 2; i <= sqrt(num); i++) {
//			if (num % i == 0) {
//				condition = 0;
//			}
//		}
//
//		if (condition == 1) {
//			printf("%d)  %d\n\n", count+1, num);
//			count++;
//		}
//
//		if (count == m) {
//			return 0;
//		}
//	}
//}
