📘 Assignment 01 – University IT Helpdesk Workload Report

Course: CS201 – Introduction to Programming
Semester: Fall 2026
Assignment: 01

🎯 Problem Statement

A university IT helpdesk receives support tickets from five campus service desks. The task is to develop a C++ program that uses a hard-coded student name and VU Student ID to generate an overall helpdesk workload report.
The program extracts five specific digits from the 9-digit numeric part of the Student ID using arithmetic operators. Each extracted digit represents the number of support tickets received by a particular service desk.
Assuming each ticket requires 20 minutes to resolve, the program calculates the estimated resolution time for each desk, classifies its workload, and displays a summary of all service desks.
All information and calculations are derived from the hard-coded Student ID without requiring user input.

🧠 Concepts Practiced

Variables and Constants

Data Types

Arithmetic Operators (/, %, *)

Conditional Statements (if, else-if, else)

Output Statements (cout)

Iterative Statements

🔢 Digit Extraction and Service Desk Assignment

The program extracts digits at the following positions from the 9-digit numeric part of the Student ID:
Digit PositionService Desk2ndNetwork Support4thComputer Lab Support5thLMS Support6thAccount Support8thHardware Support 
Implementation Constraint: Digit extraction is performed exclusively using division (/) and modulus (%) operators, without using arrays or string operations.

📊 Workload Classification

Each service desk is classified according to its number of support tickets:
Number of Tickets 0-3 => Workload Status => LIGHT
Number of Tickets 4–6 => Workload => MODERATE
Number of Tickets 7–9 => Workload => HEAVY 

⚙️ Program Features

Displays student name and VU Student ID.

Extracts five specified digits using arithmetic operations.

Assigns extracted digits to their respective service desks.

Calculates estimated resolution time at 20 minutes per ticket.

Classifies each service desk according to its workload.

Counts LIGHT, MODERATE, and HEAVY service desks.

Generates an organized University IT Helpdesk Workload Report.

▶️ How to Run

Open the .cpp source file in Dev-C++ or another compatible C++ compiler.

Compile the program.

Run the executable to generate the helpdesk workload report.

🎓 Learning Objectives

To develop practical understanding of fundamental C++ programming concepts through a real-world problem involving arithmetic digit extraction, calculations, conditional logic, and structured console output.

🛠️ Development Information

Programming Language: C++

Development Environment: Dev-C++

Status: Completed

Part of my CS201 academic assignments and ongoing C++ programming learning journey.
