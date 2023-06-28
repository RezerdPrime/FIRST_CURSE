#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector <pair<int, int>> Kuhn_Mankres(const vector <vector <int>>& matrix) {

	vector<int> u(n, 0), v(n, 0);
	vector<int> marked_indexes(n, -1);

	for (int i = 0; i < n; i++) {

		vector<int> to_del(n, -1);
		vector<int> mins(n, 2147483647);
		vector<bool> visited(n, 0);

		int marked_i = i,
			marked_j = -1,
			j;

		while (marked_i != -1) {

			j = -1;

			for (int j1 = 0; j1 < n; j1++) {
				if (!visited[j1]) {
					int tmp = matrix[marked_i][j1] - u[marked_i] - v[j1];

					if (tmp < mins[j1]) {
						mins[j1] = tmp;
						to_del[j1] = marked_j;
					}

					if (j == -1 || mins[j1] < mins[j]) j = j1;
				}
			}

			int diff = mins[j];

			for (int j1 = 0; j1 < n; j1++) {
				if (visited[j1]) {

					u[marked_indexes[j1]] += diff;
					v[j1] -= diff;
				}

				else mins[j1] -= diff;
			}

			u[i] += diff;
			visited[j] = 1;
			marked_j = j;
			marked_i = marked_indexes[j];
		}

		for (; to_del[j] != -1; j = to_del[j]) marked_indexes[j] = marked_indexes[to_del[j]];
		marked_indexes[j] = i;
	}

	vector <pair<int, int>> pair_comb;

	for (int j = 0; j < n; j++) {
		if (marked_indexes[j] != -1) {
			pair_comb.push_back(pair<int, int>(marked_indexes[j], j));
		}
	}

	return pair_comb;
}

int main() {

	cin >> n;
	vector <vector <int>> a;

	for (int i = 0; i < n; i++) {
		a.push_back(vector<int>());

		for (int j = 0; j < n; j++) {
			int tmp;
			cin >> tmp;
			a[i].push_back(--tmp);
		}
	}
	vector<pair<int, int>> pair_comb = Kuhn_Mankres(a);
	int result = 0;

	for (unsigned int i = 0; i < pair_comb.size(); i++) {
		result += a[pair_comb[i].first][pair_comb[i].second] + 1;
	}
	cout << result << endl;
}
