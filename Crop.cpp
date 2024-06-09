#include <string>
#include "Crop.h"
using namespace std;


Crop::Crop() {
	cropName = " ";
	numberOfUnits = 0.0f;
	pricePerUnit = 0.0f;
	cropExpenses = 0.0f;
};
Crop::Crop(string cropName, float numberOfUnits, float pricePerUnit, float cropExpenses) {
		this->cropName = cropName;
		this->numberOfUnits = numberOfUnits;
		this->pricePerUnit = pricePerUnit;
		this->cropExpenses = cropExpenses;
	}

string Crop::getName() {
		return cropName;
	}
	float Crop::getUnits() {
		return numberOfUnits;
	}
	float Crop::getPrice() {
		return pricePerUnit;
	}
	float Crop::getExpenses() {
		return cropExpenses;
	}
