#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int tosses;

    cout << "How many times do you want to toss the coin? ";
    cin >> tosses;

    // Seed the random number generator using the current time
    srand(time(0));

    // Generate the result for each coin toss
    for (int i = 1; i <= tosses; i++)
    {
        int toss = rand() % 2;

        if (toss == 0)
        {
            cout << "Toss " << i << ": Heads" << endl;
        }
        else
        {
            cout << "Toss " << i << ": Tails" << endl;
        }
    }

    return 0;
}
