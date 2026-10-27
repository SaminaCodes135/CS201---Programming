#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int NUMBER_OF_BAGS = 5;
const int LABEL_SIZE = 40;

// Copies a C-style string using pointers.
void copyBaggageLabel(char* destinationPointer,
                      const char* sourcePointer)
{
    while ((*destinationPointer++ = *sourcePointer++) != '\0')
    {
        // Copy until the null terminator is reached.
    }
}

// Displays baggage information using array indexing.
void displayBaggage(const int baggageWeights[],
                    const char* baggageLabels[],
                    const bool inspectionRequired[])
{
    cout << "\n--- Airport Baggage Report ---\n";
    cout << left << setw(15) << "Baggage ID"
         << setw(15) << "Weight (kg)"
         << "Inspection\n";

    cout << "--------------------------------------------\n";

    for (int baggageIndex = 0;
         baggageIndex < NUMBER_OF_BAGS;
         baggageIndex++)
    {
        cout << left << setw(15) << baggageLabels[baggageIndex]
             << setw(15) << baggageWeights[baggageIndex]
             << (inspectionRequired[baggageIndex] ? "Required" : "Clear")
             << '\n';
    }
}

// Calculates total baggage weight through pointer traversal.
int calculateTotalWeight(const int* baggageWeightPointer,
                         int numberOfBags)
{
    int totalWeight = 0;

    for (int baggageIndex = 0;
         baggageIndex < numberOfBags;
         baggageIndex++)
    {
        totalWeight += *(baggageWeightPointer + baggageIndex);
    }

    return totalWeight;
}

// Finds the index of the heaviest bag.
int findHeaviestBagIndex(const int* baggageWeightPointer,
                         int numberOfBags)
{
    int heaviestBagIndex = 0;

    for (int baggageIndex = 1;
         baggageIndex < numberOfBags;
         baggageIndex++)
    {
        if (*(baggageWeightPointer + baggageIndex) >
            *(baggageWeightPointer + heaviestBagIndex))
        {
            heaviestBagIndex = baggageIndex;
        }
    }

    return heaviestBagIndex;
}

// Demonstrates Lecture 15 pointer concepts safely.
void demonstratePointerConcepts(int baggageWeights[],
                                int numberOfBags)
{
    cout << "\n--- Pointer Learning Lab ---\n";

    int* baggageWeightPointer = baggageWeights;

    cout << "\n1. Array name and first element address\n";
    cout << "Array address: "
         << static_cast<const void*>(baggageWeights) << '\n';
    cout << "First element address: "
         << static_cast<const void*>(&baggageWeights[0]) << '\n';

    cout << "\n2. Indexing versus pointer dereferencing\n";
    cout << "baggageWeights[1] = " << baggageWeights[1] << '\n';
    cout << "*(pointer + 1)    = "
         << *(baggageWeightPointer + 1) << '\n';

    cout << "\n3. Pointer increment and decrement\n";
    cout << "First bag weight: " << *baggageWeightPointer << '\n';

    baggageWeightPointer++;
    cout << "After increment:  " << *baggageWeightPointer << '\n';

    baggageWeightPointer--;
    cout << "After decrement:  " << *baggageWeightPointer << '\n';

    cout << "\n4. Pointer offset and subtraction\n";
    int* firstBagPointer = &baggageWeights[0];
    int* fourthBagPointer = &baggageWeights[3];

    cout << "Fourth bag weight: " << *(firstBagPointer + 3) << '\n';
    cout << "Distance in elements: "
         << fourthBagPointer - firstBagPointer << '\n';

    cout << "\n5. Pointer position versus pointed-to value\n";
    cout << boolalpha;
    cout << "First pointer is before fourth pointer: "
         << (firstBagPointer < fourthBagPointer) << '\n';

    cout << "First bag weighs less than fourth bag: "
         << (*firstBagPointer < *fourthBagPointer) << '\n';

    cout << "\n6. Modifying a value through a pointer\n";
    int originalWeight = *firstBagPointer;

    *firstBagPointer += 1;
    cout << "Temporarily increased weight: "
         << *firstBagPointer << " kg\n";

    *firstBagPointer = originalWeight;
    cout << "Original weight restored: "
         << *firstBagPointer << " kg\n";

    cout << "\n7. Pointer movement versus value increment\n";
    int* currentBagPointer = &baggageWeights[0];

    cout << "Current bag weight: " << *currentBagPointer << '\n';

    (*currentBagPointer)++;
    cout << "After value increment: " << *currentBagPointer << '\n';

    (*currentBagPointer)--;

    currentBagPointer++;
    cout << "After pointer increment: " << *currentBagPointer << '\n';

    cout << "\n8. Pointer expression differences\n";
    cout << "*pointer + 5: "
         << (*firstBagPointer + 5) << '\n';

    cout << "*(pointer + 2): "
         << *(firstBagPointer + 2) << '\n';

    cout << "\n9. Pointer safety\n";
    cout << "Adding two pointers is invalid in C++.\n";
    cout << "Never dereference a pointer outside the array.\n";
    cout << "Pointer comparisons and subtraction here use one array.\n";
}

