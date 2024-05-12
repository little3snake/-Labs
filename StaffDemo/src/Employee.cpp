#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <utility>

#include "Employee.h"

Employee::Employee(const int id, std::string  fio, int work_time, Positions position)
        : id (id), fio (std::move(fio)), work_time (work_time), position (position) {}

Employee::~Employee() = default;

    //virtual int calc_salary() = 0;
    //virtual void print_info() = 0;
//void Employee::changeTime() {
//    srand(time(nullptr));
//}

void Employee::setWorkTime() {
    //srand(time(nullptr));
    work_time = rand() % 501 + 400;
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

//Project::Project(Project&& other) noexcept
//    : id(other.id), budget(std::move(other.budget)), number_of_employees(std::move(other.number_of_employees)) {}

//Project::Project(Project& other)
//        : id(other.id), budget(other.budget), number_of_employees(other.number_of_employees) {}
//Project::Project() {}

Project::Project() : id(-1), budget(0), number_of_employees(0){}

Project::~Project()  = default;

//Project::Project(const Project& other)
//    : id(other.id), budget(other.budget), number_of_employees(other.number_of_employees) {}

int Project::get_num_of_employees() const {
    return number_of_employees;
}

int Project::get_budget() const {
    return budget;
}

int Project::get_id() const {
    return id;
}

