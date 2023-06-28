// --- --- --- --- --- #1


//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//
//int main() {
//	int* arr; int size, sum = 0, prod = 1;
//
//	srand(time(NULL));
//
//	scanf_s("%d", &size);
//
//	arr = (int*)malloc(sizeof(int) * size);
//
//	for (int i = 0; i < size; i++) {
//		arr[i] = rand() % 11 - 10 * (rand() % 2);
//		printf("%d) %d\n", i, arr[i]);
//
//		if (arr[i] > 0) {
//			sum += arr[i];
//		}
//
//		if (arr[i] != 0) {
//			prod *= arr[i];
//		}
//
//		//printf("\nel: %d\t<>\ts: %d\t<>\tp: %d\n\n", arr[i], sum, prod);///
//	}
//
//	printf("Sum: %d\nProd: %d\n", sum, prod);
//}


// --- --- --- --- --- #2


//#include <stdio.h>
//
//int main() {
//	int arr[10], Increase = 0, Decrease = 9;
//
//	for (int i = 0; i < 10; i++) {
//		printf("%d) ", i); scanf_s("%d", &arr[i]); printf("\n");
//	}
//
//	for (int i = 0; i < 9; i++) {
//		if (arr[i] < arr[i + 1]) {
//			Increase++;
//		}
//
//		if (arr[i] > arr[i + 1]) {
//			Decrease--;
//		}
//	}
//
//	if (Increase == 9 or Decrease == 0) {
//		printf("\nThe array is ordered\n");
//	} else { printf("\nThe array isn't ordered\n"); }
//}


// --- --- --- --- --- #3


//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//
//int main() {
//	int* arr; int m = 0, i1 = 100, i2 = 0, b, random_size;
//
//	srand(time(NULL)); random_size = 5 + rand() % 6;
//
//	arr = (int*)malloc(sizeof(int) * random_size);
//
//	for (int j = 0; j < random_size; j++) {
//		arr[j] = rand() % 11;
//		printf("%d) %d\n", j, arr[j]);
//	}
//
//	scanf_s("%d", &b);
//
//	for (int j = 0; j < random_size; j++) {
//		if (arr[j] == b) {
//			m++;
//			i1 = (i1 > j) ? j : i1;
//			i2 = (i2 < j) ? j : i2;
//		}
//	}
//
//	if (m > 0) {
//		printf("m = %d\ni1 = %d\ni2 = %d\n", m, i1, i2);
//	}
//	else { printf("Element 'b' not found\n"); }
//}


// --- --- --- --- --- #4


//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//
//int main() {
//	int arr[10], arr2[] = { 0,0,0,0,0,0,0,0,0,0 }, count = 0;
//
//	srand(time(NULL));
//
//	for (int i = 0; i < 10; i++) {
//		arr[i] = rand() % 6 - 5 * (rand() % 2);
//
//		if (arr[i] != 0) {
//			arr2[count] = arr[i];
//
//			count++;
//		}
//	}
//
//	printf("%d\t<>\t%d\n%d\t<>\t%d\n%d\t<>\t%d\n%d\t<>\t%d\n%d\t<>\t%d\n", 
//		arr[0], arr2[0], arr[1], arr2[1], arr[2], arr2[2], arr[3], arr2[3], arr[4], arr2[4]);
//
//	printf("%d\t<>\t%d\n%d\t<>\t%d\n%d\t<>\t%d\n%d\t<>\t%d\n%d\t<>\t%d\n", 
//		arr[5], arr2[5], arr[6], arr2[6], arr[7], arr2[7], arr[8], arr2[8], arr[9], arr2[9]);
//
//	/*for (int i = 0; i < 10; i++) {
//		printf("%d\t<>\t%d\n", arr[i], arr2[i]);
//	}*/
//}


// --- --- --- --- --- #5


//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//
//int main() {
//	int arr[10], m, reserve, count = 1, index;
//
//	srand(time(NULL));
//
//	for (int i = 0; i < 10; i++) {
//		arr[i] = rand() % 11 - 10 * (rand() % 2);
//		printf("%d  ", arr[i]);
//	} printf("\n");
//
//	scanf_s("%d", &m);
//
//	while (1) {
//
//		switch (m) {
//
//		case(1):
//			for (int i = 0; i < 9; i++) {
//				if (arr[i] > arr[i + 1]) {
//					reserve = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = reserve;
//				}
//			} break;
//
//		case(-1):
//			for (int i = 0; i < 9; i++) {
//				if (arr[i] < arr[i + 1]) {
//					reserve = arr[i]; arr[i] = arr[i + 1]; arr[i + 1] = reserve;
//				}
//			} break;
//
//		case(2):
//			for (int i = 0; i < 10; i++) {
//				index = i;
//
//				for (int j = i + 1; j < 10; j++) {
//					if (arr[index] > arr[j]) {
//						index = j;
//					}
//				}
//				reserve = arr[index];
//				arr[index] = arr[i];
//				arr[i] = reserve;
//			} break;
//
//		case(-2):
//			for (int i = 0; i < 10; i++) {
//				index = i;
//
//				for (int j = i + 1; j < 10; j++) {
//					if (arr[index] < arr[j]) {
//						index = j;
//					}
//				}
//				reserve = arr[index];
//				arr[index] = arr[i];
//				arr[i] = reserve;
//			} break;
//
//		default: printf("\n\nevent.ERROR\n\n"); return 0;
//		}
//
//		for (int j = 0; j <= 8; j++) {
//			if ((m < 0 and arr[j] >= arr[j + 1]) or (m > 0 and arr[j] <= arr[j + 1])) {
//				count++;
//			}
//		}
//
//		if (count == 9) {
//			for (int i = 0; i < 10; i++) {
//				printf("%d  ", arr[i]);
//			} printf("\n\n\n"); return 0;
//		} count = 0;
//	}
//}


