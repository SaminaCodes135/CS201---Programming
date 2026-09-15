#include <iostream>
using namespace std;

void reverseString(char text[], int length)
{
    // Swap characters from both ends until reaching the middle
    for (int i = 0; i < length / 2; i++)
    {
        char temp = text[i];
        text[i] = text[length - 1 - i];
        text[length - 1 - i] = temp;
    }
}

int main()
{
    char text[100];
    int length = 0;

    cout << "Enter your name: ";
    cin.getline(text, 100);

    // Find the length of the C-string
    while (text[length] != '\0')
    {
        length++;
    }

    reverseString(text, length);

    cout << "Reversed string: " << text << endl;

    return 0;
}
