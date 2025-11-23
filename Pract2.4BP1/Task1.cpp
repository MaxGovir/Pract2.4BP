#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Gender {
    MALE,   // 0
    FEMALE  // 1
};

// structure
struct Student {
    string fullName; 
    Gender gender;   
    int birthYear;   
    double ser;      
    bool hasClub;    
};

int main() {
    vector<Student> students = {
        {"Korol I.I.", MALE, 2008, 8.5, true},
        {"Smereka O.O.", FEMALE, 2009, 9.2, false},
        {"Kuznetsov A.V.", MALE, 2008, 7.4, true},
        {"Kifa M.M.", FEMALE, 2008, 10.5, true},
        {"Bondar V.V.", MALE, 2009, 6.8, false}
    };
    int maleCount = 0;

    for (const auto& student : students) {
        if (student.gender == MALE) {
            maleCount++;
        }
    }

    cout << "Number of students: " << students.size() << endl;
    cout << "Number of boys: " << maleCount << endl;

    return 0;
}