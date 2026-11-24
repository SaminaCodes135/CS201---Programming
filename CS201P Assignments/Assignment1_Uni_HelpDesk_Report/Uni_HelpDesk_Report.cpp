#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Step 1: Store the student's information directly in the program.
    // No input is taken from the user, as required by the assignment.
    const long long studentID = BC260218531;
    const string studentName = "Samina Zahoor";

    cout << "==============================================" << endl;
    cout << "       UNIVERSITY IT HELPDESK REPORT" << endl;
    cout << "==============================================" << endl;

    cout << "Student Name: " << studentName << endl;
    cout << "VU Student ID: " << studentID << endl;

    // Step 2: Extract the required digits using division and modulus.
    // The ID has 9 digits. Division moves the required digit to the
    // units position, and % 10 obtains that digit.
    int networkTickets   = (studentID / 10000000) % 10; // 2nd digit
    int labTickets       = (studentID / 100000) % 10;    // 4th digit
    int lmsTickets       = (studentID / 10000) % 10;     // 5th digit
    int accountTickets   = (studentID / 1000) % 10;      // 6th digit
    int hardwareTickets  = (studentID / 10) % 10;        // 8th digit

    cout << "\nExtracted digits (2nd, 4th, 5th, 6th, 8th): "
         << networkTickets << ", "
         << labTickets << ", "
         << lmsTickets << ", "
         << accountTickets << ", "
         << hardwareTickets << endl;

    // Step 3: Calculate the estimated resolution time.
    // Each support ticket is assumed to take 20 minutes.
    const int minutesPerTicket = 20;

    int networkTime  = networkTickets * minutesPerTicket;
    int labTime      = labTickets * minutesPerTicket;
    int lmsTime      = lmsTickets * minutesPerTicket;
    int accountTime  = accountTickets * minutesPerTicket;
    int hardwareTime = hardwareTickets * minutesPerTicket;

    // These counters keep track of how many desks fall into each category.
    int lightCount = 0;
    int moderateCount = 0;
    int heavyCount = 0;

    cout << "\n--------------- DESK DETAILS ----------------" << endl;

    // Step 4: Classify Network Support workload.
    cout << "\nService Desk: Network Support" << endl;
    cout << "Number of Tickets: " << networkTickets << endl;
    cout << "Estimated Resolution Time: " << networkTime << " minutes" << endl;

    if (networkTickets >= 7)
    {
        cout << "Workload: HEAVY" << endl;
        heavyCount++;
    }
    else if (networkTickets >= 4)
    {
        cout << "Workload: MODERATE" << endl;
        moderateCount++;
    }
    else
    {
        cout << "Workload: LIGHT" << endl;
        lightCount++;
    }

    // Classify Computer Lab Support workload.
    cout << "\nService Desk: Computer Lab Support" << endl;
    cout << "Number of Tickets: " << labTickets << endl;
    cout << "Estimated Resolution Time: " << labTime << " minutes" << endl;

    if (labTickets >= 7)
    {
        cout << "Workload: HEAVY" << endl;
        heavyCount++;
    }
    else if (labTickets >= 4)
    {
        cout << "Workload: MODERATE" << endl;
        moderateCount++;
    }
    else
    {
        cout << "Workload: LIGHT" << endl;
        lightCount++;
    }

    // Classify LMS Support workload.
    cout << "\nService Desk: LMS Support" << endl;
    cout << "Number of Tickets: " << lmsTickets << endl;
    cout << "Estimated Resolution Time: " << lmsTime << " minutes" << endl;

    if (lmsTickets >= 7)
    {
        cout << "Workload: HEAVY" << endl;
        heavyCount++;
    }
    else if (lmsTickets >= 4)
    {
        cout << "Workload: MODERATE" << endl;
        moderateCount++;
    }
    else
    {
        cout << "Workload: LIGHT" << endl;
        lightCount++;
    }

    // Classify Account Support workload.
    cout << "\nService Desk: Account Support" << endl;
    cout << "Number of Tickets: " << accountTickets << endl;
    cout << "Estimated Resolution Time: " << accountTime << " minutes" << endl;

    if (accountTickets >= 7)
    {
        cout << "Workload: HEAVY" << endl;
        heavyCount++;
    }
    else if (accountTickets >= 4)
    {
        cout << "Workload: MODERATE" << endl;
        moderateCount++;
    }
    else
    {
        cout << "Workload: LIGHT" << endl;
        lightCount++;
    }

    // Classify Hardware Support workload.
    cout << "\nService Desk: Hardware Support" << endl;
    cout << "Number of Tickets: " << hardwareTickets << endl;
    cout << "Estimated Resolution Time: " << hardwareTime << " minutes" << endl;

    if (hardwareTickets >= 7)
    {
        cout << "Workload: HEAVY" << endl;
        heavyCount++;
    }
    else if (hardwareTickets >= 4)
    {
        cout << "Workload: MODERATE" << endl;
        moderateCount++;
    }
    else
    {
        cout << "Workload: LIGHT" << endl;
        lightCount++;
    }

    // Step 5: Display the final count of desks in each workload category.
    cout << "\n=============== FINAL SUMMARY ===============" << endl;
    cout << "Number of LIGHT workload desks: " << lightCount << endl;
    cout << "Number of MODERATE workload desks: " << moderateCount << endl;
    cout << "Number of HEAVY workload desks: " << heavyCount << endl;
    cout << "==============================================" << endl;

    return 0; // End the program successfully.
}
