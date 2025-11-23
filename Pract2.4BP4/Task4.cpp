#include <iostream>
#include <vector>
#include <string>

using namespace std;


enum Brand { TESLA, BMW, AUDI, MERCEDES, FORD };
enum Color { WHITE, BLACK, RED, BLUE, SILVER };

struct Car {
    Brand brand;
    Color color;
    int year;
};

// Helping function
string getBrandName(Brand b) {
    switch (b) {
    case TESLA: return "Tesla";
    case BMW: return "BMW";
    case AUDI: return "Audi";
    case MERCEDES: return "Mercedes";
    case FORD: return "Ford";
    default: return "Unknown";
    }
}

int main() {
    vector<Car> allCars = {
        {TESLA, WHITE, 2022},
        {BMW, BLACK, 2015},
        {AUDI, SILVER, 2018},
        {FORD, BLUE, 2010},
        {MERCEDES, BLACK, 2023},
        {TESLA, RED, 2019}
    };

    int targetYear;
    cout << "enter year for searching: ";
    cin >> targetYear;
    vector<Car> filteredCars;

    // filtration
    for (const auto& car : allCars) {
        if (car.year >= targetYear) {
            filteredCars.push_back(car);
        }
    }

    cout << "\nresult of filtration:" << endl;
    if (filteredCars.empty()) {
        cout << "Not found." << endl;
    }
    else {
        for (const auto& car : filteredCars) {
            cout << "Brand: " << getBrandName(car.brand)
                << ", Year: " << car.year << endl;
        }
    }

    return 0;
}