#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <climits>
using namespace std;

// --------------------------------------------------
// PROJECT CONSTANTS
// --------------------------------------------------

const int ROADS = 5;
const int PERIODS = 3;
const int MAX_VEHICLES = 10000;

const int MORNING = 0;
const int AFTERNOON = 1;
const int EVENING = 2;

// --------------------------------------------------
// CUSTOM STRING AND NUMBER CONVERSION FUNCTIONS
// --------------------------------------------------

// Converts a numeric character string into an integer.
// Supports an optional + or - sign.
bool myAtoi(const char* text, int& result)
{
    if (text == nullptr || *text == '\0')
        return false;

    int sign = 1;

    if (*text == '-' || *text == '+')
    {
        if (*text == '-')
            sign = -1;

        text++;
    }

    if (*text == '\0')
        return false;

    long long number = 0;

    while (*text != '\0')
    {
        if (!isdigit(static_cast<unsigned char>(*text)))
            return false;

        int digit = *text - '0';
        number = number * 10 + digit;

        if (sign == 1 && number > INT_MAX)
            return false;

        if (sign == -1 && number > static_cast<long long>(INT_MAX) + 1)
            return false;

        text++;
    }

    if (sign == -1)
        number = -number;

    result = static_cast<int>(number);
    return true;
}

