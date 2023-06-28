// Fuer 4 points

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "build_stuff.h"
// https://github.com/RezerdPrime/Random-Shrain/tree/Nutzlosigkeit/C%2B%2BShit/Graphix
using namespace std;
#define PI 3.1415926535897932384626433832795
#define sq3 1.7320508075688772935

double Aa1, Bb1, Aa2, Bb2, Aa3, Bb3, Aa4, Bb4;
float arr[2] = {};

void SP(double A1, double B1, double A2, double B2, double A3, double B3) {
    if (A2 == A3) A3 += 0.001;

    double l1 = sqrt((A1 - A2) * (A1 - A2) + (B1 - B2) * (B1 - B2)),
        l2 = sqrt((A1 - A3) * (A1 - A3) + (B1 - B3) * (B1 - B3)),
        l3 = sqrt((A3 - A2) * (A3 - A2) + (B3 - B2) * (B3 - B2));

    //cout << l1 << " " << l2 << " " << l3;

    double angleA = (l1 * l1 + l2 * l2 - l3 * l3) / (2 * l1 * l2),
        angleB = (l1 * l1 + l3 * l3 - l2 * l2) / (2 * l1 * l3),
        angleC = (l2 * l2 + l3 * l3 - l1 * l1) / (2 * l2 * l3);

    //cout << angleA << " " << angleB << " " << angleC;

    if (angleA <= -0.5) {
        //cout << A1 << " " << B1;
        //Draw(A1, B1);
        arr[0] = A1; arr[1] = B1;
        return;
    }

    else if (angleB <= -0.5) {
        //cout << A2 << " " << B2;
        //Draw(A2, B2);
        arr[0] = A2; arr[1] = B2;
        return;
    }

    else if (angleC <= -0.5) {
        //cout << A3 << " " << B3;
        //Draw(A3, B3);
        arr[0] = A3; arr[1] = B3;
        return;
    }

    else {

        int c0 = (A2 - A3 > 0) ? 1 : -1,
            c1 = ((A1 - A3) / (A2 - A3) * (B2 - B3) + B3 - B1 > 0) ? c0 : -c0,
            k = 60 * c1;

        //cout << c0 << " " << c1 << " " << k;

        double Rx = (A2 + A3) / 2 - c1 * (sq3 / 2) * (B2 - B3),
            Ry = (Rx - A2) * (cos(PI * k / 180) * (B2 - B3) - sin(PI * k / 180) * (A2 - A3));

        Ry /= (sin(PI * k / 180) * (B2 - B3) + cos(PI * k / 180) * (A2 - A3));
        Ry += B2;

        //cout << Rx << " " << Ry;

        double Sx = (A1 + A2) / 2 - c1 * (sq3 / 2) * (B1 - B2),
            Sy = (Sx - A2) * (cos(PI * k / 180) * (B1 - B2) - sin(-PI * k / 180) * (A1 - A2));

        Sy /= (sin(-PI * k / 180) * (B1 - B2) + cos(PI * k / 180) * (A1 - A2));
        Sy += B2;

        //cout << Sx << " " << Sy;

        double Fx = A1 * A3 * (Ry - Sy) + Rx * A3 * (Sy - B1) + Rx * Sx * (B1 - B3) + A1 * Sx * (B3 - Ry);
        Fx /= (Sy - B3) * (Rx - A1) - (Ry - B1) * (Sx - A3);

        double Fy = (Fx - Sx) / (Sx - A3) * (Sy - B3) + Sy;

        //cout << Fx << " " << Fy;

        //Draw(Fx, Fy);

        // https://www.desmos.com/calculator/olr6m8bcpq?lang=ru

        arr[0] = Fx, arr[1] = Fy;

    }
}

void Draw(double Fx, double Fy, double A1, double B1, double A2, double B2, double A3, double B3) {
    /*setzoom(zoom);
    buildspeed(speed);
    initwindow(screenx, screeny);*/

    setcolor(DARKGRAY);

    line(graphX(A1), 800 - graphX(B1), graphX(A2), 800 - graphX(B2));
    line(graphX(A1), 800 - graphX(B1), graphX(A3), 800 - graphX(B3));
    line(graphX(A2), 800 - graphX(B2), graphX(A3), 800 - graphX(B3));

    setcolor(LIGHTRED);

    line(graphX(Fx), 800 - graphX(Fy), graphX(A2), 800 - graphX(B2));
    line(graphX(Fx), 800 - graphX(Fy), graphX(A3), 800 - graphX(B3));
    //line(graphX(Fx), 800 - graphX(Fy), graphX(A1), 800 - graphX(B1));

    setcolor(CYAN);

    fillellipse(graphX(A1), graphY(B1), 5, 5);
    fillellipse(graphX(A2), graphY(B2), 5, 5);
    fillellipse(graphX(A3), graphY(B3), 5, 5);
    fillellipse(graphX(Fx), graphY(Fy), 5, 5);

    cout << "Info:\n\n"
        << "Point 1: (" << A1 << ", " << B1 << ")\n"
        << "Point 2: (" << A2 << ", " << B2 << ")\n"
        << "Point 3: (" << A3 << ", " << B3 << ")\n\n"
        << "Steiner's Point: (" << Fx << ", " << Fy << ")\n";

    //getch();
    //closegraph();
}

int main() {
    setzoom(0.5);
    initwindow(800, 800); Axes();
    ifstream fin("Points.txt");
    fin >> Aa1 >> Bb1 >> Aa2 >> Bb2 >> Aa3 >> Bb3 >> Aa4 >> Bb4;

    SP(Aa1, Bb1, Aa2, Bb2, Aa3, Bb3);
    float Px = arr[0], Py = arr[1];
    Draw(Px, Py, Aa1, Bb1, Aa2, Bb2, Aa3, Bb3);

    SP(Aa2, Bb2, Aa1, Bb1, Aa4, Bb4);
    float Qx = arr[0], Qy = arr[1];
    Draw(Qx, Qy, Aa2, Bb2, Aa1, Bb1, Aa4, Bb4);

    setcolor(LIGHTRED);
    line(graphX(Px), 800 - graphX(Py), graphX(Qx), 800 - graphX(Qy));

    getch();
    closegraph();


/*
    
0	0
1	2
-2	3
1	-1

-8	-4
0	0
-2	4
-4	0

-4	-4
5	5
-4	3
5	-5

-4	-4
4	4
-4	4
4	-4

-2	-4
5	2
-4	4
0	-4

*/
}
