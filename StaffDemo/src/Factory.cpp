#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

#include "Factory.h"

std::vector<Employee*> Factory::makeStaff (const std::string& filename) {
    std::ifstream file(filename); // file is stream
    std::string line;
    int id, salary, worktime, project_id, project_1_id, nightHours;
    Positions position;
    std::string fio , f , i , o , position_str;
    Project* project;
    std::vector <Project*> projects_this;
    std::vector <int> projects_this_id;
    std::vector <Employee*> result;
    if (!file.is_open()) {
        std::cerr << "Error: couldn't open file " << filename << std::endl;
        std::vector <Project*> proj = Factory::makeProjects ("../info/projects_info.txt");
    } else {
        std::vector <Project*> proj = Factory::makeProjects ("../info/projects_info.txt");
        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            lineStream >> id >> f >> i >> o >> position_str;
            fio = f + " " + i + " " + o;
            Employee* employee;
            if (position_str == "programmer") {
                position = programmer;
                lineStream >> salary >> project_id;
                for (Project* project_for: proj) {
                    if (project_for->get_id() == project_id)
                        project = project_for;
                }
                employee = new Programmer(id, fio, salary, position, project);
            } else if (position_str == "team_leader") {
                position = team_leader;
                lineStream >> salary >> project_id;
                for (Project* project_for: proj) {
                    if (project_for->get_id() == project_id)
                        project = project_for;
                }
                employee = new TeamLeader(id, fio, salary, position, project);
            } else if (position_str == "project_manager") {
                position = project_manager;
                while (lineStream >> project_1_id) {
                    projects_this_id.push_back(project_1_id);
                }
                for (int project_id_for: projects_this_id) {
                    for (Project* project_for: proj) {
                        if (project_for->get_id() == project_id_for)
                            projects_this.push_back(project_for);
                    }
                }
                employee = new ProjectManager(id, fio, position, projects_this);
                projects_this_id.clear();
                projects_this.clear();
            } else if (position_str == "senior_manager") {
                position = senior_manager;
                while (lineStream >> project_1_id) {
                    projects_this_id.push_back(project_1_id);
                }
                for (int project_id_for: projects_this_id) {
                    for (Project* project_for: proj) {
                        if (project_for->get_id() == project_id_for)
                            projects_this.push_back(project_for);
                    }
                }
                employee = new SeniorManager(id, fio, position, projects_this);
                projects_this_id.clear();
                projects_this.clear();
            } else if (position_str == "cleaner") {
                position = cleaner;
                lineStream >>  salary;
                employee = new Cleaner(id, fio, salary, position);
            } else if (position_str == "driver") {
                position = driver;
                lineStream >> worktime >> salary >> nightHours;
                employee = new Driver(id, fio, salary, position, nightHours);
            } else if (position_str == "tester") {
                position = tester;
                lineStream >> salary >> project_id;
                for (Project* project_for: proj) {
                    if (project_for->get_id() == project_id)
                        project = project_for;
                }
                employee = new Tester(id, fio, salary, position, project);
            }
            result.push_back(employee);
        }
    }
    file.close();
    return result;
}

std::vector<Project*> Factory::makeProjects (const std::string& filename) {
    std::ifstream file(filename); // file is stream
    std::string line;
    int id, budget, number_of_employees;
    std::vector <Project*> projects;
    if (!file.is_open()) {
        std::cerr << "Error: couldn't open file " << filename << std::endl;
    } else {
        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            lineStream >> id >> budget >> number_of_employees;
            auto *project = new Project(id, budget, number_of_employees);
            projects.push_back(project);
        }
    }
    file.close();
    return projects;
}

    