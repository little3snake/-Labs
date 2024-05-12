// Copyright 09.05.24 SubbotinaTanya
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

enum Positions {
    programmer,
    team_leader,
    project_manager,
    senior_manager,
    cleaner,
    driver,
    tester,
};

class Employee {
private:
    int id;
protected:
   const std::string fio;
   Positions position;
   int work_time;
   std::vector<std::string> enum_print = {"programmer",
                                           "team_leader",
                                           "project_manager",
                                           "senior_manager",
                                           "cleaner",
                                           "driver",
                                           "tester"};
   int payment{};
 public:
   Employee(int id, std::string  fio, int work_time, Positions position);
   ~Employee();
   //                                                              set work time for what?
   void print_info() ;
   //void changeTime();
   void setWorkTime();
   virtual int calc_salary() = 0;
};

class Project {
private:
    int id;
   int budget;
   int number_of_employees;
public:
   Project(int id, int budget, int number_of_employees);
   //Project(Project&& other) noexcept ;
   //Project(Project& other);
   Project();
   ~Project();
   int get_num_of_employees() const;
   int get_budget() const;
   int get_id() const;
};
#endif  // EMPLOYEE_H
