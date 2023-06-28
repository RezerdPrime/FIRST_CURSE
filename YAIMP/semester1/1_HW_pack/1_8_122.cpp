#include <iostream>
//#include <cmath>
using namespace std;

int main() {
    unsigned long long n, m;
    cin >> n >> m;

    cout << ((1 << n) | (1 << m)) << endl;
    //cout << pow(2,n) + pow(2,m) << endl;
}