// Demonstrates C-style string copying.
void demonstrateLabelCopying()
{
    cout << "\n--- Baggage Label Pointer Demo ---\n";

    char originalLabel[] = "BAG-2048";
    char copiedLabel[LABEL_SIZE] = {};

    char* originalLabelPointer = originalLabel;
    char* copiedLabelPointer = copiedLabel;

    while ((*copiedLabelPointer++ = *originalLabelPointer++) != '\0')
    {
        // Copy each character, including the final '\0'.
    }

    cout << "Original label: " << originalLabel << '\n';
    cout << "Copied label:   " << copiedLabel << '\n';
    cout << "Label length:   " << strlen(copiedLabel) << '\n';
}

int main()
{
    int baggageWeights[NUMBER_OF_BAGS] = {18, 24, 12, 30, 16};

    const char* baggageLabels[NUMBER_OF_BAGS] = {
        "BAG-1001",
        "BAG-1002",
        "BAG-1003",
        "BAG-1004",
        "BAG-1005"
    };

    bool inspectionRequired[NUMBER_OF_BAGS] = {
        false, true, false, true, false
    };

    int selectedMode;

    cout << "============================================\n";
    cout << " AIRPORT BAGGAGE ROUTING & INSPECTION SYSTEM\n";
    cout << "============================================\n";

    cout << "1. Normal Application Mode\n";
    cout << "2. Application + Pointer Learning Lab\n";
    cout << "Choose mode: ";

    if (!(cin >> selectedMode))
    {
        cout << "Invalid input.\n";
        return 1;
    }

    if (selectedMode != 1 && selectedMode != 2)
    {
        cout << "Invalid mode selected.\n";
        return 1;
    }

    displayBaggage(
        baggageWeights,
        baggageLabels,
        inspectionRequired
    );

    cout << "\nTotal baggage weight: "
         << calculateTotalWeight(baggageWeights, NUMBER_OF_BAGS)
         << " kg\n";

    int heaviestBagIndex =
        findHeaviestBagIndex(baggageWeights, NUMBER_OF_BAGS);

    cout << "Heaviest baggage: "
         << baggageLabels[heaviestBagIndex]
         << " (" << baggageWeights[heaviestBagIndex] << " kg)\n";

    cout << "Bags requiring inspection: ";

    int inspectionCount = 0;

    for (int baggageIndex = 0;
         baggageIndex < NUMBER_OF_BAGS;
         baggageIndex++)
    {
        if (inspectionRequired[baggageIndex])
        {
            inspectionCount++;
        }
    }

    cout << inspectionCount << '\n';

    if (selectedMode == 2)
    {
        demonstratePointerConcepts(baggageWeights, NUMBER_OF_BAGS);
        demonstrateLabelCopying();
    }

    cout << "\nBaggage report completed successfully.\n";

    return 0;
}
