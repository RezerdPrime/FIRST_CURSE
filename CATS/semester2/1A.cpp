#include <iostream>
#include <fstream>
#define elif else if 
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    char sym = ' ', 
         prev_sym = fin.get(),
         cond = 0;

    if ((prev_sym > 96 and prev_sym < 123) and (cond == 0)) { cond = 1; }
    elif ((prev_sym > 64 and prev_sym < 91) and (cond == 0)) { cond = 2; }

    while (!fin.eof()) {
        sym = fin.get();

        // если текущий символ и предыдущий символ оба маленькие, то состояние не изменяется

         // если предыдущий символ маленький и текущий - большой, то состояние меняется на 2
        //
        if ((cond == 1) and (sym > 64 and sym < 91)) { cond = 2; }

        // если текущий символ и предыдущий символ оба большие, то состояние не изменяется

         // если предыдущий символ большой и текущий - маленький, то состояние меняется на 3
        //
        if ((cond == 2) and (sym > 96 and sym < 123)) {
            fout << "NO";
            return 0;
        }

    }
    fout << "YES";
}

/* 
   cond 0 - состояние до считывания символа
   cond 1 - первый символ маленький
   cond 2 - первый символ большой
   cond 3 - после большого идет маленький (его вносить в код было бессмысленно)
*/
