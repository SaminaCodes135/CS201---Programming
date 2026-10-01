#include <iostream>
#include <iomanip>
#include <cstring>
#include <limits>

using namespace std;

// =====================================================
// CONSTANTS
// =====================================================

const int MAX_STUDENTS = 50;
const int SUBJECTS = 6;
const int MAX_NAME_LENGTH = 50;
const int OPTIONAL_SUBJECTS = 15;

const int PASSING_MARK = 40;
const int MAX_MARKS = 100;

// =====================================================
// FUNCTION PROTOTYPES
// =====================================================

// ---------------- Search ----------------

int searchByRollNumber(
    int rollNumbers[],
    int studentCount,
    int roll
);

void searchByName(
    char names[][MAX_NAME_LENGTH],
    int rollNumbers[],
    char group[],
    int studentCount,
    char searchName[]
);

// ---------------- Calculations ----------------

int calculateTotal(int marks[]);

double calculateAverage(int marks[]);

const char* calculateGrade(double average);

bool checkPass(int marks[]);

// ---------------- Input ----------------

int inputRollNumber(
    int rollNumbers[],
    int studentCount
);

void inputName(char name[]);

char selectGroup();

void selectCompulsorySubject(
    char subjectNames[][MAX_NAME_LENGTH]
);

void setGroupSubjects(
    char subjectNames[][MAX_NAME_LENGTH],
    char group
);

void selectArtsSubjects(
    char subjectNames[][MAX_NAME_LENGTH]
);

void inputMarks(
    char subjectNames[][MAX_NAME_LENGTH],
    int marks[]
);

// ---------------- Display ----------------

void displayStudentSummary(
    int roll,
    char name[],
    char group
);

void viewAllStudents(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    int studentCount
);

void viewStudentDetails(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int studentCount
);

void viewResult(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int studentCount
);

// ---------------- Add Student ----------------

void addStudent(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int& studentCount
);

// ---------------- Update Student ----------------

void updateName(char name[]);

void updateRollNumber(
    int rollNumbers[],
    int studentCount,
    int index
);

void updateGroupSubjects(
    char& group,
    char subjectNames[][MAX_NAME_LENGTH],
    int marks[]
);

void updateMarks(
    char subjectNames[][MAX_NAME_LENGTH],
    int marks[]
);

void updateStudent(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int studentCount
);

// ---------------- Delete Student ----------------

void shiftStudentRecords(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int index,
    int studentCount
);

void deleteStudent(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int& studentCount
);

// ---------------- Sorting ----------------

void swapStudentRecords(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int first,
    int second
);

void sortByRollNumber(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int studentCount
);

void sortByName(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int studentCount
);

void sortByTotalMarks(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int studentCount
);

void sortStudents(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int studentCount
);

// ---------------- Menu ----------------

void showMainMenu();

// =====================================================
// SEARCH FUNCTIONS
// =====================================================

int searchByRollNumber(
    int rollNumbers[],
    int studentCount,
    int roll)
{
    for (int i = 0; i < studentCount; i++)
    {
        if (rollNumbers[i] == roll)
        {
            return i;
        }
    }

    return -1;
}

