#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


in\
t ma\
i\
n(\
) {
    i\
fstream fin("input.txt");
    ofstream fout("output.txt");

    vector<vector<double>> Tarr(4, vector<double>(4));
    vector<int> styles = { 0, 1, 2, 3 };
    vector<int> ans(4);
    double Tmin = 1000000000;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            fin >> Tarr[i][j];
        }
    }

    do {
        double cur = Tarr[0][styles[0]] + Tarr[1][styles[1]] \
                   + Tarr[2][styles[2]] + Tarr[3][styles[3]];

        if (cur < Tmin) {
            Tmin = cur;
            ans = styles;
        }
    } while (next_permutation(styles.begin(), styles.end()));

    for (int x : ans) fout << x + 1 << ' ';
}
