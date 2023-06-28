#include <iostream>
using namespace std;

int main() {
    int A, n, first_part, second_part;
    cin >> A >> n;

    first_part = A << n;

    second_part = A >> (32 | (~n | 1)); second_part &= (~((~(1 << 31) >> n) << n)) & ~(1 << 31); // ~(1 << 31) -> 2 147 483 647

    // А вообще это побитовый срез вплодь до знака

    cout << (first_part | second_part) << endl;