// --- --- --- --- --- #6


//#include <stdio.h>
//
//int main() {
//	int arr[21], b, a, l_pos = 0, r_pos = 21, mid_pos;
//
//	printf("Set function arg: "); scanf_s("%d", &a); printf("\n");
//
//	for (int i = 0; i <= 20; i++) {
//		arr[i] = i * i * a - 1 * i;
//
//		printf("%d ", arr[i]);
//	} printf("\n\n");
//
//	printf("Set the sought array element: "); scanf_s("%d", &b); printf("\n");
//
//	while (l_pos <= r_pos) {
//		mid_pos = (l_pos + r_pos) / 2;
//
//		if (b < arr[mid_pos]) {
//			r_pos = mid_pos - 1;
//		}
//		else if (b > arr[mid_pos]) {
//			l_pos = mid_pos + 1;
//		}
//		else if (b == arr[mid_pos]) {
//			printf("\nIndex is: %d\n", mid_pos); return 0;
//		}
//	}
//
//	printf("\n- event.ERROR -\nThe sought array element does not exist in your array\n\n");
//}


// --- --- --- --- --- #7


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#include <utility> // Потому что мне лень проводить замену через резервную переменную
//using std::swap; // Волшебная функция, которая меняет местами значения (если они одинакового типа)
//
//int* arr;
//
//int arr_print(int k) { // Потому что не хочу вводить велик в конце просто для разового вывода массива (плюс тест простейшей функции)
//
//	for (int i = 0; i < k; i++) {
//		printf("%d ", arr[i]);
//	} printf("\n");
//
//	return 0;
//}
//
//int main() {
//	int k; scanf_s("%d", &k);
//
//	srand(time(NULL));
//
//	arr = (int*)malloc(sizeof(int) * k);
//
//	for (int i = 0; i < k; i++) {
//		arr[i] = rand() % 11;
//	}
//
//	arr_print(k);
//
//	for (int i = 0; i < (k / 2); i++) { swap(arr[i], arr[k - 1 - i]); }
//
//	arr_print(k);
//}


// --- --- --- --- --- #8


//#include <stdio.h>
//
//int main() {
//	int arr[32], a, q;
//
//	printf("Set integer: "); scanf_s("%d", &a); printf("\n"); a = (a < 0) ? -a : a;
//	printf("Set number system: "); scanf_s("%d", &q); printf("\n");
//
//	if (q < 2) { printf("\n\n\t\t- event.ERROR -\n\tNumber system should be more than 1\n\n"); return 0; }
//
//	for (int i = 31; i > 0; i--) {
//		arr[i] = a % q;
//		a /= q;
//		//printf("\n%d\n", a);
//	}
//
//	for (int i = 1; i < 32; i++) {
//		printf("%d ", arr[i]);
//	} printf("\n");
//}


// --- --- --- --- --- #9


//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int a, b, q, arr_size = 0, res, res2, condit = 1;
//
//	printf("Set begin, end, num system: \n");
//	scanf_s("%d %d %d", &a, &b, &q); printf("\n");
//
//	int* arr;
//
//	for (int i = a; i <= b; i++) {
//		res = res2 = i;
//
//		while (res > 0) {
//			res /= q; arr_size++;
//		}
//
//		arr = (int*)malloc(sizeof(int) * arr_size);
//
//		for (int i = arr_size; i > 0; i--) {
//			arr[i] = res2 % q;
//			res2 /= q;
//		}
//
//		for (int l = 1; l <= (arr_size / 2); l++) {
//			if (arr[l] != arr[arr_size + 1 - l]) {
//				condit = 0;
//			}
//		}
//
//		if (condit == 1) {
//			printf("%d - ", i);  for (int j = 1; j <= arr_size; j++) { printf("%d ", arr[j]); } printf("\n");
//		}
//		condit = 1;
//		arr_size = 0;
//	}
//}


// --- --- --- --- --- #10


//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//	int arr_size; int* arr;
//
//	scanf_s("%d", &arr_size);
//
//	arr = (int*)malloc(sizeof(int) * arr_size);
//
//	for (int i = 1; i < arr_size; i++) {
//		arr[i] = i + 1;
//		printf("%d  ", arr[i]);
//	} printf("\n\n\n\n");
//
//	for (int i = 2; i < arr_size; i++) {
//		for (int j = 2; j < arr_size; j++) {
//
//			if ((arr[j] != 0) and (arr[j] % i == 0) and (arr[j] != i)) {
//				arr[j] = 0;
//			}
//		}
//	}
//
//	for (int i = 1; i < arr_size; i++) {
//		if (arr[i] != 0) {
//			printf("%d  ", arr[i]);
//		}
//	} printf("\n\n\n");
//}
