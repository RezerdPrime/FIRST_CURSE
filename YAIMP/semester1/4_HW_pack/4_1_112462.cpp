#include <iostream>
#include <fstream>
#include <iomanip>
#define ULL unsigned long long
#define mlrd 1000000000

using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int array_size = 1, length_of_first = 1, length_of_second = 1; char iter_sym = 1;
    auto long_number1 = (ULL*)malloc(array_size * sizeof(ULL)),
        long_number2 = (ULL*)malloc(array_size * sizeof(ULL));

    long_number1[0] = 0;
    long_number2[0] = 0;

    // ----- ----- ----- ----- ----- ----- ----- 1st num
    while (iter_sym != 10) {
        iter_sym = fin.get();

        if (iter_sym != 10) {

            long_number1[0] *= 10;
            long_number1[0] += (ULL)iter_sym - 48;

            for (int i = 0; i < array_size - 1; i++) {
                long_number1[i + 1] *= 10;
                long_number1[i + 1] += long_number1[i] / mlrd;
                long_number1[i] %= mlrd;
            }

            if ((long_number1[array_size - 1]) > (mlrd - 1)) {
                array_size++, length_of_first++;
                long_number1 = (ULL*)realloc(long_number1, array_size * sizeof(ULL));
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
            long_number2[0] += (ULL)iter_sym - 48;

            for (int i = 0; i < array_size - 1; i++) {
                long_number2[i + 1] *= 10;
                long_number2[i + 1] += long_number2[i] / mlrd;
                long_number2[i] %= mlrd;
            }

            if ((long_number2[array_size - 1]) > (mlrd - 1)) {
                array_size++, length_of_second++;
                long_number2 = (ULL*)realloc(long_number2, array_size * sizeof(ULL));
                long_number2[array_size - 1] = 0;
            }
        }
    }

    if (array_size > 1) {
        long_number2[array_size - 1] += long_number2[array_size - 2] / mlrd;
        long_number2[array_size - 2] %= mlrd;
    }

    // ----- ----- ----- ----- ----- ----- -----

    //for (int i = 0; i < length_of_first; i++) {
    //    cout /* << setfill('0') << setw(9) */ << long_number1[i] << endl;
    //} cout << endl;

    //for (int i = 0; i < length_of_second; i++) {
    //    cout /* << setfill('0') << setw(9) */ << long_number2[i] << endl;
    //} cout << endl << endl << endl << endl;

    // ----- ----- ----- ----- ----- ----- ----- 
    
    //da summ f**cing

    if (length_of_first > length_of_second) {
        for (int i = 0; i < length_of_second; i++) { long_number1[i] += long_number2[i]; }

        if (long_number1[length_of_first - 1] >= mlrd) {
            length_of_first++;
            long_number1 = (ULL*)realloc(long_number1, length_of_first * sizeof(ULL));
            long_number1[length_of_first - 1] = 0;
        }

        for (int i = 0; i < length_of_first - 1; i++) {
            long_number1[i + 1] += long_number1[i] / mlrd;
            long_number1[i] %= mlrd;
        }

        fout << long_number1[length_of_first - 1];
        for (int i = length_of_first - 2; i > -1; i--) {
            fout << setfill('0') << setw(9) << long_number1[i];
        }
    }
    // ----- ----- ----- ----- ----- ----- -----
    else { 
        for (int i = 0; i < length_of_first; i++) { long_number2[i] += long_number1[i]; }

        if (long_number2[length_of_second - 1] >= mlrd) {
            length_of_second++;
            long_number2 = (ULL*)realloc(long_number2, length_of_second * sizeof(ULL));
            long_number2[length_of_second - 1] = 0;
        }

        for (int i = 0; i < length_of_second - 1; i++) {
            long_number2[i + 1] += long_number2[i] / mlrd;
            long_number2[i] %= mlrd;
        }

        fout << long_number2[length_of_second - 1];
        for (int i = length_of_second - 2; i > -1; i--) {
            fout << setfill('0') << setw(9) << long_number2[i];
        }
    }
}
