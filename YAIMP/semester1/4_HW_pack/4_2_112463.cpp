#include <iostream>
#include <fstream>
#include <iomanip>
#define LL long long
#define mlrd 1000000000

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int array_size = 1, length_of_first = 1, length_of_second = 1; char iter_sym = 1;
    auto long_number1 = (LL*)malloc(array_size * sizeof(LL)),
        long_number2 = (LL*)malloc(array_size * sizeof(LL));

    long_number1[0] = 0;
    long_number2[0] = 0;

    // ----- ----- ----- ----- ----- ----- ----- 1st num
    while (iter_sym != 10) {
        iter_sym = fin.get();

        if (iter_sym != 10) {

            long_number1[0] *= 10;
            long_number1[0] += (LL)iter_sym - 48;

            for (int i = 0; i < array_size - 1; i++) {
                long_number1[i + 1] *= 10;
                long_number1[i + 1] += long_number1[i] / mlrd;
                long_number1[i] %= mlrd;
            }

            if ((long_number1[array_size - 1]) > (mlrd - 1)) {
                array_size++, length_of_first++;
                long_number1 = (LL*)realloc(long_number1, array_size * sizeof(LL));
                long_number1[array_size - 1] = 0;
            }
        }
    }

    if (array_size > 1) {
        long_number1[array_size - 1] += long_number1[array_size - 2] / mlrd;
        long_number1[array_size - 2] %= mlrd;
    }

    // ----- ----- ----- ----- ----- ----- ----- 2nd num
    array_size = 1; iter_sym = 1;

    while (!fin.eof() and iter_sym != -1) {
        iter_sym = fin.get();

        if (!fin.eof() and iter_sym != -1) {

            long_number2[0] *= 10;
            long_number2[0] += (LL)iter_sym - 48;

            for (int i = 0; i < array_size - 1; i++) {
                long_number2[i + 1] *= 10;
                long_number2[i + 1] += long_number2[i] / mlrd;
                long_number2[i] %= mlrd;
            }

            if ((long_number2[array_size - 1]) > (mlrd - 1)) {
                array_size++, length_of_second++;
                long_number2 = (LL*)realloc(long_number2, array_size * sizeof(LL));
                long_number2[array_size - 1] = 0;
            }
        }
    }

    if (array_size > 1) {
        long_number2[array_size - 1] += long_number2[array_size - 2] / mlrd;
        long_number2[array_size - 2] %= mlrd;
    }

    // ----- ----- ----- ----- ----- ----- ----- da f**cing sub

    for (int i = 0; i < length_of_second; i++){
        long_number1[i] -= long_number2[i];

        if (length_of_first > 1){
            if (long_number1[i] < 0) {

                if (long_number1[i + 1] != 0) {
                    long_number1[i] += mlrd;
                    long_number1[i + 1] -= 1;

                } else {
                      for (int j = i + 1; long_number1[j] <= 0; j++) {
                          long_number1[j] -= 1;
                          long_number1[j - 1] += mlrd;
                      }
                }

                for (int j = 0; j < length_of_first; j++){
                    if (long_number1[j] == -1){
                        long_number1[j] += mlrd; long_number1[j + 1]--;
                    }
                }
            }

            if ((long_number1[length_of_first - 1] > 0) and (long_number1[length_of_first - 2] < 0)){
                long_number1[length_of_first - 1] -= 1; long_number1[length_of_first - 2] += mlrd;
                length_of_first--;
                long_number1 = (LL*)realloc(long_number1, length_of_first * sizeof(LL));
            }
        }
    }

    fout << long_number1[length_of_first - 1];
    for (int i = length_of_first - 2; i >= 0; i--) {
        fout << setfill('0') << setw(9) << long_number1[i];
    }
}
