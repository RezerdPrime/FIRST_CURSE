#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    auto arr = (int*)malloc(sizeof(int));
    int n = 0, s = 0, cur_el = 1;
    double Sr, De = 0;

    while (cur_el) {
        cin >> cur_el;
        if (cur_el) {
            arr[n] = cur_el;
            n++;
            s += cur_el;

            arr = (int*)realloc(arr, sizeof(int) * (n + 1));
        }
    }

    /*for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }*/

    //cout << "  <> " << s << " <> " << n << " <> " << (float)s / n << endl;

    Sr = (float)s / n;

    for (int i = 0; i < n; ++i) { 
        De += pow((arr[i] - Sr), 2); 
        //cout << De << " " << arr[i] - Sr << " " << pow((arr[i] - Sr), 2) << endl; 11
    }
    De /= (n - 1);
    De = sqrt(De);

    cout << setprecision(12) << De;
}
