// Copyright 09.05.24 SubbotinaTanya
#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
#include "Engineer.h"
#include "Personal.h"
#include "Manager.h"
class Factory {
public:
    static std::vector<Employee*> makeStaff (const std::string& filename);
    static std::vector<Project*> makeProjects (const std::string& filename);
};
#endif  // FACTORY_H