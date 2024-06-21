#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
#include "Deanery.h"
#include "Student.h"
#include "Group.h"

std::vector <Group*>& Deanery::getGroups () {
    return groups;
}

void Deanery::createGroups(const std::string& filename_groups){
    std::string title, spec, line;
    std::ifstream file(filename_groups);
    if (!file.is_open()) { // if we couldn't open the file ---> error
        std::cerr << "Error: couldn't open file " << filename_groups << std::endl;
        return;
    }
    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        lineStream >> title >> spec;
        Group *group = new Group(title, spec);
        groups.push_back(group);
    }
    file.close();
}

void Deanery::addStudents(const std::string& filename_students) {
    std::ifstream file(filename_students); // file is stream
    int id;
    std::string line;
    std::string fio, f, i, o, group_str;
    Group* group_id;
    std::vector <int> marks;
    int mark;
    if (!file.is_open()) {
        std::cerr << "Error: couldn't open file " << filename_students << std::endl;
        return;
    }
    while (std::getline(file, line)) {
        std::istringstream lineStream (line);
        lineStream >> id >> f >> i >> o >> group_str;

        for (Group* group: groups) {
            if (group->getTitle() == group_str )
                group_id = group;
        }
        Student* student = new Student (id, f+" "+i+" "+o, group_id);
        group_id->addStudent(student);
        while (lineStream >> mark) {
            student->addMark(mark);
        }
    }
    marks.clear();
    file.close();
}

void Deanery::add5MarkToAll() { // add five random marks from 1 to 10
    int mark;
    srand (time (nullptr));
    for (Group* group: groups) {
        for (Student* student: group->getStudents()) {
            for (int i = 0; i < 5; i++) {
                mark = rand() % 10 + 1;
                student->addMark(mark);
            }
        }
    }
    saveData();
}

void Deanery::getStatistics() const { // and statistic print here
    std::cout << "Group Statistics:" << std::endl;
    for (Group* group : groups) {
        std::cout << "Group: " << group->getTitle() << std::endl;
        std::cout << "Average Mark: " << group->getAverageMarkForGroup() << std::endl;
    }
    std::cout << std::endl;
}

void Deanery::moveStudent(int id, std::string targetGroup_title) {
    Student* student;
    Group* sourceGroup;
    Group* targetGroup;
    for (Group* group_for : groups) { // find group with the same name
        if (group_for->getTitle() == targetGroup_title ) {
            targetGroup = group_for;
        }
    }
    for (Group* group_for : groups) {
        for (Student* student_for : group_for->getStudents()) {
            if (student_for->getID() == id) { // find student with the same id
                student = student_for;
                sourceGroup = group_for;
                break;
            }
        }
    }
    int student_id = student->getID(); // or student_id = id
    sourceGroup->removeStudent(student_id);
    student->addToGroup(targetGroup);
    saveData();
}

void Deanery::saveData() const {
    std::ofstream file_groups;
    std::ofstream file_students;
    file_groups.open("../bd/groups.txt"); // open files
    file_students.open("../bd/students.txt");
    if (!file_groups.is_open()) { // if we couldn't open the file ---> error
        std::cerr << "Error: couldn't open file groups.txt" << std::endl;
        return;
    }
    if (!file_students.is_open()) { // if we couldn't open the file ---> error
        std::cerr << "Error: couldn't open file students.txt" << std::endl;
        return;
    }
    for ( Group* group : groups) { // reload new data
        file_groups << group->getTitle() << " " << group->getSpec() << " " << group->getHead() << std::endl;
        for ( Student* student : group->getStudents()) {
            file_students << student->getID() << " " << student->getFIO() << " " << student->getGroup() << " " << student->getMarks() << std::endl;
        }
    }
    file_groups.close();
    file_students.close();
}

void Deanery::dismissStudents() {
    for (Group* group : groups) { // delete students in each group
        std::vector<Student*> students_for_dismiss;
        for (Student* student : group->getStudents()) {
            if (student->getAverageMark() < 4.0f) { //  check  if mark less than 4
                students_for_dismiss.push_back(student);
            }
        }
        for (Student* student : students_for_dismiss) { // dismiss students
            group->removeStudent(student->getID());
            delete student; // clear memory
        }
        students_for_dismiss.clear(); // clear memory
    }
    saveData();
}

void Deanery::printData () const {
    saveData(); // only for chooseHead
    std::cout << "Deanery Data:" << std::endl;
    for (Group* group : groups) {
        std::cout << "Group: " << group->getTitle() << " Specialization: " << group->getSpec() << " Head: ";
        if (group->getHead() != 0) {
            std::cout << group->getHead()->getFIO() << std::endl;
        }
        else
            std::cout << "No head" << std::endl;
        std::cout << "Students:" << std::endl;
        for (Student* student : group->getStudents()) {
            std::cout << "ID: " << student->getID() << " FIO: " << student->getFIO() << " Marks: " << student->getMarks() << std::endl;
        }
    }
    std::cout << std::endl;
}