#include <iostream>
using namespace std;

int main()
{
    char text[100] = "PROGRAMMING";
    int count = 0;

    // Traverse the C-string until the null character is reached
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == 'A' || text[i] == 'E' || text[i] == 'I' ||
            text[i] == 'O' || text[i] == 'U' ||
            text[i] == 'a' || text[i] == 'e' || text[i] == 'i' ||
            text[i] == 'o' || text[i] == 'u')
        {
            count++;
        }
    }

    cout << "String: " << text << endl;
    cout << "Number of vowels: " << count << endl;

    return 0;
}
