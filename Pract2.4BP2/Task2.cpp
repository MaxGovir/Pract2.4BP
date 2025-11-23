#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Gender { MALE, FEMALE };

struct Student {
    string fullName;
    Gender gender;
    int birthYear;
    double gpa;
    bool hasClub;
};

int main() {
    vector<Student> students = {
        {"Ivanenko I.I.", MALE, 2008, 8.5, true},
        {"Petrenko O.O.", FEMALE, 2009, 11.2, false}, // Максимальний бал
        {"Sydorenko A.V.", MALE, 2008, 7.4, true},
        {"Kovalenko M.M.", FEMALE, 2008, 10.5, true},
        {"Bondar V.V.", MALE, 2009, 6.8, false}
    };

    if (students.empty()) {
        cout << "Список порожній." << endl;
        return 0;
    }

    int maxIndex = 0;
    double maxGPA = students[0].gpa;

    // Пошук максимуму
    for (size_t i = 1; i < students.size(); i++) {
        if (students[i].gpa > maxGPA) {
            maxGPA = students[i].gpa;
            maxIndex = i;
        }
    }

    cout << "Учень з найвищим балом:" << endl;
    cout << "Номер у списку: " << maxIndex + 1 << endl; // +1 для людського сприйняття
    cout << "ПІБ: " << students[maxIndex].fullName << endl;
    cout << "Бал: " << students[maxIndex].gpa << endl;

    return 0;
}