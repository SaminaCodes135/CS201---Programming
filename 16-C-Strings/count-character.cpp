#include <iostream>
using namespace std;

int main()
{
    char text[100] = "banana";
    char target = 'a';
    int count = 0;

    // Check each character until the null character is reached
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == target)
        {
            count++;
        }
    }

    cout << "String: " << text << endl;
    cout << "Character '" << target << "' appears " << count << " times." << endl;

    return 0;
}
