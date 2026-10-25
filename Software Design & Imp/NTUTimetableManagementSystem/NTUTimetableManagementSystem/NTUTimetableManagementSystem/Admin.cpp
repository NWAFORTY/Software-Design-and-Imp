#include "Admin.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <regex> 
#include <algorithm>
Admin::Admin(string u, string p) : User(u, p) {}

bool isLecturerRegistered(const string& name);
vector<string> getModules();
vector<string> readStudentGroups();
void writeStudentGroups(const vector<string>& groups);
void writeModules(const vector<string>& modules);
vector<string> readModules();
vector<string> readRooms();
void writeRooms(const vector<string>& rooms);
vector<string> getRegisteredLecturers();
vector<string> getStudentGroups();
vector<string> getRooms();



void Admin::menu() {
    int choice;
    do {
        cout << "\nAdmin Menu:\n";
        cout << "1. Module\n2. Student Group\n3. Room\n";
        cout << "4. Register Student\n5. Register Lecturer\n6. Create Timetable\n7. Update Timetable\n";
        cout << "8. Export Timetable to Excel (CSV)\n9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: Module(); break;
        case 2: StudentGroup(); break;
        case 3: Rooms(); break;
        case 4: registerStudent(); break;
        case 5: registerLecturer(); break;
        case 6: createTimetable(); break;
		case 7: updateTimetable(); break;
		case 8: exportTimetableToCSV(); break;
        case 9: cout << "Exiting...\n"; break;
        default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 9);
}

