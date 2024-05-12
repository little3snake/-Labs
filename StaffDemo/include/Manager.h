// Copyright 09.05.24 SubbotinaTanya
#ifndef MANAGER_H
#define MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#include "Employee.h"
#include"Interfaces.h"
#include "Factory.h"

class ProjectManager : public Employee, public Project, public Project_Budget, public Heading {
private:
   std::vector<Project*> projects;
public:
   ProjectManager(int id, const std::string& fio, Positions position, std::vector<Project*> projects);
    //virtual ~ProjectManager();
   // Получает зарплату из бюджета проекта и за руководство участниками проекта.
   int calc_Heads() override;
   int calc_salary() override;
   int calc_budget_part() override;
   int calc_pro_additions(int bonus) override;
};

class SeniorManager : public ProjectManager{
private:
   std::vector <Project*> projects;
 public:
   SeniorManager(int id, const std::string& fio, Positions position, std::vector<Project*> projects);
   //virtual ~SeniorManager();
   int calc_salary() override;
};
#endif  // MANAGER_H