#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ================================******* Patient Structure*********===================
struct person {
    int id, age;
    string name, disease;
    string department,operationName;
    string emergency;
    string referral;
    string appointment;
    int registrationFee;
    int doctorFee;
    int medicineFee;
    int testFee;
    int operationFee;
    int dayStay,totalFee;
    
};
//======================================******* online booking appointment structure datatype variable=====*****=====
// ============================ Appointment Structure ===========================
struct appointment {
    string patientName;
    string phone;
    string disease;
    string doctorName;
    string timing;
};

appointment app[200];//array for online booking this is save another txt file
int appCount = 0;

// =========================Declare array ***============================
const int MAX = 500;
person patient[MAX];//first array using struct datatype variable
int count = 0;
//**************************************** AUTOMATIC FUCTION IS GIVEN BELOW THAT I CALL IT IN REGESTER FUNCTION**********
// ---------------- Automatic SELECT DEPARTMENT ----------------============
string autoDepartment(string disease) {
    if (disease == "fracture" || disease == "heart attack" || disease == "kidney failure"){
	  return "ICU";
		}
   else{
   return "OPD";
   }
}
//===========================check emergency==================
string autoEmergency(string disease) {
    if (disease == "strokke" || disease == "heart attack" || disease == "kidney failure"){
	
        return "YES";}
    else{
	 return "NO";}
}

//============================calculate bill of patient=====================
 bool payment(int fee){
 	int pay;
 	cout<<"Fee :"<<fee<<endl;
 	cout<<"please PAy your fee now:"<<endl;
 	cin>>pay;
 	if(pay<fee){
 		cout<<"insufficient payment !\n please submit full amount";
 		cin>>pay;
 		return false;
	 }
	else{
		cout<<"payment successfully submit!thank you \n";
		return true;
	}
 }
 void prescribedTestFee(person &p){
 	p.testFee=0;
 	cout<<"Enter tests details prescribed by doctor(type 'done' to finish ):\t";
 	while(true){
 		string testName;
 		cout<<"Enter test name:\t";
 		cin.ignore();
 		getline(cin,testName);
 		if(testName=="done"||testName=="DONE"){
 			break;
		 }
	 int testPrice;
	 cout<<"Enter price of "<<testName<<" fee :\t";
	 cin>>testPrice;
	 p.testFee += testPrice;
	 }
	 if (p.testFee>0){
	 	cout<<"please pay test fee first !\t"<<endl;
	 	if(!payment(p.testFee)){
		cout<<"please submit test fee on counter firstly before test !"<<endl;
	 	return;
	 	 }
	 }
 }
 void prescribedMedicines(person &p){
 		p.medicineFee=0;
 	cout<<"Enter medicines details prescribed by doctor(type 'done' to finish ):\t";
 	while(true){
 		string MedicineName;
 		cout<<"Enter medicine name:\t";
 		cin.ignore();
 		getline(cin,MedicineName);
 		if(MedicineName=="done"||MedicineName=="DONE"){
 			break;
		 }
	   else{		 
	   int medicinePrice;
	   cout<<"Enter price of "<<MedicineName<<" fee :\t";
	   cin>>medicinePrice;
	   p.medicineFee += medicinePrice;}
	 }
	 if (p.medicineFee>0){
	 	cout<<"please pay test fee first !\t"<<endl;
	 	if(!payment(p.medicineFee)){
		cout<<"please submit full medicine amount on counter firstly !"<<endl;
	 	return;
	 	 }
	 }
 }
 void prescribedOperation(person &p){
 	int op;
 	cout<<"OPERATION REQUIRED (1=yes ,0=no)"<<endl;
 	cin>>op;
// 	string name;
 	if(op==1){
 		cout<<"ENTER OPERATION NAME \t";
 		cin.ignore();
 		getline(cin,p.operationName);
 		
 		cout<<"ENTER OPERATION FEE \t";
 		cin >> p.operationFee;
 		
 		cout<<"please submit operation fee first before operation "<<endl;
 		if(!payment(p.operationFee))
 			cout<<"please submit full medicine amount on counter firstly !"<<endl;
		 
	 }
	 else 
	 p.operationFee=0;
 }
 
 void doctorSection(person &p){
 	cout<<"ENTER DOCTOR FEE \t";
 	cin>>p.doctorFee;
 	
 	prescribedTestFee(p);
 	prescribedMedicines(p);
   prescribedOperation(p);
   
   cout<<"Days stays in hospital :\t";
   cin>>p.dayStay;	
   
   int perDayCharge = 1000;
   p.totalFee = p.registrationFee + p.doctorFee + p.medicineFee+p.testFee + (p.dayStay * perDayCharge );
   
   cout<<"\n Final bill :"<<p.totalFee<<endl;	
 	
 }
 
