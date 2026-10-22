#include <iostream>
#include <iomanip>
using namespace std;

// --------------------------------------------------
// 1. Display readings using pointer arithmetic
// --------------------------------------------------
void displayReadings(const int* pulseReadingPointer,
                     int numberOfReadings)
{
    cout << "Pulse Readings: ";

    for (int readingIndex = 0;
         readingIndex < numberOfReadings;
         readingIndex++)
    {
        cout << *(pulseReadingPointer + readingIndex);

        if (readingIndex < numberOfReadings - 1)
            cout << ", ";
    }

    cout << '\n';
}

// --------------------------------------------------
// 2. Find the highest reading
// --------------------------------------------------
int findHighestReading(const int* pulseReadingPointer,
                       int numberOfReadings)
{
    int highestReading = *pulseReadingPointer;

    for (int readingIndex = 1;
         readingIndex < numberOfReadings;
         readingIndex++)
    {
        if (*(pulseReadingPointer + readingIndex) > highestReading)
            highestReading = *(pulseReadingPointer + readingIndex);
    }

    return highestReading;
}

// --------------------------------------------------
// 3. Find the lowest reading
// --------------------------------------------------
int findLowestReading(const int* pulseReadingPointer,
                      int numberOfReadings)
{
    int lowestReading = *pulseReadingPointer;

    for (int readingIndex = 1;
         readingIndex < numberOfReadings;
         readingIndex++)
    {
        if (*(pulseReadingPointer + readingIndex) < lowestReading)
            lowestReading = *(pulseReadingPointer + readingIndex);
    }

    return lowestReading;
}

// --------------------------------------------------
// 4. Calculate the average
// --------------------------------------------------
double calculateAverage(const int* pulseReadingPointer,
                        int numberOfReadings)
{
    int totalPulseReadings = 0;

    for (int readingIndex = 0;
         readingIndex < numberOfReadings;
         readingIndex++)
    {
        totalPulseReadings += *(pulseReadingPointer + readingIndex);
    }

    return static_cast<double>(totalPulseReadings)
           / numberOfReadings;
}

// --------------------------------------------------
// 5. Update a reading safely
// --------------------------------------------------
bool updateReading(int* pulseReadingPointer,
                   int numberOfReadings,
                   int readingIndex,
                   int newPulseReading)
{
    if (readingIndex < 0 || readingIndex >= numberOfReadings)
        return false;

    if (newPulseReading <= 0)
        return false;

    *(pulseReadingPointer + readingIndex) = newPulseReading;

    return true;
}