void searchByName(
    char names[][MAX_NAME_LENGTH],
    int rollNumbers[],
    char group[],
    int studentCount,
    char searchName[])
{
    bool found = false;

    for (int i = 0; i < studentCount; i++)
    {
        if (strcmp(names[i], searchName) == 0)
        {
            displayStudentSummary(
                rollNumbers[i],
                names[i],
                group[i]
            );

            cout << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "No student found with this name.\n";
    }
}

// =====================================================
// CALCULATION FUNCTIONS
// =====================================================

int calculateTotal(int marks[])
{
    int total = 0;

    for (int i = 0; i < SUBJECTS; i++)
    {
        total += marks[i];
    }

    return total;
}

double calculateAverage(int marks[])
{
    int total = calculateTotal(marks);

    double average =
        (double) total / SUBJECTS;

    return average;
}

const char* calculateGrade(double average)
{
    if (average >= 80)
        return "A+";

    else if (average >= 70)
        return "A";

    else if (average >= 60)
        return "B";

    else if (average >= 50)
        return "C";

    else if (average >= 40)
        return "D";

    else
        return "F";
}

bool checkPass(int marks[])
{
    for (int i = 0; i < SUBJECTS; i++)
    {
        if (marks[i] < PASSING_MARK)
        {
            return false;
        }
    }

    return true;
}

// =====================================================
// INPUT FUNCTIONS
// =====================================================

int inputRollNumber(
    int rollNumbers[],
    int studentCount)
{
    int roll;

    while (true)
    {
        cout << "Enter Roll Number: ";
        cin >> roll;

        if (cin.fail())
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (roll < 0)
        {
            cout << "Roll number cannot be negative.\n";
            continue;
        }

        if (searchByRollNumber(
                rollNumbers,
                studentCount,
                roll) != -1)
        {
            cout << "This roll number already exists.\n";
            continue;
        }

        return roll;
    }
}

void inputName(char name[])
{
    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    while (true)
    {
        cout << "Enter Student Name: ";
        cin.getline(name, MAX_NAME_LENGTH);

        if (name[0] == '\0')
        {
            cout << "Name cannot be empty.\n";
            continue;
        }

        break;
    }
}

char selectGroup()
{
    char choice;

    while (true)
    {
        cout << "\nSelect Group:\n";
        cout << "1. Engineering / Pre-Engineering\n";
        cout << "2. Medical / Pre-Medical\n";
        cout << "3. Arts / Humanities\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
            case '1':
                return '1';

            case '2':
                return '2';

            case '3':
                return '3';

            default:
                cout << "Invalid group choice. Please try again.\n";
        }
    }
}

void selectCompulsorySubject(
    char subjectNames[][MAX_NAME_LENGTH])
{
    char choice;

    while (true)
    {
        cout << "\nSelect Compulsory Subject:\n";
        cout << "1. Islamiat\n";
        cout << "2. Pak Studies\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
            case '1':
                strcpy(
                    subjectNames[2],
                    "Islamiat"
                );
                return;

            case '2':
                strcpy(
                    subjectNames[2],
                    "Pak Studies"
                );
                return;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

void setGroupSubjects(
    char subjectNames[][MAX_NAME_LENGTH],
    char group)
{
    switch (group)
    {
        case '1':

            strcpy(
                subjectNames[3],
                "Physics"
            );

            strcpy(
                subjectNames[4],
                "Chemistry"
            );

            strcpy(
                subjectNames[5],
                "Mathematics"
            );

            break;

        case '2':

            strcpy(
                subjectNames[3],
                "Physics"
            );

            strcpy(
                subjectNames[4],
                "Chemistry"
            );

            strcpy(
                subjectNames[5],
                "Biology"
            );

            break;
    }
}

void selectArtsSubjects(
    char subjectNames[][MAX_NAME_LENGTH])
{
    const char optionalSubjects[
        OPTIONAL_SUBJECTS
    ][MAX_NAME_LENGTH] =
    {
        "Civics",
        "Education",
        "History",
        "Geography",
        "Economics",
        "Computer Science",
        "Mathematics",
        "Psychology",
        "Sociology",
        "Home Economics",
        "Fine Arts",
        "Arabic",
        "Punjabi",
        "Persian",
        "Physical Education"
    };

    int choice1;
    int choice2;
    int choice3;

    cout << "\nSelect 3 Optional Subjects:\n";

    for (int i = 0; i < OPTIONAL_SUBJECTS; i++)
    {
        cout << i + 1
             << ". "
             << optionalSubjects[i]
             << endl;
    }

    // Each optional-subject choice is validated separately,
    // and duplicate subjects are not allowed.

    // First subject
    while (true)
    {
        cout << "Enter first choice: ";
        cin >> choice1;

        if (cin.fail())
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice1 >= 1 &&
            choice1 <= OPTIONAL_SUBJECTS)
        {
            break;
        }

        cout << "Invalid choice. Enter a number from 1 to "
             << OPTIONAL_SUBJECTS
             << ".\n";
    }

    // Second subject
    while (true)
    {
        cout << "Enter second choice: ";
        cin >> choice2;

        if (cin.fail())
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice2 < 1 ||
            choice2 > OPTIONAL_SUBJECTS)
        {
            cout << "Invalid choice. Enter a number from 1 to "
                 << OPTIONAL_SUBJECTS
                 << ".\n";
        }
        else if (choice2 == choice1)
        {
            cout << "You already selected this subject. "
                 << "Choose another.\n";
        }
        else
        {
            break;
        }
    }

    // Third subject
    while (true)
    {
        cout << "Enter third choice: ";
        cin >> choice3;

        if (cin.fail())
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice3 < 1 ||
            choice3 > OPTIONAL_SUBJECTS)
        {
            cout << "Invalid choice. Enter a number from 1 to "
                 << OPTIONAL_SUBJECTS
                 << ".\n";
        }
        else if (choice3 == choice1 ||
                 choice3 == choice2)
        {
            cout << "You already selected this subject. "
                 << "Choose another.\n";
        }
        else
        {
            break;
        }
    }

    strcpy(
        subjectNames[3],
        optionalSubjects[choice1 - 1]
    );

    strcpy(
        subjectNames[4],
        optionalSubjects[choice2 - 1]
    );

    strcpy(
        subjectNames[5],
        optionalSubjects[choice3 - 1]
    );
}

