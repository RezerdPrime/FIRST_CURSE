#include <iostream>
#include <algorithm>
using namespace std;

int main() {
//    int x_size, y_size, x_pos = 1, y_pos = 1, x_arg = 1, y_arg = 1, count = 0;
//    cin >> x_size >> y_size;
//
//    while (!(x_pos == 0 and y_pos == y_size) and !(x_pos == 0 and y_pos == 0) and
//        !(x_pos == x_size and y_pos == y_size) and !(x_pos == x_size and y_pos == 0)){
//
//        x_pos += x_arg; y_pos += y_arg;
//
//        if ((x_pos == x_size or x_pos == 0) and !(y_pos == y_size or y_pos == 0)) { x_arg = -x_arg; count++; }
//        if ((y_pos == y_size or y_pos == 0) and !(x_pos == x_size or x_pos == 0)) { y_arg = -y_arg; count++; }
//
//        //cout << x_pos << " <x -- y> " << y_pos << " / count: " << count << endl;/////
//    }
//
//    cout << count << endl;


    int x_size1, y_size1, x_reserve, y_reserve;
    cin >> x_size1 >> y_size1; x_reserve = x_size1; y_reserve = y_size1;

    int maximum = max(x_size1,y_size1), minimum = min(x_size1,y_size1);

    while ((maximum > 0) and (minimum > 0))
    {
        maximum %= minimum; x_size1 = maximum; y_size1 = minimum;
        maximum = max(x_size1, y_size1);
        minimum = min(x_size1, y_size1);
    }

    cout << (x_reserve + y_reserve) / maximum - 2 << endl;
}
