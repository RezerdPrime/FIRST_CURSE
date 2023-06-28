#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cassert>
using namespace std;

struct Rect {
    int x, y;
};

int main() {
    ifstream fin("power.in");
    ofstream fout("power.out");

    int n, k;
    fin >> n >> k;
    vector<Rect> rects(n);

    for (int i = 0; i < n; ++i) {
        fin >> rects[i].x >> rects[i].y;
    }

    sort(rects.begin(), rects.end(), [](const Rect& left, const Rect& right) {
        return left.y > right.y;
        });

    priority_queue<int, vector<int>, greater<>> pq;
    long long max_rect = 0;

    for (const Rect& r : rects) {
        pq.push(r.x);
        if (pq.size() > k) {
            pq.pop();
        }

        assert(pq.size() <= k);
        if (pq.size() == k) {
            max_rect = max(max_rect, 1LL * r.y * pq.top());
        }
    }
    fout << max_rect;
}
