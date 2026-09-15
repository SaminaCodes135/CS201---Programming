#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[100];
    char str2[100];
    char copy[100];
    char combined[200];

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 100);

    // strlen() returns the number of characters in a C-string
    cout << "Length of first string: " << strlen(str1) << endl;

    // strcpy() copies one C-string into another
    strcpy(copy, str1);
    cout << "Copied string: " << copy << endl;

    // strcat() joins the second string to the first string
    strcpy(combined, str1);
    strcat(combined, " ");
    strcat(combined, str2);
    cout << "Combined string: " << combined << endl;

    // strcmp() compares two C-strings
    if (strcmp(str1, str2) == 0)
        cout << "Both strings are equal." << endl;
    else
        cout << "Strings are different." << endl;

    return 0;
}
