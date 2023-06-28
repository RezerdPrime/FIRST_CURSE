#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    ofstream fout("1.txt");
    
    char Sym; int count = 0, buffer;
    cin >> Sym; buffer = Sym;

    while (buffer != 0) {
        if (buffer % 2 == 1) { count++; }
        buffer /= 2;
    }

    if (count % 2 == 1) { Sym += 128; }

    fout << Sym << endl;
}
