#include <iostream>
using namespace std;

int main()
{
    const int arraySize = 100;
    int numbers[arraySize];

    int value;
    int count = 0;

    cout << "Enter integers (-1 to stop): ";

    // Keep taking input until -1 is entered or the array is full
    do
    {
        cin >> value;

        if (value != -1 && count < arraySize)
        {
            numbers[count] = value;
            count++;
        }

    } while (value != -1 && count < arraySize);

    cout << "Total numbers entered: " << count << endl;

    return 0;
}
