#include "Student.h"
#include "Group.h"
//#include "Deanery.h"

Student::Student (const int id, const std::string& fio)
    : id (id), fio (fio), group (nullptr) {}
Student::Student (const int id, const std::string& fio, Group* group, std::vector <int> marks)
        : id (id), fio (fio), group (group), marks (marks) {}
Student::Student (const int id, const std::string& fio, Group* group)
        : id (id), fio (fio), group (group) {}

Student::~Student() {}

Group* Student::getGroup () const {
    return group;
}

int Student::getID () const {
    return id;
}

const std::string Student::getFIO () const {
    return fio;
}

std::string Student::getMarks () const {
    std::string marks_str="";
    for (auto elem : marks) {
        marks_str += std::to_string(elem);
        marks_str += " ";
    }
    return marks_str;
}


void Student::addToGroup (Group* group){
    this->group = group;
    group->addStudent(this);// add to file
}

void Student::addMark (int mark) {
    marks.push_back(mark);
}

float Student::getAverageMark () const {
    int summ=0;
    if (marks.empty()) // if array of marks is empty
        return 0; // return 0 (float)
    for (int mark: marks) {
        summ+=mark;
    }
    return summ / marks.size();
}
