#include <stdio.h>

int main()
{
    FILE *f1 = fopen("input.txt","r"),
         *f2 = fopen("output.txt","w");

    long long matrix_order, str_num,
              i, j, condit = 1,
              delta1, delta2, count1 = 0;

    fscanf(f1, "%lld%lld" ,&matrix_order ,&str_num);

    long long string[matrix_order],
              count2 = matrix_order * matrix_order,
              n_buf1 = matrix_order,
              n_buf2 = matrix_order;
    
    for (j = 0; j <= matrix_order - 1; j++){ string[j] = 1; }
    i = 0;
    j = 0;

    while (count2 > 0) { // четыре велика нужны для прогона всех 4 сторон квадратной матрицы (числовой спирали)

        while (n_buf1 > condit && count2 > 0) {
            if (i != str_num - 1) {
                count2 -= n_buf1 - condit;
                j += n_buf1 - condit;
                n_buf1 = condit;

            } else {
                if (i == str_num - 1) { string[j] = count2; }
                j += 1;
                n_buf1--;
                count2--;
            }
        }
        condit = 0;
        n_buf1 = n_buf2;

        while ( n_buf1 > 1 && count2 > 0) {
            if (i <= str_num - 1){
                delta1 = str_num - i - 1;
                delta2 = n_buf2 - 1;
                if (string[j] == 1){ string[j] = count2 - delta1; }
                    i = n_buf2 - 1 + i;
                    count2 -= delta2;
                    n_buf1 = 0;

            } else {
                delta1 = str_num - i - 1;
                delta2 = n_buf2 - 1;
                i = n_buf2 - 1 + i;
                count2 -= delta2;
                n_buf1 = 0;
            }

        }
        n_buf1 = n_buf2;

        while ( n_buf1 > 1 && count2 > 0) {
            if (i != str_num - 1){
                count2 -= n_buf1 - 1;
                j -= n_buf1 - 1;
                n_buf1 = 1;
            } else {
                if (i == str_num - 1) { string[j] = count2; }
                j -= 1;
                n_buf1--;
                count2--;
            }
        }
        n_buf1 = n_buf2;

        while ( n_buf1 > 2 && count2 > 0) {
            if (i >= str_num - 1) {
                delta1 = i - str_num + 1;
                delta2 = n_buf2 - 2;
                if (string[j] == 1) { string[j] = count2 - delta1; }
                i = count1 + 1;
                count2 -= delta2;
                n_buf1 = 0;

            } else {
                delta1 = i - str_num + 1;
                delta2 = n_buf2 - 2;
                i = count1 + 1;
                count2 -= delta2;
                n_buf1 = 0;
            }
        }

        if (count2 == 1) { count2 = 0; }

        count1++;
        n_buf2 -= 2;
        n_buf1 = n_buf2;
    }
    for (j = 0; j <= matrix_order - 1; j++){
        fprintf(f2, "%lld", string[j]);
        if (j < matrix_order - 1){ fprintf(f2, " "); }
    }
}
