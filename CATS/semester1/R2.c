#include <stdio.h>

int main() {
    FILE *fin = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");

    int N, M,
        sum = 0,
        bit_counter = 0,
        let_counter = 0,
        bit_counter2 = 0,
        let_counter2 = 0;

    int bit_arr[2][10000] = {},
        let_arr[10000] = {};
    char prev_let = -1,
         cur_bit;

    fscanf(fin, "%d%d\n", &N, &M);

    for (int i = 0; i < N; i++) {
        fscanf(fin, "%c", &cur_bit);
        if (cur_bit == '0') { ++bit_counter; }
        else {
            if (bit_counter) { bit_arr[0][bit_counter2++] = -bit_counter; }
            bit_arr[0][bit_counter2++] = 1;
            bit_counter = 0;
        }
    }
    if (cur_bit == '0') bit_arr[0][bit_counter2++] = -bit_counter;
    fscanf(fin, "\n");

    for (int j = 0; j < M; j++) {
        fscanf(fin, "%c", &cur_bit);
        if (cur_bit == prev_let) { ++let_counter; }
        else {
            if (let_counter) { let_arr[let_counter2++] = let_counter * ((prev_let == 'b') ? 1 : -1); }
            let_counter = 1;
            prev_let = cur_bit;
        }
    }
    let_arr[let_counter2++] = let_counter * ((prev_let == 'b') ? 1 : -1);

    if (let_arr[0] < 0) {
        for (int i = 0; sum + (bit_arr[0][i] * ((bit_arr[0][i] >> 31) | 1)) <= -let_arr[0] && i < bit_counter2; i++) {
            sum += (bit_arr[0][i] * ((bit_arr[0][i] >> 31) | 1));
            bit_arr[1][i] = 1;
        }
    } else {
        for (int i = 0; ++sum <= let_arr[0] && i < bit_counter2 && bit_arr[0][i] == 1; bit_arr[1][i++] = 1);
    }

    for (int j = 1; j < let_counter2; j++) {
        for (int i = bit_counter2 - 1; i >= 0; i--) {

            if (bit_arr[1][i]) {
                sum = 0;
                if (let_arr[j] < 0) {
                    for (int k = i + 1; (sum + (bit_arr[0][i] * ((bit_arr[0][i] >> 31) | 1)) <= -let_arr[j]) && k < bit_counter2; k++) {
                        sum += (bit_arr[0][i] * ((bit_arr[0][i] >> 31) | 1));
                        bit_arr[1][k] = 1;
                    }
                } else {
                    for (int k = i + 1; ++sum <= let_arr[j] && bit_arr[0][k] == 1; bit_arr[1][k++] = 1);
                }
                bit_arr[1][i] = 0;
            }
        }
    }

    fprintf(fout, "%c", bit_arr[1][bit_counter2 - 1] ? 'Y' : 'N');
} // гавно
