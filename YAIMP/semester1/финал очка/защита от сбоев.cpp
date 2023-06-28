#include <iostream>
using namespace std;

int main()
{
    char sym = '_';
    int count = 0;

    while ((sym != 'e') and (sym != 'o')) {
        cin >> sym;
        if ((sym != 'e') and (sym != 'o')) cout << sym;

        if (sym == '1') { count++; }
    }

    if (sym == 'e' and count % 2 == 0) { cout << 0; }
    if (sym == 'e' and count % 2 != 0) { cout << 1; }

    if (sym == 'o' and count % 2 == 0) { cout << 1; }
    if (sym == 'o' and count % 2 != 0) { cout << 0; }
}
