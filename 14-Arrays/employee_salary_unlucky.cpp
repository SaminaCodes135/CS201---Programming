#include <iostream>
#include <iomanip>
using namespace std;

// =====================================================
// Constants
// =====================================================

const int MAX_EMPLOYEES = 100;
const int SALARY_COLUMNS = 2;

// Column indexes
const int GROSS_SALARY = 0;
const int NET_SALARY = 1;

// =====================================================
// Function Prototypes
// =====================================================

// Input gross salaries
void getInput(double salary[][SALARY_COLUMNS], int numEmployees);

// Calculate net salaries after deductions
void calculateNetSalary(double salary[][SALARY_COLUMNS],
                        int numEmployees);

// Find employees whose salary situation is unlucky
void findUnluckies(double salary[][SALARY_COLUMNS],
                  bool unlucky[],
                  int numEmployees);

// Display unlucky employees
void displayUnluckies(double salary[][SALARY_COLUMNS],
                      bool unlucky[],
                      int numEmployees);

// =====================================================
// Main Function
// =====================================================

int main()
{
    double salary[MAX_EMPLOYEES][SALARY_COLUMNS];
    bool unlucky[MAX_EMPLOYEES] = {false};

    int numEmployees;

    // -------------------------------------------------
    // Design Recipe: Identify the input
    // -------------------------------------------------

    cout << "Enter number of employees: ";
    cin >> numEmployees;

    // Validate the number of employees
    if (numEmployees <= 0 || numEmployees > MAX_EMPLOYEES)
    {
        cout << "Invalid number of employees." << endl;
        return 0;
    }

    // -------------------------------------------------
    // Design Recipe: Get the required data
    // -------------------------------------------------

    getInput(salary, numEmployees);

    // -------------------------------------------------
    // Design Recipe: Process the data
    // -------------------------------------------------

    calculateNetSalary(salary, numEmployees);

    findUnluckies(salary, unlucky, numEmployees);

    // -------------------------------------------------
    // Design Recipe: Display the result
    // -------------------------------------------------

    displayUnluckies(salary, unlucky, numEmployees);

    return 0;
}

// =====================================================
// Get Input
// =====================================================

void getInput(double salary[][SALARY_COLUMNS], int numEmployees)
{
    for (int i = 0; i < numEmployees; i++)
    {
        cout << "Enter gross salary for employee "
             << i + 1 << ": ";

        cin >> salary[i][GROSS_SALARY];
    }
}

// =====================================================
// Calculate Net Salary
// =====================================================

void calculateNetSalary(double salary[][SALARY_COLUMNS],
                        int numEmployees)
{
    for (int i = 0; i < numEmployees; i++)
    {
        double grossSalary = salary[i][GROSS_SALARY];
        double deduction;

        // Apply deduction according to gross salary
        if (grossSalary <= 5000)
        {
            deduction = 0;
        }
        else if (grossSalary <= 10000)
        {
            deduction = grossSalary * 0.05;
        }
        else if (grossSalary <= 20000)
        {
            deduction = grossSalary * 0.10;
        }
        else
        {
            deduction = grossSalary * 0.15;
        }

        salary[i][NET_SALARY] = grossSalary - deduction;
    }
}

// =====================================================
// Find Unlucky Employees
// =====================================================

void findUnluckies(double salary[][SALARY_COLUMNS],
                   bool unlucky[],
                   int numEmployees)
{
    for (int i = 0; i < numEmployees; i++)
    {
        for (int j = 0; j < numEmployees; j++)
        {
            // Compare different employees.
            //
            // Employee i is unlucky if another employee j
            // has a lower gross salary but a higher net salary.

            if (i != j &&
                salary[i][GROSS_SALARY] >
                salary[j][GROSS_SALARY] &&
                salary[i][NET_SALARY] <
                salary[j][NET_SALARY])
            {
                unlucky[i] = true;
                break;
            }
        }
    }
}

// =====================================================
// Display Unlucky Employees
// =====================================================

void displayUnluckies(double salary[][SALARY_COLUMNS],
                      bool unlucky[],
                      int numEmployees)
{
    bool found = false;

    cout << fixed << setprecision(2);

    cout << "\nUnlucky Employees:" << endl;

    for (int i = 0; i < numEmployees; i++)
    {
        if (unlucky[i])
        {
            cout << "Employee " << i + 1
                 << " - Gross: "
                 << salary[i][GROSS_SALARY]
                 << ", Net: "
                 << salary[i][NET_SALARY]
                 << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "No unlucky employees found." << endl;
    }
}
