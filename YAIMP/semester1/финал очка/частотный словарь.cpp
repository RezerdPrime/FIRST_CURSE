//#include <ctime>

#include <iostream>
#include <fstream> 
#include <iomanip>
using namespace std;

int main()
{
    //clock_t t0 = clock();

    setlocale(LC_ALL, "");

    ifstream fin("a.txt");
    short arr[256] = {};
    char c = 0;
    int count = 0, count2 = 256, cur_min_index = -1, cur_min = 500;
    
    while (!fin.eof()) {
        c = fin.get();
        if (c != -1) {
            arr[(int)c]++;
            count++;
        }
    }

    while (count2) {
        for (int j = 0; j < 256; ++j) {
            if (arr[j] < cur_min and arr[j] != 0) {
                cur_min_index = j;
                cur_min = (int)arr[j];
            }
        }
        if (arr[cur_min_index] != 0) {
            cout << setprecision(3) << (char)cur_min_index << "  " << arr[cur_min_index] << "  " << ((float)arr[cur_min_index] / count) * 100 << " %" << "\n\n";
        }
        arr[cur_min_index] = 0;
        cur_min = 500;
        count2--;
    }

    //clock_t t1 = clock();
    //cout << (t1 - t0) / 1000. << endl;

    cout << endl << "Total: " << count << endl;
}
