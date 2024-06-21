#include "Student.h"
#include "Group.h"
#include "Deanery.h"
#include <iostream>

int main() {
    Deanery course_1;
    course_1.createGroups("../bd/groups.txt"); // create groups from file
    course_1.addStudents("../bd/students.txt"); // create students from file
    course_1.add5MarkToAll(); //add marks to all students (random)
    course_1.printData ();
    course_1.getStatistics(); // get average mark for groups
    course_1.moveStudent(15, "23CST6"); // moving demonstration
    // removing demonstration
    course_1.dismissStudents();
    course_1.printData();
    // with groups
    int id=3; // id for head in chosen group
    Group* our_group = course_1.getGroups()[4]; // for group 23CST5
    our_group->chooseHead(); // chose random head
    course_1.printData();
    our_group->chooseHead(id); // chose head with id
    course_1.printData();
    // with students
    Student* you;
    id=14;
    std::string fio = "Randin Arseniy Andreevich";
    you = our_group->getStudent(id); // get fio
    std::cout << "Chosen student with id " << id << " is " << you->getFIO() << std::endl;
    you = our_group->getStudent(fio); // get id
    std::cout << fio << " has id: " << you->getID() << std::endl;
    // 2 time prog can't run because in file groups.txt will add information
    // about heads and creating classes won't work with this information
    //you should replace to origin files in ...files\origin...
    return 0;
}