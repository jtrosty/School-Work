#include "Showroom.h"
#include "Vehicle.h"
#include <iostream>
using std::cout;
using std::endl;

// Default Constructor
Showroom::Showroom(string name, unsigned int capacity) {
    _name = name;
    _capacity = capacity;
}

// Accessor/Gettor
vector<Vehicle> Showroom::GetVehicleList() {
    return _vehiclesInShowroom;
}

void Showroom::AddVehicle(Vehicle v) {
    if (_vehiclesInShowroom.size() == _capacity) {
        cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
    }
    else {
        _vehiclesInShowroom.push_back(v);
    }
}

/* Shows inventory of cars in the following format: 
Vehicles in Example Showroom 
2018 Bugatti Chiron $12447.00 4 
2013 Chrysler Sebring $1819.00 22987
*/
void Showroom::ShowInventory() {
    int size = _vehiclesInShowroom.size();
    if (size == 0) cout << _name << " Showroom is empty!" << endl;
    else {
        cout << "Vehicles in " << _name << endl;
        for(int i = 0; i < size; ++i) {
            _vehiclesInShowroom.at(i).Display();
        }
    }
}

// Returns the total value or cars in showroom
float Showroom::GetInventoryValue() {
    float sumOfPrices = 0.0f;
    int size = _vehiclesInShowroom.size();
    for (int i = 0; i < size; ++i) {
        sumOfPrices += _vehiclesInShowroom.at(i).GetPrice();
    }
    return sumOfPrices;
}
