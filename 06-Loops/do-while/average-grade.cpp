#include <iostream>
using namespace std;

int main()
{
    int grade;
    int sum = 0;
    int students = 0;

    do
    {
        cout << "Enter grade (-1 to stop): ";
        cin >> grade;

        if (grade >= 0)
        {
            sum += grade;
            students++;
        }

    } while (grade >= 0);

    if (students > 0)
    {
        double average = static_cast<double>(sum) / students;
        cout << "Average grade = " << average;
    }
    else
    {
        cout << "No grades were entered.";
    }

    return 0;
}
