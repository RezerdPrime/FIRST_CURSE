#include <fstream>
#include <vector>
using namespace std;

struct Ticket {
    int begin;
    int end;
    int ort;
};

int main() {
    ifstream fin("trains.in");
    ofstream fout("trains.out");

    int station, tick_count, ortes;
    fin >> station >> tick_count >> ortes;
    vector<vector<Ticket>> tickets(station + 1);

    for (int i = 0; i < tick_count; i++) {
        int begin, end, ort;
        fin >> begin >> end >> ort;
        tickets[end].push_back(Ticket{ begin, end, ort });
    }

    vector<int> antwort(station + 1);
    vector<int> max_stat(ortes + 1, station);
    vector<int> max_count(station + 1, 0);

    max_count[station] = ortes;
    int max_ind = station;

    for (int i = station; i >= 1; i--) {
        antwort[i] = max(i, max_ind);

        for (const Ticket& ticket : tickets[i]) {
            max_count[max_stat[ticket.ort]]--;
            max_stat[ticket.ort] = ticket.begin;
            max_count[max_stat[ticket.ort]]++;
        }

        while (max_count[max_ind] == 0) max_ind--;
    }

    vector<int> max_tick(station + 1);
    vector<int> count_tick(station + 1);

    for (int j = station; j >= 1; j--) {
        if (antwort[j] == j) {
            max_tick[j] = j;
            count_tick[j] = 0;
        }

        else {
            int tmp = antwort[j];
            if (tmp / 512 != j / 512) {
                max_tick[j] = tmp;
                count_tick[j] = 1;
            }

            else {
                max_tick[j] = max_tick[tmp];
                count_tick[j] = count_tick[tmp] + 1;
            }
        }
    }

    int q; fin >> q;

    for (int i = 0; i < q; i++) {
        int begin, end;
        fin >> begin >> end;
        int count = 0;

        while (max_tick[begin] > begin && max_tick[begin] <= end) {
            count += count_tick[begin];
            begin = max_tick[begin];
        }

        while (begin < antwort[begin] && begin < end) {
            count++;
            begin = antwort[begin];
        }

        if (begin < end) fout << -1 << "\n";

        else fout << count << "\n";
    }
}
