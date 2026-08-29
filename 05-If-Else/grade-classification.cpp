#include <iostream>
using namespace std;

int main()
{
    char grade;

    cout << "Enter your grade (A, B, C, D, or F): ";
    cin >> grade;

    // if-else-if checks conditions one by one
    if (grade == 'A')
    {
        cout << "Excellent";
    }
    else if (grade == 'B')
    {
        cout << "Very Good";
    }
    else if (grade == 'C')
    {
        cout << "Good";
    }
    else if (grade == 'D')
    {
        cout << "Poor";
    }
    else if (grade == 'F')
    {
        cout << "Fail";
    }
    else
    {
        cout << "Invalid grade";
    }

    return 0;
}
