#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int L, M; fin >> L >> M;
    string s; fin >> s;

    map<string, int> table;
    vector<int> count(M + 1);
    int max_count = 0;

    for (int i = 0; i <= M - L; ++i) {
        string sub = s.substr(i, L);
        table[sub]++;

        if (count[table[sub] - 1] > 0) count[table[sub] - 1]--;

        count[table[sub]]++;
        max_count = max(max_count, table[sub]);
    }
    fout << max_count << " ";

    for (int i = 1; i <= s.size() - M; ++i) {
        string old_sub = s.substr(i - 1, L);
        count[table[old_sub]]--;
        table[old_sub]--;

        if (count[max_count] == 0) max_count--;
        count[table[old_sub]]++;

        string new_sub = s.substr(i + M - L, L);
        table[new_sub]++;

        if (count[table[new_sub] - 1] > 0) count[table[new_sub] - 1]--;

        count[table[new_sub]]++;
        max_count = max(max_count, table[new_sub]);

        fout << max_count << " ";
    }
}
