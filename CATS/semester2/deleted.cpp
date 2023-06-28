#include <iostream>
#include <fstream>
#define elif else if
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    char word1[50] = {}, // что это за ворды, думаю, не надо пояснять
         word2[50] = {};
    char arr[91] = {}, // массив, строящийся по следующему принципу:
         sym = ' ';   //  ASCII код символа первого слова есть индекс,
                     //   соответственно значение второго слова помещается в ячейку со своим индексом
     
    for (int i = 0; sym != '\n'; i++) {
        sym = fin.get();
        if (sym != '\n') word1[i] = sym; // считывание первого слова
    }

    for (int i = 0; !fin.eof(); i++) {
        sym = fin.get();
        if (!fin.eof()) word2[i] = sym; // считывание второго слова
    }

    for (int i = 0; word1[i] != 0; i++) {

        if (arr[word1[i]] == 0) arr[word1[i]] = word2[i]; // если в рассматриваемой ячейке нет никакого значения
                                                         //  то спокойно записываем значение

        elif((arr[word1[i]] != 0) and (arr[word1[i]] != word2[i])) { // если в рассматриваемой ячейке уже имеется значение,
            fout << "--";                                           //  отличающееся от записанного ранее,
            return 0; }                                            //   то брикаем прогу
    }

    for (int i = 65; i < 91; i++) { if (arr[i] != 0) { fout << (char)i << arr[i] << endl; } }
      // уютненький вывод лексикографически отсортированного массива
     //  именно в этом был смысл создания массива на 90 элементов
}
