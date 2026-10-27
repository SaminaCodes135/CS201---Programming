#include <iostream>
#include <iomanip>
using namespace std;

// Displays energy consumption for each appliance.
void displayEnergyUsage(const double energyUsage[], int numberOfAppliances)
{
    const char* applianceNames[] = {
        "Refrigerator",
        "Air Conditioner",
        "Washing Machine",
        "LED Lights",
        "Television"
    };

    cout << "\n--- Household Energy Usage ---\n";

    for (int applianceIndex = 0;
         applianceIndex < numberOfAppliances;
         applianceIndex++)
    {
        cout << left << setw(20)
             << applianceNames[applianceIndex]
             << right << fixed << setprecision(2)
             << energyUsage[applianceIndex] << " kWh\n";
    }
}

// Calculates total energy consumption using a pointer.
double calculateTotalEnergy(const double* energyUsagePointer,
                            int numberOfAppliances)
{
    double totalEnergy = 0.0;

    for (int applianceIndex = 0;
         applianceIndex < numberOfAppliances;
         applianceIndex++)
    {
        totalEnergy += *(energyUsagePointer + applianceIndex);
    }

    return totalEnergy;
}

// Finds the appliance with the highest energy consumption.
int findHighestUsageIndex(const double* energyUsagePointer,
                          int numberOfAppliances)
{
    int highestUsageIndex = 0;

    for (int applianceIndex = 1;
         applianceIndex < numberOfAppliances;
         applianceIndex++)
    {
        if (*(energyUsagePointer + applianceIndex) >
            *(energyUsagePointer + highestUsageIndex))
        {
            highestUsageIndex = applianceIndex;
        }
    }

    return highestUsageIndex;
}

// Demonstrates pointer concepts without changing the original data.
void demonstratePointerConcepts(double energyUsage[],
                                int numberOfAppliances)
{
    cout << "\n--- Pointer Learning Lab ---\n";

    double* energyReadingPointer = energyUsage;

    cout << "\n1. Array name and first element address\n";
    cout << "Array address: " << static_cast<const void*>(energyUsage) << '\n';
    cout << "First element: " << static_cast<const void*>(&energyUsage[0]) << '\n';

    cout << "\n2. Array indexing versus pointer dereferencing\n";
    cout << "energyUsage[1]       = " << energyUsage[1] << " kWh\n";
    cout << "*(pointer + 1)       = " << *(energyReadingPointer + 1) << " kWh\n";

    cout << "\n3. Pointer arithmetic\n";
    cout << "First reading        = " << *energyReadingPointer << " kWh\n";
    cout << "Second reading       = " << *(energyReadingPointer + 1) << " kWh\n";
    cout << "Third reading        = " << *(energyReadingPointer + 2) << " kWh\n";

    double* firstReadingPointer = &energyUsage[0];
    double* thirdReadingPointer = &energyUsage[2];

    cout << "\n4. Pointer subtraction\n";
    cout << "Elements between pointers: "
         << thirdReadingPointer - firstReadingPointer << '\n';

    cout << "\n5. Pointer comparisons\n";
    cout << "First pointer is before third pointer: "
         << boolalpha
         << (firstReadingPointer < thirdReadingPointer) << '\n';

    cout << "First reading is less than third reading: "
         << (*firstReadingPointer < *thirdReadingPointer) << '\n';

    cout << "\n6. Modifying a value through a pointer\n";
    double originalEnergyValue = *energyReadingPointer;

    *energyReadingPointer += 1.0;
    cout << "Temporarily increased first reading: "
         << *energyReadingPointer << " kWh\n";

    *energyReadingPointer = originalEnergyValue;
    cout << "Original value restored: "
         << *energyReadingPointer << " kWh\n";

    cout << "\n7. Pointer movement versus value modification\n";

    double* movingReadingPointer = &energyUsage[0];

    cout << "Before pointer increment: "
         << *movingReadingPointer << " kWh\n";

    movingReadingPointer++;

    cout << "After pointer increment:  "
         << *movingReadingPointer << " kWh\n";

    cout << "Original array remains unchanged.\n";

    cout << "\n8. Pointer subtraction is valid within the same array.\n";
    cout << "Adding two pointers is invalid in C++.\n";
    cout << "Never dereference a pointer outside the array.\n";
}

int main()
{
    const int numberOfAppliances = 5;

    double energyUsage[numberOfAppliances] = {
        4.5, 8.2, 1.4, 0.8, 2.1
    };

    const char* applianceNames[] = {
        "Refrigerator",
        "Air Conditioner",
        "Washing Machine",
        "LED Lights",
        "Television"
    };

    int selectedMode;

    cout << "====================================\n";
    cout << " SMART HOME ENERGY USAGE ANALYZER\n";
    cout << "====================================\n";

    cout << "1. Normal Application Mode\n";
    cout << "2. Application + Pointer Learning Lab\n";
    cout << "Choose mode: ";
    cin >> selectedMode;

    if (selectedMode != 1 && selectedMode != 2)
    {
        cout << "Invalid mode selected.\n";
        return 1;
    }

    displayEnergyUsage(energyUsage, numberOfAppliances);

    cout << "\nTotal consumption: "
         << fixed << setprecision(2)
         << calculateTotalEnergy(energyUsage, numberOfAppliances)
         << " kWh\n";

    int highestUsageIndex =
        findHighestUsageIndex(energyUsage, numberOfAppliances);

    cout << "Highest consumption: "
         << applianceNames[highestUsageIndex]
         << " (" << energyUsage[highestUsageIndex] << " kWh)\n";

    if (selectedMode == 2)
    {
        demonstratePointerConcepts(energyUsage, numberOfAppliances);
    }

    cout << "\nAnalysis completed successfully.\n";

    return 0;
}
