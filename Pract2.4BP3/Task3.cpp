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
        {"Petrenko O.O.", FEMALE, 2009, 9.2, false},
        {"Sydorenko A.V.", MALE, 2008, 7.4, true},
        {"Kovalenko M.M.", FEMALE, 2008, 10.5, true},
        {"Bondar V.V.", MALE, 2009, 6.8, false}
    };
    // Усього 5 учнів: 3 хлопці, 2 дівчини.

    int total = students.size();
    int maleCount = 0;

    for (const auto& student : students) {
        if (student.gender == MALE) {
            maleCount++;
        }
    }

    int femaleCount = total - maleCount;

    // Розрахунок відсотків (множимо на 100.0, щоб отримати дійсне число)
    double malePercent = (maleCount * 100.0) / total;
    double femalePercent = (femaleCount * 100.0) / total;

    cout << "Всього учнів: " << total << endl;
    cout << "Хлопців: " << malePercent << "% (" << maleCount << ")" << endl;
    cout << "Дівчат: " << femalePercent << "% (" << femaleCount << ")" << endl;

    return 0;
}