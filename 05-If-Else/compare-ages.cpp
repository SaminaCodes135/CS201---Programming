#include <iostream>
using namespace std;

int main()
{
    int AmirAge, AmaraAge;

    cout << "Enter Amir's age: ";
    cin >> AmirAge;

    cout << "Enter Amara's age: ";
    cin >> AmaraAge;

    if (AmirAge > AmaraAge)
    {
        cout << "Amir is older than Amara";
    }
    else if (AmirAge < AmaraAge)
    {
        cout << "Amir is younger than Amara";
    }
    else
    {
        cout << "Amir and Amara are the same age";
    }

    return 0;
}