// Converts a decimal character string into a double.
// Supports an optional sign and one decimal point.
bool myAtof(const char* text, double& result)
{
    if (text == nullptr || *text == '\0')
        return false;

    int sign = 1;

    if (*text == '-' || *text == '+')
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

// Custom strlen: counts characters before '\0'.
int myStrlen(const char* text)
{
    int length = 0;

    while (text[length] != '\0')
        length++;

    return length;
}

// Custom strcpy: copies a string and returns
// the destination character pointer.
char* myStrcpy(char* destination, const char* source)
{
    char* originalDestination = destination;

    while ((*destination++ = *source++) != '\0')
    {
        // Characters are copied one by one.
    }

    return originalDestination;
}

// Custom strcmp: compares two strings.
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

// Custom strncmp: compares up to n characters.
int myStrncmp(const char* first, const char* second, int n)
{
    for (int i = 0; i < n; i++)
    {
        unsigned char a = static_cast<unsigned char>(first[i]);
        unsigned char b = static_cast<unsigned char>(second[i]);

        if (a != b || a == '\0')
            return a - b;
    }

    return 0;
}

// Custom strcat: appends source to destination.
char* myStrcat(char* destination, const char* source)
{
    char* originalDestination = destination;

    while (*destination != '\0')
        destination++;

    while ((*destination++ = *source++) != '\0')
    {
        // Appending characters.
    }

    return originalDestination;
}

// Custom strncat: appends at most n characters.
char* myStrncat(char* destination, const char* source, int n)
{
    char* originalDestination = destination;

    while (*destination != '\0')
        destination++;

    while (n > 0 && *source != '\0')
    {
        *destination++ = *source++;
        n--;
    }

    *destination = '\0';

    return originalDestination;
}

// Custom strchr: finds the first occurrence of a character.
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

// Custom strstr: finds a substring inside another string.
char* myStrstr(const char* text, const char* search)
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
// TRAFFIC ANALYSIS FUNCTIONS
// --------------------------------------------------

const char* classifyTraffic(int totalVehicles)
{
    if (totalVehicles < 300)
        return "LOW";

    if (totalVehicles < 500)
        return "MODERATE";

    return "HEAVY";
}

int recommendedGreenTime(int totalVehicles)
{
    if (totalVehicles < 300)
        return 30;

    if (totalVehicles < 500)
        return 45;

    return 60;
}

void calculateRoadTotals(
    int trafficData[][PERIODS],
    int roadTotals[])
{
    for (int road = 0; road < ROADS; road++)
    {
        roadTotals[road] = 0;

        for (int period = 0; period < PERIODS; period++)
        {
            roadTotals[road] += trafficData[road][period];
        }
    }
}

void calculatePeriodTotals(
    int trafficData[][PERIODS],
    int periodTotals[])
{
    for (int period = 0; period < PERIODS; period++)
    {
        periodTotals[period] = 0;

        for (int road = 0; road < ROADS; road++)
        {
            periodTotals[period] += trafficData[road][period];
        }
    }
}

// --------------------------------------------------
// NORMAL MODE REPORT
// --------------------------------------------------

void displayNormalReport(
    const char* roadNames[],
    const char* periodNames[],
    int trafficData[][PERIODS],
    double speedLimit)
{
    int roadTotals[ROADS];
    int periodTotals[PERIODS];

    calculateRoadTotals(trafficData, roadTotals);
    calculatePeriodTotals(trafficData, periodTotals);

    int grandTotal = 0;
    int busiestRoad = 0;
    int peakPeriod = 0;

    for (int road = 0; road < ROADS; road++)
    {
        grandTotal += roadTotals[road];

        if (roadTotals[road] > roadTotals[busiestRoad])
            busiestRoad = road;
    }

    for (int period = 0; period < PERIODS; period++)
    {
        if (periodTotals[period] > periodTotals[peakPeriod])
            peakPeriod = period;
    }

    cout << "\n";
    cout << "===============================================\n";
    cout << "       SMART TRAFFIC MANAGEMENT SYSTEM\n";
    cout << "===============================================\n";

    cout << fixed << setprecision(1);
    cout << "Configured speed limit: " << speedLimit << " km/h\n";

    cout << "\nTRAFFIC MONITORING REPORT\n";
    cout << "---------------------------------------------------------------\n";

    cout << left << setw(18) << "Road"
         << right << setw(10) << "Morning"
         << setw(12) << "Afternoon"
         << setw(10) << "Evening"
         << setw(10) << "Total" << "\n";

    cout << "---------------------------------------------------------------\n";

    for (int road = 0; road < ROADS; road++)
    {
        cout << left << setw(18) << roadNames[road]
             << right << setw(10) << trafficData[road][MORNING]
             << setw(12) << trafficData[road][AFTERNOON]
             << setw(10) << trafficData[road][EVENING]
             << setw(10) << roadTotals[road] << "\n";
    }

    cout << "---------------------------------------------------------------\n";

    cout << left << setw(18) << "Period Total"
         << right << setw(10) << periodTotals[MORNING]
         << setw(12) << periodTotals[AFTERNOON]
         << setw(10) << periodTotals[EVENING]
         << setw(10) << grandTotal << "\n";

    cout << "\nTRAFFIC ANALYSIS\n";
    cout << "Total vehicles monitored: " << grandTotal << "\n";
    cout << "Busiest road: " << roadNames[busiestRoad] << "\n";
    cout << "Peak traffic period: " << periodNames[peakPeriod] << "\n";

    cout << "\nROAD-WISE TRAFFIC RECOMMENDATIONS\n";

    for (int road = 0; road < ROADS; road++)
    {
        cout << roadNames[road] << ": "
             << classifyTraffic(roadTotals[road])
             << " traffic, recommended green light: "
             << recommendedGreenTime(roadTotals[road])
             << " seconds\n";
    }

    cout << "\nNote: Green-light timings are illustrative recommendations.\n";
    cout << "===============================================\n";
}

// --------------------------------------------------
// LEARNING MODE: COMMAND-LINE ARGUMENTS
// --------------------------------------------------

void showArgumentLearning(int argc, char* argv[])
{
    cout << "\n========== COMMAND-LINE ARGUMENTS ==========\n";

    cout << "argc = " << argc << "\n";
    cout << "argc represents the number of command-line arguments.\n";

    char** argumentPointer = argv;

    for (int i = 0; i < argc; i++)
    {
        cout << "\nargv[" << i << "] = " << argv[i] << "\n";
        cout << "Address of argv[" << i << "] = "
             << static_cast<void*>(argv + i) << "\n";
    }

    cout << "\nSingle dereferencing:\n";
    cout << "* (argv + 1) = " << *(argv + 1) << "\n";

    cout << "\nDouble dereferencing:\n";
    cout << "** (argumentPointer + 1) = "
         << **(argumentPointer + 1) << "\n";

    cout << "This accesses the first character of the mode argument.\n";
}

// --------------------------------------------------
// LEARNING MODE: 2D ARRAY AND POINTERS
// --------------------------------------------------

void showArrayLearning(int trafficData[][PERIODS])
{
    cout << "\n========== 2D ARRAY AND POINTERS ==========\n";

    int (*rowPointer)[PERIODS] = trafficData;

    cout << "Pointer-to-array demonstration:\n";
    cout << "rowPointer points to the first row.\n";

    cout << "First element using array notation: "
         << trafficData[0][0] << "\n";

    cout << "First element using pointer notation: "
         << *(*(rowPointer + 0) + 0) << "\n";

    cout << "Second element of first row: "
         << *(*(rowPointer + 0) + 1) << "\n";

    cout << "\nAddress of first element: "
         << static_cast<void*>(&trafficData[0][0]) << "\n";

    cout << "Address of second element: "
         << static_cast<void*>(&trafficData[0][1]) << "\n";

    cout << "Address of first element of second row: "
         << static_cast<void*>(&trafficData[1][0]) << "\n";

    cout << "\nArray of pointers demonstration:\n";

    int* rowPointers[ROADS];

    for (int road = 0; road < ROADS; road++)
        rowPointers[road] = trafficData[road];

    cout << "First road, evening traffic using rowPointers: "
         << *(rowPointers[0] + EVENING) << "\n";

    cout << "\nRow-major memory layout:\n";

    for (int road = 0; road < ROADS; road++)
    {
        for (int period = 0; period < PERIODS; period++)
        {
            cout << "trafficData[" << road << "][" << period << "] = "
                 << *(*(rowPointer + road) + period)
                 << " | Address: "
                 << static_cast<void*>(&trafficData[road][period])
                 << "\n";
        }
    }
}

// --------------------------------------------------
// LEARNING MODE: DYNAMIC 2D ARRAY
// --------------------------------------------------

void showDoublePointerLearning(
    int trafficData[][PERIODS])
{
    cout << "\n========== POINTER-TO-POINTER ==========\n";

    // Allocate a dynamic 2D array using int**.
    int** dynamicData = new int*[ROADS];

    for (int road = 0; road < ROADS; road++)
    {
        dynamicData[road] = new int[PERIODS];

        for (int period = 0; period < PERIODS; period++)
        {
            dynamicData[road][period] =
                trafficData[road][period];
        }
    }

    cout << "dynamicData is a pointer to a pointer.\n";

    cout << "Value using array notation: "
         << dynamicData[0][0] << "\n";

    cout << "Value using double dereferencing: "
         << *(*(dynamicData + 0) + 0) << "\n";

    cout << "First row pointer address: "
         << static_cast<void*>(dynamicData[0]) << "\n";

    cout << "Second row pointer address: "
         << static_cast<void*>(dynamicData[1]) << "\n";

    cout << "\nImportant: This dynamically allocated 2D array\n";
    cout << "uses separate row allocations. It is not the same\n";
    cout << "memory layout as a single fixed-size 2D array.\n";

    // Release every allocated row.
    for (int road = 0; road < ROADS; road++)
        delete[] dynamicData[road];

    delete[] dynamicData;

    cout << "Dynamic memory has been released.\n";
}

// --------------------------------------------------
// LEARNING MODE: CHARACTER AND STRING HANDLING
// --------------------------------------------------

void showStringLearning()
{
    cout << "\n========== CHARACTER AND STRING HANDLING ==========\n";

    char roadName[50];
    char copiedName[50];

    myStrcpy(roadName, "main road");

    // strcpy-like function returns destination pointer.
    char* returnedPointer = myStrcpy(copiedName, roadName);

    cout << "Original string: " << roadName << "\n";
    cout << "Copied string: " << copiedName << "\n";

    cout << "Returned destination pointer: "
         << static_cast<void*>(returnedPointer) << "\n";

    cout << "String length using myStrlen: "
         << myStrlen(roadName) << "\n";

    cout << "Comparison using myStrcmp: "
         << myStrcmp("ROAD", "ROAD") << "\n";

    cout << "First 4 characters using myStrncmp: "
         << myStrncmp("TRAFFIC", "TRAIN", 4) << "\n";

    char report[100] = "Traffic Report: ";
    myStrcat(report, "Main Road");
    cout << "After myStrcat: " << report << "\n";

    char shortReport[100] = "Peak: ";
    myStrncat(shortReport, "Evening Traffic", 7);
    cout << "After myStrncat: " << shortReport << "\n";

    cout << "myStrchr searching for 'R': "
         << (myStrchr(roadName, 'r') != nullptr ? "Found" : "Not found")
         << "\n";

    cout << "myStrstr searching for 'road': "
         << (myStrstr(roadName, "road") != nullptr ? "Found" : "Not found")
         << "\n";

    char character = 'a';

    cout << "\nCharacter: " << character << "\n";
    cout << "ASCII value: " << static_cast<int>(character) << "\n";
    cout << "isalpha: " << isalpha(static_cast<unsigned char>(character)) << "\n";
    cout << "isdigit for '5': " << isdigit('5') << "\n";
    cout << "isalnum for 'A': " << isalnum('A') << "\n";
    cout << "islower: " << islower('a') << "\n";
    cout << "isupper: " << isupper('A') << "\n";
    cout << "isspace for space: " << isspace(' ') << "\n";
    cout << "toupper: " << static_cast<char>(toupper('a')) << "\n";
    cout << "tolower: " << static_cast<char>(tolower('A')) << "\n";
}

// --------------------------------------------------
// LEARNING MODE: CUSTOM NUMBER CONVERSION
// --------------------------------------------------

void showConversionLearning()
{
    cout << "\n========== CUSTOM NUMBER CONVERSION ==========\n";

    int vehicleCount;
    double speed;

    const char integerText[] = "250";
    const char decimalText[] = "45.75";

    if (myAtoi(integerText, vehicleCount))
    {
        cout << "myAtoi converts \"" << integerText
             << "\" into integer " << vehicleCount << "\n";
    }

    if (myAtof(decimalText, speed))
    {
        cout << "myAtof converts \"" << decimalText
             << "\" into double " << speed << "\n";
    }
}

// --------------------------------------------------
// LEARNING MODE REPORT
// --------------------------------------------------

void displayLearningReport(
    int argc,
    char* argv[],
    const char* roadNames[],
    const char* periodNames[],
    int trafficData[][PERIODS],
    double speedLimit)
{
    cout << "\n\n************** LEARNING MODE **************\n";

    showArgumentLearning(argc, argv);
    showArrayLearning(trafficData);
    showDoublePointerLearning(trafficData);
    showStringLearning();
    showConversionLearning();

    cout << "\n========== FINAL APPLICATION REPORT ==========\n";

    displayNormalReport(
        roadNames,
        periodNames,
        trafficData,
        speedLimit
    );
}

// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------

int main(int argc, char* argv[])
{
    const char* roadNames[ROADS] =
    {
        "Main Road",
        "College Road",
        "Mall Road",
        "Hospital Road",
        "Canal Road"
    };

    const char* periodNames[PERIODS] =
    {
        "Morning",
        "Afternoon",
        "Evening"
    };

    // Default sample traffic data.
    int trafficData[ROADS][PERIODS] =
    {
        {120, 180, 220},
        {80, 140, 190},
        {150, 210, 250},
        {60, 90, 110},
        {100, 130, 160}
    };

    const char* mode = "normal";
    double speedLimit = 40.0;

    if (argc > 1)
        mode = argv[1];

    // Accept either:
    // mode only
    // mode + 15 vehicle counts
    // mode + 15 vehicle counts + speed limit
    if (argc != 1 && argc != 2 &&
        argc != 17 && argc != 18)
    {
        cout << "Invalid number of arguments.\n";
        cout << "Usage:\n";
        cout << "traffic normal\n";
        cout << "traffic learning\n";
        cout << "traffic normal followed by 15 vehicle counts\n";
        cout << "traffic learning followed by 15 vehicle counts\n";
        cout << "An optional speed limit can follow the 15 counts.\n";
        return 1;
    }

    if (strcmp(mode, "normal") != 0 &&
        strcmp(mode, "learning") != 0)
    {
        cout << "Invalid mode. Use normal or learning.\n";
        return 1;
    }

    // Read custom traffic counts when supplied.
    if (argc == 17 || argc == 18)
    {
        int argumentIndex = 2;

        for (int road = 0; road < ROADS; road++)
        {
            for (int period = 0; period < PERIODS; period++)
            {
                int vehicleCount;

                if (!myAtoi(argv[argumentIndex], vehicleCount) ||
                    vehicleCount < 0 ||
                    vehicleCount > MAX_VEHICLES)
                {
                    cout << "Invalid vehicle count at argument "
                         << argumentIndex << ".\n";
                    cout << "Enter a whole number from 0 to "
                         << MAX_VEHICLES << ".\n";
                    return 1;
                }

                trafficData[road][period] = vehicleCount;
                argumentIndex++;
            }
        }

        // Read optional decimal speed limit.
        if (argc == 18)
        {
            if (!myAtof(argv[17], speedLimit) ||
                speedLimit <= 0.0 ||
                speedLimit > 200.0)
            {
                cout << "Invalid speed limit.\n";
                cout << "Enter a value greater than 0 and up to 200.\n";
                return 1;
            }
        }
    }

    if (strcmp(mode, "normal") == 0)
    {
        displayNormalReport(
            roadNames,
            periodNames,
            trafficData,
            speedLimit
        );
    }
    else
    {
        displayLearningReport(
            argc,
            argv,
            roadNames,
            periodNames,
            trafficData,
            speedLimit
        );
    }

    return 0;
}