void inputMarks(
    char subjectNames[][MAX_NAME_LENGTH],
    int marks[])
{
    for (int i = 0; i < SUBJECTS; i++)
    {
        while (true)
        {
            cout << "Enter marks for "
                 << subjectNames[i]
                 << " (0-"
                 << MAX_MARKS
                 << "): ";

            cin >> marks[i];

            if (cin.fail())
            {
                cin.clear();

                cin.ignore(
                    numeric_limits<streamsize>::max(),
                    '\n'
                );

                cout << "Invalid input. Please enter a number.\n";
                continue;
            }

            if (marks[i] < 0 ||
                marks[i] > MAX_MARKS)
            {
                cout << "Marks must be between 0 and "
                     << MAX_MARKS
                     << ".\n";

                continue;
            }

            break;
        }
    }
}

// =====================================================
// DISPLAY FUNCTIONS
// =====================================================

void displayStudentSummary(
    int roll,
    char name[],
    char group)
{
    cout << "Roll Number : " << roll << endl;
    cout << "Name        : " << name << endl;

    cout << "Group       : ";

    switch (group)
    {
        case '1':
            cout << "Engineering / Pre-Engineering";
            break;

        case '2':
            cout << "Medical / Pre-Medical";
            break;

        case '3':
            cout << "Arts / Humanities";
            break;

        default:
            cout << "Unknown";
    }

    cout << endl;
}

void viewAllStudents(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    int studentCount)
{
    if (studentCount == 0)
    {
        cout << "\nNo students found.\n";
        return;
    }

    cout << "\n========== ALL STUDENTS ==========\n\n";

    cout << left
         << setw(12) << "Roll No."
         << setw(25) << "Name"
         << "Group"
         << endl;

    cout << "------------------------------------------------------\n";

    for (int i = 0; i < studentCount; i++)
    {
        cout << left
             << setw(12) << rollNumbers[i]
             << setw(25) << names[i];

        switch (group[i])
        {
            case '1':
                cout << "Engineering";
                break;

            case '2':
                cout << "Medical";
                break;

            case '3':
                cout << "Arts";
                break;

            default:
                cout << "Unknown";
        }

        cout << endl;
    }

    cout << "------------------------------------------------------\n";

    cout << "Total Students: "
         << studentCount
         << endl;

    cout << "======================================================\n";
}

