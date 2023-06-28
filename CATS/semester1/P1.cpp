#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//#include <C+.h>

int main() {
    FILE* fin = fopen("input.txt", "r"),
        * fout = fopen("output.txt", "w");

    int N; fscanf(fin, "%d", &N);

    auto arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) { fscanf(fin, "%d", &arr[i]); }

    //if (N == 2) { 

    int max_sum = 0, 
        Lindex, Mindex, Rindex;

    for (int i = 0; i < N - 1; i++) {

        int rbuf = i, 
            mbuf = i,
            M_sum = arr[i], 
            R_sum = 0;

        while (rbuf < N) {

            if (M_sum < R_sum) {
                mbuf++; //
                M_sum += arr[mbuf];
                R_sum -= arr[mbuf];
            }

            else { rbuf++; R_sum += arr[rbuf]; }

            if ((M_sum == R_sum) and (M_sum > max_sum)) { max_sum = M_sum;

                Lindex = i + 1;
                Mindex = mbuf + 1;
                Rindex = rbuf + 1;
                // cout(max_sum); cout(" "); cout(Lindex); cout(" "); cout(Mindex); cout(" "); cout(Rindex);
            }
        }
    }

    if (max_sum) { fprintf(fout, "%d %d %d", Lindex, Mindex, Rindex); }
    else { fprintf(fout, "%d", -1); }
}

/*

[1 2  3] 4 5 
[1 2  3] 4 5 6

1 2 3 [4 5  9]

*/
