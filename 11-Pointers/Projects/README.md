CS201 — Real-World C++ Pointer Projects

A collection of four practical C++ programs developed to strengthen pointer fundamentals through real-world-inspired applications.

These projects apply the concepts studied in Lecture 15, including pointer arithmetic, array traversal, dereferencing, pointer comparisons, and C-style string manipulation.

The goal is to move beyond isolated examples and understand how pointers work within structured, readable, and practical programs.

📂 Project Collection

01. Hospital Vital Signs Monitoring System

A demonstration program that analyzes sample vital-sign readings using arrays and pointers.

Key features

- Displays sample readings in a readable report.
- Calculates minimum, maximum, and average readings.
- Demonstrates pointer traversal and modification of array elements.
- Includes a learning mode for exploring pointer expressions.

Concepts: Array pointers, dereferencing, pointer arithmetic, and value modification.

02. Smart Home Energy Usage Analyzer

A household energy analysis program that examines the consumption of different appliances.

Key features

- Displays energy usage for individual appliances.
- Calculates total energy consumption.
- Identifies the appliance with the highest recorded usage.
- Demonstrates pointer arithmetic and comparisons.

Concepts: Array traversal, pointer offsets, pointer subtraction, and comparisons.

03. Parcel Label Transfer System

A parcel-label processing program that demonstrates copying and traversing C-style strings using pointers.

Key features

- Accepts a parcel label from the user.
- Copies the label into a separate character array using pointers.
- Calculates the label length.
- Demonstrates character traversal and null termination.

Concepts: Character pointers, C-style strings, "'\0'", pointer increment, and pointer-based copying.

04. Airport Baggage Routing and Inspection System

A baggage-reporting program that combines numeric array processing with pointer-based string operations.

Key features

- Displays baggage identifiers, weights, and inspection statuses.
- Calculates total baggage weight.
- Identifies the heaviest bag.
- Counts bags marked for inspection.
- Demonstrates pointer operations in a separate learning mode.

Concepts: Pointer arithmetic, dereferencing, comparisons, pointer subtraction, array manipulation, and C-style strings.

🎯 Learning Objectives

Through these projects, the learner practises:

- Understanding the relationship between arrays and pointers.
- Accessing array elements using indexing and pointer expressions.
- Using pointer increment, decrement, and offset operations.
- Distinguishing pointer movement from modification of pointed-to values.
- Comparing pointer positions and comparing the values they reference.
- Understanding pointer subtraction within the same array.
- Working with character arrays and null-terminated strings.
- Applying pointer safety and array-boundary rules.
- Writing readable, function-based C++ programs.

🧪 Application Mode and Learning Mode

Each program is designed around two modes:

Normal Application Mode

Focuses on the program's task and presents clean, user-friendly output.

Pointer Learning Lab

Demonstrates relevant pointer concepts through practical examples, helping connect the underlying C++ expressions to their effects.

🛠️ Technologies

- Language: C++
- Standard: C++17
- Core topics: Pointers, arrays, functions, loops, conditional statements, and C-style strings.
- Tools: Any C++17-compatible compiler or online C++ IDE.

▶️ How to Compile and Run

1. Open the desired ".cpp" file in a C++ compiler or IDE.
2. Compile the program using a C++17-compatible compiler.

For example, using GCC:

g++ -std=c++17 01-HospitalVitalSigns.cpp -o hospital

3. Run the compiled program:

./hospital

On Windows, the executable can be run with:

hospital.exe

Repeat these steps with the appropriate source filename for each project.

📚 Repository Context

These projects are part of the CS201 learning journey.

- "14pointers/" — Existing pointer notes, examples, and practice programs.
- "15-pointer-projects/" — Practical projects applying pointer concepts.
- "projects/" — Larger integrated projects, including the Student Management System.

This organization separates foundational exercises from practical applications while keeping related coursework together.

⚠️ Educational Scope

All data used in these programs is illustrative. The applications are designed for programming education and are not connected to real medical monitoring, household sensors, airport systems, or security equipment.

🚀 Project Goal

To develop a strong understanding of C++ pointers by applying them to practical problems, writing clear code, and learning how individual pointer operations contribute to a complete program.

---

Course: CS201
Language: C++
Focus: Pointers, arrays, and C-style strings
