#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for better format percentage

using namespace std;

enum Gender {
    MALE,   // 0 - Чоловіча
    FEMALE  // 1 - Жіноча
};

struct Student {
    string fullName; 
    Gender gender;   
    int birthYear;   
    double ser;      
    bool hasClub;    
};

int main() {

    vector<Student> students = {
        {"Petrenko Ivan", MALE, 2008, 8.5, true},
        {"Kovalenko Maria", FEMALE, 2009, 11.2, false},
        {"Bondar Oleksiy", MALE, 2008, 7.4, true},
        {"Shevchenko Olena", FEMALE, 2008, 10.5, true},
        {"Tkachenko Vasyl", MALE, 2009, 9.0, false},
        {"Melnyk Anna", FEMALE, 2010, 11.8, true}
    };

    if (students.empty()) {
        cout << "list of student is empty." << endl;
        return 0;
    }

    int maleCount = 0;          // number of boys, task1
	int maxSerIndex = 0;        // index of student with max ser, task2
    double maxSerVal = students[0].ser;

    for (size_t i = 0; i < students.size(); i++) {

		// Counting male
        if (students[i].gender == MALE) {
            maleCount++;
        }

		// Searching max ser
        if (students[i].ser > maxSerVal) {
            maxSerVal = students[i].ser;
            maxSerIndex = i;
        }
    }
	// Counting percentages, task3
    int totalStudents = students.size();
    int femaleCount = totalStudents - maleCount;

    double malePercent = (static_cast<double>(maleCount) / totalStudents) * 100;
    double femalePercent = (static_cast<double>(femaleCount) / totalStudents) * 100;

    cout << "Task1, number of boys" << endl;
    cout << "Total number of student: " << totalStudents << endl;
    cout << "Number of boys: " << maleCount << endl;
    cout << "Next task" << endl;

    cout << "task2, student with max average" << endl;
    cout << "Number in list: " << maxSerIndex + 1 << endl; 
    cout << "FullName: " << students[maxSerIndex].fullName << endl;
    cout << "Average score: " << students[maxSerIndex].ser << endl;
    cout << "Next task" << endl;

    cout << "Task3, Percentage ratio" << endl;
    cout << fixed << setprecision(2); 
    cout << "Boys: " << malePercent << "%" << endl;
    cout << "Girls: " << femalePercent << "%" << endl;

    return 0;
}