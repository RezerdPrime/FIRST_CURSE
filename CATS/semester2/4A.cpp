#include <iostream>
#include <fstream>
//#include <timecheck.cpp>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

void swap(int* a, int i, int j) {

    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}

bool p_next(int* a, int n) {

    int j = n - 2;
    while ((j != -1) and (a[j] >= a[j + 1])) j--;
    if (j == -1) return false; // больше перестановок нет

    int k = n - 1;
    while (a[j] >= a[k]) k--;
    swap(a, j, k);

    int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
    while (l < r) swap(a, l++, r--);
    return true;
}

void p_out(int* a, int n) {  // вывод перестановки

    for (int i = 0; i < n; i++) fout << a[i] << " ";
    fout << endl;
}

int main() {

    int n, *a;
    fin >> n;

    //START // макрос на начало подсчёта рантайма алгоритма

    a = new int[n];

    for (int i = 0; i < n; i++) a[i] = i + 1;
    p_out(a, n);

    while (p_next(a, n)) p_out(a, n);

    //STOP // макрос на конец подсчёта рантайма алгоритма
}
