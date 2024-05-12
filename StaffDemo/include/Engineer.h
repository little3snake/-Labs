// Copyright 09.05.24 SubbotinaTanya
#ifndef ENGINEER_H
#define ENGINEER_H

#include <iostream>

#include "Employee.h"
#include "Interfaces.h"
#include "Personal.h"
//#include ""

class Engineer : public Personal, public Project_Budget, public Project {
protected:
    Project* project;
public:
    Engineer(int id, const std::string& fio,
                       int work_time, int salary, Positions position, Project* project);
    //~Engineer();
    int calc_budget_part() override;
    int calc_bonus_salary(int bonus) override;
    //calc base in personal
    //virtual int calc_salary (); // what's it
};

class Programmer : public Engineer {
public:
    Programmer(int id, const std::string& fio,
        int work_time, int salary, Positions position, Project* project);
    //~Programmer();
    // calc base in personal
    // calc budget part in engineer
    int calc_pro_additions(int bonus) override;// дополнительную премию за досрочно написанный код.
    int calc_salary () override;//       потому что делать это в инженере нелогично
};

class Tester : public Engineer {
public:
    Tester(int id, const std::string& fio,
                   int work_time, int salary, Positions position, Project* project);
    //~Tester();
    // calc base in personal
    // calc budget part in engineer
    //int calc_bonus_salary(int bonus) override;
    int calc_salary () override;
    int calc_pro_additions(int bonus) override;// за количество найденных ошибок
};

class TeamLeader : public Programmer, public Heading {
public:
    TeamLeader(int id, const std::string& fio,
                           int work_time, int salary, Positions position, Project* project);
    //~TeamLeader();
    //Получает зарплату за отработанное время, часть бюджета проекта и за руководство программистами.
    int calc_salary () override;
    int calc_Heads() override;
};

#endif // ENGINEER_H