void viewStudentDetails(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int studentCount)
{
    if (studentCount == 0)
    {
        cout << "\nNo students found.\n";
        return;
    }

    int roll;

    cout << "\nEnter Roll Number: ";
    cin >> roll;

    int index =
        searchByRollNumber(
            rollNumbers,
            studentCount,
            roll
        );

    if (index == -1)
    {
        cout << "Student not found.\n";
        return;
    }

    cout << "\n========== STUDENT DETAILS ==========\n";

    displayStudentSummary(
        rollNumbers[index],
        names[index],
        group[index]
    );

    cout << "\nSubject Marks:\n";
    cout << "--------------------------------------\n";

    for (int i = 0; i < SUBJECTS; i++)
    {
        cout << left
             << setw(25)
             << subjectNames[index][i]
             << marks[index][i]
             << endl;
    }

    cout << "--------------------------------------\n";

    int total =
        calculateTotal(marks[index]);

    double average =
        calculateAverage(marks[index]);

    const char* grade =
        calculateGrade(average);

    bool passed =
        checkPass(marks[index]);

    cout << "\nTotal   : "
         << total
         << " / "
         << SUBJECTS * MAX_MARKS
         << endl;

    cout << "Average : "
         << fixed
         << setprecision(2)
         << average
         << endl;

    cout << "Grade   : "
         << grade
         << endl;

    cout << "Result  : ";

    if (passed)
        cout << "PASS";
    else
        cout << "FAIL";

    cout << "\n======================================\n";
}

void viewResult(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int studentCount)
{
    if (studentCount == 0)
    {
        cout << "\nNo students found.\n";
        return;
    }

    int roll;

    cout << "\nEnter Roll Number: ";
    cin >> roll;

    int index =
        searchByRollNumber(
            rollNumbers,
            studentCount,
            roll
        );

    if (index == -1)
    {
        cout << "Student not found.\n";
        return;
    }

    int total =
        calculateTotal(marks[index]);

    double average =
        calculateAverage(marks[index]);

    const char* grade =
        calculateGrade(average);

    bool passed =
        checkPass(marks[index]);

    cout << "\n";
    cout << "============================================\n";
    cout << "             STUDENT RESULT CARD            \n";
    cout << "============================================\n";

    cout << "Roll Number : "
         << rollNumbers[index]
         << endl;

    cout << "Name        : "
         << names[index]
         << endl;

    cout << "Group       : ";

    switch (group[index])
    {
        case '1':
            cout << "Engineering / Pre-Engineering";
            break;

        case '2':
            cout << "Medical / Pre-Medical";
            break;

        case '3':
            cout << "Arts / Humanities";
            break;

        default:
            cout << "Unknown";
    }

    cout << "\n\n";

    cout << left
         << setw(25)
         << "Subject"
         << "Marks"
         << endl;

    cout << "--------------------------------------------\n";

    for (int i = 0; i < SUBJECTS; i++)
    {
        cout << left
             << setw(25)
             << subjectNames[index][i]
             << marks[index][i]
             << endl;
    }

    cout << "--------------------------------------------\n";

    cout << "Total Marks : "
         << total
         << " / "
         << SUBJECTS * MAX_MARKS
         << endl;

    cout << "Average     : "
         << fixed
         << setprecision(2)
         << average
         << endl;

    cout << "Grade       : "
         << grade
         << endl;

    cout << "Result      : ";

    if (passed)
        cout << "PASS";
    else
        cout << "FAIL";

    cout << "\n============================================\n";
}

// =====================================================
// ADD STUDENT
// =====================================================

void addStudent(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int& studentCount)
{
    if (studentCount >= MAX_STUDENTS)
    {
        cout << "\nStudent limit reached. "
             << "Cannot add more students.\n";

        return;
    }

    cout << "\n========== ADD STUDENT ==========\n";

    rollNumbers[studentCount] =
        inputRollNumber(
            rollNumbers,
            studentCount
        );

    inputName(
        names[studentCount]
    );

    group[studentCount] =
        selectGroup();

    strcpy(
        subjectNames[studentCount][0],
        "English"
    );

    strcpy(
        subjectNames[studentCount][1],
        "Urdu"
    );

    selectCompulsorySubject(
        subjectNames[studentCount]
    );

    if (group[studentCount] == '1' ||
        group[studentCount] == '2')
    {
        setGroupSubjects(
            subjectNames[studentCount],
            group[studentCount]
        );
    }
    else
    {
        selectArtsSubjects(
            subjectNames[studentCount]
        );
    }

    cout << "\nEnter Marks:\n";

    inputMarks(
        subjectNames[studentCount],
        marks[studentCount]
    );

    studentCount++;

    cout << "\nStudent added successfully.\n";
    cout << "================================\n";
}

// =====================================================
// UPDATE FUNCTIONS
// =====================================================

