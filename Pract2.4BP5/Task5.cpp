#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Brand { TESLA, BMW, AUDI, MERCEDES, FORD, COUNT_BRANDS };
enum Color { WHITE, BLACK, RED, BLUE, SILVER };

struct Car {
    Brand brand;
    Color color;
    int year;
};

string getBrandName(int index) {
    switch (index) {
    case TESLA: return "Tesla";
    case BMW: return "BMW";
    case AUDI: return "Audi";
    case MERCEDES: return "Mercedes";
    case FORD: return "Ford";
    default: return "Unknown";
    }
}

int main() {
    vector<Car> cars = {
        {BMW, BLACK, 2015},
        {TESLA, WHITE, 2022},
        {BMW, SILVER, 2019},
        {AUDI, BLUE, 2020},
        {BMW, RED, 2021},      
        {TESLA, RED, 2019},    
        {FORD, WHITE, 2010}
    };

	// Array for counting brands
    int brandCounts[COUNT_BRANDS] = { 0 };

    // Counting
    for (const auto& car : cars) {
        brandCounts[car.brand]++;
    }

    // search max
    int maxCount = 0;
    int maxBrandIndex = 0;

    for (int i = 0; i < COUNT_BRANDS; i++) {
        if (brandCounts[i] > maxCount) {
            maxCount = brandCounts[i];
            maxBrandIndex = i;
        }
    }

    cout << "Статистика:" << endl;
    for (int i = 0; i < COUNT_BRANDS; i++) {
        cout << getBrandName(i) << ": " << brandCounts[i] << endl;
    }

    cout << "\nМарка, що переважає: " << getBrandName(maxBrandIndex)
        << " (Кількість: " << maxCount << ")" << endl;

    return 0;
}