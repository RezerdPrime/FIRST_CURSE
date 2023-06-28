#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N, arg = 1; double sum = 1;

    cin >> N; N = (N > 10) ? 10 : N; //Дальше 10 просто нет смысла смотреть, ибо сумма стремится к числу Эйлера, которое как раз равно ~ 2.7182818284590452...
                                    //Но нам тут важно только 2.71828
    for (int i = 1; i < N+1; i++){
        for (int j = 1; j < i+1; j++){
            arg *= j;
        }
        sum += 1. / arg; arg = 1;
    }

    cout << fixed << setprecision(5) << sum << endl;
}
