#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"

class Student : public User {
public:
    Student(string u, string p);
    void menu() override;
    void viewTimetable();
    void searchTimetable();
};

#endif