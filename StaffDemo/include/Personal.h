// Copyright 09.05.24 SubbotinaTanya
#ifndef PERSONAL_H
#define PERSONAL_H

#include <iostream>
#include <string>
#include <utility>

#include "Employee.h"
#include"Interfaces.h"

class Personal : public Employee, public Work_Base_Time {
protected:
   int salary;
public:
   Personal(int id, const std::string& fio,
      int work_time, int salary, Positions position);
   //virtual ~Personal();
   //int calc_bonus_salary(int bonus = 0) override;
   //void print_info() override;
   int calc_base_salary(int salary, int work_time) override;
   //int get_salary () const;
};

class Driver : public Personal {
 //private:
   //int night_hours; // for calc_bonus_salary                not in original file
 public:
   Driver(int id, const std::string& fio,
      int work_time, int salary, Positions position); // int night hours
   //virtual ~Driver();
   int calc_salary () override;
   int calc_bonus_salary(int bonus) override; // int night hours

};

class Cleaner : public Personal {
 public:
   Cleaner(int id, const std::string& fio,
      int work_time, int salary, Positions position);
   //virtual ~Cleaner();
   int calc_salary () override;
   int calc_bonus_salary(int bonus) override; // it isn't work without this useless method
};
#endif  // PERSONAL_H
