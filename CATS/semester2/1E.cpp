#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <fstream>
using namespace std;

void qs(int* narr, int left, int right) {

    int prop = narr[left];
    int lbuf = left;
    int rbuf = right;

    while (left < right) {
        while ((narr[right] >= prop) and (left < right))
            right--;

        if (left != right) {
            narr[left] = narr[right];
            left++;
        }

        while ((narr[left] <= prop) and (left < right)) left++;

        if (left != right) {
            narr[right] = narr[left];
            right--;
        }
    }

    narr[left] = prop;
    prop = left;
    left = lbuf;
    right = rbuf;

    if (left < prop) {
        qs(narr, left, prop - 1);
    }

    if (right > prop) {
        qs(narr, prop + 1, right);
    }
}
int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    //FILE* fin = fopen("input.txt", "r"), * fout = fopen("output.txt", "w");

    int N, L, res = 0;
    fin >> N >> L;
    //fscanf(fin, "%d", &N); fscanf(fin, "%d", &L);

    int* minut_arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) { 
        fin >> minut_arr[i];
        //fscanf(fin, "%d", &minut_arr[i]); 

    }

    qs(minut_arr, 0, N - 1);
    for (int i = 0; i < N; i++) {
        if (res < minut_arr[i]) {
            res = minut_arr[i];
        }
        res += L;
    }

    fout << res;
    //fprintf(fout, "%d", res);


}