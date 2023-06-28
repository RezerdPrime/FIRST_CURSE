#include <iostream>
using namespace std;

int main() {
    int A, n;
    cin >> A >> n;
  cout << (A & ~((A >> n) << n)) << endl;
}

/*

10111 >> <<
10100 ~
01011 &
=> 00011

*/
