#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, count = 0;
    cin >> a >> b;
    int maximum = max(a,b), minimum = min(a,b);

    while ((maximum > 0) and (minimum > 0))
    {
        maximum %= minimum; a = maximum; b = minimum;
        maximum = max(a,b);
        minimum = min(a,b);
        count++;
    }
    cout << maximum << " " << count << endl;
}
