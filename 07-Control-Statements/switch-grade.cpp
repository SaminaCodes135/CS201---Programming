#include <iostream>
using namespace std;

int main()
{
    char grade;

    cout << "Enter your grade (A, B, C, D, or F): ";
    cin >> grade;

    // switch selects one case based on the value of grade
    switch (grade)
    {
        case 'A':
        case 'a':
            cout << "Excellent";
            break;

        case 'B':
        case 'b':
            cout << "Very Good";
            break;

        case 'C':
        case 'c':
            cout << "Good";
            break;

        case 'D':
        case 'd':
            cout << "Poor";
            break;

        case 'F':
        case 'f':
            cout << "Fail";
            break;

        default:
            cout << "Invalid grade";
    }

    return 0;
}
