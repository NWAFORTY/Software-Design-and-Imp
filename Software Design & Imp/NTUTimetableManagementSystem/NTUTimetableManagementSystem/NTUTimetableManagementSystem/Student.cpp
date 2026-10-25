#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>
Student::Student(string u, string p) : User(u, p) {}

void Student::menu() {
    int choice;
    do {
        cout << "\nStudent Menu:\n";
        cout << "1. View Timetable\n2. Search Timetable\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: viewTimetable(); break;
        case 2: searchTimetable(); break;
        case 3: cout << "Exiting...\n"; break;
        default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 3);
}

void Student::viewTimetable() 
{ 
    ifstream file("Timetable.txt");

    if (!file.is_open()) {
        cerr << " Unable to open timetable file.\n";
        return;
    }

    string line;
    cout << "\n--- University Timetable ---\n\n";

    while (getline(file, line)) {
        cout << line << "\n";
    }

    file.close();
}


void Student::searchTimetable()
{
    ifstream file("Timetable.txt");
    if (!file.is_open()) {
        cerr << "Unable to open Timetable.txt file.\n";
        return;
    }

    int choice;
    cout << "\nSearch Timetable By:\n";
    cout << "1. Entry Number\n2. Module Name\n3. Room\n4. Lecturer\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // Clear newline character

    string keyword;

    switch (choice) {
    case 1:
        cout << "Enter entry number: ";
        getline(cin, keyword);
        break;
    case 2: {
        ifstream modules("modules.txt");
        if (!modules.is_open()) {
            cerr << "Unable to open modules.txt\n";
            return;
        }
        cout << "\nAvailable Modules:\n";
        string m;
        while (getline(modules, m)) {
            if (!m.empty()) cout << "- " << m << endl;
        }
        modules.close();
        cout << "Enter Module Name: ";
        getline(cin, keyword);
        break;
    }
    case 3: {
        ifstream rooms("rooms.txt");
        if (!rooms.is_open()) {
            cerr << "Unable to open rooms.txt\n";
            return;
        }
        cout << "\nAvailable Rooms:\n";
        string r;
        while (getline(rooms, r)) {
            if (!r.empty()) cout << "- " << r << endl;
        }
        rooms.close();
        cout << "Enter Room Name: ";
        getline(cin, keyword);
        break;
    }
    case 4: {
        ifstream lecturers("lecturers.txt");
        if (!lecturers.is_open()) {
            cerr << "Unable to open lecturers.txt\n";
            return;
        }
        cout << "\nAvailable Lecturers:\n";
        string l;
        while (getline(lecturers, l)) {
            size_t pos = l.find(',');
            if (pos != string::npos) {
                string lecturerName = l.substr(pos + 1);
                cout << "- " << lecturerName << endl;
            }
        }
        lecturers.close();
        cout << "Enter Lecturer Name: ";
        getline(cin, keyword);
        break;
    }
    default:
        cout << "Invalid choice.\n";
        return;
    }

    cout << "\n--- Search Results ---\n\n";

    string line, entry;
    bool found = false;
    int entryCounter = 0;

    while (getline(file, line)) {
        entry += line + "\n";

        if (line.find("-------------------------------") != string::npos) {
            entryCounter++;
            bool match = false;

            switch (choice) {
            case 1:
                if (to_string(entryCounter) == keyword) match = true;
                break;
            case 2:
                if (entry.find("Module: " + keyword) != string::npos) match = true;
                break;
            case 3:
                if (entry.find("Room: " + keyword) != string::npos) match = true;
                break;
            case 4:
                if (entry.find("Lecturer: " + keyword) != string::npos) match = true;
                break;
            }

            if (match) {
                cout << "Entry " << entryCounter << ":\n" << entry << endl;
                found = true;
            }

            entry = ""; // Reset for next entry
        }
    }

    if (!found) {
        cout << "No matching entries found.\n";
    }

    file.close();
}








