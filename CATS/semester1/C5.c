#include <stdio.h>
#include <math.h>

int main() {
    FILE* fin  = fopen("input.txt", "r"),
        * fout = fopen("output.txt", "w");

    float price,
          price_buffer;
    int kaunt;
    float result[1000] = {};

    fscanf(fin , "%f", &price);
    fscanf(fin , "%d", &kaunt);

    int sqrt_price = floor(sqrt(price)),
        condit = 0, sqrt_buffer;

    while (sqrt_price > 0) {

        price_buffer = price;
        price_buffer = price_buffer - sqrt_price  * sqrt_price; // Проверка на наличие корня у переменной price
        result[0] = sqrt_price;

        if (price_buffer != 0){ // Проверка отстатка от верхних вычислений
            for (int i = 1; i < kaunt; i++) {

                sqrt_buffer = floor(sqrt(price_buffer));
                price_buffer = price_buffer - sqrt_buffer * sqrt_buffer;
                result[i] = sqrt_buffer;

                if (price_buffer == 0) {
                    kaunt = i + 1;
                    condit = 1; break; }
            }
        }
        else { condit = 1; kaunt = 1; }
        sqrt_price--;
        if (condit == 1) { break; }

    }
    if (condit != 0) {
        fprintf(fout,"YES\n");
        for (int i = 0; i < kaunt; i++){ fprintf(fout, "%d ", (int)result[i]); }
    }
    if (condit == 0){ fprintf(fout,  "NO\n"); }
}
