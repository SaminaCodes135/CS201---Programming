
#include <iostream>
using namespace std;

// ==================================================
// Constants
// ==================================================

const int SIZE = 5;

// ==================================================
// Function Prototypes
// ==================================================

void displayInventory(const int *ptr, const char *names[], int size);
void updateQuantity(int *ptr, int newQuantity);
void swapQuantities(int *ptr1, int *ptr2);

// ==================================================
// Main Function
// ==================================================

int main()
{
    // Store product quantities in an array
    int quantities[SIZE] = {10, 20, 30, 15, 8};

    // Store product names
    const char *products[SIZE] = {
        "Laptops",
        "Keyboards",
        "Mouse Devices",
        "Monitors",
        "USB Drives"
    };

    // Display the address of the first array element
    cout << "Address of first element: "
         << quantities << endl;

    // Declare a pointer and store the first element's address
    int *ptr = &quantities[0];

    cout << "\nFirst product (" << products[0]
         << ") quantity: " << *ptr << endl;

    // Display inventory using a pointer
    cout << "\n--- Warehouse Inventory ---" << endl;

    displayInventory(quantities, products, SIZE);

    // Update a quantity through a pointer
    cout << "\n--- Updating Inventory ---" << endl;

    updateQuantity(&quantities[1], 25);

    cout << products[1] << " updated quantity: "
         << quantities[1] << endl;

    // Demonstrate a constant pointer-to-data
    cout << "\n--- Read-Only Pointer ---" << endl;

    int x = quantities[0];
    const int *myptr = &x;

    cout << "Quantity through myptr: " << *myptr << endl;

    // *myptr = 50; // Error: cannot modify x through myptr

    // Swap two quantities using pointers
    cout << "\n--- Swapping Quantities ---" << endl;

    cout << "Before swapping:" << endl;
    cout << products[0] << ": " << quantities[0] << endl;
    cout << products[1] << ": " << quantities[1] << endl;

    swapQuantities(&quantities[0], &quantities[1]);

    cout << "\nAfter swapping:" << endl;
    cout << products[0] << ": " << quantities[0] << endl;
    cout << products[1] << ": " << quantities[1] << endl;

    // Demonstrate pointer arithmetic
    cout << "\n--- Pointer Arithmetic ---" << endl;

    ptr = quantities;

    for (int i = 0; i < SIZE; i++)
    {
        cout << products[i] << ": "
             << *(ptr + i) << endl;
    }

    return 0;
}

// ==================================================
// Display Inventory Using a Pointer
// ==================================================

void displayInventory(const int *ptr, const char *names[], int size)
{
    if (ptr == nullptr || names == nullptr || size <= 0)
    {
        cout << "Invalid inventory data." << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        cout << names[i] << ": " << *(ptr + i) << endl;
    }
}

// ==================================================
// Update Quantity Through a Pointer
// ==================================================

void updateQuantity(int *ptr, int newQuantity)
{
    if (ptr == nullptr)
    {
        cout << "Cannot update quantity: invalid pointer." << endl;
        return;
    }

    if (newQuantity < 0)
    {
        cout << "Quantity cannot be negative." << endl;
        return;
    }

    *ptr = newQuantity;
}

// ==================================================
// Swap Two Quantities Using Pointers
// ==================================================

void swapQuantities(int *ptr1, int *ptr2)
{
    if (ptr1 == nullptr || ptr2 == nullptr)
    {
        cout << "Cannot swap quantities: invalid pointer." << endl;
        return;
    }

    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
