#include "Personal.h"

Personal::Personal(const int id, const std::string& fio, int salary, Positions position)
        : Employee (id, fio, position), salary (salary){}

int Personal::calc_base_salary(int salary_calc, int work_time)  {
    return work_time * salary_calc;
}

Driver::Driver(const int id, const std::string& fio, int salary, Positions position, int night_hours)
    : Personal (id, fio, salary, position), night_hours (night_hours) {}

int Driver::calc_bonus_salary(int bonus) { // int night hours
    return bonus * night_hours; // 15  - is night hours
    //                                               question how to calculate bonus salary (where these hours)
}

int Driver::calc_salary() {
    return payment = calc_base_salary(salary, work_time) + calc_bonus_salary(400);
}

Cleaner::Cleaner(const int id, const std::string& fio, int salary, Positions position)
    : Personal (id, fio, salary, position) {}

int Cleaner::calc_bonus_salary(int bonus) {
    return 0;
}

int Cleaner::calc_salary() {
    return payment = calc_base_salary(salary, work_time);
}