// --------------------------------------------------
// 6. Display pointer concepts for learning/debugging
// --------------------------------------------------
void demonstratePointers(int* pulseReadingPointer,
                         int numberOfReadings)
{
    cout << "\n===== POINTER LEARNING LAB =====\n";

    // Array name and first-element address
    cout << "\n1. Array and pointer addresses\n";

    cout << "Array address:       "
         << static_cast<const void*>(pulseReadingPointer) << '\n';

    cout << "First element address: "
         << static_cast<const void*>(&pulseReadingPointer[0]) << '\n';

    cout << "First element value: " << *pulseReadingPointer << '\n';

    // Indexing versus pointer arithmetic
    cout << "\n2. Indexing versus pointer arithmetic\n";

    for (int readingIndex = 0;
         readingIndex < numberOfReadings;
         readingIndex++)
    {
        cout << "pulse[" << readingIndex << "] = "
             << pulseReadingPointer[readingIndex]
             << ", *(pointer + " << readingIndex << ") = "
             << *(pulseReadingPointer + readingIndex)
             << ", address = "
             << static_cast<const void*>(
                    pulseReadingPointer + readingIndex)
             << '\n';
    }

    // Pointer movement
    cout << "\n3. Pointer movement\n";

    int* currentReadingPointer = pulseReadingPointer;

    cout << "Before increment: value = "
         << *currentReadingPointer << '\n';

    currentReadingPointer++;

    cout << "After increment:  value = "
         << *currentReadingPointer << '\n';

    currentReadingPointer--;

    cout << "After decrement:  value = "
         << *currentReadingPointer << '\n';

    // Moving a pointer versus modifying a value
    cout << "\n4. Pointer movement versus value modification\n";

    int* selectedReadingPointer = pulseReadingPointer;

    selectedReadingPointer += 2;

    cout << "After pointer += 2, value = "
         << *selectedReadingPointer << '\n';

    cout << "Before *pointer += 5, value = "
         << *selectedReadingPointer << '\n';

    *selectedReadingPointer += 5;

    cout << "After *pointer += 5, value = "
         << *selectedReadingPointer << '\n';

    // Expressions with different meanings
    cout << "\n5. Pointer expressions\n";

    int* expressionPointer = pulseReadingPointer;

    cout << "*pointer + 5   = "
         << *expressionPointer + 5 << '\n';

    cout << "*(pointer + 2) = "
         << *(expressionPointer + 2) << '\n';

    // Incrementing the pointed-to value
    cout << "\n6. Incrementing a pointed-to value\n";

    int originalValue = *expressionPointer;

    cout << "Before (*pointer)++: "
         << *expressionPointer << '\n';

    (*expressionPointer)++;

    cout << "After (*pointer)++:  "
         << *expressionPointer << '\n';

    // Restore the value so the demonstration does not
    // permanently change the first reading.
    *expressionPointer = originalValue;

    // Demonstrate *pointer++ safely
    cout << "\n7. The expression *pointer++\n";

    int* postIncrementPointer = pulseReadingPointer;

    cout << "Value produced by *pointer++: "
         << *postIncrementPointer++ << '\n';

    cout << "Pointer now points to value: "
         << *postIncrementPointer << '\n';

    // Compare addresses and values separately
    cout << "\n8. Pointer comparison versus value comparison\n";

    int* firstReadingPointer = &pulseReadingPointer[0];
    int* secondReadingPointer = &pulseReadingPointer[1];

    cout << "Same address? "
         << (firstReadingPointer == secondReadingPointer
                 ? "Yes" : "No") << '\n';

    cout << "First address is before second? "
         << (firstReadingPointer < secondReadingPointer
                 ? "Yes" : "No") << '\n';

    cout << "First value is greater than second? "
         << (*firstReadingPointer > *secondReadingPointer
                 ? "Yes" : "No") << '\n';

    // Pointer subtraction measures elements
    cout << "\n9. Pointer subtraction\n";

    cout << "Distance between element 0 and element 3: "
         << (&pulseReadingPointer[3] - &pulseReadingPointer[0])
         << " elements\n";

    // Explain invalid pointer operations
    cout << "\n10. Pointer safety rules\n";

    cout << "- Do not add two pointers.\n";
    cout << "- Do not dereference a one-past-the-end pointer.\n";
    cout << "- Pointer subtraction and relational comparisons\n";
    cout << "  should use positions within the same array.\n";

    cout << "\n===== END OF POINTER LAB =====\n";
}

// --------------------------------------------------
// Main application
// --------------------------------------------------
int main()
{
    int pulseReadings[] = {72, 85, 110, 68, 95};

    const int numberOfReadings =
        sizeof(pulseReadings) / sizeof(pulseReadings[0]);

    int selectedMode;

    cout << "====================================\n";
    cout << "   HOSPITAL VITAL SIGNS MONITOR\n";
    cout << "====================================\n";

    cout << "\nSelect a mode:\n";
    cout << "1. Normal application\n";
    cout << "2. Learning and pointer demonstrations\n";
    cout << "Your choice: ";

    if (!(cin >> selectedMode) ||
        (selectedMode != 1 && selectedMode != 2))
    {
        cout << "Invalid choice. Please enter 1 or 2.\n";
        return 1;
    }

    cout << "\n";

    // Normal application output
    displayReadings(pulseReadings, numberOfReadings);

    cout << "\nMonitoring Summary\n";
    cout << "------------------\n";

    cout << "Highest Reading: "
         << findHighestReading(pulseReadings, numberOfReadings)
         << '\n';

    cout << "Lowest Reading:  "
         << findLowestReading(pulseReadings, numberOfReadings)
         << '\n';

    cout << fixed << setprecision(2);

    cout << "Average Reading: "
         << calculateAverage(pulseReadings, numberOfReadings)
         << '\n';

    // Update a sample reading
    cout << "\nUpdating reading 2...\n";

    if (updateReading(pulseReadings, numberOfReadings, 1, 90))
        cout << "Reading updated successfully.\n";
    else
        cout << "Update failed.\n";

    cout << "\nUpdated Monitoring Summary\n";
    cout << "--------------------------\n";

    displayReadings(pulseReadings, numberOfReadings);

    cout << "Highest Reading: "
         << findHighestReading(pulseReadings, numberOfReadings)
         << '\n';

    cout << "Lowest Reading:  "
         << findLowestReading(pulseReadings, numberOfReadings)
         << '\n';

    cout << "Average Reading: "
         << calculateAverage(pulseReadings, numberOfReadings)
         << '\n';

    // Only show technical details when requested
    if (selectedMode == 2)
    {
        demonstratePointers(pulseReadings, numberOfReadings);
    }

    cout << "\nMonitoring complete.\n";

    return 0;
}
