// https://fincalculator.ru/kalkulyator-dnej - Калькулятор дней
// https://web2.0calc.com/ - Просто научный калькулятор

#include <iostream>
using namespace std;

int main() {
    int day, mouth, year, bday, bmouth;
    cin >> bday >> bmouth;   cin >> day >> mouth >> year;

    int arg = (14 - mouth) / 12,    year_arg = year + 4800 - arg,    mouth_arg = mouth + 12 * arg - 3;

    int JDN = day + (153 * mouth_arg + 2) / 5 + 365 * year_arg + (year_arg / 4) - (year_arg / 100) + (year_arg / 400) - 32045;

    if  (((bmouth < mouth) and (bday != 29 or bmouth != 2)) or ((bmouth == mouth) and (bday < day))) { /* Если месяц рождения перед текущим и др не 29 фев
                                                                                                            ИЛИ др в одном месяце с тек.датой, но уже прошёл */
        year++;
        //cout << "first\n";/////
    }

    else if ( (!(((year % 4 == 0) and (year % 100 != 0)) or (year % 400 == 0)) or ((mouth > 2) and
        (((year % 4 == 0) and (year % 100 != 0)) or (year % 400 == 0)))) and (bday == 29 and bmouth == 2) ) { // Добавление дней, если др 29 фев

        for (int i = year; i < 3000; i++) { // Проверка года на "високосность"
            year++;
            if ( (((year % 4 == 0) and (year % 100 != 0)) or (year % 400 == 0)) ) {
                //cout << "\nsecond\n";/////
                break;
            }
        }
    }

    int arg2 = (14 - bmouth) / 12,     year_arg2 = year + 4800 - arg2,     mouth_arg2 = bmouth + 12 * arg2 - 3;

    int JDN2 = bday + (153 * mouth_arg2 + 2) / 5 + 365 * year_arg2 + (year_arg2 / 4) - (year_arg2 / 100) + (year_arg2 / 400) - 32045;

    cout << JDN2 - JDN << endl;
}
