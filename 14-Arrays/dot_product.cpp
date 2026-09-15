#include <iostream>
using namespace std;

int main()
{
    int vector1[3], vector2[3];
    int dotProduct = 0;

    cout << "Enter 3 elements for the first vector: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> vector1[i];
    }

    cout << "Enter 3 elements for the second vector: ";
    for (int i = 0; i < 3; i++)
    {
        cin >> vector2[i];
    }

    // Multiply corresponding elements and add the results
    for (int i = 0; i < 3; i++)
    {
        dotProduct += vector1[i] * vector2[i];
    }

    cout << "Dot product = " << dotProduct << endl;

    return 0;
}
