#include <iostream>
using namespace std;

// Constants
#define MAX 70
#define MAXSUB 5
#define SIZE 30

// Structure for Date
struct mydata {
    int dd, mm, yy;
};

// Structure for Student Information
struct studinfo {
    int regno;
    string name;
    string fatherName;
    int marks[MAXSUB];
    int totalMarks;
    mydata dob;
    mydata doa;
    float cgpa;
};

// Function Prototypes
void CreateDB(studinfo SS[], int& nn);
void AppendRecord(studinfo SS[], int& nn);
void SearchRecord(studinfo SS[], int nn);
void DeleteRecord(studinfo SS[], int& nn);
void UpdateRecord(studinfo SS[], int nn);
void DisplayStudentResults(studinfo SS[], int nn);

int main() {
    studinfo S[MAX];
    int n = 0, ch;

    do {
        cout << "MENU" << endl;
        cout << "1. Create Database" << endl;
        cout << "2. Append Record" << endl;
        cout << "3. Search Record" << endl;
        cout << "4. Delete Record" << endl;
        cout << "5. Update Record" << endl;
        cout << "6. Display Student Results" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your Choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            CreateDB(S, n);
            break;
        case 2:
            if (n ==0) {
                cout << "create database first";
            }
            else {
                AppendRecord(S, n);
            }
            break;
        case 3:
            if (n == 0) {
                cout << " No Data Found.Create Database first.";
                
            }
            else {
                SearchRecord(S, n);
            }
            break;
        case 4:
            if (n == 0) {
                cout << "No Data Found. Create Database first." << endl;
            }
            else {
                DeleteRecord(S, n);
                
            }
            break;
        case 5:
            if (n == 0) {
                cout << "No Data Found. Create Database first." << endl;
                
            }
            else {
                UpdateRecord(S, n);
                

            }
            break;
        case 6:
            if (n == 0) {
                cout << "No Data Found. Create Database first." << endl;
                
            }
            else {
                DisplayStudentResults(S, n);
                
            }
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid Option" << endl;
        }
    } while (true);

    return 0;
}

// Function to Create Database
void CreateDB(studinfo SS[], int& nn) {
    cout << "Enter the number of students less to " << MAX << "): ";
    cin >> nn;

    if (nn > MAX) {
        cout << "Exceeds maximum capacity (max=70)";
        cin >> nn;
    }

    for (int i = 0; i < nn; i++) {
        cout << "Enter Student #" << i + 1 << " Details:" << endl;
        SS[i].regno = i + 1;

        cout << "Name: ";
        cin >> SS[i].name;

        cout << "Father's Name: ";
        cin >> SS[i].fatherName;

        cout << "Date of Birth (DD MM YY): ";
        cin >> SS[i].dob.dd >> SS[i].dob.mm >> SS[i].dob.yy;

        cout << "Date of Admission (DD MM YY): ";
        cin >> SS[i].doa.dd >> SS[i].doa.mm >> SS[i].doa.yy;

        cout << "Enter Marks for 5 Subjects:" << endl;
        SS[i].totalMarks = 0;
        for (int j = 0; j < MAXSUB; j++) {
            cout << "Subject " << j + 1 << ": ";
            cin >> SS[i].marks[j];
            SS[i].totalMarks += SS[i].marks[j];
        }

        cout << "CGPA: ";
        cin >> SS[i].cgpa;
    }
    cout << "Database Created Successfully!" << endl;
}

// Function to Append Record
void AppendRecord(studinfo SS[], int& nn) {
    if (nn < MAX) {
        cout << "Enter Student #" << nn + 1 << " Details:" << endl;
        SS[nn].regno = nn + 1;

        cout << "Name: ";
        cin >> SS[nn].name;

        cout << "Father's Name: ";
        cin >> SS[nn].fatherName;

        cout << "Date of Birth (DD MM YY): ";
        cin >> SS[nn].dob.dd >> SS[nn].dob.mm >> SS[nn].dob.yy;

        cout << "Date of Admission (DD MM YY): ";
        cin >> SS[nn].doa.dd >> SS[nn].doa.mm >> SS[nn].doa.yy;

        cout << "Enter Marks for 5 Subjects:" << endl;
        SS[nn].totalMarks = 0;
        for (int j = 0; j < MAXSUB; j++) {
            cout << "Subject " << j + 1 << ": ";
            cin >> SS[nn].marks[j];
            SS[nn].totalMarks += SS[nn].marks[j];
        }

        cout << "CGPA: ";
        cin >> SS[nn].cgpa;

        nn++;
        cout << "Record Appended Successfully!" << endl;
    }
    else {
        cout << "Database is full. Cannot append more records." << endl;
    }
}

