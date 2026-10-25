#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <vector>

class Admin : public User {
public:
    Admin(string u, string p);
    void menu() override;

    void Module();
    void StudentGroup();
	void Rooms();
    void registerStudent();
    void registerLecturer();
    void createTimetable();
	void updateTimetable();
	void exportTimetableToCSV();
};

#endif

