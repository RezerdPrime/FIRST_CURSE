#include <iostream>
using namespace std;

double factorial(int i){
    double fact_num = 1;

    for (int j = 1; j <= i; j++){
        fact_num *= j;
    }
    return fact_num;
}

int main() {
    int n; double x, pow, sum = 1;
    cin >> n >> x;  pow = x;

    for (int i = 1; i <= n; i++){
        sum += pow / factorial(i);
        pow *= x;
        //cout << sum << " " << factorial(i) << " " << pow << endl;///
    }

    cout << sum << endl;
}

// s = '1 + '; x = 2; for i in range(1,100): s += str(x) + '^' + str(i) + ' / ' + str(i) + '! + '
