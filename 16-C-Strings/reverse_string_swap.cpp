#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char text[100];

    cout << "Enter a word: ";
    cin >> text;

    int length = strlen(text);

    // Swap characters from both ends to reverse the string
    for (int i = 0; i < length / 2; i++)
    {
        swap(text[i], text[length - 1 - i]);
    }

    cout << "Reversed string: " << text << endl;

    return 0;
}
