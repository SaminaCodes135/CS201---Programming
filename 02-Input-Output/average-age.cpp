#include <iostream>
using namespace std;

int main()
{
    int age1, age2, age3, age4, age5;
    int totalAge;
    double averageAge;

    cout << "Enter the ages of 5 students: ";
    cin >> age1 >> age2 >> age3 >> age4 >> age5;

    totalAge = age1 + age2 + age3 + age4 + age5;
    averageAge = totalAge / 5.0;

    cout << "Average age = " << averageAge << endl;

    return 0;
}
