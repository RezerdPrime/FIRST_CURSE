#include <iostream>
#include <string>
//#include <ctime>
#include <fstream>
using namespace std;

int main()
{   
    ifstream fin("a.txt");

    string fst_word,
           snd_word;

    getline(fin, fst_word);
    getline(fin, snd_word);

    //clock_t t0 = clock();

    int len = fst_word.length(), len_res = snd_word.length(),
        range = 0;

    for (int i = 0; i < len - 1; ++i) {
        if (fst_word[i] != snd_word[i]) { ++range; }
    }

    cout << range << endl;

    /*clock_t t1 = clock();
    double t = difftime(t1, t0) / 1000;
    cout << endl << t << endl;*/
}