void updateName(char name[])
{
    char newName[MAX_NAME_LENGTH];

    cin.ignore(
        numeric_limits<streamsize>::max(),
        '\n'
    );

    while (true)
    {
        cout << "Enter New Name: ";

        cin.getline(
            newName,
            MAX_NAME_LENGTH
        );

        if (newName[0] == '\0')
        {
            cout << "Name cannot be empty.\n";
            continue;
        }

        break;
    }

    strcpy(
        name,
        newName
    );

    cout << "Name updated successfully.\n";
}

void updateRollNumber(
    int rollNumbers[],
    int studentCount,
    int index)
{
    int newRoll;

    while (true)
    {
        cout << "Enter New Roll Number: ";
        cin >> newRoll;

        if (cin.fail())
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (newRoll < 0)
        {
            cout << "Roll number cannot be negative.\n";
            continue;
        }

        int existingIndex =
            searchByRollNumber(
                rollNumbers,
                studentCount,
                newRoll
            );

        if (existingIndex != -1 &&
            existingIndex != index)
        {
            cout << "This roll number already belongs "
                 << "to another student.\n";

            continue;
        }

        rollNumbers[index] =
            newRoll;

        cout << "Roll number updated successfully.\n";

        break;
    }
}

void updateGroupSubjects(
    char& group,
    char subjectNames[][MAX_NAME_LENGTH],
    int marks[])
{
    char newGroup =
        selectGroup();

    char newSubjectNames[
        SUBJECTS
    ][MAX_NAME_LENGTH];

    strcpy(
        newSubjectNames[0],
        "English"
    );

    strcpy(
        newSubjectNames[1],
        "Urdu"
    );

    selectCompulsorySubject(
        newSubjectNames
    );

    if (newGroup == '1' ||
        newGroup == '2')
    {
        setGroupSubjects(
            newSubjectNames,
            newGroup
        );
    }
    else
    {
        selectArtsSubjects(
            newSubjectNames
        );
    }

    cout << "\nEnter new marks for all subjects:\n";

    int newMarks[SUBJECTS];

    inputMarks(
        newSubjectNames,
        newMarks
    );

    group =
        newGroup;

    for (int i = 0; i < SUBJECTS; i++)
    {
        strcpy(
            subjectNames[i],
            newSubjectNames[i]
        );

        marks[i] =
            newMarks[i];
    }

    cout << "\nGroup and subjects updated successfully.\n";
}

void updateMarks(
    char subjectNames[][MAX_NAME_LENGTH],
    int marks[])
{
    int choice;

    cout << "\n========== UPDATE MARKS ==========\n";

    for (int i = 0; i < SUBJECTS; i++)
    {
        cout << i + 1
             << ". "
             << subjectNames[i]
             << " ("
             << marks[i]
             << ")"
             << endl;
    }

    while (true)
    {
        cout << "Select subject to update (1-"
             << SUBJECTS
             << "): ";

        cin >> choice;

        if (cin.fail())
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice < 1 ||
            choice > SUBJECTS)
        {
            cout << "Invalid choice. Please select 1-"
                 << SUBJECTS
                 << ".\n";

            continue;
        }

        break;
    }

    int subjectIndex =
        choice - 1;

    while (true)
    {
        cout << "Enter new marks for "
             << subjectNames[subjectIndex]
             << " (0-"
             << MAX_MARKS
             << "): ";

        cin >> marks[subjectIndex];

        if (cin.fail())
        {
            cin.clear();

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (marks[subjectIndex] < 0 ||
            marks[subjectIndex] > MAX_MARKS)
        {
            cout << "Marks must be between 0 and "
                 << MAX_MARKS
                 << ".\n";

            continue;
        }

        break;
    }

    cout << "Marks updated successfully.\n";
}

