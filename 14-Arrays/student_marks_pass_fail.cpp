#include <iostream>
using namespace std;

void inputMarks(int marks[], int size)
{
    // Input marks for each subject
    for (int i = 0; i < size; i++)
    {
        cin >> marks[i];
    }
}

void displayResult(int marks[], int size)
{
    // Check whether each subject is passed or failed
    for (int i = 0; i < size; i++)
    {
        if (marks[i] >= 50)
            cout << "Subject " << i + 1 << ": Pass" << endl;
        else
            cout << "Subject " << i + 1 << ": Fail" << endl;
    }
}

int main()
{
    int marks[5];

    cout << "Enter marks for 5 subjects: ";
    inputMarks(marks, 5);

    cout << "\nResult:" << endl;
    displayResult(marks, 5);

    return 0;
}
