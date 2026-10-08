#include <iostream>
using namespace std;

// =====================================================
// Constants
// =====================================================

const int MAX_SIZE = 10;

// =====================================================
// Function Prototypes
// =====================================================

// Check whether the matrix is an identity matrix
bool isIdentity(int matrix[][MAX_SIZE], int size);

// =====================================================
// Main Function
// =====================================================

int main()
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;

    // -------------------------------------------------
    // Input matrix size
    // -------------------------------------------------

    cout << "Enter the size of the square matrix: ";
    cin >> size;

    // Validate matrix size
    if (size <= 0 || size > MAX_SIZE)
    {
        cout << "Invalid matrix size." << endl;
        return 0;
    }

    // -------------------------------------------------
    // Input matrix elements
    // -------------------------------------------------

    cout << "Enter " << size * size
         << " elements:" << endl;

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            cin >> matrix[row][col];
        }
    }

    // -------------------------------------------------
    // Check the matrix
    // -------------------------------------------------

    if (isIdentity(matrix, size))
    {
        cout << "\nThe matrix is an identity matrix." << endl;
    }
    else
    {
        cout << "\nThe matrix is not an identity matrix." << endl;
    }

    return 0;
}

// =====================================================
// Check Identity Matrix
// =====================================================

bool isIdentity(int matrix[][MAX_SIZE], int size)
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            // Main diagonal elements must be 1
            if (row == col)
            {
                if (matrix[row][col] != 1)
                {
                    return false;
                }
            }
            // All non-diagonal elements must be 0
            else
            {
                if (matrix[row][col] != 0)
                {
                    return false;
                }
            }
        }
    }

    return true;
}
