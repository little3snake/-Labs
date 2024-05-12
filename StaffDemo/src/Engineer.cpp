#include <iostream>

#include "Engineer.h"

//class Project;

Engineer::Engineer(const int id, const std::string& fio, int work_time, int salary, Positions position, Project* project)
        : Personal (id, fio, work_time, salary, position), project (project){}

//Engineer::~Engineer()  {}

int Engineer::calc_budget_part() {
    return (int)(project->get_budget() / project->get_num_of_employees());
}

int Engineer::calc_bonus_salary(int bonus) {
    return 0;
}

//int calc_bonus_salary(int bonus) { // it isn't work without this useless method
//    return 0;
//}
Programmer::Programmer(const int id, const std::string& fio, int work_time, int salary, Positions position, Project* project)
    : Engineer (id, fio, work_time, salary, position, project) {}

//Programmer::~Programmer() {}

int Programmer::calc_pro_additions(int bonus) { //               programmer finished work early          random
    int is_finished_early;
    int pro_add = 0;

    is_finished_early = rand() % 2; // 0 or 1 like true or false
    if (is_finished_early) {
        pro_add = bonus;
    }
    return pro_add;
}

//int Programmer::calc_bonus_salary(int bonus) { // isn't work without this
//    return 0;
//}

int Programmer::calc_salary () {
    return payment = calc_budget_part() + calc_base_salary(salary, work_time) + calc_pro_additions(20);
}

Tester::Tester(const int id, const std::string& fio, int work_time, int salary, Positions position, Project* project)
    : Engineer(id, fio, work_time, salary, position, project) {}

//Tester::~Tester() {}

int Tester::calc_pro_additions(int bonus) {
    //bonus = 30;
    int number_of_fixed_errors;
    number_of_fixed_errors = rand() % 201;
    return number_of_fixed_errors * bonus; // calc pro additions
}

//int Tester::calc_bonus_salary(int bonus) { // isn't work without this
//    return 0;
//}
int Tester::calc_salary () {
    return payment = calc_base_salary(salary, work_time) + calc_budget_part() + calc_pro_additions(30);
}

TeamLeader::TeamLeader(const int id, const std::string& fio, int work_time, int salary, Positions position, Project* project)
    : Programmer(id, fio,work_time, salary, position, project) {}

//TeamLeader::~TeamLeader() {}

//int TeamLeader::calc_bonus_salary(int bonus) { // isn't work without this
//    return 0;
//}

int TeamLeader::calc_salary () {
    return payment = calc_base_salary(salary, work_time) + calc_budget_part() + calc_Heads();
}


int TeamLeader::calc_Heads() {
    return project->get_num_of_employees() * 30;
}



