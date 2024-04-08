// Copyright 28.03.24 SubbotinaTanya

#ifndef DEANERY_H
#define DEANERY_H

#include <string>
#include <vector>

class Student;
class Group;

class Deanery {
private:
    std::vector <Group*> groups;

public:
    std::vector <Group*>& getGroups ();

    void createGroups(const std::string& file);
    void addStudents(const std::string& file); // with their marks
    void add5MarkToAll();
    void getStatistics() const; //print here
    void moveStudent(int id, std::string targetGroup);
    void saveData() const;
    void dismissStudents();
    void printData () const;
};

#endif // DEANERY_H