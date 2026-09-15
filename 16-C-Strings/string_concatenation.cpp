#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[100];
    char str2[100];

    cout << "Enter first string: ";
    cin.getline(str1, 100);

    cout << "Enter second string: ";
    cin.getline(str2, 100);

    // Add the second string to the end of the first string
    strcat(str1, str2);

    cout << "Concatenated string: " << str1 << endl;

    return 0;
}
