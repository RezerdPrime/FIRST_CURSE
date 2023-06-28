// --- --- --- #1


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main() {
//
//	srand(time(NULL));
//	int max_el = 0, min_el = 999, k; int* arr;
//
//	scanf_s("%d", &k);
//	arr = (int*)malloc(sizeof(int) * k);
//
//	for (int i = 0; i < k; i++) {
//		arr[i] = rand() % 10;
//		printf("%d  ", arr[i]);
//	}
//
//	printf("\n");
//
//	for (int i = 0; i < k; i++) {
//		if (arr[i] % 2 != 0) {
//			max_el = (arr[i] > max_el) ? arr[i] : max_el;
//		}
//		else {
//			min_el = (min_el > arr[i]) ? arr[i] : min_el;
//		}
//	}
//
//	printf("Max element is: %d\nMin element is: %d\n", max_el, min_el);
//}


// --- --- --- №2


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main() {
//
//	srand(time(NULL));
//
//	int k, negative_sum = 0;
//	int* arr;
//
//	scanf_s("%d", &k);
//	arr = (int*)malloc(sizeof(int) * k);
//
//	for (int i = 0; i < k; i++) {
//		arr[i] = rand() % 10 - 10 * (rand() % 2);
//		printf("%d  ", arr[i]);
//	}
//
//	printf("\n");
//
//	for (int i = 0; i < k; i++) {
//		if (arr[i] < 0) {
//			negative_sum += arr[i];
//		}
//	}
//
//	printf("Sum is: %d\n", negative_sum);
//}


// --- --- --- №3


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main() {
//	int k, prod = 1;
//	int* arr;
//
//	srand(time(NULL)); scanf_s("%d", &k);
//	arr = (int*)malloc(sizeof(int) * k);
//	
//	for (int i = 0; i < k; i++) {
//		arr[i] = rand() % 10;
//		printf("%d) %d\n", i, arr[i]);
//	}
//
//	for (int i = 0; i < k; i++) {
//		if ((i % 2) != 0) {
//			prod *= arr[i];
//		}
//	}
//
//	printf("\n%d\n", prod);
//}


// --- --- --- №4


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//
//int main() {
//	int k, nul_index1 = 11, nul_index2 = 11, sum = 0;
//	int* arr;
//
//	srand(time(NULL)); scanf_s("%d", &k);
//	arr = (int*)malloc(sizeof(int) * k);
//	
//	for (int i = 0; i < k; i++) {
//		arr[i] = rand() % 11;
//		printf("%d) %d\n", i, arr[i]);
//	}
//
//	printf("\n");
//
//	for (int i = 0; i < k; i++) {
//		if (arr[i] == 0) {
//			if (nul_index1 == 11) { nul_index1 = i; }
//
//			else { nul_index2 = i; break; }
//		}
//	}
//
//	if (nul_index1 == 11 or nul_index2 == 11) {
//		printf("\n0\n");
//		return 0;
//	}
//
//	for (int i = nul_index1; i < nul_index2; i++) {
//		sum += arr[i];
//	}
//
//	printf("\nResult is: %d\n", sum);
//}


// --- --- --- №5


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main() {
//	int k, max_value = 0, min_value = 1000;
//	int* arr;
//
//	srand(time(NULL)); scanf_s("%d", &k);
//	arr = (int*)malloc(sizeof(int) * k);
//	
//	for (int i = 0; i < k; i++) {
//		arr[i] = rand() % (k + 1);
//		printf("%d) %d\n", i, arr[i]);
//	}
//
//	for (int i = 0; i < k; i++) {
//		max_value = (arr[i] > max_value) ? arr[i] : max_value;
//
//		min_value = (arr[i] < min_value) ? arr[i] : min_value;
//	}
//
//	printf("\nMinimum is: %d\nMaximum is: %d\n", min_value, max_value);
//}


// --- --- --- №6


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main() {
//	int k, min_value = 1000;
//	int* arr;
//
//	srand(time(NULL)); scanf_s("%d", &k);
//	arr = (int*)malloc(sizeof(int) * k);
//
//	for (int i = 0; i < k; i++) {
//		arr[i] = rand() % (k + 1);
//		printf("%d) %d\n", i, arr[i]);
//	}
//
//	for (int i = 0; i < k; i++) {
//		if (arr[i] < 0) { arr[i] = -arr[i]; }
//		min_value = (arr[i] < min_value) ? arr[i] : min_value;
//	}
//
//	printf("Minimal module is: %d", min_value);
//}


// --- --- --- №7


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main() {
//	int k, count = 0;
//	int* arr; int* arr2;
//
//	srand(time(NULL)); scanf_s("%d", &k);
//	arr = (int*)malloc(sizeof(int) * k);
//	arr2 = (int*)malloc(sizeof(int) * k);
//
//	for (int i = 0; i < k; i++) {
//		arr[i] = arr2[i] = rand() % (k + 1) - k * (rand() % 2);
//		printf("%d) %d\n", i, arr[i]);
//	}
//
//	printf("\nResult is:\n");
//
//	for (int i = 0; i < k; i++) {
//		if (arr[i] == 0) { arr2[count] = 0; printf("%d  ", arr2[count]); count++; }
//	}
//
//	for (int i = 0; i < k; i++) {
//		if (arr[i] != 0) { arr2[count] = arr[i]; printf("%d  ", arr2[count]); count++; }
//	}
//}
