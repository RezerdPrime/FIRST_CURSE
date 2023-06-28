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

struct set {
    int* elements;
    int size;
    int capacity;
};

set init() {
    set new_set;
    new_set.size = 0;
    new_set.capacity = 4;
    new_set.elements = (int*)malloc(new_set.capacity * sizeof(int));
    return new_set;
}

bool inset(set s, int element) {
    for (int i = 0; i < s.size; i++) {
        if (s.elements[i] == element) {
            return 1;
        }
    }
    return 0;
}

void add(set* s, int element) {
    if (!inset(*s, element)) {
        if (s->size == s->capacity) {
            s->capacity *= 2;
            s->elements = (int*)realloc(s->elements, s->capacity * sizeof(int));
        }
        s->elements[s->size] = element;
        s->size++;
    }
}

void del(set* s, int element) {
    for (int i = 0; i < s->size; i++) {
        if (s->elements[i] == element) {
            s->elements[i] = s->elements[s->size - 1];
            s->size--;
            return;
        }
    }
}


int main() {
    set A = init();
    //int* R = new int[A.size / 2];
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int cur = 1;
    while (cur) {
        fin >> cur;

        if (cur > 0) add(&A, cur);
        if (cur < 0) del(&A, -cur);
        if (!cur) {
            //A.elements
            int* R = new int[A.size / 2];
            int* L = new int[A.size / 2];
            merge_sort(A.elements, L, R, 0, A.size - 1);

            for (int i = 0; i < A.size; i++) fout << A.elements[i] << " ";
        }

    }
}
