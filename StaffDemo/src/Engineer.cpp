#include <iostream>

#include "Engineer.h"

Engineer::Engineer(const int id, const std::string& fio, int salary, Positions position, Project* project)
        : Personal (id, fio, salary, position), project (project){}

int Engineer::calc_budget_part() {
    return (int)(project->get_budget() / project->get_num_of_employees());
}

int Engineer::calc_bonus_salary(int bonus) {
    return 0;
}

Programmer::Programmer(const int id, const std::string& fio, int salary, Positions position, Project* project)
    : Engineer (id, fio, salary, position, project) {}

int Programmer::calc_pro_additions(int bonus) { //         programmer finished work early          random
    int is_finished_early;
    int pro_add = 0;
    is_finished_early = rand() % 2; // 0 or 1 like true or false
    if (is_finished_early) {
        pro_add = bonus;
    }
    return pro_add;
}

int Programmer::calc_salary () {
    return payment = calc_budget_part() + calc_base_salary(salary, work_time) + calc_pro_additions(20);
}

Tester::Tester(const int id, const std::string& fio, int salary, Positions position, Project* project)
    : Engineer(id, fio, salary, position, project) {}

int Tester::calc_pro_additions(int bonus) {
    int number_of_fixed_errors;
    number_of_fixed_errors = rand() % 201;
    return number_of_fixed_errors * bonus;
}

int Tester::calc_salary () {
    return payment = calc_base_salary(salary, work_time) + calc_budget_part() + calc_pro_additions(30);
}

TeamLeader::TeamLeader(const int id, const std::string& fio, int salary, Positions position, Project* project)
    : Programmer(id, fio, salary, position, project) {}

int TeamLeader::calc_salary () {
    return payment = calc_base_salary(salary, work_time) + calc_budget_part() + calc_Heads();
}

int TeamLeader::calc_Heads() {
    return project->get_num_of_employees() * 30;
}



