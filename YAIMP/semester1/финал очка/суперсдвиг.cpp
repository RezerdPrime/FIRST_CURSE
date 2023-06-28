#include <iostream>
using namespace std;

int main()
{
    int count, shear; cin >> count;
    auto arr = (int*)malloc(sizeof(int) * count);

    for (int i = 0; i < count; ++i) { cin >> arr[i]; }

    cin >> shear;

    if (shear) {
        for (int i = 0; i < count / 2; ++i) { swap(arr[i], arr[count - i - 1]); }
    }

    if (shear > 0) {
        if (shear > count) shear %= count;
        for (int i = 0; i < shear / 2; ++i) { swap(arr[i], arr[shear - i - 1]); }
        for (int i = 0; i < (count - shear) / 2; ++i) { swap(arr[shear + i], arr[count - i - 1]); }
    }

    else if (shear < 0) {
        shear = -shear;
        if (shear > count) shear %= count;
        for (int i = 0; i < (count - shear) / 2; ++i) { swap(arr[i], arr[count - shear - i - 1]); }
        for (int i = 0; i < shear / 2; ++i) { swap(arr[count - shear + i], arr[count - i - 1]); }
    }

    for (int i = 0; i < count; ++i) { cout << arr[i] << " "; }
}
