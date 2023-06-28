#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Line {
public:
    int vowels;
    bool intonation;
};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    bool bool_arr[256] = { false };
    int vow_arr[] = { 'a', 'o', 'u', 'e', 'i', 'y', 
                      'A', 'O', 'U', 'E', 'I', 'Y' };

    for (auto i : vow_arr) bool_arr[i] = 1;

    int str_count, song_count;
    string a;
    vector<Line> arr_str, arr_songs;
    fin >> str_count >> song_count;
    getline(fin, a);

    for (int i = 0; i < str_count; i++) {
        getline(fin, a);
        int vow_count = 0;
        bool intonation = false;

        for (auto j : a) {
            if (bool_arr[j]) vow_count++;

            if (j == '!') intonation = true;
        }
        arr_str.push_back({ vow_count, intonation });
    }

    for (int i = 0; i < song_count; i++) {
        getline(fin, a);
        int count_vowels = 0;
        bool intonation = false;

        for (auto j : a) {
            if (bool_arr[j]) count_vowels++;

            if (j == '!') intonation = true;
        }
        arr_songs.push_back({ count_vowels, intonation });
    }

    vector<vector<int>> table(song_count);
    for (int i = 0; i < song_count; i++) {
        for (int j = 0; j < str_count; j++) {

            if (arr_str[j].vowels == arr_songs[i].vowels && arr_str[j].intonation == arr_songs[i].intonation) {
                table[i].push_back(arr_str[j].vowels);
            }

            else table[i].push_back(0);
            
            if (i > 0 && j > 0) {
                table[i][j] += table[i - 1][j - 1];
                int max = (table[i - 1][j] > table[i][j - 1]) ? table[i - 1][j] : table[i][j - 1];
                table[i][j] = (table[i][j] > max) ? table[i][j] : max;
            }

            else {
                if (i > 0) {
                    table[i][j] = (table[i][j] > table[i - 1][j]) ? table[i][j] : table[i - 1][j];
                }

                if (j > 0) {
                    table[i][j] = (table[i][j] > table[i][j - 1]) ? table[i][j] : table[i][j - 1];
                }
            }
        }
    }
    fout << table[song_count - 1][str_count - 1];
}
