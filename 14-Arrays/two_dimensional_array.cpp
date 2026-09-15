#include <iostream>
using namespace std;

int main()
{
    int matrix[2][3];

    cout << "Enter 6 elements for the 2x3 matrix:" << endl;

    // Use nested loops to input elements row by row
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\nMatrix:" << endl;

    // Display the 2D array in rows and columns
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