void updateStudent(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int studentCount)
{
    // -------------------------------------------------
    // Check whether any student records exist.
    // -------------------------------------------------
    if (studentCount == 0)
    {
        cout << "\nNo students found.\n";
        return;
    }

    int roll;

    cout << "\nEnter Roll Number of student to update: ";
    cin >> roll;

    // -------------------------------------------------
    // Search for the student using the entered
    // roll number.
    // -------------------------------------------------
    int index =
        searchByRollNumber(
            rollNumbers,
            studentCount,
            roll
        );

    // -------------------------------------------------
    // Stop the update operation if no matching
    // student is found.
    // -------------------------------------------------
    if (index == -1)
    {
        cout << "Student not found.\n";
        return;
    }

    cout << "\nStudent Found:\n";

    displayStudentSummary(
        rollNumbers[index],
        names[index],
        group[index]
    );

    char choice;

    // -------------------------------------------------
    // Keep showing the update menu until the user
    // chooses Back. This allows multiple fields of
    // the same student to be updated in one visit.
    // -------------------------------------------------
    do
    {
        cout << "\n========== UPDATE STUDENT ==========\n";

        cout << "1. Update Name\n";
        cout << "2. Update Roll Number\n";
        cout << "3. Update Group / Subjects\n";
        cout << "4. Update Marks\n";
        cout << "5. Back\n";

        cout << "Enter choice: ";

        cin >> choice;

        switch (choice)
        {
            case '1':

                // Update only the student's name.
                updateName(
                    names[index]
                );

                break;

            case '2':

                // Update the roll number while
                // preventing duplicate roll numbers.
                updateRollNumber(
                    rollNumbers,
                    studentCount,
                    index
                );

                break;

            case '3':

                // Changing the group may change the
                // student's subjects, so the group,
                // subjects and marks are updated together.
                updateGroupSubjects(
                    group[index],
                    subjectNames[index],
                    marks[index]
                );

                break;

            case '4':

                // Update the marks of one selected subject.
                updateMarks(
                    subjectNames[index],
                    marks[index]
                );

                break;

            case '5':

                // Leave the update submenu and return
                // to the main menu.
                cout << "Returning to main menu...\n";

                break;

            default:

                // Handle an invalid update-menu choice.
                cout << "Invalid choice. Please select 1-5.\n";
        }

    }
    while (choice != '5');
}

// =====================================================
// DELETE FUNCTIONS
// =====================================================

void shiftStudentRecords(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int index,
    int studentCount)
{
    // -----------------------------------------------------
    // Shift every record after the deleted student one
    // position to the left so that the arrays remain
    // synchronized and no gap is left.
    // -----------------------------------------------------
    for (
        int i = index;
        i < studentCount - 1;
        i++
    )
    {
        rollNumbers[i] =
            rollNumbers[i + 1];

        strcpy(
            names[i],
            names[i + 1]
        );

        group[i] =
            group[i + 1];

        for (int j = 0; j < SUBJECTS; j++)
        {
            strcpy(
                subjectNames[i][j],
                subjectNames[i + 1][j]
            );

            marks[i][j] =
                marks[i + 1][j];
        }
    }
}

void deleteStudent(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int& studentCount)
{
    if (studentCount == 0)
    {
        cout << "\nNo students found.\n";
        return;
    }

    int roll;

    cout << "\nEnter Roll Number of student to delete: ";
    cin >> roll;

    int index =
        searchByRollNumber(
            rollNumbers,
            studentCount,
            roll
        );

    if (index == -1)
    {
        cout << "Student not found.\n";
        return;
    }

    cout << "\nStudent to be deleted:\n";

    displayStudentSummary(
        rollNumbers[index],
        names[index],
        group[index]
    );

    char confirm;

    cout << "\nAre you sure you want to delete "
         << "this student? (Y/N): ";

    cin >> confirm;

    if (confirm == 'Y' ||
        confirm == 'y')
    {
        shiftStudentRecords(
            rollNumbers,
            names,
            group,
            subjectNames,
            marks,
            index,
            studentCount
        );

        studentCount--;

        cout << "\nStudent deleted successfully.\n";
    }
    else
    {
        cout << "\nDeletion cancelled.\n";
    }
}

// =====================================================
// SORT FUNCTIONS
// =====================================================

