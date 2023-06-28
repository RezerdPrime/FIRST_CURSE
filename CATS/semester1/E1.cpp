#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binsearch(int arr[], int left, int right, int value, int size) { // пробовал избавиться от лишнего аргумента в виде размера массива
    int mit = 0; // die Mitte, середина                              // юзал sizeof(arr) / 4, но ИДЕшка выпендривается, мол значение может быть неправильное
    for (int i = 0; i <= size; i++) {
        mit = (left + right) / 2;

        if (value < arr[mit]) { right = mit - 1; }

        else if (value > arr[mit]) { left = mit + 1; }

        else { return mit; }

        if (left > right) { return -1; } // Ну типа ноль зарезервирован, а мне нужно какое-то "зануляющее" значение для выхода
    }
}
int main() {

    FILE* fin = fopen("input.txt", "r"),
        * fout = fopen("output.txt", "w");

    int count_repeats = 0, size1, size2, size3;

    fscanf(fin, "%d", &size1);
    fscanf(fin, "%d", &size2);
    fscanf(fin, "%d", &size3);

    auto arr1 = (int*)malloc(sizeof(int) * size1),
         arr2 = (int*)malloc(sizeof(int) * size2),
         arr3 = (int*)malloc(sizeof(int) * size3);

    for (int i = 0; i < size1; i++) { fscanf(fin, "%d", &arr1[i]); }

    for (int i = 0; i < size2; i++) { fscanf(fin, "%d", &arr2[i]); }

    for (int i = 0; i < size3; i++) { fscanf(fin, "%d", &arr3[i]); }

    for (int i = 0; i < size1; i++) {
        if (binsearch(arr2, 0, size2, arr1[i], size2) != -1) { 
            if (binsearch(arr3, 0, size3, arr1[i], size3) != -1) { count_repeats++; } 
        }
    }
    fprintf(fout, "%d", count_repeats);
}
