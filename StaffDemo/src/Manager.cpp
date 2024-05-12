#include <iostream>
#include <utility>

#include "Manager.h"

ProjectManager::ProjectManager(const int id, const std::string& fio, Positions position, std::vector<Project*> projects)
    : Employee(id, fio, position), projects (std::move(projects)) {}

int ProjectManager::calc_Heads(){
    int finish_heads = 0;
    for (Project* project_1: projects) {
        finish_heads += project_1->get_num_of_employees() * 50;
    }
    return finish_heads;
}

int ProjectManager::calc_budget_part() {
    int finish_calc = 0;
    for (Project* project_1: projects)
        finish_calc += (int)(project_1->get_budget() / project_1->get_num_of_employees());
    return finish_calc;
}

int ProjectManager::calc_pro_additions(int bonus) { // it isn't work without this useless method
    return 0;
}

int ProjectManager::calc_salary() {
    return payment = calc_budget_part() + calc_Heads();
}

SeniorManager::SeniorManager(const int id, const std::string& fio, Positions position, std::vector<Project*> projects)
    : ProjectManager(id, fio, position, std::move(projects)) {}

int SeniorManager::calc_salary() {
    return payment = calc_Heads() + calc_budget_part();
}

