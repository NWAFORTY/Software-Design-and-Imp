#include <iostream>
#include "Admin.h"
#include "Student.h"


using namespace std;

User* login() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username == "admin" && password == "adminpass") {
        return new Admin(username, password);
    }
    else if (username == "student" && password == "studentpass") {
        return new Student(username, password);
    }
    else {
        cout << "Invalid credentials!\n";
        return nullptr;
    }
}

int main() {
    User* user = nullptr;
    while (!user) {
        user = login();
    }

    user->menu();  // Assuming this is defined in your User, Admin, or Student class
    delete user;

    return 0;
}







