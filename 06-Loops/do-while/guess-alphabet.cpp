#include <iostream>
using namespace std;

int main()
{
    char guess;
    int tryNumber = 1;
    const int maxTries = 5;

    do
    {
        cout << "Guess the alphabet (a to z): ";
        cin >> guess;

        if (guess == 'z')
        {
            cout << "Congratulations! You guessed the right answer.";
            break;
        }

        tryNumber++;

    } while (tryNumber <= maxTries);

    if (guess != 'z')
    {
        cout << "Sorry! You used all your tries.";
    }

    return 0;
}
