#include <iostream>
#include <string>

using namespace std;

const int DAYS = 30;

struct Student {
    string name;
    int attendance[DAYS];
    int totalPresent;
    int totalAbsent;
    int totalLeave;
    float percentage;
};

void inputStudentData(Student &s) {
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);

    cout << "Enter attendance for " << DAYS << " days:\n";
    cout << "(1 for Present, 0 for Absent, 2 for Leave)\n";

    for (int d = 0; d < DAYS; d++) {
        int status;
        cout << "Day " << d + 1 << ": ";
        cin >> status;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input! Please enter 1, 0, or 2 only." << endl;
            d--;
        } else if (status == 1 || status == 0 || status == 2) {
            s.attendance[d] = status;
            cin.ignore();
        } else {
            cin.ignore();
            cout << " Invalid value! Only 1 (Present), 0 (Absent), or 2 (Leave) are allowed." << endl;
            d--;
        }
    }
}

void calculateAttendance(Student &s) {
    s.totalPresent = 0;
    s.totalAbsent = 0;
    s.totalLeave = 0;

    for (int d = 0; d < DAYS; d++) {
        if (s.attendance[d] == 1) {
            s.totalPresent++;
        } else if (s.attendance[d] == 0) {
            s.totalAbsent++;
        } else if (s.attendance[d] == 2) {
            s.totalLeave++;
        }
    }

    s.percentage = ((float)s.totalPresent / DAYS) * 100.0;
}

void displayStudentResults(const Student &s) {
    cout << "\n--- Results for " << s.name << " ---" << endl;
    cout << "Present: " << s.totalPresent << " days" << endl;
    cout << "Absent: " << s.totalAbsent << " days" << endl;
    cout << "Leave: " << s.totalLeave << " days" << endl;
    cout << "Attendance Percentage: " << s.percentage << "%" << endl;

    if (s.percentage < 75.0) {
        cout << "WARNING: Attendance is below 75%!" << endl;
    } else {
        cout << "Status: Normal" << endl;
    }
    cout << "----------------------------\n" << endl;
}

int main() {
    int numStudents;

    cout << "=== Attendance Monitoring System ===" << endl;
    cout << "Enter number of students: ";
    cin >> numStudents;
    cin.ignore();

    Student* students = new Student[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "\n--- Student #" << i + 1 << " ---" << endl;
        inputStudentData(students[i]);
        calculateAttendance(students[i]);
    }

    cout << "\n\n======== FINAL ATTENDANCE REPORT ========" << endl;

    for (int i = 0; i < numStudents; i++) {
        displayStudentResults(students[i]);
    }

    delete[] students;

    return 0;
}
