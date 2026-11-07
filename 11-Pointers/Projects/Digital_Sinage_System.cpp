#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;

// --------------------------------------------------
// PROJECT CONSTANTS
// --------------------------------------------------

const int MAX_MESSAGES = 4;
const int MAX_LENGTH = 120;

// --------------------------------------------------
// CUSTOM STRING FUNCTIONS
// --------------------------------------------------

// Counts characters until the null character.
int myStrlen(const char* text)
{
    int length = 0;

    while (text[length] != '\0')
        length++;

    return length;
}

// Copies a string and returns the original
// destination pointer.
char* myStrcpy(char* destination,
               const char* source,
               int capacity)
{
    char* originalDestination = destination;

    if (capacity <= 0)
        return nullptr;

    int i = 0;

    while (i < capacity - 1 && source[i] != '\0')
    {
        destination[i] = source[i];
        i++;
    }

    destination[i] = '\0';

    return originalDestination;
}

// Compares two strings.
int myStrcmp(const char* first, const char* second)
{
    while (*first == *second && *first != '\0')
    {
        first++;
        second++;
    }

    return static_cast<unsigned char>(*first) -
           static_cast<unsigned char>(*second);
}

// Compares up to n characters.
int myStrncmp(const char* first,
              const char* second,
              int n)
{
    for (int i = 0; i < n; i++)
    {
        unsigned char a =
            static_cast<unsigned char>(first[i]);

        unsigned char b =
            static_cast<unsigned char>(second[i]);

        if (a != b || a == '\0')
            return a - b;
    }

    return 0;
}

// Appends a string to another string.
char* myStrcat(char* destination,
               const char* source,
               int capacity)
{
    char* originalDestination = destination;

    int length = myStrlen(destination);

    if (length >= capacity)
        return nullptr;

    int i = 0;

    while (length < capacity - 1 && source[i] != '\0')
    {
        destination[length] = source[i];
        length++;
        i++;
    }

    destination[length] = '\0';

    return originalDestination;
}

// Appends at most n characters.
char* myStrncat(char* destination,
                const char* source,
                int n,
                int capacity)
{
    char* originalDestination = destination;

    int length = myStrlen(destination);
    int i = 0;

    if (length >= capacity)
        return nullptr;

    while (i < n &&
           length < capacity - 1 &&
           source[i] != '\0')
    {
        destination[length] = source[i];
        length++;
        i++;
    }

    destination[length] = '\0';

    return originalDestination;
}

// Finds the first occurrence of a character.
char* myStrchr(const char* text, char target)
{
    while (*text != '\0')
    {
        if (*text == target)
            return const_cast<char*>(text);

        text++;
    }

    if (target == '\0')
        return const_cast<char*>(text);

    return nullptr;
}

// Finds a substring.
char* myStrstr(const char* text,
               const char* search)
{
    if (*search == '\0')
        return const_cast<char*>(text);

    while (*text != '\0')
    {
        const char* first = text;
        const char* second = search;

        while (*first != '\0' &&
               *second != '\0' &&
               *first == *second)
        {
            first++;
            second++;
        }

        if (*second == '\0')
            return const_cast<char*>(text);

        text++;
    }

    return nullptr;
}

// --------------------------------------------------
// CUSTOM NUMERIC CONVERSION FUNCTIONS
// --------------------------------------------------

// Converts a character string into an integer.
bool myAtoi(const char* text, int& result)
{
    if (text == nullptr || *text == '\0')
        return false;

    int sign = 1;

    if (*text == '+' || *text == '-')
    {
        if (*text == '-')
            sign = -1;

        text++;
    }

    if (*text == '\0')
        return false;

    long long number = 0;

    long long limit = (sign == -1)
        ? static_cast<long long>(INT_MAX) + 1
        : INT_MAX;

    while (*text != '\0')
    {
        if (!isdigit(static_cast<unsigned char>(*text)))
            return false;

        int digit = *text - '0';

        // Check overflow before multiplication.
        if (number > (limit - digit) / 10)
            return false;

        number = number * 10 + digit;
        text++;
    }

    if (sign == -1)
        number = -number;

    result = static_cast<int>(number);

    return true;
}

