#include <iostream>
using namespace std;

int main() {
    int A, i;
    cin >> A >> i;

    cout << (A ^ (1 << i)) << endl;
}

/*
 * При исключающем ИЛИ происходит следующее изменение битов:
 *      1 ^ 0 = 1
 *      1 ^ 1 = 0
 *      0 ^ 0 = 0
 *      0 ^ 1 = 1
 */