void Admin::Module() 
{
    int choice;
    do {
        cout << "\n--- Module Management ---\n";
        cout << "1. Add New Module\n";
        cout << "2. Edit Existing Module\n";
        cout << "3. Delete Module\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer after choice

        switch (choice) {
        case 1:
            // Add a new module
        {
            string moduleName;
            cout << "Enter Module Name: ";
            getline(cin, moduleName);

            // Validate input
            if (moduleName.empty()) {
                cout << "Module name cannot be empty.\n";
                break;
            }

            // Add the module to the file
            vector<string> modules = readModules();
            modules.push_back(moduleName);
            writeModules(modules);

            cout << "Module '" << moduleName << "' added successfully!\n";
        }
        break;

        case 2:
            // Edit an existing module
        {
            vector<string> modules = readModules();

            if (modules.empty()) {
                cout << "No modules available to edit.\n";
                break;
            }

            cout << "\n--- Existing Modules ---\n";
            for (size_t i = 0; i < modules.size(); ++i) {
                cout << i + 1 << ". " << modules[i] << "\n";
            }

            int moduleChoice;
            cout << "Select a module to edit: ";
            cin >> moduleChoice;
            cin.ignore();

            if (moduleChoice < 1 || moduleChoice > modules.size()) {
                cout << "Invalid choice.\n";
                break;
            }

            string newModuleName;
            cout << "Enter new name for the module: ";
            getline(cin, newModuleName);

            if (newModuleName.empty()) {
                cout << "Module name cannot be empty.\n";
                break;
            }

            // Update the module name
            modules[moduleChoice - 1] = newModuleName;
            writeModules(modules);

            cout << "Module name updated to '" << newModuleName << "' successfully!\n";
        }
        break;

        case 3:
            // Delete an existing module
        {
            vector<string> modules = readModules();

            if (modules.empty()) {
                cout << "No modules available to delete.\n";
                break;
            }

            cout << "\n--- Existing Modules ---\n";
            for (size_t i = 0; i < modules.size(); ++i) {
                cout << i + 1 << ". " << modules[i] << "\n";
            }

            int moduleChoice;
            cout << "Select a module to delete: ";
            cin >> moduleChoice;
            cin.ignore();

            if (moduleChoice < 1 || moduleChoice > modules.size()) {
                cout << "Invalid choice.\n";
                break;
            }

            // Delete the module
            modules.erase(modules.begin() + moduleChoice - 1);
            writeModules(modules);

            cout << "Module deleted successfully!\n";
        }
        break;

        case 4:
            cout << "Exiting Module Management...\n";
            break;

        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    } while (choice != 4);
}


void Admin::StudentGroup() {
    int choice;
    do {
        cout << "\n--- Student Group Management ---\n";
        cout << "1. Add New Group\n";
        cout << "2. Edit Existing Group\n";
        cout << "3. Delete Group\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer after choice

        switch (choice) {
        case 1:
            // Add a new group
        {
            string groupName;
            cout << "Enter Group Name (e.g., Group A): ";
            getline(cin, groupName);

            // Validate input
            if (groupName.empty()) {
                cout << "Group name cannot be empty.\n";
                break;
            }

            // Add the group to the file
            vector<string> groups = readStudentGroups();
            groups.push_back(groupName);
            writeStudentGroups(groups);

            cout << "Student group '" << groupName << "' added successfully!\n";
        }
        break;

        case 2:
            // Edit an existing group
        {
            vector<string> groups = readStudentGroups();

            if (groups.empty()) {
                cout << "No groups available to edit.\n";
                break;
            }

            cout << "\n--- Existing Groups ---\n";
            for (size_t i = 0; i < groups.size(); ++i) {
                cout << i + 1 << ". " << groups[i] << "\n";
            }

            int groupChoice;
            cout << "Select a group to edit: ";
            cin >> groupChoice;
            cin.ignore();

            if (groupChoice < 1 || groupChoice > groups.size()) {
                cout << "Invalid choice.\n";
                break;
            }

            string newGroupName;
            cout << "Enter new name for the group: ";
            getline(cin, newGroupName);

            if (newGroupName.empty()) {
                cout << "Group name cannot be empty.\n";
                break;
            }

            // Update the group name
            groups[groupChoice - 1] = newGroupName;
            writeStudentGroups(groups);

            cout << "Group name updated to '" << newGroupName << "' successfully!\n";
        }
        break;

        case 3:
            // Delete an existing group
        {
            vector<string> groups = readStudentGroups();

            if (groups.empty()) {
                cout << "No groups available to delete.\n";
                break;
            }

            cout << "\n--- Existing Groups ---\n";
            for (size_t i = 0; i < groups.size(); ++i) {
                cout << i + 1 << ". " << groups[i] << "\n";
            }

            int groupChoice;
            cout << "Select a group to delete: ";
            cin >> groupChoice;
            cin.ignore();

            if (groupChoice < 1 || groupChoice > groups.size()) {
                cout << "Invalid choice.\n";
                break;
            }

            // Delete the group
            groups.erase(groups.begin() + groupChoice - 1);
            writeStudentGroups(groups);

            cout << "Group deleted successfully!\n";
        }
        break;

        case 4:
            cout << "Exiting Student Group Management...\n";
            break;

        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    } while (choice != 4);
}


void Admin::Rooms() 
{
    int choice;
    do {
        cout << "\n--- Room Management ---\n";
        cout << "1. Add New Room\n";
        cout << "2. Edit Existing Room\n";
        cout << "3. Delete Room\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear input buffer after choice

        switch (choice) {
        case 1:
            // Add a new room
        {
            string roomName;
            cout << "Enter Room Name: ";
            getline(cin, roomName);

            // Validate input
            if (roomName.empty()) {
                cout << "Room name cannot be empty.\n";
                break;
            }

            // Add the room to the file
            vector<string> rooms = readRooms();
            rooms.push_back(roomName);
            writeRooms(rooms);

            cout << "Room '" << roomName << "' added successfully!\n";
        }
        break;

        case 2:
            // Edit an existing room
        {
            vector<string> rooms = readRooms();

            if (rooms.empty()) {
                cout << "No rooms available to edit.\n";
                break;
            }

            cout << "\n--- Existing Rooms ---\n";
            for (size_t i = 0; i < rooms.size(); ++i) {
                cout << i + 1 << ". " << rooms[i] << "\n";
            }

            int roomChoice;
            cout << "Select a room to edit: ";
            cin >> roomChoice;
            cin.ignore();

            if (roomChoice < 1 || roomChoice > rooms.size()) {
                cout << "Invalid choice.\n";
                break;
            }

            string newRoomName;
            cout << "Enter new name for the room: ";
            getline(cin, newRoomName);

            if (newRoomName.empty()) {
                cout << "Room name cannot be empty.\n";
                break;
            }

            // Update the room name
            rooms[roomChoice - 1] = newRoomName;
            writeRooms(rooms);

            cout << "Room name updated to '" << newRoomName << "' successfully!\n";
        }
        break;

        case 3:
            // Delete an existing room
        {
            vector<string> rooms = readRooms();

            if (rooms.empty()) {
                cout << "No rooms available to delete.\n";
                break;
            }

            cout << "\n--- Existing Rooms ---\n";
            for (size_t i = 0; i < rooms.size(); ++i) {
                cout << i + 1 << ". " << rooms[i] << "\n";
            }

            int roomChoice;
            cout << "Select a room to delete: ";
            cin >> roomChoice;
            cin.ignore();

            if (roomChoice < 1 || roomChoice > rooms.size()) {
                cout << "Invalid choice.\n";
                break;
            }

            // Delete the room
            rooms.erase(rooms.begin() + roomChoice - 1);
            writeRooms(rooms);

            cout << "Room deleted successfully!\n";
        }
        break;

        case 4:
            cout << "Exiting Room Management...\n";
            break;

        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    } while (choice != 4);
} 


void Admin::registerStudent() {
    ifstream groupFile("studentgroups.txt");
    if (!groupFile.is_open()) {
        cerr << "Failed to open groups file.\n";
        return;
    }

    vector<string> groups;
    string line;
    while (getline(groupFile, line)) {
        if (!line.empty()) {
            groups.push_back(line);
        }
    }
    groupFile.close();

    if (groups.empty()) {
        cout << "No groups found. Please add groups first.\n";
        return;
    }

    string studentName;
    cout << "\n--- Register Student ---\n";

    // Validate student name (no numbers)
    while (true) {
        cout << "Enter Student Name (letters only): ";
        cin.ignore(); // flush newline
        getline(cin, studentName);

        bool hasDigit = false;
        for (char c : studentName) {
            if (isdigit(c)) {
                hasDigit = true;
                break;
            }
        }

        if (!hasDigit && !studentName.empty()) {
            break; // valid name
        }
        else {
            cout << "Invalid name. Please enter a name without numbers.\n";
        }
    }

    cout << "\nAvailable Groups:\n";
    for (size_t i = 0; i < groups.size(); ++i) {
        cout << i + 1 << ". " << groups[i] << "\n";
    }

    int groupChoice;
    cout << "Select a group by number: ";
    cin >> groupChoice;
    cin.ignore();

    if (groupChoice < 1 || groupChoice > groups.size()) {
        cout << "Invalid group selection.\n";
        return;
    }

    string selectedGroup = groups[groupChoice - 1];

    ofstream studentFile("students.txt", ios::app);
    if (!studentFile.is_open()) {
        cerr << "Failed to open student file.\n";
        return;
    }

    studentFile << studentName << "," << selectedGroup << "\n";
    studentFile.close();

    cout << "Student " << studentName << " registered successfully in " << selectedGroup << ".\n";
}




void Admin::registerLecturer() {
    ofstream file("lecturers.txt", ios::app);
    if (!file.is_open()) {
        cerr << "Failed to open lecturer registration file.\n";
        return;
    }

    string lecturerName, lecturerID;

    cout << "\n--- Lecturer Registration ---\n";

    // Validate name input
    while (true) {
        cout << "Enter Lecturer Name (letters only): ";
        cin.ignore(); // clear newline from previous input
        getline(cin, lecturerName);

        bool hasDigit = false;
        for (char c : lecturerName) {
            if (isdigit(c)) {
                hasDigit = true;
                break;
            }
        }

        if (!hasDigit && !lecturerName.empty()) {
            break; // Valid input
        }
        else {
            cout << "Invalid name. Please enter a name without numbers.\n";
        }
    }

    cout << "Enter Lecturer ID: ";
    getline(cin, lecturerID);

    file << lecturerID << "," << lecturerName << "\n";
    file.close();

    cout << "Lecturer registered successfully!\n";
}



void Admin::createTimetable() 
{ 
    ofstream file("Timetable.txt", ios::app); // Append mode

    if (!file.is_open()) {
        cerr << " Failed to open timetable file.\n";
        return;
    }

    string moduleName, lecturer, group, day, timeSlot, room;

    cout << "\n--- Add Timetable Entry ---\n";

    vector<string> lecturers = getRegisteredLecturers();
    if (lecturers.empty()) {
        cout << "No registered lecturers found. Please register lecturers first.\n";
        return;
    }

    cout << "\nAvailable Registered Lecturers:\n";
    for (size_t i = 0; i < lecturers.size(); ++i) {
        cout << i + 1 << ". " << lecturers[i] << "\n";
    }

    int lecturerChoice;
    cout << "Select a lecturer by number: ";
    cin >> lecturerChoice;
    cin.ignore();

    if (lecturerChoice < 1 || lecturerChoice > lecturers.size()) {
        cout << "Invalid lecturer selection.\n";
        return;
    }

    lecturer = lecturers[lecturerChoice - 1];


    vector<string> modules = getModules();
    if (modules.empty()) {
        cout << " No modules found. Please add modules first.\n";
        return;
    }

    cout << "\nAvailable Modules:\n";
    for (size_t i = 0; i < modules.size(); ++i) {
        cout << i + 1 << ". " << modules[i] << "\n";
    }

    int moduleChoice;
    cout << "Select a module by number: ";
    cin >> moduleChoice;
    cin.ignore();

    if (moduleChoice < 1 || moduleChoice > modules.size()) {
        cout << " Invalid module selection.\n";
        return;
    }

    moduleName = modules[moduleChoice - 1];

    vector<string> groups = getStudentGroups();
    if (groups.empty()) {
        cout << "No student groups found. Please add student groups first.\n";
        return;
    }

    cout << "\nAvailable Student Groups:\n";
    for (size_t i = 0; i < groups.size(); ++i) {
        cout << i + 1 << ". " << groups[i] << "\n";
    }

    int groupChoice;
    cout << "Select a group by number: ";
    cin >> groupChoice;
    cin.ignore();

    if (groupChoice < 1 || groupChoice > groups.size()) {
        cout << "Invalid group selection.\n";
        return;
    }

    group = groups[groupChoice - 1];


    vector<string> validDays = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

    while (true) {
        cout << "Enter Day (e.g., Monday): ";
        getline(cin, day);

        // Convert input to lowercase for case-insensitive matching
        string inputDayLower = day;
        transform(inputDayLower.begin(), inputDayLower.end(), inputDayLower.begin(), ::tolower);

        bool isValid = false;
        for (const string& validDay : validDays) {
            string validDayLower = validDay;
            transform(validDayLower.begin(), validDayLower.end(), validDayLower.begin(), ::tolower);
            if (inputDayLower == validDayLower) {
                day = validDay; // Store the correctly capitalized day
                isValid = true;
                break;
            }
        }

        if (isValid) {
            break;
        }
        else {
            cout << "Invalid day. Please enter a valid day of the week (e.g., Monday).\n";
        }
    }




    regex timePattern(R"(^\d{2}:\d{2}\s*-\s*\d{2}:\d{2}$)");

    while (true) {
        cout << "Enter Time Slot (e.g., 09:00 - 10:00): ";
        getline(cin, timeSlot);

        if (regex_match(timeSlot, timePattern)) {
            // Optionally: Validate time ranges (e.g., hours < 24, minutes < 60)
            int startHour, startMin, endHour, endMin;
            if (sscanf_s(timeSlot.c_str(), "%d:%d - %d:%d", &startHour, &startMin, &endHour, &endMin) == 4 &&
                startHour >= 0 && startHour < 24 && startMin >= 0 && startMin < 60 &&
                endHour >= 0 && endHour < 24 && endMin >= 0 && endMin < 60) {
                break;
            }
            else {
                cout << "Invalid time range. Please enter a valid slot.\n";
            }
        }
        else {
            cout << "Invalid format. Use HH:MM - HH:MM format only.\n";
        }
    }


    vector<string> rooms = getRooms();
    if (rooms.empty()) {
        cout << "No rooms found. Please add rooms first.\n";
        return;
    }

    cout << "\nAvailable Rooms:\n";
    for (size_t i = 0; i < rooms.size(); ++i) {
        cout << i + 1 << ". " << rooms[i] << "\n";
    }

    int roomChoice;
    cout << "Select a room by number: ";
    cin >> roomChoice;
    cin.ignore();

    if (roomChoice < 1 || roomChoice > rooms.size()) {
        cout << "Invalid room selection.\n";
        return;
    }

    room = rooms[roomChoice - 1];


    // Session Type Selection
    vector<string> sessionTypes = { "Lecture", "Lab" };

    cout << "\nSelect Session Type:\n";
    for (size_t i = 0; i < sessionTypes.size(); ++i) {
        cout << i + 1 << ". " << sessionTypes[i] << "\n";
    }

    int sessionChoice;
    cout << "Enter your choice: ";
    cin >> sessionChoice;
    cin.ignore();

    if (sessionChoice < 1 || sessionChoice > sessionTypes.size()) {
        cout << "Invalid session type selected.\n";
        return;
    }

    string sessionType = sessionTypes[sessionChoice - 1];


    // Write formatted entry
    file << "-------------------------------\n";
    file << "Module: " << moduleName << "\n";
    file << "Lecturer: " << lecturer << "\n";
    file << "Group: " << group << "\n";
    file << "Day: " << day << "\n";
    file << "Time: " << timeSlot << "\n";
    file << "Room: " << room << "\n";
    file << "Session Type: " << sessionType << "\n";
	file << "-------------------------------";
    file.close();
    cout << "Entry added successfully to text file!\n";
}


void Admin::updateTimetable() {
    ifstream inFile("Timetable.txt");
    if (!inFile.is_open()) {
        cerr << "Unable to open Timetable.txt\n";
        return;
    }

    vector<string> entries;
    string line, entry;

    // Collect entries
    while (getline(inFile, line)) {
        entry += line + "\n";
        if (line.find("-------------------------------") != string::npos && !entry.empty()) {
            if (entry.find("Module: ") != string::npos) {
                entries.push_back(entry);
            }
            entry = "";
        }
    }
    inFile.close();

    if (entries.empty()) {
        cout << "No timetable entries to update.\n";
        return;
    }

    // Display existing entries
    cout << "\n--- Existing Timetable Entries ---\n";
    for (size_t i = 0; i < entries.size(); ++i) {
        cout << "Entry " << i + 1 << ":\n" << entries[i] << "\n";
    }

    int index;
    cout << "Enter the number of the entry to update: ";
    cin >> index;
    cin.ignore();
    if (index < 1 || index > entries.size()) {
        cout << "Invalid entry number.\n";
        return;
    }

    // ----------- REPEAT createTimetable flow below ----------- //

    // Load available modules
    vector<string> modules = getModules();
    if (modules.empty()) {
        cout << "No registered modules found.\n";
        return;
    }

    cout << "\nAvailable Modules:\n";
    for (size_t i = 0; i < modules.size(); ++i) {
        cout << i + 1 << ". " << modules[i] << "\n";
    }

    int moduleChoice;
    cout << "Select a module by number: ";
    cin >> moduleChoice;
    cin.ignore();
    if (moduleChoice < 1 || moduleChoice > modules.size()) {
        cout << "Invalid module selection.\n";
        return;
    }
    string moduleName = modules[moduleChoice - 1];

    // Load available lecturers
    vector<string> lecturers = getRegisteredLecturers(); // assume this returns just names
    if (lecturers.empty()) {
        cout << "No registered lecturers found.\n";
        return;
    }

    cout << "\nAvailable Lecturers:\n";
    for (size_t i = 0; i < lecturers.size(); ++i) {
        cout << i + 1 << ". " << lecturers[i] << "\n";
    }

    int lecturerChoice;
    cout << "Select a lecturer by number: ";
    cin >> lecturerChoice;
    cin.ignore();
    if (lecturerChoice < 1 || lecturerChoice > lecturers.size()) {
        cout << "Invalid lecturer selection.\n";
        return;
    }
    string lecturer = lecturers[lecturerChoice - 1];

    // Load groups
    vector<string> groups = getStudentGroups();
    if (groups.empty()) {
        cout << "No student groups available.\n";
        return;
    }

    cout << "\nAvailable Groups:\n";
    for (size_t i = 0; i < groups.size(); ++i) {
        cout << i + 1 << ". " << groups[i] << "\n";
    }

    int groupChoice;
    cout << "Select a group by number: ";
    cin >> groupChoice;
    cin.ignore();
    if (groupChoice < 1 || groupChoice > groups.size()) {
        cout << "Invalid group selection.\n";
        return;
    }
    string group = groups[groupChoice - 1];

    // Day validation
    vector<string> days = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    cout << "\nAvailable Days:\n";
    for (size_t i = 0; i < days.size(); ++i) {
        cout << i + 1 << ". " << days[i] << "\n";
    }

    int dayChoice;
    cout << "Select a day by number: ";
    cin >> dayChoice;
    cin.ignore();
    if (dayChoice < 1 || dayChoice > days.size()) {
        cout << "Invalid day selection.\n";
        return;
    }
    string day = days[dayChoice - 1];

    // Time slot validation
    string timeSlot;
    while (true) {
        cout << "Enter Time Slot (format HH:MM - HH:MM): ";
        getline(cin, timeSlot);

        int sh, sm, eh, em;
        if (sscanf_s(timeSlot.c_str(), "%d:%d - %d:%d", &sh, &sm, &eh, &em) == 4 &&
            sh >= 0 && sh < 24 && sm >= 0 && sm < 60 &&
            eh >= 0 && eh < 24 && em >= 0 && em < 60) {
            break;
        }
        cout << "Invalid time format.\n";
    }

    // Rooms
    vector<string> rooms = getRooms();
    if (rooms.empty()) {
        cout << "No registered rooms found.\n";
        return;
    }

    cout << "\nAvailable Rooms:\n";
    for (size_t i = 0; i < rooms.size(); ++i) {
        cout << i + 1 << ". " << rooms[i] << "\n";
    }

    int roomChoice;
    cout << "Select a room by number: ";
    cin >> roomChoice;
    cin.ignore();
    if (roomChoice < 1 || roomChoice > rooms.size()) {
        cout << "Invalid room selection.\n";
        return;
    }
    string room = rooms[roomChoice - 1];

    // Session type
    cout << "Select session type:\n1. Lecture\n2. Lab\nChoice: ";
    int typeChoice;
    cin >> typeChoice;
    cin.ignore();
    string sessionType;
    if (typeChoice == 1) sessionType = "Lecture";
    else if (typeChoice == 2) sessionType = "Lab";
    else {
        cout << "Invalid session type selection.\n";
        return;
    }

    // Replace entry
    string updatedEntry =
        "-------------------------------\n"
        "Module: " + moduleName + "\n" +
        "Lecturer: " + lecturer + "\n" +
        "Group: " + group + "\n" +
        "Day: " + day + "\n" +
        "Time: " + timeSlot + "\n" +
        "Room: " + room + "\n" +
        "Session Type: " + sessionType + "\n" +
        "-------------------------------\n";

    entries[index - 1] = updatedEntry;

    ofstream outFile("Timetable.txt");
    for (const string& e : entries) {
        outFile << e;
    }
    outFile.close();

    cout << "Timetable entry updated successfully.\n";
}



void Admin::exportTimetableToCSV() {
    ifstream inputFile("Timetable.txt");
    ofstream outputFile("Timetable.csv");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Failed to open input or output file.\n";
        return;
    }

    outputFile << "Module,Lecturer,Group,Day,Time,Room,Session Type\n"; // CSV Header

    string line, module, lecturer, group, day, time, room, session;
    while (getline(inputFile, line)) {
        if (line.find("Module: ") != string::npos)
            module = line.substr(8);
        else if (line.find("Lecturer: ") != string::npos)
            lecturer = line.substr(10);
        else if (line.find("Group: ") != string::npos)
            group = line.substr(7);
        else if (line.find("Day: ") != string::npos)
            day = line.substr(5);
        else if (line.find("Time: ") != string::npos)
            time = line.substr(6);
        else if (line.find("Room: ") != string::npos)
            room = line.substr(6);
        else if (line.find("Session Type: ") != string::npos)
            session = line.substr(14);
        else if (line.find("-------------------------------") != string::npos) {
            // Write CSV row
            outputFile << module << "," << lecturer << "," << group << "," << day << "," << time << "," << room << "," << session << "\n";
            // Reset for next entry
            module = lecturer = group = day = time = room = session = "";
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Timetable exported successfully to Timetable.csv\n";
}






bool isLecturerRegistered(const string& name)
{
    ifstream file("lecturers.txt");
    if (!file.is_open()) {
        cerr << " Failed to open lecturer file for verification.\n";
        return false;
    }

    string line;
    while (getline(file, line)) {
        size_t commaPos = line.find(",");
        if (commaPos != string::npos) {
            string id = line.substr(0, commaPos);
            string regName = line.substr(commaPos + 1);
            if (regName == name) {
                return true;
            }
        }
    }


    return false;
}
// Function to read current modules from file
vector<string> readModules() {
    vector<string> modules;
    ifstream file("modules.txt");

    if (!file.is_open()) {
        std::cerr << "Failed to open modules file.\n";
        return modules;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            modules.push_back(line);
        }
    }

    return modules;
}

// Function to rewrite the modules file with updated modules
void writeModules(const vector<string>& modules) {
    ofstream file("modules.txt", ios::trunc); // Clear and rewrite the file

    if (!file.is_open()) {
        cerr << "Failed to open modules file.\n";
        return;
    }

    for (const auto& module : modules) {
        file << module << "\n";
    }
}
vector<string> getModules()
{
    vector<string> modules;
    ifstream file("modules.txt");

    if (!file.is_open()) {
        cerr << "Failed to read modules file.\n";
        return modules;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            modules.push_back(line);
        }
    }

    return modules;

}
// Function to rewrite the student groups file with updated groups
void writeStudentGroups(const vector<string>& groups) {
    ofstream file("studentgroups.txt", ios::trunc); // Clear and rewrite the file

    if (!file.is_open()) {
        cerr << "Failed to open student groups file.\n";
        return;
    }

    for (const auto& group : groups) {
        file << group << "\n";
    }
}
// Function to read current student groups from file
vector<string> readStudentGroups() {
    vector<string> groups;
    ifstream file("studentgroups.txt");

    if (!file.is_open()) {
        cerr << "Failed to open student groups file.\n";
        return groups;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            groups.push_back(line);
        }
    }

    return groups;
}
// Function to read current rooms from file
vector<string> readRooms() {
    vector<string> rooms;
    ifstream file("rooms.txt");

    if (!file.is_open()) {
        cerr << "Failed to open rooms file.\n";
        return rooms;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            rooms.push_back(line);
        }
    }

    return rooms;
}

