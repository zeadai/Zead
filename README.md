Main Idea of the Program

The Attendance Monitoring System is a C++ program designed to manage and monitor students’ attendance records for 30 days.
The program allows the user to enter each student’s name and daily attendance status, where:

1 = Present
0 = Absent
2 = Leave

After collecting the data, the system calculates:

Total present days
Total absent days
Total leave days
Attendance percentage

Finally, the program displays a detailed attendance report for each student and gives a warning if the attendance percentage is below 75%.

----------------  ---------------------    ------------------  --------------------     ---------------------------   -----------------------------     -----------

Algorithm of the Program

Start the program.
Enter the number of students.
Create an array of student records dynamically.
For each student:
Input the student’s name.
Input attendance for 30 days.
Validate the entered values (only 0, 1, or 2 are accepted).
Count:
Present days
Absent days
Leave days
Calculate attendance percentage using:

Attendance Percentage=
30
Total Present Days × 100

Display the final attendance report.
Show a warning if attendance is below 75%.
Free allocated memory.
End the program.