// Converts a decimal character string into double.
bool myAtof(const char* text, double& result)
{
    if (text == nullptr || *text == '\0')
        return false;

    int sign = 1;

    if (*text == '+' || *text == '-')
    {
        if (*text == '-')
            sign = -1;

        text++;
    }

    if (*text == '\0')
        return false;

    double number = 0.0;
    double placeValue = 0.1;

    bool decimalFound = false;
    bool digitFound = false;

    while (*text != '\0')
    {
        if (*text == '.' && !decimalFound)
        {
            decimalFound = true;
        }
        else if (isdigit(static_cast<unsigned char>(*text)))
        {
            int digit = *text - '0';
            digitFound = true;

            if (!decimalFound)
                number = number * 10 + digit;
            else
            {
                number += digit * placeValue;
                placeValue *= 0.1;
            }
        }
        else
        {
            return false;
        }

        text++;
    }

    if (!digitFound)
        return false;

    result = sign * number;

    return true;
}

// --------------------------------------------------
// TEXT PROCESSING FUNCTIONS
// --------------------------------------------------

// Converts a string into uppercase.
void convertToUpper(char* text)
{
    while (*text != '\0')
    {
        *text = static_cast<char>(
            toupper(static_cast<unsigned char>(*text))
        );

        text++;
    }
}

// Converts a string into lowercase.
void convertToLower(char* text)
{
    while (*text != '\0')
    {
        *text = static_cast<char>(
            tolower(static_cast<unsigned char>(*text))
        );

        text++;
    }
}

// Counts letters, digits, spaces and special characters.
void analyseCharacters(
    const char* text,
    int& letters,
    int& digits,
    int& spaces,
    int& specialCharacters)
{
    letters = 0;
    digits = 0;
    spaces = 0;
    specialCharacters = 0;

    while (*text != '\0')
    {
        unsigned char character =
            static_cast<unsigned char>(*text);

        if (isalpha(character))
            letters++;
        else if (isdigit(character))
            digits++;
        else if (isspace(character))
            spaces++;
        else
            specialCharacters++;

        text++;
    }
}

// Counts words separated by whitespace.
int countWords(const char* text)
{
    int words = 0;
    bool insideWord = false;

    while (*text != '\0')
    {
        if (isspace(static_cast<unsigned char>(*text)))
        {
            insideWord = false;
        }
        else if (!insideWord)
        {
            words++;
            insideWord = true;
        }

        text++;
    }

    return words;
}

// --------------------------------------------------
// NORMAL MODE
// --------------------------------------------------

void displayNormalMode(
    const char* messageNames[],
    char messages[][MAX_LENGTH])
{
    cout << "\n";
    cout << "================================================\n";
    cout << "      DYNAMIC DIGITAL SIGNAGE SYSTEM\n";
    cout << "================================================\n";

    cout << "\nCURRENT DIGITAL DISPLAY MESSAGES\n";

    for (int i = 0; i < MAX_MESSAGES; i++)
    {
        cout << "\n" << i + 1 << ". "
             << messageNames[i] << "\n";

        cout << "   " << messages[i] << "\n";
    }

    cout << "\nMESSAGE ANALYSIS\n";
    cout << "------------------------------------------------\n";

    for (int i = 0; i < MAX_MESSAGES; i++)
    {
        int letters;
        int digits;
        int spaces;
        int specialCharacters;

        analyseCharacters(
            messages[i],
            letters,
            digits,
            spaces,
            specialCharacters
        );

        cout << "\nMessage: " << messageNames[i] << "\n";

        cout << "Characters: "
             << myStrlen(messages[i]) << "\n";

        cout << "Words: "
             << countWords(messages[i]) << "\n";

        cout << "Letters: " << letters << "\n";
        cout << "Digits: " << digits << "\n";
        cout << "Spaces: " << spaces << "\n";
        cout << "Special characters: "
             << specialCharacters << "\n";
    }

    // Demonstrate a combined display message.
    char combinedMessage[250] = "";

    myStrcpy(
        combinedMessage,
        messages[0],
        250
    );

    myStrcat(
        combinedMessage,
        " | ",
        250
    );

    myStrcat(
        combinedMessage,
        messages[1],
        250
    );

    cout << "\nCOMBINED DIGITAL DISPLAY\n";
    cout << combinedMessage << "\n";

    cout << "\n================================================\n";
}

