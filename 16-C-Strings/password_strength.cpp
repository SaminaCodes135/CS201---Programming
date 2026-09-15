#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char password[100];
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;

    cout << "Enter your password: ";
    cin >> password;

    // Check whether the password contains uppercase, lowercase, and digit characters
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (isupper(password[i]))
            hasUpper = true;
        else if (islower(password[i]))
            hasLower = true;
        else if (isdigit(password[i]))
            hasDigit = true;
    }

    if (hasUpper && hasLower && hasDigit)
        cout << "Strong password." << endl;
    else
        cout << "Weak password. Use uppercase, lowercase, and a digit." << endl;

    return 0;
}
