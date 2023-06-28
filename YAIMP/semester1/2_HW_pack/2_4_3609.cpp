#include <iostream>
#include <cmath>
//#include <iomanip>
using namespace std;

int main() {
    double N; cin >> N;

    cout << fixed << (int) floor((N - floor(N)) * 10) << endl; // N = 1.75   floor(1.75) = 1
    //cout << fixed << setprecision(3) << N << endl;
}
