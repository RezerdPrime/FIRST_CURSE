#include <iostream>
using namespace std;

int op(int first_num, int second_num, char sym) {
    switch (sym) {
        case '+': { return first_num + second_num; }
        case '-': { return first_num - second_num; }
        case '*': { return first_num * second_num; }
        case '/': { return first_num / second_num; }
    }
}

int main() {

    char sym;
    cin >> sym;
    int arr[75] {1, int(sym) - 48};
    cin.get();

    do {
        sym = cin.get();
        int inted_sym = int(sym) - 48;
        int arr_len = arr[0];

        if (0 <= inted_sym and inted_sym <= 9) {
            arr[arr_len + 1] = int(sym) - 48;
            arr[0]++;
        }
        else {
            arr[arr_len - 1] = op(arr[arr_len - 1], arr[arr_len], sym);
            arr[0]--;
        }
        sym = cin.get();

        //for (int i = 0; i < 75; ++i) { cout << arr[i] << " "; } cout << endl;
        
    } while(sym != '\n');

    cout << arr[1];
}

// 6 5 3 - 7 + *
