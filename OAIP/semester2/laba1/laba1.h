#include <iostream>
using namespace std;

int sw_count = 0, co_count = 0;

int max(int* arr, int begin, int end) {
	int max = -2147483648, ind = 0;
	
	for (int i = begin; i < end; i++) {
		co_count++;

		if (arr[i] > max) { 
			max = arr[i];
			ind = i;
			co_count++;
		}
	}
	return ind;
}


// #1 // ============================================================================================ //

void _1() { // O(N^2)
	int N; cout << "Size of the array: "; cin >> N;
	int* arr = new int[N];

	int cur_ind = 0;
	
	cout << "Elements of the array: \n";
	for (int i = 0; i < N; i++) { cin >> arr[i]; } cout << endl;

	for (int i = 0; i < N; i++) { swap(arr[i], arr[max(arr, i, N)]); sw_count++; }
	
	for (int i = 0; i < N; i++) { cout << arr[i] << " "; } cout << endl;
	
	for (int i = N - 1; i >= 0; i--) { cout << arr[i] << " "; } cout << endl;

	cout << "\nSwaps count: " << sw_count << "\nComparisons count: " << co_count << endl;
}


// #2 // ============================================================================================ //

void _2(bool cond) { // O(max_el - min_el) у меня max_el == 100

	int N; cout << "Size of the array: "; cin >> N;
	int* arr = new int[N];
	int sorted[100] = {};

	cout << "Elements of the array: \n";
	for (int i = 0; i < N; i++) { 
		cin >> arr[i]; 
		sorted[arr[i]]++;
	} cout << endl;

	if (cond) {
		for (int i = 0; i < 100; i++) {
			if (sorted[i]) {
				while (sorted[i]) {
					cout << i << " ";
					sorted[i]--;
				}
			} 
		} cout << "\n\n";
	}

	else {
		for (int i = 99; i > -1; i--) {
			if (sorted[i]) {
				while (sorted[i]) {
					cout << i << " ";
					sorted[i]--;
				}
			}
		} cout << "\n\n";
	}
}


// #3 // ============================================================================================ //

struct Bucket {
	int arr_[10];
	int index = 0;
};

void _3() { // ~ O(N^2)
	int N; cout << "Size of the array: "; cin >> N;
	int* narr = new int[N];

	cout << "Elements of the array: \n";
	for (int i = 0; i < N; i++) {
		cin >> narr[i];
	} cout << endl;

	Bucket* Musor = new Bucket[narr[max(narr, 0, N)] / 10 + 1];

	for (int i = 0; i < N; i++) {
		Musor[narr[i] / 10].arr_[Musor[narr[i] / 10].index] = narr[i];

		// Musor[narr[i] % 5].arr_[ ... ]  ->  обращение к массиву конкретного ведра
		// Musor[narr[i] % 5].index        ->  обращение к индексу текущей свободной ячейки

		Musor[narr[i] / 10].index++;
	}

	for (int i = 0; i < narr[max(narr, 0, N)] / 10 + 1; i++) {
		for (int j = 0; j < 10; j++) {
			swap(Musor[i].arr_[j], Musor[i].arr_[max(Musor[i].arr_, j, 10)]);
		}
	} cout << endl;

	for (int i = 0; i < narr[max(narr, 0, N)] / 10 + 1; i++) {
		for (int j = Musor[i].index - 1; j > -1; j--) {
			cout << Musor[i].arr_[j] << " ";
		}
	} cout << endl;

	for (int i = narr[max(narr, 0, N)] / 10; i > -1; i--) {
		for (int j = 0; j < Musor[i].index; j++) {
			cout << Musor[i].arr_[j] << " ";
		}
	} cout << endl;
}


// #4 // ============================================================================================ //

void _4() { // O(N * k) у меня k == 3
	int N; cout << "Size of the array: "; cin >> N;
	int* narr = new int[N];

	cout << "Elements of the array: \n";
	for (int i = 0; i < N; i++) {
		cin >> narr[i];
	} cout << endl;

	short cond = 0;
	Bucket* Garbage = new Bucket[3];

	for (int i = 0; i < N; i++) {
		cond = (narr[i] / 100 > 0) ? 2 : ( (narr[i] / 10 > 0) ? 1 : 0 );

		Garbage[cond].arr_[Garbage[cond].index] = narr[i]; Garbage[cond].index++;
	}

	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 10; i++) {
			swap(Garbage[k].arr_[i], Garbage[k].arr_[max(Garbage[k].arr_, i, 10)]);
		}
	} cout << endl;

	int self_index = 0;

	for (int k = 2; k > -1; k--) {
		for (int i = 0; i < Garbage[k].index; i++) {
			cout << Garbage[k].arr_[i] << " ";
			narr[self_index] = Garbage[k].arr_[i];
			self_index++;
		}
	} cout << "\n\n";

	for (int k = N - 1; k > -1; k--) {
		cout << narr[k] << " ";
	} cout << endl;
}


// #5 // ============================================================================================ //

void arrout(int arr[], int count, bool cond) { // cond != 0 по возрастанию
											  //  cond == 0 по убыванию
	if (cond) {
		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}
	}

	else {
		for (int i = count - 1; i > -1; i--) {
			cout << arr[i] << " ";
		}
	} cout << "\n\n";
}

void conversion(int arr[], int number, int index) { // распиши лучше ченить, не об\яснишь же нормальнр

	int cur = index,
		left = 2 * index + 1,
		right = 2 * index + 2;

	// если левый дочерний элемент больше корня
	if (left < number and arr[left] > arr[cur])
		cur = left;

	// если правый дочерний элемент больше, чем самый большой элемент на данный момент (наш корень)
	if (right < number and arr[right] > arr[cur])
		cur = right;

	// если самый большой элемент не корень
	if (cur != index) {

		swap(arr[index], arr[cur]);
		conversion(arr, number, cur);
	}
}

void heap_sort(int arr[], int number, bool cond) {

	// преобразуем массив под кучу
	for (int i = number / 2 - 1; i >= 0; i--)
		conversion(arr, number, i);

	for (int i = number - 1; i >= 0; i--) {

		// перемещаем текущий корень в конец
		swap(arr[0], arr[i]);

		// снова преобразуем массив, чтобы он был кучей
		conversion(arr, i, 0);

		// вывод массива в консоль
		arrout(arr, number, cond);
	}
}

void _5(bool cond) { // O(N*logN)

	int N; cout << "Size of the array: "; cin >> N;
	int* narr = new int[N];

	cout << "Elements of the array: \n";
	for (int i = 0; i < N; i++) {
		cin >> narr[i];
	} cout << endl;

	heap_sort(narr, N, cond);
}
/*

     10(0)
     /   \
   5(1)  4(2)
        /    \
      3(3)   1(4)

*/
