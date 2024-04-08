// Copyright 28.03.24 SubbotinaTanya

#ifndef GROUP_H
#define GROUP_H

//#include "Deanery.h"
#include <string>
#include <vector>

class Student; //forward declaration
class Deanery;

class Group {
private:
    std::string title;
    std::string spec;
    std::vector <Student*> students;
    Student* head;

public:
    Group (const std::string& title, const std::string& spec);
    ~Group();

    const std::string getTitle () const;
    const std::string getSpec () const;
    Student* getHead () const;
    std::vector <Student*>& getStudents () ;

    void addStudent (Student* student);
    void chooseHead (int id);
    void chooseHead ();
    float getAverageMarkForGroup () const;
    Student* getStudent (const std::string& fio) const; // const
    Student* getStudent (int id) const; // const
    void removeStudent (int id); // or with Student* student
};

#endif // GROUP_H
