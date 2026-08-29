#include <iostream>
using namespace std;

int main()
{
    int age, height;

    cout << "Enter age and height: ";
    cin >> age >> height;

    // || means OR: at least one condition must be true
    if (age > 18 || height > 5)
    {
        cout << "You qualify";
    }
    else
    {
        cout << "You do not qualify";
    }

    return 0;
}