// --------------------------------------------------
// LEARNING MODE: POINTERS AND ARRAY HANDLING
// --------------------------------------------------

void showPointerLearning(
    char messages[][MAX_LENGTH])
{
    cout << "\n========== POINTER AND ARRAY LEARNING ==========\n";

    // Pointer to an array of MAX_LENGTH characters.
    char (*rowPointer)[MAX_LENGTH] = messages;

    cout << "\nPointer-to-array demonstration:\n";

    cout << "First message: "
         << *rowPointer << "\n";

    cout << "Second message: "
         << *(rowPointer + 1) << "\n";

    cout << "\nAccessing a character through pointer arithmetic:\n";

    cout << "First character of first message: "
         << *(*(rowPointer + 0) + 0) << "\n";

    cout << "Second character of first message: "
         << *(*(rowPointer + 0) + 1) << "\n";

    cout << "\nArray of pointers demonstration:\n";

    char* messagePointers[MAX_MESSAGES];

    for (int i = 0; i < MAX_MESSAGES; i++)
        messagePointers[i] = messages[i];

    cout << "First message through pointer array:\n";
    cout << messagePointers[0] << "\n";

    cout << "\nMemory address of first message: "
         << static_cast<void*>(messages[0]) << "\n";

    cout << "Memory address of second message: "
         << static_cast<void*>(messages[1]) << "\n";
}

// --------------------------------------------------
// LEARNING MODE: STRING FUNCTIONS
// --------------------------------------------------

void showStringLearning()
{
    cout << "\n========== CUSTOM STRING FUNCTIONS ==========\n";

    char original[100];
    char copied[100];

    myStrcpy(original, "Welcome to the Airport", 100);

    // Custom strcpy returns the destination pointer.
    char* returnedPointer =
        myStrcpy(copied, original, 100);

    cout << "Original string: " << original << "\n";
    cout << "Copied string: " << copied << "\n";

    cout << "Returned destination pointer: "
         << static_cast<void*>(returnedPointer) << "\n";

    cout << "Length: " << myStrlen(original) << "\n";

    cout << "Compare equal strings: "
         << myStrcmp(original, copied) << "\n";

    cout << "Compare first 7 characters: "
         << myStrncmp("WELCOME", "WELFARE", 3) << "\n";

    char announcement[100] = "Notice: ";

    myStrcat(
        announcement,
        "Gate Number 5",
        100
    );

    cout << "After concatenation: "
         << announcement << "\n";

    char shortMessage[100] = "Flight: ";

    myStrncat(
        shortMessage,
        "Departure",
        4,
        100
    );

    cout << "Limited concatenation: "
         << shortMessage << "\n";

    cout << "Search character 'A': "
         << (myStrchr(original, 'A') != nullptr
             ? "Found" : "Not found") << "\n";

    cout << "Search word 'Airport': "
         << (myStrstr(original, "Airport") != nullptr
             ? "Found" : "Not found") << "\n";
}

// --------------------------------------------------
// LEARNING MODE: CHARACTER HANDLING
// --------------------------------------------------

void showCharacterLearning()
{
    cout << "\n========== CHARACTER HANDLING ==========\n";

    char character = 'a';

    cout << "Character: " << character << "\n";

    cout << "ASCII value: "
         << static_cast<int>(character) << "\n";

    cout << "isalpha('A'): " << isalpha('A') << "\n";
    cout << "isdigit('5'): " << isdigit('5') << "\n";
    cout << "isalnum('A'): " << isalnum('A') << "\n";
    cout << "islower('a'): " << islower('a') << "\n";
    cout << "isupper('A'): " << isupper('A') << "\n";
    cout << "isspace(' '): " << isspace(' ') << "\n";

    cout << "toupper('a'): "
         << static_cast<char>(toupper('a')) << "\n";

    cout << "tolower('A'): "
         << static_cast<char>(tolower('A')) << "\n";
}

