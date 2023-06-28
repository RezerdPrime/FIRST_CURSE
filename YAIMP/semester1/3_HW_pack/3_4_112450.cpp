#include <iostream>
//#include <ctime> // Тайм_чек для наблюдения за микрооптимизацией
using namespace std;

int main() {

    int* prime_arr; int N, i, j, count = 1;
    cin >> N;

    prime_arr = (int*)malloc(sizeof(int) * N); // Задание массива указанной длины
    prime_arr[0] = 2; // В котором первый элемент - всегда двойка

    //clock_t t0 = clock();

    for (i = 3; i <= N; i+=2) { // Проверка всех нечетных чисел в указанном диапазоне
                                // И всех делителей (также нечетных)
        j = 3;
        while ((j*j <= i) and (i%j != 0)){ j+=2; } // Переход к следующему делителю,
        // Если число делится нацело и его квадрат не превосходит само число

        if (j*j > i){ // Если квадрат делителя превышает число, то это уже окончательно
            prime_arr[count] = i; // Простое число
            ++count;
        }
    }

    //clock_t t1 = clock(); // 1'000'000 -> 0.053 сек

    //cout << (t1 - t0) / 1000. << endl;

    for (int l = 0; l < count; l++){
        cout << prime_arr[l] << " ";
    }
}
