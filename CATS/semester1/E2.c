#include <stdio.h>

void merge(float arr[], int indexes[], int begin, int end, int mid, int lang) {

    float mergedArr[lang];
    int mergedIndexes[lang];
    int i, j, k;
    i = begin;
    k = begin;
    j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] >= arr[j]) {
            // cout << arr[i] << " " << arr[j] << endl;
            mergedArr[k] = arr[i];
            mergedIndexes[k] = indexes[i];
            k++;
            i++;
        }
        else {
            // cout << arr[i] << " | " << arr[j] << endl;
            mergedArr[k] = arr[j];
            mergedIndexes[k] = indexes[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        mergedArr[k] = arr[i];
        mergedIndexes[k] = indexes[i];
        k++;
        i++;
    }

    while (j <= end) {
        mergedArr[k] = arr[j];
        mergedIndexes[k] = indexes[j];
        k++;
        j++;
    }

    for (i = begin; i < k; i++) {
        arr[i] = mergedArr[i];
        indexes[i] = mergedIndexes[i];
    }
}

void merg_sort(float arr[], int indexes[], int begin, int end, int lang) {
	int mid;
	if (begin < end) {
		mid = (begin + end) / 2;
		merg_sort(arr, indexes, begin, mid, lang);
		merg_sort(arr, indexes, mid + 1, end, lang);
		merge(arr, indexes, begin, end, mid, lang);
	}
}

int main() {
    int N;
    FILE *f1 = fopen("input.txt", "r"),
         *f2 = fopen("output.txt", "w");

    fscanf(f1, "%d", &N);

    float growth[N]; // росты солдатов
    char name[N][255]; // их имена
    int ind[N]; // сэйв индексов

    for (int i = 0; i < N; i++) {
        fscanf(f1, "%f %s", &growth[i], &name[i]);
        ind[i] = i;
    }

    merg_sort(growth, ind, 0, N - 1, N);

    for (int i = 0; i < N; i++) {
        fprintf(f2, "%s\n", name[ind[i]]);
        // printf("%d\n", a[i]);
    }
}