// --------------------------------------------------
// LEARNING MODE: NUMERIC CONVERSION
// --------------------------------------------------

void showConversionLearning()
{
    cout << "\n========== NUMERIC CONVERSION ==========\n";

    const char integerText[] = "125";
    const char decimalText[] = "45.75";

    int number;
    double decimalNumber;

    if (myAtoi(integerText, number))
    {
        cout << "String: " << integerText << "\n";
        cout << "Converted integer: " << number << "\n";
    }

    if (myAtof(decimalText, decimalNumber))
    {
        cout << "String: " << decimalText << "\n";
        cout << "Converted double: "
             << decimalNumber << "\n";
    }
}

// --------------------------------------------------
// LEARNING MODE: COMMAND-LINE ARGUMENTS
// --------------------------------------------------

void showArgumentLearning(int argc, char* argv[])
{
    cout << "\n========== COMMAND-LINE ARGUMENTS ==========\n";

    cout << "argc = " << argc << "\n";

    for (int i = 0; i < argc; i++)
    {
        cout << "argv[" << i << "] = "
             << argv[i] << "\n";
    }

    char** argumentPointer = argv;

    if (argc > 1)
    {
        cout << "\nSingle dereferencing:\n";

        cout << "*(argumentPointer + 1) = "
             << *(argumentPointer + 1) << "\n";

        cout << "\nDouble dereferencing:\n";

        cout << "**(argumentPointer + 1) = "
             << **(argumentPointer + 1) << "\n";
    }
}

// --------------------------------------------------
// LEARNING MODE
// --------------------------------------------------

void displayLearningMode(
    int argc,
    char* argv[],
    const char* messageNames[],
    char messages[][MAX_LENGTH])
{
    cout << "\n";
    cout << "***********************************************\n";
    cout << "       DIGITAL SIGNAGE - LEARNING MODE\n";
    cout << "***********************************************\n";

    showArgumentLearning(argc, argv);

    showPointerLearning(messages);

    showStringLearning();

    showCharacterLearning();

    showConversionLearning();

    cout << "\n========== FINAL SIGNAGE APPLICATION ==========\n";

    displayNormalMode(messageNames, messages);
}

// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------

int main(int argc, char* argv[])
{
    const char* messageNames[MAX_MESSAGES] =
    {
        "Welcome Announcement",
        "Emergency Announcement",
        "Opening Hours",
        "Promotional Message"
    };

    // Four rows, each capable of storing 119
    // characters plus the null character.
    char messages[MAX_MESSAGES][MAX_LENGTH] =
    {
        "Welcome to City Shopping Mall!",
        "Emergency Exit - Please Follow Safety Signs",
        "Opening Hours: 09:00 AM to 10:00 PM",
        "Special Discount: 25% OFF Today!"
    };

    const char* mode = "normal";

    // Accept default execution or one mode argument.
    if (argc > 2)
    {
        cout << "Invalid number of arguments.\n";
        cout << "Usage: signage normal\n";
        cout << "       signage learning\n";
        return 1;
    }

    if (argc == 2)
        mode = argv[1];

    // Validate operating mode.
    if (strcmp(mode, "normal") != 0 &&
        strcmp(mode, "learning") != 0)
    {
        cout << "Invalid mode.\n";
        cout << "Use normal or learning.\n";
        return 1;
    }

    // Select the required operating mode.
    if (strcmp(mode, "normal") == 0)
    {
        displayNormalMode(
            messageNames,
            messages
        );
    }
    else
    {
        displayLearningMode(
            argc,
            argv,
            messageNames,
            messages
        );
    }

    return 0;
}
