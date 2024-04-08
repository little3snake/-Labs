// Примерный перечень полей:

// - **id** - идентификационный номер
// - **fio** - фамилия и инициалы
// - **group** - ссылка на группу (объект Group)
// - **marks** - вектор оценок

// Обеспечить класс следующими методами:

// - создание студента с указанием ИД и ФИО
// - зачисление в группу
// - добавление оценки
// - вычисление средней оценки

// Copyright 28.03.24 SubbotinaTanya

#ifndef STUDENT_H
#define STUDENT_H

//#include "Deanery.h"
//#include "Group.h"
#include <string>
#include <vector>

class Group;

class Student {
private:
    int id;
    std::string fio;
    Group* group;
    std::vector <int> marks;

public:
    Student (int id, const std::string& fio);
    Student (const int id, const std::string& fio, Group* group, std::vector <int> marks);
    Student (const int id, const std::string& fio, Group* group);
    ~Student();

    Group* getGroup () const;
    int getID () const;
    const std::string getFIO () const; // 1st const
    std::string getMarks () const;

    void addToGroup (Group* group);
    void addMark (int mark);
    float getAverageMark () const;
};

#endif // STUDENT_H