# Software Design & Imp

**NTU Timetable Management System** is a C++ console app for university timetabling. Admins manage modules, student groups, rooms, students, lecturers, and the timetable. Students can view and search the timetable. Data is stored in text files and can be exported to CSV.

This is the Software Design and Implementation coursework: an analysis/design report plus a Visual Studio C++ solution that uses inheritance (`User` → `Admin` / `Student`) and file I/O.

## Run the program

1. Open `Software Design & Imp/NTUTimetableManagementSystem/NTUTimetableManagementSystem/NTUTimetableManagementSystem.sln` in Visual Studio.
2. Build and run the console project.
3. Log in with the demo accounts from `main.cpp`:
   - Admin: `admin` / `adminpass`
   - Student: `student` / `studentpass`

Working files (`Modules.txt`, `Timetable.txt`, `students.txt`, and similar) sit next to the source so the program can read and write them at runtime.

## What it does

**Admin menu**

1. Modules — add, edit, delete
2. Student groups
3. Rooms
4. Register student
5. Register lecturer
6. Create timetable
7. Update timetable
8. Export timetable to CSV (Excel)

**Student menu**

1. View timetable (`Timetable.txt`)
2. Search by entry number, module name, room, or lecturer

## Project files

The course folder is `Software Design & Imp/`.

| Path | Role |
| --- | --- |
| `Analysis and Design Report.docx` | Analysis and design write-up |
| `NTUTimetableManagementSystem.sln` | Visual Studio solution |
| `main.cpp` | Login and program entry |
| `User.h` | Abstract base user with a virtual menu |
| `Admin.h` / `Admin.cpp` | Admin menus and file-backed management |
| `Student.h` / `Student.cpp` | Student view/search |
| `Modules.txt`, `rooms.txt`, `students.txt`, `lecturers.txt`, `Timetable.txt`, `Timetable.csv` | Persistent data |

Visual Studio cache (`.vs`), build folders (`x64`), and the 78 MB zip of those extras were left out so the repo stays source-only.

## Course

**Software Design & Implementation** — object-oriented design (inheritance, menus, file persistence) applied to a small timetable system.
