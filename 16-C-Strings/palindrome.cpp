#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    char word[100];
    int length = 0;
    bool palindrome = true;

    cout << "Enter a word: ";
    cin >> word;

    // Find the length of the C-string
    while (word[length] != '\0')
    {
        length++;
    }

    // Compare characters from both ends of the string
    for (int i = 0; i < length / 2; i++)
    {
        if (tolower(word[i]) != tolower(word[length - 1 - i]))
        {
            palindrome = false;
            break;
        }
    }

    if (palindrome)
        cout << "It is a palindrome." << endl;
    else
        cout << "It is not a palindrome." << endl;

    return 0;
}
