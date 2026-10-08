#include <iostream>
using namespace std;

// =====================================================
// Constants
// =====================================================

const int ROWS = 3;
const int COLS = 3;

// =====================================================
// Function Prototypes
// =====================================================

// Display the matrix with rows in reverse order
void displayReverseRows(int matrix[][COLS], int rows);

// Display each row with columns in reverse order
void displayReverseColumns(int matrix[][COLS], int rows);

// =====================================================
// Main Function
// =====================================================

int main()
{
    int matrix[ROWS][COLS];

    // Input matrix elements row by row
    cout << "Enter " << ROWS * COLS
         << " elements for the " << ROWS << "x"
         << COLS << " matrix:" << endl;

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            cin >> matrix[row][col];
        }
    }

    // Display rows in reverse order
    cout << "\nMatrix (Reverse Row Order):" << endl;
    displayReverseRows(matrix, ROWS);

    // Display columns in reverse order
    cout << "\nMatrix (Reverse Column Order):" << endl;
    displayReverseColumns(matrix, ROWS);

    return 0;
}

// =====================================================
// Display Rows in Reverse Order
// =====================================================

void displayReverseRows(int matrix[][COLS], int rows)
{
    for (int row = rows - 1; row >= 0; row--)
    {
        for (int col = 0; col < COLS; col++)
        {
            cout << matrix[row][col] << " ";
        }

        cout << endl;
    }
}

// =====================================================
// Display Columns in Reverse Order
// =====================================================

void displayReverseColumns(int matrix[][COLS], int rows)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = COLS - 1; col >= 0; col--)
        {
            cout << matrix[row][col] << " ";
        }

        cout << endl;
    }
}
