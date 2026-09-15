#include <iostream>
using namespace std;

int main()
{
    int marks[3][4];

    cout << "Enter marks for 3 students in 4 subjects:" << endl;

    // Use rows for students and columns for subjects
    for (int i = 0; i < 3; i++)
    {
        cout << "Student " << i + 1 << ": ";

        for (int j = 0; j < 4; j++)
        {
            cin >> marks[i][j];
        }
    }

    cout << "\nStudent Marks Table:" << endl;

    // Display the marks row by row
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << marks[i][j] << "\t";
        }

        cout << endl;
    }

    return 0;
}