void swapStudentRecords(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int first,
    int second)
{
    // -----------------------------------------------------
    // Swap all information belonging to two students.
    // Every parallel array must be swapped together so
    // that each student's complete record stays intact.
    // -----------------------------------------------------
    int tempRoll =
        rollNumbers[first];

    rollNumbers[first] =
        rollNumbers[second];

    rollNumbers[second] =
        tempRoll;

    char tempName[
        MAX_NAME_LENGTH
    ];

    strcpy(
        tempName,
        names[first]
    );

    strcpy(
        names[first],
        names[second]
    );

    strcpy(
        names[second],
        tempName
    );

    char tempGroup =
        group[first];

    group[first] =
        group[second];

    group[second] =
        tempGroup;

    for (int i = 0; i < SUBJECTS; i++)
    {
        char tempSubject[
            MAX_NAME_LENGTH
        ];

        strcpy(
            tempSubject,
            subjectNames[first][i]
        );

        strcpy(
            subjectNames[first][i],
            subjectNames[second][i]
        );

        strcpy(
            subjectNames[second][i],
            tempSubject
        );

        int tempMark =
            marks[first][i];

        marks[first][i] =
            marks[second][i];

        marks[second][i] =
            tempMark;
    }
}

void sortByRollNumber(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int studentCount)
{
    for (
        int i = 0;
        i < studentCount - 1;
        i++
    )
    {
        for (
            int j = 0;
            j < studentCount - i - 1;
            j++
        )
        {
            if (
                rollNumbers[j] >
                rollNumbers[j + 1]
            )
            {
                swapStudentRecords(
                    rollNumbers,
                    names,
                    group,
                    subjectNames,
                    marks,
                    j,
                    j + 1
                );
            }
        }
    }

    cout << "Students sorted by Roll Number.\n";
}

void sortByName(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int studentCount)
{
    for (
        int i = 0;
        i < studentCount - 1;
        i++
    )
    {
        for (
            int j = 0;
            j < studentCount - i - 1;
            j++
        )
        {
            if (
                strcmp(
                    names[j],
                    names[j + 1]
                ) > 0
            )
            {
                swapStudentRecords(
                    rollNumbers,
                    names,
                    group,
                    subjectNames,
                    marks,
                    j,
                    j + 1
                );
            }
        }
    }

    cout << "Students sorted by Name.\n";
}

void sortByTotalMarks(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int studentCount)
{
    for (
        int i = 0;
        i < studentCount - 1;
        i++
    )
    {
        for (
            int j = 0;
            j < studentCount - i - 1;
            j++
        )
        {
            if (
                calculateTotal(marks[j]) <
                calculateTotal(marks[j + 1])
            )
            {
                swapStudentRecords(
                    rollNumbers,
                    names,
                    group,
                    subjectNames,
                    marks,
                    j,
                    j + 1
                );
            }
        }
    }

    cout << "Students sorted by Total Marks.\n";
}

void sortStudents(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    char subjectNames[][SUBJECTS][MAX_NAME_LENGTH],
    int marks[][SUBJECTS],
    int studentCount)
{
    if (studentCount == 0)
    {
        cout << "\nNo students found.\n";
        return;
    }

    char choice;

    cout << "\n========== SORT STUDENTS ==========\n";

    cout << "1. Sort by Roll Number\n";
    cout << "2. Sort by Name\n";
    cout << "3. Sort by Total Marks\n";
    cout << "4. Back\n";

    cout << "Enter choice: ";

    cin >> choice;

    switch (choice)
    {
        case '1':

            sortByRollNumber(
                rollNumbers,
                names,
                group,
                subjectNames,
                marks,
                studentCount
            );

            break;

        case '2':

            sortByName(
                rollNumbers,
                names,
                group,
                subjectNames,
                marks,
                studentCount
            );

            break;

        case '3':

            sortByTotalMarks(
                rollNumbers,
                names,
                group,
                subjectNames,
                marks,
                studentCount
            );

            break;

        case '4':

            return;

        default:

            cout << "Invalid choice.\n";
    }
}

// =====================================================
// SEARCH MENU
// =====================================================

