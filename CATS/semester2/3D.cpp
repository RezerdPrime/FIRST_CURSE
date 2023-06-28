#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

class HT {
private:
    vector<pair<string, int>> table;

public:
    int count_obj = 0;

    void add(string key, int value) {
        auto beg = table.begin();
        bool kiy = false;

        while (beg != table.end()) {
            if (beg->first == key) {
                kiy = true;
                beg->second += value;
                break;
            }

            beg++;
        }

        if (!kiy) {
            table.emplace_back(key, value);
            count_obj++;
        }
    }

    int get(int key) {
        return table[key].second;
    }

    string obj(int key) {
        return table[key].first;
    }
};


int main() {
    FILE* fin = fopen("schools.in", "r");
    FILE* fout = fopen("schools.out", "w");

    HT schulen;
    int count, schule_count = 0;
    fscanf(fin, "%d", &count);

    for (int i = 0; i <= count; i++) {
        char name[101];
        fscanf(fin, "%*[^0123456789]%100[0123456789]", name);

        schulen.add(name, 1);
    }

    for (int i = 0; i < schulen.count_obj; i++) if (schulen.get(i) <= 5) schule_count++;
    fprintf(fout, "%d\n", schule_count);

    for (int i = 0; i < schulen.count_obj; i++) {
        if (schulen.get(i) <= 5) fprintf(fout, "%s\n", schulen.obj(i).c_str());
    }

}
