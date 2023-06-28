#include <iostream>
using namespace std;

int matrix[9][9], way[9], besser_weg[9], N, K, best = 2147483647;
bool visited[9];

void Zyklenexistenz(int begin, int cur, int left_to_go) {

    if (left_to_go == 1) {
        if (matrix[cur][begin] != 0) {

            way[K] = begin;
            int prev = begin, len = 0;

            for (int i = 1; i <= K; i++) {
                len += matrix[prev][way[i]];
                prev = way[i];
            }

            if (len < best) {
                best = len;
                for (int i = 0; i <= K; i++) besser_weg[i] = way[i];
            }
        }

        return;
    }

    visited[cur] = true;

    for (int i = begin + 1; i <= N; i++) {

        if (!visited[i] and matrix[cur][i] != 0) {
            way[K - left_to_go + 1] = i;
            Zyklenexistenz(begin, i, left_to_go - 1);
        }
    }
    visited[cur] = false;
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) cin >> matrix[i][j];

    cin >> K;

    for (int i = 1; i <= N; i++) {
        way[0] = i;
        Zyklenexistenz(i, i, K);
    }

    if (best == 2147483647) cout << 0 << '\n';

    else {
        cout << best << '\n';

        for (int i = 0; i <= K; i++) cout << besser_weg[i] << ' ';
        cout << endl;
    }
}

// https://informatics.msk.ru/mod/statements/view.php?chapterid=112639#1
