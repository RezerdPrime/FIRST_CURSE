#include <iostream>
using namespace std;
int kaunt = 0;

/// Time checking /// ================================================ ///
int t0 = 0, t1 = 0;

void begin__() { t0 = clock(); }
void end__() {
    t1 = clock();
    double dif = (t1 - t0) / 1000.;
    cout << dif << endl;
}

#define _START_ begin__();
#define _STOP_ end__();

/// Random /// ======================================================= ///

int RDVALUE_ = 1;
#define RAND RD()

int RD(void) {
    int A;
    RDVALUE_ = (RDVALUE_ + (int)(&A)) * 1103515245 + 12345;
    return RDVALUE_ / 31;
}

/// Merge sorting /// ================================================ ///

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
        kaunt++;
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
    kaunt++;
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, L, R, l, m);
        merge_sort(arr, L, R, m + 1, r);
        merge(arr, L, R, l, m, r);
    }
}


/// Shell sorting /// ================================================ ///

void shell_sort(int* arr, int size) {
    for (int s = size / 2; s > 0; s /= 2) {
        //kaunt += 3;
        for (int i = s; i < size; ++i) {
            //kaunt++;
            for (int j = i - s; j >= 0 and arr[j] > arr[j + s]; j -= s) {
                //kaunt += 5;

                int temp = arr[j];
                arr[j] = arr[j + s];
                arr[j + s] = temp;
                //kaunt += 5;
                kaunt++;
            }
        }
    }
}

/// Main /// ========================================================= ///

int main() {
    int N = 1000;

    for (int i = 0; i < 10; i++) {
        int* arr = new int[N];

        int* L = new int[N/2];
        int* R = new int[N/2];

        for (int i = 0; i < N; ++i) {
            arr[i] = RAND; //cout << arr[i] << " ";
        } //cout << endl;

        //_START_

        merge_sort(arr, L, R, 0, N - 1); cout << kaunt << endl; kaunt = 0;
        //shell_sort(arr, N); cout << kaunt << endl; kaunt = 0;

        //_STOP_

        /*for (int i = 0; i < N; ++i) {
            cout << arr[i] << " ";
        }*/

        delete[] arr; 
        delete[] L;
        delete[] R;
    }
}

// Короче, юмор в том, что вы должны потестить сортировочки на одном и том же наборе данных, который генерится рандомно :clown: :clown: :clown:
