#include <iostream>
using namespace std;

int main()
{
    int number;

    cout << "Enter numbers (0 to stop): ";

    cin >> number;

    while (number != 0)
    {
        cout << "You entered: " << number << endl;

        cin >> number;
    }

    cout << "Input stopped.";

    return 0;
}
