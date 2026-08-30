#include <iostream>
using namespace std;

int main()
{
    int number;

    cout << "Enter a positive number: ";
    cin >> number;

    if (number < 0)
    {
        cout << "Invalid input.";
        goto end;
    }

    cout << "You entered: " << number << endl;

end:
    cout << "Program finished.";

    return 0;
}
