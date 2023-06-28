#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int num, element_of_set; cin >> num;
    string command;

    set <int> num_set;

    while (num > 0){
        cin >> command;
        num--;

        if (command == "ADD"){
            cin >> element_of_set;
            num_set.insert(element_of_set);
            //cout << num_set.size() << " " << command << " " << element_of_set << endl;///
        }

        if (command == "COUNT"){
            cout << num_set.size() << endl;
        }

        if (command == "PRESENT"){
            cin >> element_of_set;
            if (num_set.count(element_of_set) == 0){ cout << "NO\n"; }
            else { cout << "YES\n"; }
        }
    }
}
