#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char text[100];

    cout << "Enter a word: ";
    cin >> text;

    int length = strlen(text);

    // Swap the first and third characters as an example
    if (length >= 3)
    {
        swap(text[0], text[2]);
        cout << "After swapping first and third characters: " << text << endl;
    }

    // Reverse the string by swapping characters from both ends
    for (int i = 0; i < length / 2; i++)
    {
        swap(text[i], text[length - 1 - i]);
    }

    cout << "Reversed string: " << text << endl;

    return 0;
}
