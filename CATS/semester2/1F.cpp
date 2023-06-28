#include <iostream>
#include <fstream>
using namespace std;

void merge(int* arr, int L[], int R[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    //int* L = new int[n1], * R = new int[n2];

    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 or j < n2) {

        if (j >= n2 or (i < n1 and L[i] <= R[j])) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
}

void merge_sort(int* arr, int L[], int R[], int l, int r) {

    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, L, R, l, m);
        merge_sort(arr, L, R, m + 1, r);
        merge(arr, L, R, l, m, r);
    }
}

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int N; fin >> N; char cur[4] = {};
	int* arr = new int[N];
    int* R = new int[N / 2];
    int* L = new int[N / 2];

	for (int i = 0; i < N; i++) {
		
        fin >> cur;
        arr[i] = cur[0] * 1000000 + cur[1] * 1000 + cur[2];
        //cout << arr[i] << endl;
	}

    merge_sort(arr, L, R, 0, N - 1);

	for (int i = 0; i < N; i++) {
        fout << (char)(arr[i] / 1000000) << (char)((arr[i] % 1000000) / 1000) << (char)(arr[i] % 1000) << endl;
        //fout << arr[i] << endl;
	}
}

// карманная сортировка - это позерство ебаное
