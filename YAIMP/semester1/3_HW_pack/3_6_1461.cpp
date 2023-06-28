#include <iostream>
#include <string>
using namespace std;

int main() {
    string main_str = "", element;
    int element_count, cur_count = 1, del_count = 0, index = -1; cin >> element_count;
    bool equal_elements = true;

    for (int i = 0; i < element_count; i++){
        cin >> element;
        main_str += element;
    } main_str += " "; element_count = -1;

    while (equal_elements) {
        //cout << del_count << " <1> " << element_count << endl;/////

        for (int i = 0; i < main_str.length(); i++) {

            if (main_str[i] == main_str[i + 1]) {
                cur_count++;
                if (index == -1) { index = i; }

            } else {

                if (cur_count > 2) {
                    del_count += cur_count;
                    main_str.replace(index, cur_count, "");

                }
                index = -1;
                cur_count = 1;
                //cout << del_count << " <2> " << element_count << endl;/////
            }
        }
        if (element_count == del_count){ equal_elements = false; }
        else { element_count = del_count; }
    }
    cout << del_count << endl;
}
