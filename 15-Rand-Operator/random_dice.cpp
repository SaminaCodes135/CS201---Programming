#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    // Seed the random number generator
    srand(time(0));

    // Generate a random number from 1 to 6
    int dice = rand() % 6 + 1;

    cout << "Dice: " << dice << endl;

    return 0;
}
