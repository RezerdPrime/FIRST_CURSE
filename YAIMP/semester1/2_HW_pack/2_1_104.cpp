#include <iostream>
using namespace std;

int main() {
    char C; cin >> C;

    char lowercase[] = {'q','w','e','r','t','y','u','i','o','p','a','s','d',
                      'f','g','h','j','k','l','z','x','c','v','b','n','m'};

    char uppercase[] = {'Q','W','E','R','T','Y','U','I','O','P','A','S','D',
                      'F','G','H','J','K','L','Z','X','C','V','B','N','M'};

    for (int i = 0; i < 26; ++i) {
        if (lowercase[i] == C) { cout << uppercase[i]; return 0;}
        if (uppercase[i] == C) { cout << lowercase[i]; return 0;}
    }

    cout << C << endl;
}
