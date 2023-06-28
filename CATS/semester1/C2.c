//#define _CRT_SECURE_NO_WARNINGS
//#define and &&
#include <stdio.h>

//void switcher(

int main() {
    FILE *fin = fopen("input.txt","r"),
         *fout = fopen("output.txt","w");

    char N, i, max; // char для некой экономии памяти

    int sum_in_1 = 0,
        sum_in_2 = 0;

    fscanf(fin,"%hhi",&N);

    char orig_arr[N], edited_arr1[N], edited_arr2[N]; // Визуалка меня предала на этом моменте
// orig_arr - это начальный массив из длин досок
// edired_arr1 - массив, собранный по принципу "Нечётные выше чётных"
// edited_arr2 - массив, собранный по обратному принципу

// sum_in_1 - сумма в первом изменённом первом
// sum_in_2 - аналогично во втором

    if (N < 3) {
        if (N == 2) {
            for (i = 0; i < N; i++) { fscanf(fin,"%hhi",&orig_arr[i]); }

            if (orig_arr[0] != orig_arr[1]) { fprintf(fout,"%hhi %hhi",orig_arr[0],orig_arr[1]); }

            else { fprintf(fout,"%hhi %hhi",orig_arr[0] + 1,orig_arr[1]); }
        } else {
            fscanf(fin,"%hhi",&orig_arr[0]);
            fprintf(fout,"%hhi",orig_arr[0]);
        }
    } else {
        for (i = 0; i < N; i++) { fscanf(fin,"%hhi",&orig_arr[i]); }

        for (i = 1; i < N; i += 2) {
            if ((orig_arr[i] > orig_arr[i + 1]) && (orig_arr[i] > orig_arr[i - 1])) {
                edited_arr1[i] = orig_arr[i];
                edited_arr1[i + 1] = orig_arr[i + 1];
                edited_arr1[i - 1] = orig_arr[i - 1];
            } else {
                if (orig_arr[i + 1] > orig_arr[i-1]) { max = orig_arr[i + 1];

                } else { max = orig_arr[i - 1]; }

                edited_arr1[i] = max + 1;
                edited_arr1[i + 1] = orig_arr[i + 1];
                edited_arr1[i - 1] = orig_arr[i - 1];
            }
        }
        if (N % 2 == 0) {
            if (orig_arr[N - 1] <= orig_arr[N - 2]){
                edited_arr1[N - 1] = orig_arr[N - 2] + 1;
            }
        }
        if (orig_arr[0] <= orig_arr[1]) { edited_arr2[0] = orig_arr[1] + 1; }

        else { edited_arr2[0] = orig_arr[0]; }

        for (i = 2; i < N; i += 2) {
            if ((orig_arr[i] > orig_arr[i + 1]) && (orig_arr[i] > orig_arr[i - 1])) {
                edited_arr2[i] = orig_arr[i];
                edited_arr2[i + 1] = orig_arr[i + 1];
                edited_arr2[i - 1] = orig_arr[i - 1];
            } else {
                if (orig_arr[i + 1] > orig_arr[i - 1]) { max = orig_arr[i + 1];
                } else { max = orig_arr[i - 1]; }

                edited_arr2[i] = max + 1;
                edited_arr2[i + 1] = orig_arr[i + 1];
                edited_arr2[i - 1] = orig_arr[i - 1];
            }
        }
        if (N % 2 == 1) {
            if (orig_arr[N - 1] <= orig_arr[N - 2]) { edited_arr2[N - 1] = orig_arr[N - 2] + 1; }
        }
        for (i = 0; i < N; i++){
            sum_in_1 += edited_arr1[i];
            sum_in_2 += edited_arr2[i];
        }
        if (sum_in_1 < sum_in_2){
            for (i = 0; i < N; i++){
                fprintf(fout,"%hhi",edited_arr1[i]);

                if (i != N - 1) { fprintf(fout," "); }
            }
        } else {
            for (i = 0; i < N; i++){
                fprintf(fout,"%hhi",edited_arr2[i]);

                if (i != N - 1){ fprintf(fout," "); }
            }
        }
    }
}

// ОНО РВБОТАЕТ!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! НЕУЖЕЛИ

/*
#define _CRT_SECURE_NO_WARNINGS
#define true 1
#define false 0
#include <stdio.h>

typedef int boolean; //плюсы момент плюсы момент плюсы момент плюсы моментид

void switcher(int& plank_changer, int& prev_plank, int& cur_plank) {
    if (cur_plank > prev_plank) { plank_changer++; }
    else { prev_plank++; }
    return;
}

int main() {
    FILE* fin = fopen("input.txt", "r"),
        * fout = fopen("output.txt", "w");

    int plank_count, // Количество досок
        plank_changer, // Длина доски, изменившей последовательность (обычно 3-я в левую сторону от числа)
        prev_plank, // Длина предыдущей планки
        cur_plank; // Длина оперируемой планки

    boolean prev_state, // Статус последовательности в прошлом. false - опускается, true - поднимается
            cur_state, // Статус последовательности на данный момент. false - опускается, true - поднимается
            equal_state = false;
 */
