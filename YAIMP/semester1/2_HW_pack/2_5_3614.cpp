#include <iostream>
using namespace std;

int main() {
    float degrees; cin >> degrees;
    int degrees_int;

    int hour, min, sec;
    //cout << degrees * 120 << endl;///
    degrees_int = int(degrees * 120);

    //cout << degrees_int << endl;///

//    hour = degrees_int / 3600; degrees_int -= hour * 3600;
//    min = degrees_int / 60; degrees_int -= min * 60;
//    sec = degrees_int;

    hour = degrees_int / 3600;
    min = (degrees_int - (hour * 3600)) / 60;
    sec = degrees_int % 60;

    cout << hour << " " << min << " " << sec << endl;
    //cout << hour * 3600 + min * 60 + sec << endl;///
}


// 30 deg = 1 hour      1 hour = 3600 sec   =>  1 deg = 120 sec
// 31 deg = 31 * 120 = 3720 sec
