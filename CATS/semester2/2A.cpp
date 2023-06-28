#include <iostream>
#include <fstream>
using namespace std;

class Heap {
private:
    int arr[1000000], size;

public:
    Heap() { size = 0; }

    int parent(int i) { return (i - 1) / 2; }

    int left_ch(int i) { return (i * 2) + 1; }

    int right_ch(int i) { return (i * 2) + 2; }

    void sort(int i) {
        int left, right, largest, temp;

        left = left_ch(i);
        right = right_ch(i);
        largest = i;

        if (left <= size and arr[left] > arr[largest]) largest = left;

        if (right <= size and arr[right] > arr[largest]) largest = right;

        if (largest != i) {
            temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;

            sort(largest);
        }
    }

    int del() {
        int max = arr[0];

        arr[0] = arr[size - 1];
        size--;

        sort(0);

        return max;
    }

    void swap(int* x, int* y) {
        int temp = *x;

        *x = *y;
        *y = temp;
    }

    void add(int num) {
        arr[size] = num;
        int i = size;
        size++;

        while (i != 0 and arr[parent(i)] < arr[i]) {
            swap(&arr[parent(i)], &arr[i]);
            i = parent(i);
        }
    }

    int siz() { return size; }

    int head() { return arr[0]; }
};


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int count, num, min;
    Heap mx_heap, mn_heap;

    fin >> count;

    for (int i = 0; i < count; i++) {
        fin >> num;

        if (mn_heap.siz() != 0) {
            min = -mn_heap.head();

            if (num > min) mn_heap.add(-num);
            else mx_heap.add(num);
        }

        else { mx_heap.add(num); }

        while (mn_heap.siz() > mx_heap.siz()) 
            mx_heap.add(-mn_heap.del());

        while (mn_heap.siz() + 1 < mx_heap.siz()) 
            mn_heap.add(-mx_heap.del());

        fout << mx_heap.head() << " ";
    }
}
