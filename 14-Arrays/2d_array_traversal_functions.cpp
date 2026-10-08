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

// Display the matrix using row-wise traversal
void displayRowWise(int matrix[][COLS], int rows);

// Display the matrix using column-wise traversal
void displayColumnWise(int matrix[][COLS], int rows);

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

    // Display using row-wise traversal
    cout << "\nMatrix (Row-Wise):" << endl;
    displayRowWise(matrix, ROWS);

    // Display using column-wise traversal
    cout << "\nMatrix (Column-Wise Traversal):" << endl;
    displayColumnWise(matrix, ROWS);

    return 0;
}

// =====================================================
// Display Matrix Row-Wise
// =====================================================

void displayRowWise(int matrix[][COLS], int rows)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            cout << matrix[row][col] << " ";
        }

        cout << endl;
    }
}

// =====================================================
// Display Matrix Column-Wise
// =====================================================

void displayColumnWise(int matrix[][COLS], int rows)
{
    for (int col = 0; col < COLS; col++)
    {
        for (int row = 0; row < rows; row++)
        {
            cout << matrix[row][col] << " ";
        }

        cout << endl;
    }
}
