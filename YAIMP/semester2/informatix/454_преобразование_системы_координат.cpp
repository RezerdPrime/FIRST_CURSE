#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double A, B, C, D,
           x1, y1,
           x2, y2;

    cin >> A >> B >> C >> D
        >> x1 >> y1
        >> x2 >> y2;

    cout << scientific << setprecision(5)
        << (x1 - A) / (C - A) << " " << (y1 - B) / (D - B) << " "
        << A + x2 * (C - A) << " " << B + y2 * (D - B);
}

// https://informatics.msk.ru/mod/statements/view.php?chapterid=454#1
