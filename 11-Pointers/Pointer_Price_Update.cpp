
#include <iostream>
using namespace std;

int main()
{
    // Declare a variable to store the product price
    float price = 1500.0;

    // Declare a pointer and store the address of price
    float *ptr = &price;

    // Display the original price
    cout << "Original Price: Rs. " << price << endl;

    // Display the value using the pointer
    cout << "Price using Pointer: Rs. " << *ptr << endl;

    // Update the price using the dereferencing operator
    *ptr = 1800.0;

    // Display the updated price
    cout << "Updated Price: Rs. " << price << endl;

    return 0;
}
