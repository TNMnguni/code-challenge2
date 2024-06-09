#include "AdvancedCrop.h"  // Include the header file for your class definition
#include "Crop.h"        // Include the header file for the base class (Crop)

AdvancedCrop::AdvancedCrop(): Crop() {
	propertyTax = 0.0f;
	sizeOfCrop = 0.0f;
}
AdvancedCrop::AdvancedCrop(std::string cropName, float numberOfUnits, float pricePerUnit, float cropExpenses, float sizeOfCrop, float propertyTax)
	: Crop(cropName, numberOfUnits, pricePerUnit, cropExpenses), sizeOfCrop(sizeOfCrop), propertyTax(propertyTax) {}


AdvancedCrop::AdvancedCrop(const AdvancedCrop& other)
	: Crop(other), sizeOfCrop(other.sizeOfCrop), propertyTax(other.propertyTax) {}

float AdvancedCrop::getProduceProfit() {
	float totalRevenue = getPrice() * getUnits();
	float profit = totalRevenue - (getExpenses() + (sizeOfCrop * propertyTax));
	return profit;
}

float AdvancedCrop::getPropertyTax() {
     return propertyTax;
 }

float AdvancedCrop::getSizeOfCrop() {
      return sizeOfCrop;
	}

