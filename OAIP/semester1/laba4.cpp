// --- --- --- 1


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main() {
//
//	FILE* fin = fopen("input1.txt", "r");
//	FILE* fout = fopen("output1.ass", "w");
//
//	int num, indeh = 999, count = 0; fscanf(fin, "%d\n", &num);
//	char A, B; 
//	fscanf(fin, "%c\n", &A);
//	fscanf(fin, "%c", &B);
//
//	printf("A und B sind: %c %c\n", A, B);
//
//	srand(time(NULL));
//	char* arr;
//	arr = (char*)malloc(sizeof(char) * num);
//
//	for (int i = 0; i < num; i++) {
//		arr[i] = 65 + (rand() % 26);
//		printf("%c ", arr[i]);
//
//		if (arr[i] == A) { indeh = i; }
//		if (arr[i] == B and indeh < i) { count++; indeh = 999; }
//
//	} printf("\n");
//
//	fprintf(fout, "%d", count);
//
//	fclose(fin); fclose(fout);
//}


// --- --- --- 2


//#include <stdio.h>
//#include <stdlib.h>
//
//int main(){
//
//	FILE* fin = fopen("input2.txt", "r");
//	FILE* fout = fopen("output2.ass", "w");
//
//	int num, count_of_el = 1, max_count = -1, str_count = 0; fscanf(fin, "%d", &num);
//
//	char* arr = (char*)malloc(sizeof(num));
//	int* sizes_of_substr = (int*)malloc(sizeof(num)); sizes_of_substr[0] = 0;
//
//	fscanf(fin, "%c\n", &arr[0]);
//	for (int i = 1; i < num; i++) {
//		fscanf(fin, "%c\n", &arr[i]);
//
//		if (arr[i - 1] == arr[i]) { count_of_el++; sizes_of_substr[i] = 0; }
//		else { 
//			sizes_of_substr[i] = count_of_el;
//			count_of_el = 1;
//		}
//		max_count = (max_count < sizes_of_substr[i]) ? sizes_of_substr[i] : max_count;
//	}
//
//	for (int i = 1; i < num; i++) {
//		printf("%d ", sizes_of_substr[i]);
//		if (sizes_of_substr[i] == max_count) { str_count++; }
//	}
//
//	printf("\n%d", max_count);
//	fprintf(fout, "%d", str_count);
//	fclose(fin);  fclose(fout);
//}


// --- --- --- 3


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main(){
//
//	srand(time(NULL));
//
//	FILE* fin = fopen("input3.txt", "r");
//	FILE* fout = fopen("output3.ass", "w");
//
//	int str_len = 10 + rand() % 11, substr_len;
//	char* main_str = (char*)malloc(sizeof(char) * str_len);
//
//	fscanf(fin, "%d\n", &substr_len);
//
//	char* sub_str1 = (char*)malloc(sizeof(char) * substr_len);
//	char* sub_str2 = (char*)malloc(sizeof(char) * substr_len);
//
//	for (int i = 0; i < substr_len; i++) {
//		fscanf(fin, "%c\n", &sub_str1[i]);
//		printf("%c ", sub_str1[i]);
//	} printf("\n");
//
//	for (int i = 0; i < substr_len; i++) {
//		fscanf(fin, "%c\n", &sub_str2[i]);
//		printf("%c ", sub_str2[i]);
//	} printf("\n\n");
//
//	for (int i = 0; i < str_len; i++) {
//		main_str[i] = 65 + (rand() % 26);
//		printf("%c ", main_str[i]);
//
//		for (int j = 0; j < substr_len; j++) {
//			if (main_str[i] == sub_str1[j]) {
//				main_str[i] = sub_str2[j];
//			}
//		}
//	} printf("\n\n");
//
//	for (int i = 0; i < str_len; i++) {
//		fprintf(fout, "%c ", main_str[i]);
//	}
//  fclose(fin); fclose(fout);
//}


// --- --- --- 4


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main() {
//
//    srand(time(NULL));
//
//    FILE* fin = fopen("input4.txt", "r");
//    FILE* fout = fopen("output4.ass", "w");;
//    
//    int count; char* arr;
//    fscanf_s(fin, "%d", &count);
//    arr = (char*)malloc(sizeof(char) * count);
//
//    for (int i = 0; i < count; i++) {
//        arr[i] = 48 + rand() % 2;
//        printf("%c ", arr[i]);
//    }
//
//    for (int i = 0; i < (count / 2); i++) {
//        if (arr[i] == arr[count - i - 1]) {
//            fprintf(fout, "%c ", arr[i]);
//        }
//        else { return 0; }
//    }
//}


// --- --- --- 5


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//int main() {
//
//	FILE* fin = fopen("input5.txt", "r");
//	FILE* fout = fopen("output5.ass", "w");
//
//	int main_len, sub_len, index_of_min = 1;
//	char iterable_sym;
//	fscanf(fin, "%d", &main_len); fscanf(fin, "%d", &sub_len);
//
//	srand(time(NULL));
//
//	char* main_str = (char*)malloc(sizeof(char) * (main_len + main_len / sub_len));
//
//	for (int i = 0; i < main_len + main_len / sub_len + 1; i++) {
//		if (i % (sub_len + 1) == 0 ) { main_str[i] = '\n'; }
//		else { main_str[i] = 65 + (rand() % 26); }
//
//		printf("%c", main_str[i]);
//	}
//
//	for (int l = 0; l < main_len / sub_len; l++) {
//
//		iterable_sym = main_str[1];
//		for (int i = sub_len + 2; i < (main_len / sub_len) * (sub_len + 1); i += sub_len + 1) {
//
//			if (iterable_sym > main_str[i]) {
//				iterable_sym = main_str[i];
//				index_of_min = i;
//			}
//		}
//
//		for (int i = index_of_min; i < index_of_min + sub_len; i++) {
//			fprintf(fout, "%c", main_str[i]);
//		} fprintf(fout, " ");
//		main_str[index_of_min] = (char) (91 + l);
//
//		index_of_min = 1;
//	}
//}


// --- --- --- 6


//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#define obosrand srand
//
//int main() {
//
//	FILE* fin = fopen("input6.txt", "r");
//	FILE* fout = fopen("output6.ass", "w");
//
//	int main_len, sub_len;
//	fscanf(fin, "%d", &main_len);
//	fscanf(fin, "%d", &sub_len);
//	int begin_index = 0, end_index = sub_len;
//
//	obosrand(time(NULL));
//
//	char* main_str = (char*)malloc(sizeof(char) * (main_len + main_len / sub_len));
//
//	for (int i = 0; i < main_len + main_len / sub_len + 1; i++) {
//		if (i % (sub_len + 1) == 0) { main_str[i] = '\n'; }
//		else { main_str[i] = 65 + (rand() % 26); }
//
//		printf("%c", main_str[i]);
//	}
//
//	for (int l = 0; l < main_len / sub_len; l++) {
//
//		for (int i = end_index; i > begin_index; i--) {
//			fprintf(fout, "%c", main_str[i]);
//		} fprintf(fout, "\n");
//
//		end_index += sub_len + 1;
//		begin_index += sub_len + 1;
//	}
//}


// --- --- --- 7


#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE* file_helper = fopen("file_helper7.ass", "w");
    FILE* fout = fopen("output7.ass", "w");

    int elem_count, minus_in_begin = 0, count_bracket_open = 0, count_bracked_close = 0;
    printf("Set length: "); scanf_s("%d", &elem_count);

    auto expression = (char *)malloc(sizeof(char) * (elem_count + 2));
    printf("Bring diese Scheisse: ");

    getchar();

    for (int i = 0; i < elem_count + 1; i++) {
        scanf_s("%c", &expression[i]);
        fprintf(file_helper, "%c", expression[i]);
    }
    for (int i = 0; i < elem_count + 1; i++) {
        printf("%d ", expression[i]);
    }

    if (expression[0] == '-') { minus_in_begin = 1; }

    if ((expression[0] == '+') or (expression[0] == '/') or (expression[0] == '*') or (expression[0] == ')')) {
        fprintf(fout, "WRONG");
        return 0;
    }

    for (int i = 0; i < elem_count; i++) {
            if (expression[1] == ')') {
                fprintf(fout, "WRONG");
                return 0;
            }
            if ((expression[1] == '-' or expression[1] == '/' or expression[1] == '+' or expression[1] == '*') and
                (minus_in_begin == 1)) {
                fprintf(fout, "WRONG");
                return 0;
            }
            if (expression[0] == '(' and (expression[i] == '*' or expression[i] == '+' or expression[i] == '/')) {
                fprintf(fout, "WRONG");
                return 0;
            }
            if (((expression[i] == '+' or expression[i] == '-' or expression[i] == '/' or expression[i] == '*') and
                (expression[i + 1] == '+' or expression[i + 1] == '-' or expression[i + 1] == '/' or
                 expression[i + 1] == '*')) and !((expression[i] == '+' or expression[i] == '-' or
                     expression[i] == '/' or expression[i] == '*') and expression[i + 1] == '(')) {
                fprintf(fout, "WRONG");
                return 0;

            }
            if (expression[elem_count] == '-' or expression[elem_count] == '*' or expression[elem_count] == '/' or
                expression[elem_count] == '+' or expression[elem_count] == '(') {
				fprintf(fout, "WRONG");
				return 0;
			}
            if (expression[i] == ')') { count_bracked_close += 1; }
            if (expression[i] == '(') { count_bracket_open += 1; }

        }

    if ((expression[elem_count] != ')' and count_bracket_open != count_bracked_close) or
        (expression[elem_count]) == ')' and (count_bracked_close + 1) != count_bracket_open) {
        fprintf(fout, "WRONG");
        return 0;
    }

    fprintf(fout, "RIGHT");
    fclose(fout); fclose(file_helper);
}


// --- --- --- 8


//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//
//	FILE* fin = fopen("input8.txt", "r");
//	FILE* fout = fopen("output8.ass", "w");
//
//	char Das_Wort[100];
//	int only_ints = 1, is_error = 0; // only_funs
//
//	while (!feof(fin)) {
//
//		fgets(Das_Wort, 100, fin);
//
//		for (int i = 0; Das_Wort[i] != 0; i++) {
//
//			if (Das_Wort[i] != 10) {
//
//				if ((Das_Wort[i] < 48) or (Das_Wort[i] > 57 and Das_Wort[i] < 65)
//					or (Das_Wort[i] > 90 and Das_Wort[i] < 97 and Das_Wort[i] != 95) or (Das_Wort[i] > 122)) {
//					is_error = 1;
//				}
//
//				if ((Das_Wort[i] > 64 and Das_Wort[i] < 91) or (Das_Wort[i] > 96 and Das_Wort[i] < 123)) {
//					only_ints = 0;
//				}
//
//				if (((Das_Wort[0] < 65) or (Das_Wort[0] > 90 and Das_Wort[0] < 97 and Das_Wort[0] != 95) or (Das_Wort[0] > 122)) and (only_ints == 0)) {
//					is_error = 1;
//				}
//
//				if (Das_Wort[0] == 95 and only_ints == 1) {
//					only_ints = 0;
//				}
//
//				if ((Das_Wort[0] == 'i' and Das_Wort[1] == 'n' and Das_Wort[2] == 't' and Das_Wort[3] == 10) or /* int */
//
//					(Das_Wort[0] == 'c' and Das_Wort[1] == 'h' and Das_Wort[2] == 'a' and Das_Wort[3] == 'r' and Das_Wort[4] == 10) or /* char */
//					/*--- --- --- --- ---*/
//					(Das_Wort[0] == 'f' and Das_Wort[1] == 'l' and Das_Wort[2] == 'o' and Das_Wort[3] == 'a' and Das_Wort[4] == 't' and Das_Wort[4] == 10) or /* float */
//
//					(Das_Wort[0] == 'd' and Das_Wort[1] == 'o' and Das_Wort[2] == 'u' and Das_Wort[3] == 'b' and Das_Wort[4] == 'l' and Das_Wort[4] == 'e' and Das_Wort[5] == 10) or /* double */
//					/*--- --- --- --- ---*/
//					(Das_Wort[0] == 'i' and Das_Wort[1] == 'f' and Das_Wort[2] == 10) or /* if */
//
//					(Das_Wort[0] == 'a' and Das_Wort[1] == 'n' and Das_Wort[2] == 'd' and Das_Wort[3] == 10) or /* and */
//					/*--- --- --- --- ---*/
//					(Das_Wort[0] == 'f' and Das_Wort[1] == 'o' and Das_Wort[2] == 'r' and Das_Wort[3] == 10) or /* for */
//
//					(Das_Wort[0] == 'o' and Das_Wort[1] == 'r' and Das_Wort[2] == 10) or /* or */
//					/*--- --- --- --- ---*/
//					(Das_Wort[0] == 'w' and Das_Wort[1] == 'h' and Das_Wort[2] == 'i' and Das_Wort[3] == 'l' and Das_Wort[4] == 'e' and Das_Wort[4] == 10) or /* while */
//
//					(Das_Wort[0] == 'r' and Das_Wort[1] == 'e' and Das_Wort[2] == 't' and Das_Wort[3] == 'u' and Das_Wort[4] == 'r' and Das_Wort[4] == 'n' and Das_Wort[5] == 10)) { /* return */
//					is_error = 1;
//				}
//			}
//		}
//
//		if (is_error == 0) {
//
//			if (only_ints == 1) { fprintf(fout, "CONST\n"); }
//			else { fprintf(fout, "IDENT\n"); }
//		}
//
//		else { fprintf(fout, "ERROR\n"); }
//
//		is_error = 0; only_ints = 1;
//	}
//}


// --- --- --- 9


// --- --- --- 10


//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//
//	FILE* fin = fopen("input10.txt", "r");
//	FILE* fout = fopen("output10.ass", "r");
//
//
//}
