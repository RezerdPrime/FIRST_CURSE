#include <fstream>
#include <vector>
using namespace std;

class Timer {
public:
    int up = 0;
    int down = 0;
};

class Table {
public:
    bool ex = false;
    int time;
    int timer;
    Table* id;
};

class Result {
public:
    int time;
    int timer;
};

Table arr_of_shit[500][100][100];

Table* opt_state(Timer a, Timer b, int t, int T, Table* id) {

    if (a.up > 0 && b.up > 0) {
        int min = (a.up < b.up) ? a.up : b.up;
        a.up -= min;
        b.up -= min;
        a.down += min;
        b.down += min;
        t -= min;
    }

    else {

        if (a.up > 0) {
            a.down += a.up;
            t -= a.up;
            a.up = 0;
        }

        if (b.up > 0) {
            b.down += b.up;
            t -= b.up;
            b.up = 0;
        }
    }

    if (t > 0) {

        if (!arr_of_shit[T - t][a.up][b.up].ex) {
            arr_of_shit[T - t][a.up][b.up].id = id;
            id = &arr_of_shit[T - t][a.up][b.up];

            arr_of_shit[T - t][a.up][b.up].ex = true;
            arr_of_shit[T - t][a.up][b.up].time = T - t;
            Table* m;

            arr_of_shit[T - t][a.up][b.up].timer = 1;
            swap(a.up, a.down);
            m = opt_state(a, b, t, T, id);

            if (m) return m;

            swap(a.up, a.down);

            arr_of_shit[T - t][a.up][b.up].timer = 2;
            swap(b.up, b.down);
            m = opt_state(a, b, t, T, id);

            if (m) return m;

            swap(b.up, b.down);

            arr_of_shit[T - t][a.up][b.up].timer = 3;
            swap(a.up, a.down);
            swap(b.up, b.down);
            m = opt_state(a, b, t, T, id);

            if (m) return m;
        }
    }
    if (!t && !a.up && !b.up) return id;

    else {
        while (id) {
            id->ex = 0;
            id = id->id;
        }

        return nullptr;
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, t, a, b;
    fin >> n;

    Table* cur_state = NULL;
    vector<Result> sols;

    for (int i = 0; i < n; i++) {
        fin >> t >> a >> b;
        Timer A = { 0, a }, B = { 0, b };
        cur_state = opt_state(A, B, t, t, nullptr);

        while (cur_state) {
            sols.push_back({ cur_state->time, cur_state->timer });
            cur_state->ex = false;
            cur_state = cur_state->id;
        }

        fout << size(sols) << endl;

        for (int j = size(sols); j > 0; j--) {
            fout << sols[j - 1].time << " " << sols[j - 1].timer << endl;
        }

        sols.clear();
    }
}
