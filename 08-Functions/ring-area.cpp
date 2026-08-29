#include <iostream>
using namespace std;

// Function calculates the area of a ring
double ringArea(double innerRadius, double outerRadius)
{
    return 3.14159 * (outerRadius * outerRadius -
                      innerRadius * innerRadius);
}

int main()
{
    double innerRadius, outerRadius;

    cout << "Enter inner radius: ";
    cin >> innerRadius;

    cout << "Enter outer radius: ";
    cin >> outerRadius;

    if (innerRadius < 0 || outerRadius <= 0 ||
        innerRadius >= outerRadius)
    {
        cout << "Invalid radii.";
    }
    else
    {
        cout << "Area of ring = "
             << ringArea(innerRadius, outerRadius);
    }

    return 0;
}
