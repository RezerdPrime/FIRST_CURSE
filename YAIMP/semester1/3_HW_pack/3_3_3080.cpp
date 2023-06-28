#include <iostream>
using namespace std;

int main(){
    int el1, el2, el3, count_of_max = 0, count = 0, min_range = 1000000000;

    cin >> el1 >> el2 >> el3;

    while (el3){

        if (el1 < el2 and el2 > el3){

            min_range = (count < min_range and count > 0) ? count : min_range;
            count = 0;
            count_of_max++;
        }

        else if (count_of_max > 0){ count++; }

        //cout << "\t" << count << " " << count_of_max << " " << min_range << endl;///

        el1 = el2; el2 = el3; cin >> el3;
    }

    if (count_of_max > 1){ min_range++; } // Это счёт количества элементов, а нам нужно
    // количество смещений
    else { min_range = 0; }
    cout << min_range << endl;
}
