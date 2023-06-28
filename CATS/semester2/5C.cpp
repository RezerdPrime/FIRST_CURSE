#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {

    ifstream fin("input.txt");
    ofstream fout("output.txt");
    long long n, c, p, t, 
              chel_sum = 0;

    fin >> n >> c >> p >> t;
    long long chels[n], remove_chels[n];
    long long l = 0, r, mid, k, capacity;

    for (long long i = 0; i < n; i++) {
        remove_chels[i] = 0;
        fin >> chels[i];
        chel_sum += chels[i];

    }
    r = chel_sum;

    while (l < r) {
        mid = (l + r + 1) / 2;
        long long buf = mid;

        for (long long i = 0; i < n; i++) {
            remove_chels[i] = min(chels[i], buf);
            buf -= remove_chels[i];
        }

        long long pos = n - 1, tmp_sum = 0;

        while (true) {
            while (pos >= 0 && !remove_chels[pos]) pos--;
            if (pos < 0) break;

            k = (remove_chels[pos] + c - 1) / c;
            tmp_sum += 2 * k * (pos + 1);
            capacity = k * c;

            while (pos >= 0 && capacity != 0) {
                if (!remove_chels[pos]) pos--;

                long long valid_cap = min(remove_chels[pos], capacity);
                remove_chels[pos] -= valid_cap;
                capacity -= valid_cap;
            }
        }
        if (tmp_sum <= t / p) l = mid;

        else r = mid - 1;
    }
    fout << l;
}
