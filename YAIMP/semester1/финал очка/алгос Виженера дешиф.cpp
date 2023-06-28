#include <iostream>
#include <fstream>
using namespace std;

char arr[34] = { 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'Й',
                 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф',
                 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я', ' ' };

int find(char c) {
    for (int i = 0; i < 34; ++i) {
        if (c == arr[i]) return i;
    }
}

int main()
{
    ifstream fin("inp.txt");
    ofstream fout("out.txt");

    setlocale(LC_ALL, "");

    auto key = (char*)malloc(sizeof(char));
    int key_length = 0, message_index = 0; char current_element = '_';

    while (current_element != '\n') {
        current_element = fin.get();

        if (current_element != '\n') {
            key[key_length] = current_element;
            key_length++;
            key = (char*)realloc(key, sizeof(char) * (key_length + 1));
        }
    }

    while (!fin.eof()) {
        current_element = fin.get();

        if (!fin.eof()) {
            int delta = find(current_element) - find(key[message_index % key_length]);
            fout << arr[delta + 34 * (delta < 0)];
            message_index++;
        }
    }
}
