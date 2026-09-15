#include <iostream>
using namespace std;

int main()
{
    char city[100];

    cout << "Enter your city: ";
    cin.getline(city, 100);

    // Traverse the C-string until the null character is found
    for (int i = 0; city[i] != '\0'; i++)
    {
        cout << "city[" << i << "] = " << city[i] << endl;
    }

    return 0;
}
