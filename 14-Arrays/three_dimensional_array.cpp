#include <iostream>
using namespace std;

int main()
{
    int building[2][3][4];

    cout << "Enter 24 elements for the 3D array:" << endl;

    // Use three nested loops for layers, rows, and columns
    for (int i = 0; i < 2; i++)
    {
        cout << "Layer " << i + 1 << ":" << endl;

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cin >> building[i][j][k];
            }
        }
    }

    cout << "\n3D Array:" << endl;

    // Display each layer separately
    for (int i = 0; i < 2; i++)
    {
        cout << "Layer " << i + 1 << ":" << endl;

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cout << building[i][j][k] << "\t";
            }

            cout << endl;
        }

        cout << endl;
    }

    return 0;
}
