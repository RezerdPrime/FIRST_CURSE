#include <iostream>
#include <fstream>
using namespace std;

int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int chel_count, chng_count;
    fin >> chel_count >> chng_count;

    int* chels = new int[chel_count];
    for (int i = 0; i < chel_count; i++) fin >> chels[i];

    int bufnum, bufval,
        maxval = chels[0], maxind = 0;

    for (int i = 1; i < chel_count; i++) {
        if (maxval < chels[i]) {
            maxval = chels[i];
            maxind = i;
        }
    }

    for (int i = 0; i < chng_count; i++) {

        fin >> bufnum >> bufval;
        chels[--bufnum] += bufval;

        if (bufval > 0) {
            if (maxval < chels[bufnum]) {
                maxval = chels[bufnum];
                maxind = bufnum;
            }
        }

        if (maxind == bufnum) {
            maxval = chels[0];
            maxind = 0;

            for (int j = 1; j < chel_count; j++) {
                if (maxval < chels[j]) {
                    maxval = chels[j];
                    maxind = j;
                }
            }
        }

        fout << maxval << endl;
    }
}

// нет я пошел на микроконтроллеры, а не на 1с
