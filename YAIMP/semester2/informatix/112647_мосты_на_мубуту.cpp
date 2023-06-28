#include <iostream>
#include <string>
using namespace std;

int main() {
	int** matrix;
	string* islands;

	int n;
	int r1 = 0;
	int r2 = 0;
	cin >> n;

	islands = new string[n];
	matrix = new int*[n];

	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];

		for (int j = 0; j < n; j++) cin >> matrix[i][j];
	}

	for (int i = 0; i < n; i++) cin >> islands[i];

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {

			if (matrix[i][j] != 0) {

				if (islands[i] == islands[j]) r1++;
				else r2++;
			}
		}
	}

	cout << r1 << ' ' << r2;
}

// https://informatics.msk.ru/mod/statements/view.php?chapterid=112647#1
