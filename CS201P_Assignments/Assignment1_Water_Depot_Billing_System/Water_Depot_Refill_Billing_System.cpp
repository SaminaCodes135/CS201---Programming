#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Store the student's name and VU Student ID.
    const string studentName = "Samina Zahoor";
    const string studentID = "BC260218531";
    const long long idNumber = 260218531;

    // Display student information before the billing details.
    cout << "Student Name: " << studentName << endl;
    cout << "VU Student ID: " << studentID << endl;

    // Extract the last five digits from the numeric part of the student ID.
    // Division moves the required digit to the last position, and % 10 extracts it.
    int digit1 = (idNumber / 10000) % 10;
    int digit2 = (idNumber / 1000) % 10;
    int digit3 = (idNumber / 100) % 10;
    int digit4 = (idNumber / 10) % 10;
    int digit5 = idNumber % 10;

    // Initialize variables used to calculate the daily totals.
    int totalContainers = 0;
    int totalOriginalCharges = 0;
    int totalDiscount = 0;
    int totalCollected = 0;

    cout << "\nCOMMUNITY WATER REFILL DEPOT BILLING SYSTEM\n";
    cout << "--------------------------------------------\n";

    // Use a loop to process the five customer orders.
    for (int order = 1; order <= 5; order++)
    {
        int digit;
        int quantity;
        int rate;
        int originalCharge;
        int discount;
        int finalCharge;
        string packageType;

        // Select the extracted student-ID digit for this order.
        if (order == 1)
            digit = digit1;
        else if (order == 2)
            digit = digit2;
        else if (order == 3)
            digit = digit3;
        else if (order == 4)
            digit = digit4;
        else
            digit = digit5;

        // Each extracted digit represents ten containers.
        quantity = digit * 10;

        // The first three orders use 5-litre containers.
        // The last two orders use 19-litre containers.
        if (order <= 3)
        {
            packageType = "5-litre container";
            rate = 70;
        }
        else
        {
            packageType = "19-litre container";
            rate = 180;
        }

        // Calculate the original charge before applying any discount.
        originalCharge = quantity * rate;

        // Give a 10% discount when an order contains 50 or more containers.
        if (quantity >= 50)
            discount = originalCharge * 10 / 100;
        else
            discount = 0;

        // Subtract the discount from the original charge.
        finalCharge = originalCharge - discount;

        // Display the details of the current customer order.
        cout << "\nOrder " << order << endl;
        cout << "Quantity: " << quantity << " containers" << endl;
        cout << "Package Type: " << packageType << endl;
        cout << "Original Charge: Rs. " << originalCharge << endl;
        cout << "Discount: Rs. " << discount << endl;
        cout << "Final Charge: Rs. " << finalCharge << endl;

        // Add this order's values to the daily totals.
        totalContainers = totalContainers + quantity;
        totalOriginalCharges = totalOriginalCharges + originalCharge;
        totalDiscount = totalDiscount + discount;
        totalCollected = totalCollected + finalCharge;
    }

    // Classify daily sales according to the final amount collected.
    string salesStatus;

    if (totalCollected < 15000)
        salesStatus = "LOW SALES";
    else if (totalCollected <= 29999)
        salesStatus = "NORMAL SALES";
    else
        salesStatus = "HIGH SALES";

    // Display the complete daily sales summary.
    cout << "\nDAILY SALES SUMMARY\n";
    cout << "-------------------\n";
    cout << "Total Containers Supplied: " << totalContainers << endl;
    cout << "Total Original Charges: Rs. " << totalOriginalCharges << endl;
    cout << "Total Discount: Rs. " << totalDiscount << endl;
    cout << "Final Amount Collected: Rs. " << totalCollected << endl;
    cout << "Sales Status: " << salesStatus << endl;

    // End the program successfully.
    return 0;
}
