#include <stdio.h>
#include <stdlib.h>

struct obj{ // жалкие попытки оптимизировать предыдущий код закончились
    int current_obj; // желанием снести винду с ноутбука. 
    int cur_index; // Я забил болт и пошел играться со структурками,
}; // после чего осознал, что это может быть быстрее, чем тупой прогон.

void merg_sort(struct obj* arr, int left, int right)
{
    if (left == right) { return; }
    int mid = (left + right) / 2;

    merg_sort(arr, left, mid);
    merg_sort(arr, mid + 1, right);

    int i = left,
        j = mid + 1;
    struct obj cur[right];

    for (int k = 0; k < right - left + 1; k++) {

        if ((j > right) || ((i <= mid) && (arr[i].current_obj < arr[j].current_obj))) {
            cur[k] = arr[i];
            i++;
        }
        else { cur[k] = arr[j]; j++; }
    }
    for (int k = 0; k < right - left + 1; k++) { arr[left + k] = cur[k]; }
}

int main(){
    FILE* fin = fopen("shelter.in", "r"),
        * fout = fopen("shelter.out", "w");

    int vil_count, 
        shel_count;
    fscanf(fin, "%d", &vil_count);

    struct obj arr_village[vil_count];
    for (int i = 0; i < vil_count; i++) {
        fscanf(fin,"%d", &arr_village[i].current_obj);
        arr_village[i].cur_index = i + 1;
    }

    fscanf(fin, "%d", &shel_count);

    struct obj arr_shelter[shel_count];
    for (int i = 0; i < shel_count; i++) {
        fscanf(fin, "%d", &arr_shelter[i].current_obj);
        arr_shelter[i].cur_index = i + 1;
    }

    merg_sort(arr_village, 0, vil_count - 1);
    merg_sort(arr_shelter, 0, shel_count - 1);

    int counter = 0,
        length,
        min_length;
    int help_arr[vil_count];

    for (int i = 0; i < vil_count; i++) {
        min_length = abs(arr_village[i].current_obj - arr_shelter[counter].current_obj);
        length = abs(arr_village[i].current_obj - arr_shelter[counter + 1].current_obj);

        while (min_length >= length) {
            counter++;
            min_length = length;
            length = abs(arr_village[i].current_obj - arr_shelter[counter + 1].current_obj);

            if (counter == shel_count) {
                for (int j = i; j < vil_count; j++) { help_arr[arr_village[j].cur_index] = arr_shelter[counter].cur_index; }
                return 0;
            }
        }
        help_arr[arr_village[i].cur_index] = arr_shelter[counter].cur_index;
    }
    for (int i = 1; i <= vil_count; i++) { fprintf(fout, "%d ", help_arr[i]); }
} 
// задача гавно