void searchStudent(
    int rollNumbers[],
    char names[][MAX_NAME_LENGTH],
    char group[],
    int studentCount)
{
    if (studentCount == 0)
    {
        cout << "\nNo students found.\n";
        return;
    }

    char choice;

    cout << "\n========== SEARCH STUDENT ==========\n";

    cout << "1. Search by Roll Number\n";
    cout << "2. Search by Name\n";
    cout << "3. Back\n";

    cout << "Enter choice: ";

    cin >> choice;

    switch (choice)
    {
        case '1':
        {
            int roll;

            cout << "Enter Roll Number: ";
            cin >> roll;

            int index =
                searchByRollNumber(
                    rollNumbers,
                    studentCount,
                    roll
                );

            if (index == -1)
            {
                cout << "Student not found.\n";
            }
            else
            {
                cout << "\nStudent Found:\n";

                displayStudentSummary(
                    rollNumbers[index],
                    names[index],
                    group[index]
                );
            }

            break;
        }

        case '2':
        {
            char searchName[
                MAX_NAME_LENGTH
            ];

            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "Enter Student Name: ";

            cin.getline(
                searchName,
                MAX_NAME_LENGTH
            );

            if (searchName[0] == '\0')
            {
                cout << "Name cannot be empty.\n";
                break;
            }

            searchByName(
                names,
                rollNumbers,
                group,
                studentCount,
                searchName
            );

            break;
        }

        case '3':

            return;

        default:

            cout << "Invalid choice. Please try again.\n";
    }
}

// =====================================================
// MAIN MENU
// =====================================================

void showMainMenu()
{
    cout << "\n";
    cout << "====================================================\n";
    cout << "       STUDENT ACADEMIC MANAGEMENT SYSTEM           \n";
    cout << "====================================================\n";

    cout << "1. Add Student\n";
    cout << "2. View All Students\n";
    cout << "3. View Student Details\n";
    cout << "4. Search Student\n";
    cout << "5. Update Student\n";
    cout << "6. Delete Student\n";
    cout << "7. Calculate / View Result\n";
    cout << "8. Sort Students\n";
    cout << "9. Exit\n";

    cout << "====================================================\n";
    cout << "Enter choice: ";
}

// =====================================================
// MAIN FUNCTION
// =====================================================

int main()
{
    // -----------------------------------------------------
    // Parallel arrays are used to store each student's data.
    // The same index represents the same student across
    // roll number, name, group, subjects and marks.
    // -----------------------------------------------------
    int rollNumbers[MAX_STUDENTS];

    char names[
        MAX_STUDENTS
    ][MAX_NAME_LENGTH];

    char group[
        MAX_STUDENTS
    ];

    char subjectNames[
        MAX_STUDENTS
    ][SUBJECTS][MAX_NAME_LENGTH];

    int marks[
        MAX_STUDENTS
    ][SUBJECTS];

    int studentCount = 0;

    char choice;

    do
    {
        showMainMenu();

        cin >> choice;

        switch (choice)
        {
            case '1':

                addStudent(
                    rollNumbers,
                    names,
                    group,
                    subjectNames,
                    marks,
                    studentCount
                );

                break;

            case '2':

                viewAllStudents(
                    rollNumbers,
                    names,
                    group,
                    studentCount
                );

                break;

            case '3':

                viewStudentDetails(
                    rollNumbers,
                    names,
                    group,
                    subjectNames,
                    marks,
                    studentCount
                );

                break;

            case '4':

                searchStudent(
                    rollNumbers,
                    names,
                    group,
                    studentCount
                );

                break;

            case '5':

                updateStudent(
                    rollNumbers,
                    names,
                    group,
                    subjectNames,
                    marks,
                    studentCount
                );

                break;

            case '6':

                deleteStudent(
                    rollNumbers,
                    names,
                    group,
                    subjectNames,
                    marks,
                    studentCount
                );

                break;

            case '7':

                viewResult(
                    rollNumbers,
                    names,
                    group,
                    subjectNames,
                    marks,
                    studentCount
                );

                break;

            case '8':

                sortStudents(
                    rollNumbers,
                    names,
                    group,
                    subjectNames,
                    marks,
                    studentCount
                );

                break;

            case '9':

                cout << "\nThank you for using the "
                     << "Student Academic Management System.\n";

                cout << "Goodbye!\n";

                break;

            default:

                cout << "\nInvalid choice. "
                     << "Please select 1-9.\n";
        }

    }
    while (choice != '9');

    return 0;
}
