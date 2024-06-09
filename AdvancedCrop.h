#ifndef ADVANCEDCROP_H
#define ADVANCEDCROP_H

#include "Crop.h"  
#include <string>

class AdvancedCrop : public Crop {
protected:
	float propertyTax;
	float sizeOfCrop;
public:
	AdvancedCrop();                                      
	AdvancedCrop(string cropName, float numberOfUnits, float pricePerUnit, float cropExpenses, float sizeOfCrop, float propertyTax);  // Parameterized constructor
	AdvancedCrop(const AdvancedCrop& other);
	float getProduceProfit();
	float getPropertyTax();
	float getSizeOfCrop();                               
};

#endif

