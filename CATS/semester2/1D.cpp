#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct run {
    int tim, prub, time, att[20];
};

struct res {
    int tim, prub, time, cond;
};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int c, n; fin >> c >> n;

    vector<run> teams(c);
    vector<res> rez;
    vector<vector <bool>> tasks(c, vector<bool>(20, { false }));

    for (int i = 0; i < n; i++) {
        int team, problem, time, attempt;
        fin >> team >> problem >> time >> attempt;
        rez.push_back({ team, problem, time, attempt });
    }

    for (int i = 0; i < c; i++) {
        teams[i].tim = i + 1;
    }

    sort(rez.begin(), rez.end(), [](res l, res r) {
        return l.time < r.time;
        });

    for (auto r : rez) {
        if (r.cond and !tasks[r.tim - 1][r.prub - 1]) {

            teams[r.tim - 1].prub++;
            teams[r.tim - 1].time += 1200 * teams[r.tim - 1].att[r.prub - 1] + r.time;
            tasks[r.tim - 1][r.prub - 1] = true;
        }
        else if (!tasks[r.tim - 1][r.prub - 1]) teams[r.tim - 1].att[r.prub - 1]++;
    }

    sort(teams.begin(), teams.end(), [](run& l, run& r) {
        if (l.prub > r.prub) return true;

        else {
            if (l.prub == r.prub and l.time < r.time) return true;
            if (l.prub == r.prub and l.time == r.time) return l.tim < r.tim;
        }
        return false;
        });

    for (auto a : teams) fout << a.tim << " ";
}
