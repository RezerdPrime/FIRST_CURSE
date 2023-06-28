#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>
using namespace std;

int main() {
    cout << "Name" << setw(24) << "Size" << setw(24) << "Min" << setw(24) << "Max" << endl;
    cout << "Bool" << setw(24) << sizeof(bool) << setw(24) << 0 << setw(24) << 1 << endl;
    cout << "Char" << setw(24) << sizeof(char) << setw(24) << CHAR_MIN << setw(24) << CHAR_MAX << endl;
    cout << "Unsigned Char" << setw(15) << sizeof(unsigned char) << setw(24) << 0 << setw(24) << UCHAR_MAX << endl;
    cout << "Short" << setw(23) << sizeof(short) << setw(24) << SHRT_MIN << setw(24) << SHRT_MAX << endl;
    cout << "Unsigned Short" << setw(14) << sizeof(unsigned short) << setw(24) << 0 << setw(24) << USHRT_MAX << endl;
    cout << "Int (Long)" << setw(18) << sizeof(int) << setw(24) << INT_MIN << setw(24) << INT_MAX << endl;
    cout << "Unsigned Int (Long)" << setw(9) << sizeof(unsigned int) << setw(24) << 0 << setw(24) << UINT32_MAX << endl;
    cout << "Long Long" << setw(19) << sizeof(long long) << setw(24) << LLONG_MIN << setw(24) << LLONG_MAX << endl;
    cout << "Unsigned Long Long" << setw(10) << sizeof(unsigned long long) << setw(24) << 0 << setw(24) << ULLONG_MAX << endl << endl;
    cout << "Float" << setw(23) << sizeof(float) << setw(24) << FLT_MIN << setw(24) << FLT_MAX << endl;
    cout << "Double" << setw(22) << sizeof(double) << setw(24) << DBL_MIN << setw(24) << DBL_MAX << endl;
    cout << "Long Double" << setw(17) << sizeof(long double) << setw(24) << LDBL_MIN << setw(24) << LDBL_MAX << endl;
}
