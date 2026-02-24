# Hospital-management-system-c-project
<h1 align="center">🏥 Hospital Management System (C++ Project)</h1>

<p align="center">
A Console-Based Hospital Management System developed using C++.<br>
This project demonstrates core programming concepts including structures, arrays, loops, conditions, file handling, and modular functions.
</p>

<hr>

<h2>📌 Project Overview</h2>

<p>
The Hospital Management System is a menu-driven console application that manages:
</p>

<ul>
  <li>Patient Registration</li>
  <li>Automatic Department Assignment (ICU / OPD)</li>
  <li>Emergency Detection</li>
  <li>Complete Billing System</li>
  <li>Online Appointment Booking</li>
  <li>Search and Delete Patient Records</li>
  <li>Permanent Data Storage using File Handling</li>
</ul>

<hr>

<h2>🎯 Programming Concepts Used</h2>

<ul>
  <li><b>Structures (struct)</b></li>
  <li><b>Arrays</b></li>
  <li><b>Conditional Statements (if, else, switch)</b></li>
  <li><b>Loops (for, while, do-while)</b></li>
  <li><b>Functions (Modular Programming)</b></li>
  <li><b>File Handling (ifstream, ofstream)</b></li>
  <li><b>Global Variables</b></li>
  <li><b>Input Validation</b></li>
</ul>

<hr>

<h2>🛠️ Technology Used</h2>

<ul>
  <li><b>Language:</b> C++</li>
  <li><b>Libraries:</b> iostream, fstream, string</li>
  <li><b>Platform:</b> Console Application</li>
</ul>

<hr>

<h2>📂 Project Structure</h2>

<pre>
Hospital-Management-System/
│
├── main.cpp
├── patient.txt
├── appointment.txt
└── README.md
</pre>

<hr>

<h2>🧠 System Structures</h2>

<h3>1️⃣ Patient Structure</h3>

<pre>
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
</pre>

<h3>2️⃣ Appointment Structure</h3>

<pre>
struct appointment {
    string patientName;
    string phone;
    string disease;
    string doctorName;
    string timing;
};
</pre>

<hr>

<h2>🚀 System Features</h2>

<h3>🔹 Patient Registration</h3>
<ul>
  <li>Validates ID, Name, and Disease</li>
  <li>Automatically assigns department</li>
  <li>Automatically detects emergency cases</li>
  <li>Calculates full hospital bill</li>
  <li>Saves data to <b>patient.txt</b></li>
</ul>

<h3>🔹 Automatic Department Selection</h3>
<p>
ICU → fracture, heart attack, kidney failure<br>
OPD → other diseases
</p>

<h3>🔹 Automatic Emergency Detection</h3>
<p>
YES → stroke, heart attack, kidney failure<br>
NO → others
</p>

<h3>🔹 Complete Billing System</h3>

<p><b>Billing Includes:</b></p>
<ul>
  <li>Registration Fee</li>
  <li>Doctor Fee</li>
  <li>Test Fee</li>
  <li>Medicine Fee</li>
  <li>Operation Fee</li>
  <li>Daily Stay Charges (1000 per day)</li>
</ul>

<p><b>Final Bill Formula:</b></p>

<pre>
totalFee = registrationFee + doctorFee + medicineFee 
         + testFee + (dayStay × 1000)
</pre>

<hr>

<h3>🔹 Online Appointment Booking</h3>

<ul>
  <li>Enter Patient Details</li>
  <li>Select Doctor:</li>
  <ul>
    <li>Dr. Ahmed (9AM - 12PM)</li>
    <li>Dr. Sara (12PM - 4PM)</li>
    <li>Dr. Ali (4PM - 8PM)</li>
  </ul>
  <li>Saved in <b>appointment.txt</b></li>
</ul>

<hr>

<h3>🔹 Search Patient</h3>
<ul>
  <li>Search by ID</li>
  <li>Search by Name</li>
</ul>

<h3>🔹 Delete Patient Record</h3>
<ul>
  <li>Delete using ID or Name</li>
  <li>File automatically updates</li>
</ul>

<hr>

<h2>🖥️ Main Menu</h2>

<pre>
1. Register Patient
2. Review Patient Record
3. Online Book Appointment
4. View Appointment
5. Search By Name
6. Delete Patient Record
7. Exit
</pre>

<hr>

<h2>▶️ How to Run</h2>

<h3>Step 1: Compile</h3>

<pre>
g++ main.cpp -o hospital
</pre>

<h3>Step 2: Run</h3>

<pre>
./hospital
</pre>

<hr>

<h2>📈 Learning Outcomes</h2>

<ul>
  <li>Understanding structured programming</li>
  <li>Applying real-world billing logic</li>
  <li>Working with file storage systems</li>
  <li>Implementing modular programming</li>
  <li>Building a complete menu-driven system</li>
</ul>

<hr>

<h2>🔮 Future Improvements</h2>

<ul>
  <li>Admin Login System</li>
  <li>Graphical User Interface (GUI)</li>
  <li>Database Integration (MySQL)</li>
  <li>Dynamic Memory Allocation</li>
  <li>Advanced Billing with Receipt Printing</li>
</ul>

<hr>

<h2>👨‍💻 Author</h2>

<p>
MalikFAIZ ANWAR<br>
BS AI – First Semester<br>
C++ Programming Project
</p>

<hr>

<p align="center">
⭐ If you like this project, don't forget to give it a star!
</p>




