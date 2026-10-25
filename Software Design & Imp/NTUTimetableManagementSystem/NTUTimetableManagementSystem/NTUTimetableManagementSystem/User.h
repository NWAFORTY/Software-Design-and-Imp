#pragma once
#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string username, password;
public:
    User(string u, string p) : username(u), password(p) {}
    virtual void menu() = 0; // Abstract method for derived classes
    virtual ~User() {}
};

#endif

