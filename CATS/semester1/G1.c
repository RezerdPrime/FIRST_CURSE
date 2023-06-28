#include <math.h>
#include <stdio.h>
//#include <iostream>
//using namespace std;

int main() {
    FILE *fin = fopen("input.txt", "r"),
         *fout = fopen("output.txt", "w");
    int n, m;
    fscanf(fin, "%d", &n);

    int size_of_tree = (int)pow(2, ceil(log2(n)));
    int tree[size_of_tree * 2 + 1];

    for (int i = size_of_tree; i < size_of_tree * 2; i++) { // Чтение массива
        if (i < n + size_of_tree) { fscanf(fin, "%d", &tree[i]); }
        
        else { tree[i] = -(float)(1 << 32); }
    }
    
    for (int i = size_of_tree - 1; i > 0; i--) { // Построение дерева отрезков
        tree[i] = (tree[i * 2] > tree[i * 2 + 1]) ? tree[i * 2] : tree[i * 2 + 1];
    }

    fscanf(fin, "%d", &m);
    int left = 0,
        reft = 0,
        lindex = left,
        rindex = reft;
    int result[m],
        max_elem = tree[size_of_tree];
    
    char shear; // = getc(fin);
    fscanf(fin, "%c", &shear);
    // fscanf(fin, "%c");
    // getc(fin);
    
    for (int i = 0; i < m; i++) {
        // shear = getc(fin);
        fscanf(fin, "%c", &shear);
        // cout << shear << " " << endl;
        if (shear == 'R') { reft++; }
        if (shear == 'L') { left++; }
        
        // cout << endl << l << " " << r << " = ";
		lindex = left + size_of_tree;
		rindex = reft + size_of_tree;

        while (lindex < rindex - 1) {
            // Если левая или правая граница нечётна или чётна соответственно,
	        // то они "захватывают" не всю пару чисел, а лишь одно число из неё
            
            if (rindex % 2 == 0) { max_elem = (max_elem < tree[rindex]) ? tree[rindex] : max_elem; }
            if (lindex % 2 == 1) { max_elem = (max_elem < tree[lindex]) ? tree[lindex] : max_elem; }

            lindex = (lindex + 1) / 2;
            rindex = (rindex - 1) / 2;
        }

        if (lindex == rindex && max_elem < tree[rindex]) { max_elem = tree[rindex]; }
        
        else if (lindex == rindex - 1 && (max_elem < tree[lindex] || max_elem < tree[rindex])) {
            max_elem = (max_elem < tree[lindex]) ? tree[lindex] : max_elem;
            max_elem = (max_elem < tree[rindex]) ? tree[rindex] : max_elem;
        }
        // cout << max_elem << endl;

        result[i] = max_elem;
        max_elem = -1000000000;
        // cout << result[i] << " ";
    }
    // cout << result[0];
    
    fprintf(fout, "%d", result[0]);
    for (int i = 1; i < m; i++) { fprintf(fout, " %d", result[i]); }
}
