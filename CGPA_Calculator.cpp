#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct GradeResult {
    double gpa;
    string letter;
};

GradeResult convertgrade(double grade) {
    GradeResult result;

    if (grade < 4.0) {
        result.gpa = 0.0;
        result.letter = "F";
    } else if (grade < 5.0) {
        result.gpa = 1.0;
        result.letter = "D";
    } else if (grade < 5.5) {
        result.gpa = 1.5;
        result.letter = "D+";
    } else if (grade < 6.5) {
        result.gpa = 2.0;
        result.letter = "C";
    } else if (grade < 7.0) {
        result.gpa = 2.5;
        result.letter = "C+";
    } else if (grade < 8.0) {
        result.gpa = 3.0;
        result.letter = "B";
    } else if (grade < 8.5) {
        result.gpa = 3.5;
        result.letter = "B+";
    } else if (grade < 9.0) {
        result.gpa = 3.8;
        result.letter = "A";
    } else {
        result.gpa = 4.0;
        result.letter = "A+";
    }

    return result;
}

struct Subject {
    string name;
    double scoreMid;
    double scoreFinal;
    double avgScore10;     // Score on 10-point scale
    double gradePoint;     // GPA (4.0 scale)
    string letterGrade;
    int credit;
};

struct Semester {
    string name;
    vector<Subject> subjects;
    double gpa;
    int totalCredits;
};

vector<Semester> semRecord;

void calculateGPA() {
    int numSubject;
    string semName;
    double totalPoints = 0.0;
    int totalCredits = 0;

    cout << "Enter the Semester Name: ";
    cin.ignore();
    getline(cin, semName);

    cout << "Enter the number of Subjects: ";
    cin >> numSubject;

    vector<Subject> subjects;

    for (int i = 0; i < numSubject; i++) {
        Subject subj;

        cout << "\nSubject " << i + 1 << " Name: ";
        cin.ignore();
        getline(cin, subj.name);

        cout << "Credit hour: ";
        cin >> subj.credit;

        cout << "Mid-term Score: ";
        cin >> subj.scoreMid;

        cout << "Final-term Score: ";
        cin >> subj.scoreFinal;

        subj.avgScore10 = subj.scoreMid * 0.4 + subj.scoreFinal * 0.6;

        GradeResult grade = convertgrade(subj.avgScore10);

        subj.gradePoint = grade.gpa;
        subj.letterGrade = grade.letter;

        subjects.push_back(subj);

        totalPoints += subj.gradePoint * subj.credit;
        totalCredits += subj.credit;
    }

    double gpa = totalPoints / totalCredits;
    semRecord.push_back({semName, subjects, gpa, totalCredits});

    // Print subject table
    cout << fixed << setprecision(1);
    cout << endl << "================= Subject Report =================" << endl;
    cout << left
         << setw(25) << "Subject"
         << setw(12) << "Credit"
         << setw(15) << "Avg(10pt)"
         << setw(8) << "Grade" << "\n";

    for (const auto& s : subjects) {
        cout << left
             << setw(25) << s.name
             << setw(12) << s.credit
             << setw(15) << s.avgScore10
             << setw(8) << s.letterGrade << "\n";
    }

    cout << endl << "--------------------------------------------------" << endl;
    cout << left
         << setw(25) << ("Semeseter " + semName)
         << setw(12) << totalCredits
         << setw(15) << " "
         << setw(8) << fixed << setprecision(2) << gpa << endl;
}

void calculateCGPA()
{
    if (semRecord.empty())
    {
        cout << "No semester available!" << endl;
        return;
    }

    double totalWeightedGPA = 0.0;
    int totalCredits = 0;

    cout << endl << "=================List of Semester==============" << endl;
    cout << left
         << setw(25) << "Semester"
         << setw(12) << "Credit"
         << setw(15) << "GPA" << endl;
    for (int i = 0; i < semRecord.size(); i++)
    {
        const auto& sem = semRecord[i];
        cout << left
             << setw(25) << sem.name
             << setw(12) << sem.totalCredits
             << setw(15) << fixed << setprecision(2) << sem.gpa << endl;

        totalWeightedGPA += sem.gpa * sem.totalCredits;
        totalCredits += sem.totalCredits;
    }
    double cgpa = totalWeightedGPA / totalCredits;

    cout << endl << "--------------------------------------------------" << endl;
    cout << left
         << setw(25) << "CGPA of Semesters"
         << setw(12) << totalCredits
         << setw(15) << fixed << setprecision(2) << cgpa << endl;
}

int main() 
{
    int choice;

    while(1) 
    {
        cout << "\n========= GPA / CGPA Calculator =========\n";
        cout << "1. Calculate GPA for a semester\n";
        cout << "2. Calculate CGPA\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            calculateGPA();
        }
        else if (choice == 2)
        {
            calculateCGPA();
        }
        else
        {
            cout << "Thank you!" << endl;
            break;
        }        
    } 
    return 0;
}
