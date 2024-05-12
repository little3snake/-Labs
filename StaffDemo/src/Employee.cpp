#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <utility>

#include "Employee.h"

Employee::Employee(const int id, std::string  fio, Positions position)
        : id (id), fio (std::move(fio)), position (position) {}

Employee::~Employee() = default;

void Employee::setWorkTime() {
    work_time = rand() % 601 + 400;
}

void Employee::print_info(){
    std::string position_str;
    if (position == programmer) {
        position_str = "programmer";
    } else if (position == team_leader) {
        position_str = "team_leader";
    } else if (position == project_manager) {
        position_str = "project_manager";
    } else if (position == senior_manager) {
        position_str = "senior_manager";
    } else if (position == cleaner) {
        position_str = "cleaner";
    } else if (position == driver) {
        position_str = "driver";
    } else if (position == tester) {
        position_str = "tester";
    }
    std::cout
        << std::left
        << std::setw(40)
        << fio
        << std::left
        << std::setw(20)
        << position_str
        << std::left
        << std::setw(13)
        << work_time
        << std::left
        << std::setw(10)
        << payment;
}

Project::Project(int id, int budget, int number_of_employees)
    : id (id), budget (budget), number_of_employees (number_of_employees) {}

Project::Project() : id(-1), budget(0), number_of_employees(0){}

Project::~Project()  = default;

int Project::get_num_of_employees() const {
    return number_of_employees;
}

int Project::get_budget() const {
    return budget;
}

int Project::get_id() const {
    return id;
}

