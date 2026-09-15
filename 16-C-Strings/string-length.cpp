#include <iostream>
using namespace std;

int main()
{
    char name[100] = "Aliza";
    int length = 0;

    // Count characters until the null character is reached
    while (name[length] != '\0')
    {
        length++;
    }

    cout << "String: " << name << endl;
    cout << "Length: " << length << endl;

    return 0;
}
