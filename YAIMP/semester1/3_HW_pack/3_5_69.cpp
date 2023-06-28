#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int N; int* arr;
    cin >> N;

    arr = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; ++i){
        cin >> arr[i];
    }

    for (int i = 0; i < (N / 2); ++i){
        swap(arr[i], arr[N - 1 - i]);
    }

    for (int i = 0; i < N; ++i){
        cout << arr[i] << " ";
    }
