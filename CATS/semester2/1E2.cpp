#include <vector>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    vector<pair<string, vector<int>>> colors;
    int lamp_count; fin >> lamp_count;
    bool cond;

    for (auto i = 0; i < lamp_count; ++i) {
        string s;
        fin >> s;
        cond = false;

        for (auto& j : colors) {
            if (j.first == s) {
                j.second.push_back(i);
                cond = true;
                break;
            }
        }

        if (!cond) {
            colors.emplace_back(s, vector<int>());
            colors.back().second.push_back(i);
        }
    }

    int req, min;
    bool cd1, cd2;
    fin >> req;

    for (int z = 0; z < req; z++) {

        string beg_col, end_col;
        fin >> beg_col >> end_col;
        min = 2147483647;
        cd1 = cd2 = false;

        vector<int> tmp1, tmp2;
        for (auto& j : colors) {

            if (j.first == beg_col) {
                cd1 = true;
                tmp1 = j.second;
            }

            if (j.first == end_col) {
                cd2 = true;
                tmp2 = j.second;
            }
        }

        if (!cd1 || !cd2) {
            fout << -1 << '\n';
            continue;
        }

        if (beg_col == end_col) {

            if (tmp1.size() == 1) {
                fout << -2 << '\n';
                continue;
            }

            int min_val = tmp1[1] - tmp1[0];
            for (int i = 1; i < tmp1.size() - 1; i++) {

                if (tmp1[i + 1] - tmp1[i] < min_val) {
                    min_val = tmp1[i + 1] - tmp1[i];

                    if (min_val == 1) {
                        break;
                    }
                }
            }

            fout << min_val - 1 << '\n';
            continue;
        }

        int i = 0;
        int j = 0;

        min = abs(tmp1[0] - tmp2[0]);

        for (;;) {
            if (tmp1[i] > tmp2[j]) j++;

            else i++;

            if ((i >= tmp1.size()) || (j >= tmp2.size())) break;

            if (min > abs(tmp1[i] - tmp2[j])) min = abs(tmp1[i] - tmp2[j]);
        }
        fout << min - 1 << '\n';
    }
}
