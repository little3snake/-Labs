#include "Personal.h"


Personal::Personal(const int id, const std::string& fio, int work_time, int salary, Positions position)
        : Employee (id, fio, work_time, position), salary (salary){}

// void Personal::print_info() override {
//     std::cout << "Worker's name: " << name << " position: " << position;
//     std::cout << " working time: " << work_time << " salary:" << salary << std::endl;
// }

int Personal::calc_base_salary(int salary_calc, int work_time)  {
    return work_time * salary_calc;
}

//int Personal::get_salary () const {
//    return salary;
//}

Driver::Driver(const int id, const std::string& fio, int work_time, int salary, Positions position)
    : Personal (id, fio, work_time, salary, position) {}

int Driver::calc_bonus_salary(int bonus) { // int night hours
    return bonus * (rand() % 50); // 15  - is night hours
    //                                                 question how to calculate bonus salary (where these hours)
}

int Driver::calc_salary() {
    return payment = calc_base_salary(salary, work_time) + calc_bonus_salary(4);
}

Cleaner::Cleaner(const int id, const std::string& fio, int work_time, int salary, Positions position)
    : Personal (id, fio, work_time, salary, position) {}

int Cleaner::calc_bonus_salary(int bonus) {
    return 0;
}

int Cleaner::calc_salary() {
    return payment = calc_base_salary(salary, work_time);
}
