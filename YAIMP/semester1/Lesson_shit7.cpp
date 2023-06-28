#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("Hash_codes.txt");

    int M, code = 0; fin >> M;
    char sym = fin.get();

    while (!fin.eof()) {
        sym = fin.get(); //cout << (int)sym << endl;

        if (sym != '\n' and !fin.eof()) { code += (char)sym; }
        if (sym == '\n' or fin.eof()) {
            cout << code % M << endl;
            code = 0;
        }
    }
}
