#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

struct chelik {
    float height;
    char name[256];
};

struct chelik* arr_buf;

long long merge(struct chelik arr[], struct chelik arr_buf[], int left, int mid, int right) {

    int i, j, k;
    int count = 0;

    i = left;
    j = mid;
    k = left;

    while ((i <= mid - 1) and (j <= right)) {

        if ((arr[i].height >= arr[j].height)) { arr_buf[k++] = arr[i++]; }
        else {
            arr_buf[k++] = arr[j++];
            count += (mid - i);
        }
    }

    while (i <= mid - 1) { arr_buf[k++] = arr[i++]; }

    while (j <= right) { arr_buf[k++] = arr[j++]; }

    for (i = left; i <= right; i++) { arr[i] = arr_buf[i]; }

    return count;
}

long long true_merge(struct chelik arr[], struct chelik arr_buf[], int left, int right) {

    int mid;
    long long count = 0;
    if (right > left) {

        mid = (right + left) / 2;
        count += true_merge(arr, arr_buf, left, mid);
        count += true_merge(arr, arr_buf, mid + 1, right);

        count += merge(arr, arr_buf, left, mid + 1, right);
    }
    return count;
}

long long merge_sort(struct chelik arr[], int size) {

    arr_buf = (struct chelik*)malloc(sizeof(struct chelik) * size);
    return true_merge(arr, arr_buf, 0, size - 1);
}

int main() {

    FILE* fin = fopen("input.txt", "r"),
        * fout = fopen("output.txt", "w");

    int K;
    fscanf(fin, "%d", &K);
    struct chelik* Arr = (struct chelik*)malloc((sizeof(struct chelik)) * K);

    for (int i = 0; i < K; i++) {
        fscanf(fin, "%f %s", &Arr[i].height, &Arr[i].name);
    }

    long long res = merge_sort(Arr, K);
    fprintf(fout, "%lld", res);
}