// Function to Search Record
void SearchRecord(studinfo SS[], int nn) {
    int regno;
    cout << "Enter Registration Number to Search: ";
    cin >> regno;

    for (int i = 0; i < nn; i++) {
        if (SS[i].regno == regno) {
            cout << "Student Record Found:" << endl;
            cout << "Registration Number: " << SS[i].regno << endl;
            cout << "Name: " << SS[i].name << endl;
            cout << "Father's Name: " << SS[i].fatherName << endl;
            cout << "Date of Birth: " << SS[i].dob.dd << "/" << SS[i].dob.mm << "/" << SS[i].dob.yy << endl;
            cout << "Date of Admission: " << SS[i].doa.dd << "/" << SS[i].doa.mm << "/" << SS[i].doa.yy << endl;
            cout << "Marks for 5 Subjects:" << endl;
            for (int j = 0; j < MAXSUB; j++) {
                cout << "Subject " << j + 1 << ": " << SS[i].marks[j] << endl;
            }
            cout << "Total Marks Obtained: " << SS[i].totalMarks << "/500" << endl;
            cout << "CGPA: " << SS[i].cgpa << endl;
            return; // Record found, exit the function
        }
    }

    // If the loop completes, the record was not found
    cout << "Record not found for Registration Number: " << regno << endl;
}

// Function to Delete Record
void DeleteRecord(studinfo SS[], int& nn) {
    int regno;
    cout << "Enter Registration Number to Delete: ";
    cin >> regno;

    for (int i = 0; i < nn; i++) {
        if (SS[i].regno == regno) {
            // Shift all records after the deleted one to the left
            for (int j = i; j < nn - 1; j++) {
                SS[j] = SS[j + 1];
            }
            nn--; // Decrement the number of records
            cout << "Record for Registration Number " << regno << " has been deleted." << endl;
            return;
        }
    }

    // If the loop completes, the record was not found
    cout << "Record not found for Registration Number: " << regno << endl;
}

// Function to Update Record
void UpdateRecord(studinfo SS[], int nn) {
    int regno;
    cout << "Enter Registration Number to Update: ";
    cin >> regno;

    for (int i = 0; i < nn; i++) {
        if (SS[i].regno == regno) {
            cout << "Enter updated details for Student #" << regno << ":" << endl;

            cout << "Name: ";
            cin >> SS[i].name;

            cout << "Father's Name: ";
            cin >> SS[i].fatherName;

            cout << "Date of Birth (DD MM YY): ";
            cin >> SS[i].dob.dd >> SS[i].dob.mm >> SS[i].dob.yy;

            cout << "Date of Admission (DD MM YY): ";
            cin >> SS[i].doa.dd >> SS[i].doa.mm >> SS[i].doa.yy;

            cout << "Enter Marks for 5 Subjects:" << endl;
            SS[i].totalMarks = 0;
            for (int j = 0; j < MAXSUB; j++) {
                cout << "Subject " << j + 1 << ": ";
                cin >> SS[i].marks[j];
                SS[i].totalMarks += SS[i].marks[j];
            }

            cout << "CGPA: ";
            cin >> SS[i].cgpa;

            cout << "Record for Registration Number " << regno << " has been updated." << endl;
            return;
        }
    }

    // If the loop completes, the record was not found
    cout << "Record not found for Registration Number: " << regno << endl;
}

// Function to Display Student Results
void DisplayStudentResults(studinfo SS[], int nn) {
    cout << "Registration Number | Name                 | Total Marks | CGPA" << endl;
    cout << "-------------------------------------------------------------" << endl;

    for (int i = 0; i < nn; i++) {
        cout << SS[i].regno << "\t\t| " << SS[i].name << "\t\t| " << SS[i].totalMarks << "/500\t| " << SS[i].cgpa << endl;
    }
}