//============================================= File read and write /store and display patient record============== 
// ---------------- Save all patients to file ----------------
void saveAllPatientsToFile() {
    ofstream file("patient.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }
//FOR LOOP TO STORE MULTIPLE RECORD BUT I CALL THIS IS ALSO REQUIRED FUNCTION
    for (int i = 0; i < count; i++) {
        file << patient[i].id << endl;
        file << patient[i].name << endl;
        file << patient[i].age << endl;
        file << patient[i].disease << endl;
        file << patient[i].department << endl;
        file << patient[i].emergency << endl;
         file << patient[i].testFee<<endl;
        file << patient[i].doctorFee << endl;
        file << patient[i].medicineFee << endl;
         file << patient[i].operationFee << endl;
        file << patient[i].totalFee << endl;
        file << "-----" << endl;
    }
    file.close();
}
//==============================================FUCTION IS TO RETRIVE DATA FROM STORE TXT FILE==================
void readFromFile(){
	ifstream file("patient.txt");

    if (!file) {
        return;
    }

    count = 0;   
    string line;

    while (file >> patient[count].id) {
        file.ignore();
        getline(file, patient[count].name);
        file >> patient[count].age;
        file.ignore();
        getline(file, patient[count].disease);
        getline(file, patient[count].department);
        getline(file, patient[count].emergency);
        file >> patient[count].testFee;
        file >> patient[count].doctorFee;
        file >> patient[count].medicineFee;
         file >> patient[count].operationFee;
        file >> patient[count].totalFee;

        file.ignore();
        getline(file, line); // read "-----"

        count++;
    }

    file.close();
}
// ****************************************************************************************************************
//=====================@@@@@@@@@@@@@another txt file write for online booking @@@@@@@@@@@==================
void saveAppointmentToFile(appointment a) {
    ofstream file("appointment.txt", ios::app);
    if (!file) {
        cout << "Error opening appointment file!\n";
        return;
    }

    file << a.patientName << endl;
    file << a.phone << endl;
    file << a.disease << endl;
    file << a.doctorName << endl;
    file << a.timing << endl;
    file << "-----" << endl;

    file.close();
}
//===========@@@@@@@@@@@@@@@@@@@@@ txt file for view booking details@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@===============
void readAppointmentsFromFile() {
    ifstream file("appointment.txt");
    if (!file) return;

    appCount = 0;
    string sep;

    while (getline(file, app[appCount].patientName)) {
        getline(file, app[appCount].phone);
        getline(file, app[appCount].disease);
        getline(file, app[appCount].doctorName);
        getline(file, app[appCount].timing);
        getline(file, sep); 
        appCount++;
    }
    file.close();
}


//=========================================****** main program start *****========================
// ---------------- Register Patient ----------------
void registerPatient() {
//    loadPatientsFromFile();
    if (count >= MAX) {
        cout << "Hospital full!" << endl;
        return;
    }
     person p; //this is variable of 2nd structure variable
    cout<<"Enter registration fee : ";
    cin>>p.registrationFee;
     if(!payment(p.registrationFee)){
	 cout<<"please firstly submit registration fee !"<<endl;
	 return;
	 }
     
// enter patient record by following  validation logic 
  
    
    cout << "Enter ID: "; cin >> p.id;

    if(p.id<=0){
	cout<<"invalid id ,please Enter valid id"<<endl;
	return;
}//enter validation
    
    cout << "Enter Name: ";
	cin.ignore();
	 getline(cin, p.name);
    if(p.name.empty()){
	cout<<"Empty name ,Please fill"<<endl;
	return;
}
    
    cout << "Enter Age: ";
	 cin >> p.age; 
//	cin.ignore();
    
    cout << "Enter Disease: "; 
	cin.ignore();
	getline(cin, p.disease);
    if(p.disease.empty()){
	cout<<"Empty disease ,Please fill"<<endl;
	return;
}     

// cout<<"Enter registration fee : ";
//    cin>>p.registrationFee;
//     if(!payment(p.registrationFee)){
//	 cout<<"please firstly submit registration fee !"<<endl;
//	 return;
//	 }
//  ================== now call auto fuctions =====================
    p.department = autoDepartment(p.disease);
    p.emergency = autoEmergency(p.disease);


   doctorSection(p);
   int perDayCharge = 1000;
     p.totalFee = p.registrationFee + p.doctorFee + p.medicineFee+p.testFee + (p.dayStay * perDayCharge );
   // ============patient record is increse by count ++ and below call write data function===========
    patient[count++] = p;
    saveAllPatientsToFile();
    cout << "Patient registered successfully!" << endl;
}
//================================******* 2nd main function to see all patient record or read functiion *****=========
void reviewPatientRecord() {
	readFromFile();//call read function
    if (count == 0) {
        cout << "No record available!" << endl;
        return;
    }

    cout << "\n------ Patient History ------\n";

    for (int i = 0; i < count; i++) {
        cout << "\nID: " << patient[i].id;
        cout << "\nName: " << patient[i].name;
        cout << "\nAge: " << patient[i].age;
        cout << "\nDisease: " << patient[i].disease;
        cout << "\nDepartment: " << patient[i].department;
        cout << "\nEmergency: " << patient[i].emergency;
		cout<<"\n test fee :" <<patient[i].testFee;
        cout << "\nDoctor Fee: " << patient[i].doctorFee;
        cout << "\nMedicine Fee: " << patient[i].medicineFee;
        cout << "\nTotal Fee: " << patient[i].totalFee;
        cout << "\n-----------------------------\n";
    }
}
//$$$$$$$$$$$$$$$$$$$$@@@@@@@@@@@@@@@@@@@@@@@below main fuction of online booking system @@@@@@@@@@@@@@@@@@@$$$$$$$$
void bookAppointment() {
    appointment a;// a struct variable single record

    cout << "\n=========== ONLINE APPOINTMENT BOOKING ===========\n";

   
    cout << "Enter Patient Name: ";
     cin.ignore();
    getline(cin, a.patientName);

    cout << "Enter Phone Number: ";
    getline(cin, a.phone);

    cout << "Enter Disease: ";
     cin.ignore();
    getline(cin, a.disease);

    cout << "\nAvailable Doctors:\n";
    cout << "1. Dr. Ahmed (9AM - 12PM)\n";
    cout << "2. Dr. Sara (12PM - 4PM)\n";
    cout << "3. Dr. Ali (4PM - 8PM)\n";

    int choice;
    cout << "Choose Doctor (1-3): ";
    cin >> choice;

    switch (choice) {
        case 1:
            a.doctorName = "Dr. Ahmed";
            a.timing = "9AM - 12PM";
            break;
        case 2:
            a.doctorName = "Dr. Sara";
            a.timing = "12PM - 4PM";
            break;
        case 3:
            a.doctorName = "Dr. Ali";
            a.timing = "4PM - 8PM";
            break;
        default:
            cout << "Invalid choice!\n";
            return;
    }

    saveAppointmentToFile(a);

    cout << "\n? Appointment Booked Successfully!\n";
    cout << "Doctor: " << a.doctorName << endl;
    cout << "Timing: " << a.timing << endl;
    cout << "===============================================\n";
    return;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ==== read and display data from online booking txt file@@@@@@@22+++++
void viewAppointments() {
    readAppointmentsFromFile();

    if (appCount == 0) {
        cout << "No appointments available!\n";
        return;
    }

    cout << "\n========= APPOINTMENT LIST =========\n";
    for (int i = 0; i < appCount; i++) {
        cout << "\nPatient Name: " << app[i].patientName;
        cout << "\nPhone: " << app[i].phone;
        cout << "\nDisease: " << app[i].disease;
        cout << "\nDoctor: " << app[i].doctorName;
        cout << "\nTiming: " << app[i].timing;
        cout << "\n-----------------------------------\n";
    }
    return;
}
//******************************************************************************************************************
// ================================*** below function is  to searhch by id and name of patient ****===========
// ---------------- Search Patient by Name ----------------
void searchByName() {
    readFromFile();// firstly call this read function
    cin.ignore();
    string name;
    cout << "Enter name to search: "; getline(cin, name);
    int id;
    cout<<"enter id for search :";cin>>id;
    bool found = false;

    for (int i = 0; i < count; i++) {
        if (patient[i].id == id ||patient[i].name == name ) {
            found = true;
            cout << "ID: " << patient[i].id
                 << ", Name: " << patient[i].name
                 << ", Disease: " << patient[i].disease
                 << ", Department: " << patient[i].department << endl;
        }
    }
    if (!found) cout << "Patient not found!" << endl;
}
// ======================*** this function is deleadte a specific record of one patient by matching id and name
// ---------------- Delete Patient ----------------
void deletePatient() {
   readFromFile();
    int id;
    cout << "Enter Patient ID to delete: "; cin >> id;
     cin.ignore();
    string name;
    cout << "Enter name to delete: "; getline(cin, name);
    bool found = false;

    for (int i = 0; i < count; i++) {
        if (patient[i].id == id || patient[i].name==name) {
            for (int j = i; j < count - 1; j++)
                patient[j] = patient[j + 1];
            count--;
            found = true;
            cout << "Patient deleted successfully." << endl;
            break;
        }
    }

    saveAllPatientsToFile();
    if (!found) cout << "Patient not found!" << endl;
}


int main(){
//	registerPatient() ;
	int choice;
    do {
        cout << "\n=====\2\2\2\2\2\2 \4\4\4\4\4\4\4\4HOSPITAL MANAGEMENT SYSTEM\3\3\3\3\3\3\3\3\3\3\3\5\5\5\5\5\5\5\5\5\5 =====\n";
        cout << "1. Register Patient\n2. Review patient record \n 3.online Book Appointment\n";
        cout << "4. view appointment\n5. searchByName\n6. Delete patient record\n7. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerPatient(); break;
             case 2:  reviewPatientRecord(); break;
              case 3: bookAppointment(); break;
            case 4: viewAppointments(); break;
            case 5: searchByName(); break;
            case 6: deletePatient(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);
	
	
	return 0;
}
