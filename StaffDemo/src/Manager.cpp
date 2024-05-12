#include <iostream>
#include <utility>
//#include <time.h>

#include "Manager.h"

ProjectManager::ProjectManager(const int id, const std::string& fio, int work_time, Positions position, std::vector<Project*> projects)
    : Employee(id, fio, work_time, position), projects (std::move(projects)) {}

int ProjectManager::calc_Heads(){
    int finish_heads = 0;
    //std::cout << "heads" << " ";
    for (Project* project_1: projects) {
        //std::cout << project_1->get_num_of_employees() << std::endl;
        finish_heads += project_1->get_num_of_employees() * 50;
    }
    //return projects[0]->get_num_of_employees() * 50;
    return finish_heads;
}

//Project ProjectManager::get_project () {
//    return *projects[0];
//}
int ProjectManager::calc_budget_part() {
    int finish_calc = 0;
    //std::cout << "part1" << " ";
    for (Project* project_1: projects)
        finish_calc += (int)(project_1->get_budget() / project_1->get_num_of_employees());
    //std::cout << "part2" << " ";
    return finish_calc;
}

int ProjectManager::calc_pro_additions(int bonus) { // it isn't work without this useless method
    return 0;
}

int ProjectManager::calc_salary() {
    //std::cout << "all" << " ";
    return payment = calc_budget_part() + calc_Heads();
}

SeniorManager::SeniorManager(const int id, const std::string& fio, int work_time, Positions position, std::vector<Project*> projects)
    : ProjectManager(id, fio, work_time, position, std::move(projects)) {}

int SeniorManager::calc_salary() {
    //int proj_salary = 0;
    //for (Project* project_1: projects) {
    //    proj_salary += (int)(project_1->get_budget() / project_1->get_num_of_employees());
    //}
    return payment = calc_Heads() + calc_budget_part();
}

