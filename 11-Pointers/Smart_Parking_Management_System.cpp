#include <iostream>
using namespace std;

// Function prototypes
void displayParkingStatus(int *status);
void updateParkingSpace(int *status, int spaceNumber);

int main()
{
    // 0 = Available, 1 = Occupied
    int space1 = 0;
    int space2 = 1;
    int space3 = 0;

    // Declare three pointers
    int *ptr1, *ptr2, *ptr3;

    // Store the addresses of parking spaces
    ptr1 = &space1;
    ptr2 = &space2;
    ptr3 = &space3;

    cout << "================================\n";
    cout << " SMART PARKING MANAGEMENT SYSTEM\n";
    cout << "================================\n";

    // Display initial status
    cout << "\nInitial Parking Status:\n";

    cout << "Space 1: ";
    displayParkingStatus(ptr1);

    cout << "Space 2: ";
    displayParkingStatus(ptr2);

    cout << "Space 3: ";
    displayParkingStatus(ptr3);

    // Update a parking space through a pointer
    cout << "\nUpdating Parking Space 1...\n";
    updateParkingSpace(ptr1, 1);

    // Display updated status
    cout << "\nUpdated Parking Status:\n";

    cout << "Space 1: ";
    displayParkingStatus(ptr1);

    // Reassign ptr1 to point to space2
    ptr1 = &space2;

    cout << "\nNow ptr1 points to Space 2.\n";
    cout << "Space 2 status accessed through ptr1: ";
    displayParkingStatus(ptr1);

    // Demonstrate a null pointer
    int *ptr4 = nullptr;

    cout << "\nChecking an unassigned pointer:\n";

    if (ptr4 == nullptr)
    {
        cout << "No parking space is assigned to ptr4.\n";
    }

    cout << "\nProgram completed successfully!\n";

    return 0;
}

// Function to display parking status
void displayParkingStatus(int *status)
{
    if (status == nullptr)
    {
        cout << "Invalid pointer!\n";
        return;
    }

    if (*status == 0)
    {
        cout << "Available\n";
    }
    else
    {
        cout << "Occupied\n";
    }
}

// Function to update a parking space
void updateParkingSpace(int *status, int spaceNumber)
{
    if (status == nullptr)
    {
        cout << "Invalid pointer!\n";
        return;
    }

    int choice;

    cout << "1. Mark as Available\n";
    cout << "2. Mark as Occupied\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        *status = 0;
        cout << "Space " << spaceNumber
             << " is now Available.\n";
    }
    else if (choice == 2)
    {
        *status = 1;
        cout << "Space " << spaceNumber
             << " is now Occupied.\n";
    }
    else
    {
        cout << "Invalid choice. Status unchanged.\n";
    }
}