// Function to write updated rooms to file
void writeRooms(const vector<string>& rooms) {
    ofstream file("rooms.txt", ios::trunc); // Clear and rewrite the file

    if (!file.is_open()) {
        cerr << "Failed to open rooms file.\n";
        return;
    }

    for (const auto& room : rooms) {
        file << room << "\n";
    }
}


vector<string> getRegisteredLecturers() {
    vector<string> lecturers;
    ifstream file("lecturers.txt");
    if (!file.is_open()) {
        cerr << "Failed to open lecturers file.\n";
        return lecturers;
    }

    string line;
    while (getline(file, line)) {
        size_t commaPos = line.find(",");
        if (commaPos != string::npos) {
            string name = line.substr(commaPos + 1);
            lecturers.push_back(name);
        }
    }

    file.close();
    return lecturers;
}


vector<string> getStudentGroups() {
    vector<string> groups;
    ifstream file("studentgroups.txt");
    if (!file.is_open()) {
        cerr << "Failed to open student groups file.\n";
        return groups;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            groups.push_back(line);
        }
    }

    file.close();
    return groups;
}

vector<string> getRooms() {
    vector<string> rooms;
    ifstream file("rooms.txt");
    if (!file.is_open()) {
        cerr << "Failed to open rooms file.\n";
        return rooms;
    }

    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            rooms.push_back(line);
        }
    }

    file.close();
    return rooms;
}
