#include <iostream>
using namespace std;

int main()
{
    // Outer loop controls the rows
    for (int row = 1; row <= 5; row++)
    {
        // Inner loop prints stars according to the row number
        for (int counter = 1; counter <= row; counter++)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}
