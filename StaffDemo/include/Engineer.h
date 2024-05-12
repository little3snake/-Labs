// Copyright 09.05.24 SubbotinaTanya
#ifndef ENGINEER_H
#define ENGINEER_H

#include <iostream>

#include "Employee.h"
#include "Interfaces.h"
#include "Personal.h"

class Engineer : public Personal, public Project_Budget, public Project {
protected:
    Project* project;
public:
    Engineer(int id, const std::string& fio,
                       int salary, Positions position, Project* project);
    //~Engineer();
    int calc_budget_part() override;
    int calc_bonus_salary(int bonus) override;
};

class Programmer : public Engineer {
public:
    Programmer(int id, const std::string& fio,
        int salary, Positions position, Project* project);
    //~Programmer();
    int calc_pro_additions(int bonus) override;// дополнительную премию за досрочно написанный код.
    int calc_salary () override;
};

class Tester : public Engineer {
public:
    Tester(int id, const std::string& fio,
                   int salary, Positions position, Project* project);
    //~Tester();
    int calc_salary () override;
    int calc_pro_additions(int bonus) override;// за количество найденных ошибок
};

class TeamLeader : public Programmer, public Heading {
public:
    TeamLeader(int id, const std::string& fio,
                           int salary, Positions position, Project* project);
    //~TeamLeader();
    //Получает зарплату за отработанное время, часть бюджета проекта и за руководство программистами.
    int calc_salary () override;
    int calc_Heads() override;
};
#endif // ENGINEER_H