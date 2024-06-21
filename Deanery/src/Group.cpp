#include "Group.h"
#include "Student.h"
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()


Group::Group (const std::string& title, const std::string& spec)
    : title (title), spec (spec), head (nullptr) {}

Group::~Group() {}

const std::string Group::getTitle () const {
    return title;
}

const std::string Group::getSpec () const {
    return spec;
}

Student* Group::getHead() const {
    return head;
}

std::vector <Student*>& Group::getStudents () {
    return students;
}

void Group::addStudent (Student* student) {
    students.push_back(student);
}

void Group::chooseHead (int id) {
    for (Student* student: students) {
        if (student->getID() == id) {
            head = student;
        }
    }
}

void Group::chooseHead () { // choose random
    int chosen_id;
    srand (time (nullptr));
    chosen_id = rand() % students.size() + 1;
    for (Student* student: students) {
        if (student->getID() == chosen_id) {
            head = student;
        }
    }
}

float Group::getAverageMarkForGroup () const {
    int summ = 0;
    if (students.empty()) // no elements in marks array
        return 0;
    for (Student* student : students) {
        summ += student->getAverageMark();
    }
    return summ / students.size();
}

Student* Group::getStudent (const std::string& fio) const {
    for (Student* student : students) {
        if (student->getFIO() == fio)
            return student;
    }
    return nullptr;
}

Student* Group::getStudent (int id) const {
    for (Student* student : students) {
        if (student->getID() == id)
            return student;
    }
    return nullptr;
}

void Group::removeStudent (int id) {
    for (auto it = students.begin(); it != students.end(); ++it) {
        if ((*it)->getID() == id) {
            students.erase(it);
            break;
        }
    }
}

