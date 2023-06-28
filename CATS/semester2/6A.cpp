#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class buttom {
public:
    int x;
    int y;
};

class pos {
public:
    int lpos;
    int rpos;
    int count = 0;
    double sum = 0;
    int index;
};

double distance(buttom l, buttom r) {
    return sqrt(pow(l.x - r.x, 2) + pow(l.y - r.y, 2));
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fout << setprecision(16);

    buttom buttons[10] = {         4, 2,
                           1, 1,   1, 2,   1, 3, 
                           2, 1,   2, 2,   2, 3, 
                           3, 1,   3, 2,   3, 3
                         };

    int count, a, left, right;
    double d;

    fin >> count;
    vector <pos> poses;
    vector <pos> nposes;

    poses.push_back({ 4, 6, 0, 0 });
    pos table[10][10];

    for (int i = 1; i <= count; i++) {
        fin >> a;

        for (int j = 0; j < size(poses); j++) {
            left = poses[j].lpos;
            right = poses[j].rpos;

            d = distance(buttons[right], buttons[a]);
            if (buttons[a].y >= buttons[left].y && a != left) {

                if (table[left][a].count == i) {
                    if (table[left][a].sum > poses[j].sum + d) {
                        table[left][a].sum = poses[j].sum + d;
                        nposes[table[left][a].index].sum = poses[j].sum + d;
                    }
                }

                else {
                    table[left][a].count = i;
                    table[left][a].sum = poses[j].sum + d;
                    nposes.push_back({ left, a, i, poses[j].sum + d });
                    table[left][a].index = size(nposes) - 1;
                }
            }

            d = distance(buttons[left], buttons[a]);
            if (buttons[a].y <= buttons[right].y && a != right) {

                if (table[a][right].count == i) {
                    if (table[a][right].sum > poses[j].sum + d) {
                        table[a][right].sum = poses[j].sum + d;
                        nposes[table[a][right].index].sum = poses[j].sum + d;
                    }
                }

                else {
                    table[a][right].count = i;
                    table[a][right].sum = poses[j].sum + d;
                    nposes.push_back({ a, right, i, poses[j].sum + d });
                    table[a][right].index = size(nposes) - 1;
                }
            }
        }
        poses.clear();
        poses = nposes;
        nposes.clear();
    }

    double min = 1e9;
    for (int i = 0; i < size(poses); i++) {
        min = (min < poses[i].sum) ? min : poses[i].sum;
    }

    fout << min << endl;
}
