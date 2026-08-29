#include <iostream>
using namespace std;

// Function calculates the area of a circle
double circleArea(double radius)
{
    return 3.14159 * radius * radius;
}

int main()
{
    double radius;

    cout << "Enter radius: ";
    cin >> radius;

    if (radius < 0)
    {
        cout << "Invalid radius.";
    }
    else
    {
        cout << "Area of circle = " << circleArea(radius);
    }

    return 0;
}
