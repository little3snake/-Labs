#include <iostream>
#include <iomanip>
#include <ctime>

#include "Employee.h"
//#include "Engineer.h"
#include "Factory.h"
//#include "Interfaces.h"
//#include "Manager.h"
//#include "Personal.h"

using namespace std;

class Factory;
int main() {
    // создание штата сотрудников на основе файла
    srand(time(nullptr));
    vector<Employee*> staff = Factory::makeStaff("../info/staff_info.txt");
    // присвоение отработанного времени
    for(Employee* emp: staff) {
        emp -> setWorkTime(); // random
    }
    // расчет зарплаты
    for(Employee* emp: staff) {
        emp -> calc_salary();
    }
    // вывод данных о зарплате
    cout
        << left
        << setw(40)
        << "Name"
        << left
        << setw(20)
        << "Position"
        << left
        << setw(13)
        << "Work_time"
        << left
        << setw(10)
        << "Payment"
        << endl;
    for(Employee* emp: staff) {
        emp -> print_info();
        cout << endl;
    }
    return 0;
}