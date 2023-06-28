#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<long long> degrees = { 1 };
vector<long long> hashes = { 0 };

long long Hash(int begin, int end) { return hashes[begin + end] - hashes[begin] * degrees[end]; }

int main() {
    fstream fin("input.txt");
    ofstream fout("output.txt");
    string wort;

    int op_amount, a, b, c, d;
    fin >> wort;
    fin >> op_amount;

    for (char i : wort) {
        int x = (int)(i - 'a' + 1);
        hashes.push_back((hashes.back() * 31 + x) % 1000000007);
        degrees.push_back((degrees.back() * 31) % 1000000007);
    }

    for (int i = 0; i < op_amount; i++) {
        fin >> a >> b >> c >> d;

        if (!((Hash(a - 1, b - a + 1) - Hash(c - 1, d - c + 1)) % 1000000007)) fout << "Yes\n";
        else fout << "No\n";
    }
}
