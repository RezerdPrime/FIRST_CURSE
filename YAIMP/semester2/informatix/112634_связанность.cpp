#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    bool** W = (bool**)calloc(sizeof(bool*), N);

    for (int i = 0; i < N; i++) {
        W[i] = (bool*)calloc(sizeof(bool), N);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];// << " ";
        } //cout << endl;
    } cout << endl;

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                W[i][j] = W[i][j] || (W[i][k] && W[k][j]);

    int ans = 0;

    for (int i = 0; i < N; i++) {
        int anscur = 1;

        for (int j = 0; j < N; j++) {
            //cout << W[i][j] << " ";
            anscur = anscur && W[i][j];
        } 
        //cout << endl;
        ans = ans || anscur;
    }

    //cout << endl << ans;
    if (ans) cout << "YES";
    else cout << "NO";
}

// https://informatics.msk.ru/mod/statements/view.php?chapterid=112634#1
