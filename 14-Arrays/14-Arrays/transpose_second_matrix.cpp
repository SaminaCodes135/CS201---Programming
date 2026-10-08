#include <iostream>
using namespace std;

// =====================================================
// Constants
// =====================================================

const int SIZE = 3;

// =====================================================
// Function Prototypes
// =====================================================

// Display a square matrix
void displayMatrix(int matrix[][SIZE]);

// Create the transpose in a separate matrix
void transposeMatrix(int matrix[][SIZE], int transposed[][SIZE]);

// =====================================================
// Main Function
// =====================================================

int main()
{
    int matrix[SIZE][SIZE];
    int transposed[SIZE][SIZE];

    // -------------------------------------------------
    // Input the original matrix
    // -------------------------------------------------

    cout << "Enter " << SIZE * SIZE
         << " elements for the " << SIZE << "x"
         << SIZE << " matrix:" << endl;

    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            cin >> matrix[row][col];
        }
    }

    // -------------------------------------------------
    // Display the original matrix
    // -------------------------------------------------

    cout << "\nOriginal Matrix:" << endl;
    displayMatrix(matrix);

    // -------------------------------------------------
    // Create the transpose
    // -------------------------------------------------

    transposeMatrix(matrix, transposed);

    // -------------------------------------------------
    // Display the transposed matrix
    // -------------------------------------------------

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(transposed);

    return 0;
}

// =====================================================
// Display Matrix
// =====================================================

void displayMatrix(int matrix[][SIZE])
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            cout << matrix[row][col] << " ";
        }

        cout << endl;
    }
}

// =====================================================
// Transpose Matrix
// =====================================================

void transposeMatrix(int matrix[][SIZE],
                     int transposed[][SIZE])
{
    // In a transpose, rows become columns
    // and columns become rows.
    //
    // Example:
    // matrix[row][col]
    // becomes
    // transposed[col][row]

    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            transposed[col][row] = matrix[row][col];
        }
    }
}
