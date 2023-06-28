#include <fstream>
#include <set>
using namespace std;

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int count, sips; fin >> count >> sips;
    long long sum = 0;
    multiset<int> thirst;

    for (int i = 0; i < count; i++) {
        int thirst_lvl; fin >> thirst_lvl;
        sum += thirst_lvl;
        thirst.insert(thirst_lvl);
    }

    for (int i = 0; i < sips && sum > 0; i++) {
        auto max = thirst.rbegin();
        auto res = *max / 10;

        sum -= *max - res;
        thirst.erase(thirst.find(*max));
        thirst.insert(res);
    }

    fout << sum;
}
