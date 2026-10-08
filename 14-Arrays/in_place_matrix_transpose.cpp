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

// Transpose the matrix by swapping upper and lower
// triangle elements
void transposeInPlace(int matrix[][SIZE]);

// =====================================================
// Main Function
// =====================================================

int main()
{
    int matrix[SIZE][SIZE];

    // -------------------------------------------------
    // Input the matrix
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
    // Transpose the matrix in place
    // -------------------------------------------------

    transposeInPlace(matrix);

    // -------------------------------------------------
    // Display the transposed matrix
    // -------------------------------------------------

    cout << "\nTransposed Matrix:" << endl;
    displayMatrix(matrix);

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
// In-Place Matrix Transpose
// =====================================================

void transposeInPlace(int matrix[][SIZE])
{
    // Only the upper triangle is processed.
    // Each pair is swapped exactly once.
    //
    // Example:
    // matrix[0][1] <-> matrix[1][0]
    // matrix[0][2] <-> matrix[2][0]
    // matrix[1][2] <-> matrix[2][1]
    //
    // The diagonal elements remain unchanged.

    for (int row = 0; row < SIZE; row++)
    {
        for (int col = row + 1; col < SIZE; col++)
        {
            int temp = matrix[row][col];

            matrix[row][col] = matrix[col][row];
            matrix[col][row] = temp;
        }
    }
}
