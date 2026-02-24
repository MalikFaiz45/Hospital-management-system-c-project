# Hospital-management-system-c-project
🏥 Hospital Management System (C++ Project)

A console-based Hospital Management System developed in C++ as a semester project.
This system manages patient records, billing, and online appointment booking using fundamental programming concepts.

📌 Project Description

This project simulates a real-world hospital environment where:

Patients can be registered

Bills are automatically calculated

Departments are assigned automatically

Emergency cases are detected

Appointments can be booked online

Records are stored permanently using file handling

The system is completely menu-driven and runs in the console.

🎯 Programming Concepts Used

This project demonstrates strong understanding of:

✅ Structures (struct)

✅ Arrays

✅ Conditional Statements (if, else, switch)

✅ Loops (for, while, do-while)

✅ Functions (Modular Programming)

✅ File Handling (ifstream, ofstream)

✅ Global Variables

✅ Input Validation

✅ Billing System Logic

🛠️ Technology Used

Language: C++

Libraries Used:

<iostream>

<fstream>

<string>

Platform: Console Application

📂 Project Structure
Hospital-Management-System/
│
├── main.cpp
├── patient.txt
├── appointment.txt
└── README.md
🧠 System Architecture
1️⃣ Patient Structure
struct person {
    int id, age;
    string name, disease;
    string department, operationName;
    string emergency;
    string referral;
    string appointment;
    int registrationFee;
    int doctorFee;
    int medicineFee;
    int testFee;
    int operationFee;
    int dayStay, totalFee;
};

Stores complete patient medical and billing information.

2️⃣ Appointment Structure
struct appointment {
    string patientName;
    string phone;
    string disease;
    string doctorName;
    string timing;
};

Used for online appointment booking.

🚀 Features
🔹 1. Patient Registration

Validates ID, Name, Disease

Automatically assigns:

Department (ICU / OPD)

Emergency status (YES / NO)

Calculates full hospital bill

Stores data in patient.txt

🔹 2. Automatic Department Selection
string autoDepartment(string disease)

ICU → fracture, heart attack, kidney failure

OPD → other diseases

🔹 3. Automatic Emergency Detection
string autoEmergency(string disease)

YES → stroke, heart attack, kidney failure

NO → others

🔹 4. Complete Billing System

Billing Includes:

Registration Fee

Doctor Fee

Test Fee

Medicine Fee

Operation Fee

Daily Stay Charges (1000 per day)

Final Bill Calculation:

totalFee = registrationFee + doctorFee + medicineFee 
         + testFee + (dayStay × 1000)
🔹 5. Online Appointment Booking

Patient enters details

Selects doctor:

Dr. Ahmed (9AM–12PM)

Dr. Sara (12PM–4PM)

Dr. Ali (4PM–8PM)

Stored in appointment.txt

🔹 6. File Handling
Patient Records

saveAllPatientsToFile()

readFromFile()

Stored in:

patient.txt
Appointment Records

saveAppointmentToFile()

readAppointmentsFromFile()

Stored in:

appointment.txt

Data remains saved even after program closes.

🔹 7. Search Patient

Search by:

ID

Name

🔹 8. Delete Patient Record

Deletes a patient using:

ID

Name

File updates automatically after deletion.

🖥️ Main Menu
1. Register Patient
2. Review Patient Record
3. Online Book Appointment
4. View Appointment
5. Search By Name
6. Delete Patient Record
7. Exit

The system runs using a do-while loop until the user selects Exit.

🔐 Input Validation

The system ensures:

ID must be greater than 0

Name cannot be empty

Disease cannot be empty

Full payment required before proceeding

📊 Data Storage Logic

Uses global arrays

patient[MAX]

app[200]

Uses global counters:

count

appCount

▶️ How to Run
Step 1: Compile
g++ main.cpp -o hospital
Step 2: Run
./hospital
📈 Learning Outcomes

Through this project, the following skills were developed:

Structured programming

Real-world problem solving

File-based data management

Function modularization

Logical thinking and validation

Billing system implementation

🔮 Future Improvements

Admin login authentication

GUI (Graphical User Interface)

Database integration (MySQL)

Dynamic memory allocation

Improved error handling

Advanced billing system with receipt printing

👨‍💻 Author
MalikFAIZ ANWAR
BS AI – First Semester
C++ Programming Project
