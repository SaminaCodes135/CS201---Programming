#include <iostream>
using namespace std;

int main()
{
    // C-string initialized using individual characters
    char name[4] = {'V', 'U', 'C', '\0'};

    // C-string initialized using a string literal
    char city[] = "Lahore";

    // C-string with explicitly specified size
    char language[4] = {'C', '+', '+', '\0'};

    // Display the C-strings
    cout << "Name: " << name << endl;
    cout << "City: " << city << endl;
    cout << "Language: " << language << endl;

    return 0;
}
