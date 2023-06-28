#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
using namespace std;


unsigned long long hashf(string key) {
    unsigned long long result = 0;

    for (char c : key)
        result = (result * 120 + (c - 'a' + 1)) % 4000;

    return result;
}


class HT {
private:
    list<pair<string, int>> table[4000];

public:
    void add(string key, int value) {
        unsigned long long hash_ind = hashf(key);
        auto& cell = table[hash_ind];
        auto bit = begin(cell);
        bool keys = false;

        while (bit != end(cell)) {
            if (bit->first == key) {
                keys = true;
                bit->second = value;

                break;
            }
            bit++;
        }

        if (!keys) {
            cell.emplace_back(key, value);
        }
    }

    int get(string key) {
        unsigned long long hash_ind = hashf(key);
        auto& cell = table[hash_ind];
        auto bit = begin(cell);

        while (bit != end(cell)) {
            if (bit->first == key)
                return bit->second;

            bit++;
        }

        return 0;
    }
};


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n, m, k;
    HT HT;
    string key1, key2;
    vector<string> arrkey;

    fin >> n;

    int ans[n][n];
    memset(ans, 0, sizeof(ans));

    for (int i = 0; i < n; ++i) {
        fin >> key1;
        arrkey.push_back(key1);
    }

    sort(arrkey.begin(), arrkey.end());

    for (int i = 0; i < n; i++) HT.add(arrkey[i], i);

    fin >> m;

    for (int i = 0; i < m; i++) {
        fin >> key1 >> key2;

        ans[HT.get(key1)][HT.get(key2)] = 1;
        ans[HT.get(key2)][HT.get(key1)] = 2;
    }

    fin >> k;

    for (int i = 0; i < k; i++) {
        fin >> key1 >> key2;

        fout << ans[HT.get(key1)][HT.get(key2)] << " ";
    }
}
