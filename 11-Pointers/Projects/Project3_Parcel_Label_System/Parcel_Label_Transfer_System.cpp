#include <iostream>
#include <iomanip>
using namespace std;

const int LABEL_SIZE = 100;

// Copies a C-style string using pointers.
// The null terminator is copied too.
void copyParcelLabel(char* destinationPointer,
                     const char* sourcePointer)
{
    while ((*destinationPointer++ = *sourcePointer++) != '\0')
    {
        // Each character is copied until '\0' is reached.
    }
}

// Calculates the string length without using strlen().
int calculateLabelLength(const char* labelPointer)
{
    int labelLength = 0;

    while (*labelPointer != '\0')
    {
        labelLength++;
        labelPointer++;
    }

    return labelLength;
}

// Displays a label character by character using a pointer.
void displayLabelCharacters(const char* labelPointer)
{
    while (*labelPointer != '\0')
    {
        cout << *labelPointer;
        labelPointer++;
    }

    cout << '\n';
}

// Demonstrates pointer concepts using separate local arrays.
void demonstratePointerConcepts()
{
    char sourceLabel[] = "PK-SWL-2048";
    char destinationLabel[LABEL_SIZE] = {};

    cout << "\n--- Pointer Learning Lab ---\n";

    cout << "\n1. Original C-style string\n";
    cout << "Source label: ";
    displayLabelCharacters(sourceLabel);

    cout << "\n2. String copying through pointers\n";
    copyParcelLabel(destinationLabel, sourceLabel);

    cout << "Copied label: ";
    displayLabelCharacters(destinationLabel);

    cout << "\n3. Character addresses and values\n";

    char* characterPointer = sourceLabel;

    cout << "First character: " << *characterPointer << '\n';
    cout << "First character address: "
         << static_cast<const void*>(characterPointer) << '\n';

    characterPointer++;

    cout << "After pointer increment: "
         << *characterPointer << '\n';

    cout << "\n4. Array indexing versus pointer access\n";
    cout << "sourceLabel[3]: " << sourceLabel[3] << '\n';
    cout << "*(sourceLabel + 3): "
         << *(sourceLabel + 3) << '\n';

    cout << "\n5. Null terminator\n";
    int labelLength = calculateLabelLength(sourceLabel);

    cout << "String length: " << labelLength << '\n';
    cout << "Character at index " << labelLength
         << " is the null terminator: "
         << (sourceLabel[labelLength] == '\0') << '\n';

    cout << "\n6. Pointer subtraction\n";
    char* firstCharacterPointer = &sourceLabel[0];
    char* lastCharacterPointer = &sourceLabel[labelLength - 1];

    cout << "Distance from first to last character: "
         << lastCharacterPointer - firstCharacterPointer
         << " elements\n";

    cout << "\n7. Pointer comparison\n";
    cout << boolalpha;
    cout << "First character is before last character: "
         << (firstCharacterPointer < lastCharacterPointer)
         << '\n';

    cout << "\n8. Value modification versus pointer movement\n";

    char* editableCharacterPointer = sourceLabel;
    char originalCharacter = *editableCharacterPointer;

    *editableCharacterPointer = 'p';

    cout << "Temporarily changed first character: "
         << sourceLabel[0] << '\n';

    *editableCharacterPointer = originalCharacter;

    editableCharacterPointer++;

    cout << "After moving pointer, current character: "
         << *editableCharacterPointer << '\n';

    cout << "Original source label restored: "
         << sourceLabel << '\n';

    cout << "\n9. Safety rules\n";
    cout << "- Copy only when the destination has enough capacity.\n";
    cout << "- Preserve the null terminator '\\0'.\n";
    cout << "- Do not dereference a one-past-end pointer.\n";
    cout << "- Adding two pointers is invalid in C++.\n";
}

int main()
{
    char originalParcelLabel[LABEL_SIZE] = {};
    char transferredParcelLabel[LABEL_SIZE] = {};

    int selectedMode;

    cout << "====================================\n";
    cout << "     PARCEL LABEL TRANSFER SYSTEM\n";
    cout << "====================================\n";

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

    cin.ignore(10000, '\n');

    cout << "\nEnter parcel label (maximum "
         << LABEL_SIZE - 1 << " characters): ";

    cin.getline(originalParcelLabel, LABEL_SIZE);

    if (cin.fail())
    {
        cout << "Label is too long or input failed.\n";
        return 1;
    }

    copyParcelLabel(transferredParcelLabel, originalParcelLabel);

    cout << "\n--- Transfer Summary ---\n";

    cout << "Original label: ";
    displayLabelCharacters(originalParcelLabel);

    cout << "Transferred label: ";
    displayLabelCharacters(transferredParcelLabel);

    cout << "Characters transferred: "
         << calculateLabelLength(transferredParcelLabel) << '\n';

    if (selectedMode == 2)
    {
        demonstratePointerConcepts();
    }

    cout << "\nParcel label transfer completed successfully.\n";

    return 0;
}
